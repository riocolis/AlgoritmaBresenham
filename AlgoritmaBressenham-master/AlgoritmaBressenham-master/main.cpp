///Algoritma Bresenham

#include <GL\glut.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

///identifier fungsi
void init();
void display(void);
void bresenham(void);

///  posisi window di layar
int window_x,window_y;

int x1,y1,x2,y2;

///  ukuran window
int window_width = 512;
int window_height = 512;

/// judul window
char *judul_window = "Algoritma Bresenham";

int main(int argc, char **argv)
{
    awal:cout<<"Masukkan nilai x1 : ";cin>>x1;
    cout<<"Masukkan nilai y1 : ";cin>>y1;
    cout<<"\nMasukkan nilai x2 : ";cin>>x2;
    cout<<"Masukkan nilai y2 : ";cin>>y2;
    if((x1 < 0) || (y1 < 0) || (x2 < 0) || (y2 < 0)){
        cout<<"Nilai masukan ada yang bernilai negatif\n";
        goto awal;
    }
    cout<<endl;

	///  inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);

	/// set posisi window supaya berada di tengah
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); ///set ukuran window
	glutInitWindowPosition(window_x, window_y); ///set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); /// set display RGB dan double buffer
	glutCreateWindow(judul_window); ///set judul window

	init(); ///jalankan fungsi init
	glutDisplayFunc(display); ///  set fungsi display
	glutMainLoop(); /// set loop pemrosesan GLUT
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); ///set warna background
	glColor3f(1.0, 1.0, 1.0); ///set warna titik
	glPointSize(2.0); ///set ukuran titik
	glMatrixMode(GL_PROJECTION); ///set mode matriks yang digunakan
	glLoadIdentity(); /// load matriks identitas
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); /// set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); ///clear color
	bresenham(); ///jalankan fungsi bresenham
	glutSwapBuffers(); ///swap buffer
}

void bresenham(void) {
	int x, y, dx, dy, yend, p, duadx, duadxdy;
	int duady,duadydx,xend;
	int i=2;

	///hitung dx dan dy
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	///hitung p
	if(dy>dx){   ///untuk garis yang mendekati vertikal
        p = 2*dx - dy;
        duadx = 2*dx;
        duadxdy = 2 * (dx - dy);

        ///Menentukan titik awal dan akhir
        if(y1<y2){
            cout<<"\nMasuk dy dg y1 lebih kecil\n";
            x = x1;
            xend = x2;
            y = y1;
            yend = y2;
        }else{
            cout<<"\nMasuk dy dg y2 lebih kecil\n";
            x = x2;
            xend = x1;
            y = y2;
            yend = y1;
        }
	}else{  ///untuk garis yang mendekati horisontal
        p = 2*dy - dx;
        duady = 2*dy;
        duadydx = 2*(dy - dx);

        ///Menentukan titik awal dan akhir
        if(x1<x2){
            cout<<"\nMasuk dx dg x1 lebih kecil\n";
            x = x1;
            xend = x2;
            y = y1;
            yend = y2;
        }else{
            cout<<"\nMasuk dx dg x2 lebih kecil x\n";
            x = x2;
            xend = x1;
            y = y2;
            yend = y1;
        }
	}

	///gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	cout<<"Titik ke-1 --> ("<<x<<","<<y<<")\n";

	///perulangan untuk menggambar titik-titik

	do { ///kondisi : (garis -> vertikal || garis -> hor) (dy>dx || dy=<dx)
        if(dy>dx){ ///kondisi dy lebih besar
            y++;
            if (p < 0) {
                p += duadx;
            }
            else{
                if (x > xend){ ///cek x
                    x--;
                }else{
                    x++;
                }
                p += duadxdy;
            }
        }else{ ///kondisi dx lebih besar
            x++;
            if (p < 0) {
                p += duady;
            }
            else{
                if (y > yend){ ///cek x
                    y--;
                }else{
                    y++;
                }
                p += duadydx;
            }
        }
        glVertex2i(x, y);
        cout<<"Titik ke-"<<i<<" --> ("<<x<<","<<y<<")\n";
        i++;
	}while(y < yend || x < xend); ///kondisi : (garis -> vertikal || garis -> hor) (dy>dx || dy=<dx)

	glEnd();
	glFlush();
}
