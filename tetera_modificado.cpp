#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
double rotate_y=0;
double rotate_x=0;
double rotate_z=0.2;
GLfloat zoom=0.5;


void init(void)
{
/* selecciona el color de borrado */
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
/* borra la pantalla */
glClear (GL_COLOR_BUFFER_BIT);
/* seleccionamos la matriz modelo/vista */
glMatrixMode(GL_MODELVIEW);
/* color */
glColor3f(1.0, 1.0, 1.0);
glLoadIdentity();
glTranslatef(0.0, 0.0, 0.0);
glRotatef(0.0, 0.0, 0.0, 1.0);
/* transformación modelo/vista */
gluLookAt(rotate_x,rotate_y,rotate_z, //punto de vista en el eje X,Y,Z
0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
/* Dibujamos una tetera */
glutWireTeapot(zoom);
/* Vacia el buffer de dibujo */
glFlush ();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	
	{
	case 'z':
			rotate_z +=0.2; 
			break;
	case 'Z':
			rotate_z -=0.2;
			break;
    case 'x' :
        rotate_x += 0.2;
        break;
    case 'X' :
          rotate_x -= 0.2;
        break;
    case 'y' :
        rotate_y += 0.2;
        break;
    case 'Y' :
        rotate_y -= 0.2;
        break;
    	
    case '-':
			zoom -=0.1;
			break;
	case '+':
			zoom +=0.1;
			break;
   
	}
	 glutPostRedisplay();
	
	}


int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
glutInit(&argc, argv);
// Inicializa el modo de visualización
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
glutInitWindowSize(500, 500);
// Indica la posición inicial (xmin,ymin)
glutInitWindowPosition(100, 100);
// Abre la ventana con el título indicado
glutCreateWindow("Dibujando una tetera 3d");
// Inicializar valores
init();
// Indica cual es la función de dibujo
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
// Indica cual es la función para el cambio de tamaño de laventana

// Comienza el bucle de dibujo y proceso de eventos.
glutMainLoop();
}
