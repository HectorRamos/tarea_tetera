#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat zoom=60.0f;

void init(void)
{
/* selecciona el color de borrado */
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
/* borra la pantalla */
glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
/* seleccionamos la matriz modelo/vista */
glMatrixMode(GL_MODELVIEW);
/* color */
glColor3f(1.0, 1.0, 1.0);

/* transformación modelo/vista */
glLoadIdentity();
glRotatef(rotate_x, 1.0, 0.0, 0.0 );
glRotatef(rotate_y, 0.0, 1.0, 0.0 );
glRotatef(rotate_z, 0.0, 0.0, 1.0 );
glTranslatef(0.0, 0.0, -5.0);
/* Dibujamos una tetera */
glutWireTeapot(1.0);
/* Vacia el buffer de dibujo */
glFlush ();
glutSwapBuffers();
}
void reshape(int w, int h)
{
/* definemos el marco */
glViewport(0, 0, w, h);
/* cambiamos a la matriz de proyección */
glMatrixMode(GL_PROJECTION);
/* definimos una proyección perspectiva con
un fovy de 60 grados y el near a 1.0 y el
far a 20.0 */
glLoadIdentity();
gluPerspective(GLfloat(zoom), GLfloat(w) / GLfloat(h), 1.0, 20.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	
	{
	case 'x':
		rotate_x +=7; 
		break;
	case 'X':
			rotate_x -=7;
			break;
	case 'y':
		rotate_y +=7; 
		break;
	case 'Y':
			rotate_y -=7;
			break;
	case 'z':
		rotate_z +=7; 
		break;
	case 'Z':
			rotate_z -=7;
			break;
	
	case '-':
			zoom += 10.0;
			break;
    case '+':
        zoom -= 10.0;
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
glutKeyboardFunc(keyboard); //invoca funcion de teclado
//glutSpecialFunc(specialKeys);//invoca teclas de función especial
// Indica cual es la función para el cambio de tamaño de laventana
glutReshapeFunc(reshape);

// Comienza el bucle de dibujo y proceso de eventos.
glutMainLoop();
return 0;
}
