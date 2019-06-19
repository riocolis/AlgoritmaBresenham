# AlgoritmaBressenham
Implementasi Algoritma Bresenham

Dalam project ini menggunakan Aplikasi CodeBlock sebagai tempat penulisan codingnya.
agar dapat menjalankan Project ini Codeblocknya harus sudah di include glut.h di MINGW -nya.
untuk cara include glut.h dapat dilihat di video ini : https://youtu.be/pak-Z6uQjAQ.

Algoritma Bresenham adalah suatu algoritma yang digunakan menggambar garis. 
Kelemahan Algoritma Bresenham hanya dapat menggambar garis horisontal, atau miring 45 derajat.
selain itu Bresenham hanya dapat menggambar garis dari kiri ke kanan. tetapi dalam project ini 
sudah di modifikasi sehingga dapat menggambar garis dengan arah yang diingankan (dapat menggambar
seperti Algoritma DDA)


Project ini menggunakan user input dalam menentukan titik awal (x1,y1) dan titik Akhirnya (x2,y2),
dengan catatan semua nilai x1,y1,x2,y2 harus positif.

Output program ini berupa garis yang digambar di window baru dan panjangnya sesuai dengan input.

Langkah-langkah pembentukan garis berdasarkan algoritma Bressenham adalah:

1.  Tentukan dua titik yang akan dihubungkan dalam pembentukan garis.
2.  Tentukan salah satu sebagai titik awal (x0, y0) dan titik akhir (x1, y1).
3.  Hitung dx,  dy, 2dy  dan 2dy - 2dx
4.  Hitung parameter : po = 2dy - dx
5.  Untuk setiap xk sepanjang jalur garis, dimulai dengan k=0
      -  bila  pk < 0   maka titik selanjutnya adalah:
		(xk+1, yk)  dan  pk+1 = pk + 2dy
      -  bila tidak, titik selanjutnya adalah: 
		(xk+1, yk+1)  dan  pk+1 = pk + 2dy – 2dx
6.   Ulangi nomor 5 untuk menentukan posisi pixel berikutnya, sampai 
      x = x1  atau  y = y1
