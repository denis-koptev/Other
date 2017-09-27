/*
* Personal template for OpenGL project in VS
*/

#define _CRT_SECURE_NO_WARNINGS

#include <GL/glut.h>

/* Data */

GLint winSize = 1000;

GLint sphereLevels = 30;
GLdouble sphereRad = 100;

const float rotationStep = 2;
GLdouble angleX = 0, angleY = 0, angleZ = 0;

/* Functions */

void specialKeys(int key, int x, int y);
void keyboardKeys(unsigned char key, int x, int y);
void display();

/* Entry */

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(winSize, winSize);
	glutInitWindowPosition(460, 10);
	glutCreateWindow("Shapes");

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboardKeys);

	glutMainLoop();

	return 0;
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_RIGHT:
		{
			angleY += rotationStep;
			break;
		}
		case GLUT_KEY_LEFT:
		{
			angleY -= rotationStep;
			break;
		}
		case GLUT_KEY_UP:
		{
			angleX -= rotationStep;
			break;
		}
		case GLUT_KEY_DOWN:
		{
			angleX += rotationStep;
			break;
		}
		default:
		{
			break;
		}
	}

	glutPostRedisplay();
}

void sphereInCylinder()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(- winSize / 2, winSize / 2,
	        - winSize / 2, winSize / 2,
	        - winSize / 2, winSize / 2);

	glPushMatrix();
	glRotatef(angleY, 0, 1, 0);
	glRotatef(angleX, 1, 0, 0);

	// sphere
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(sphereRad, sphereLevels, sphereLevels);

	glPopMatrix();

	glFlush();
}

void keyboardKeys(unsigned char key, int x, int y)
{
	if (key == '\033')
	{
		exit(0);
	}
}