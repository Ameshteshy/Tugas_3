#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
//#include <iostream>

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;

static float rotX = 0, rotY = 0, rotZ = 0, rotAngle = 0;

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();

	// Modeling transformations.
	//Kamera
	glTranslatef(X, Y, Z);
	glRotatef(0, rotX, rotY, rotZ);

	//Kepala Meja
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glColor3f(1, 1, 0);
	glutSolidCylinder(6.0, 1.0, 8, 1);
	glPopMatrix();

	//Kaki Depan
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 3, 1);
	glRotatef(-15, 1, 0, 0);
	glColor3f(1, 1, 0);
	glutSolidCylinder(0.5, 8.0, 8, 1);
	glPopMatrix();

	//Kaki Kanan
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(3, 0, 1);
	glColor3f(1, 1, 0);
	glRotatef(15, 0, 1, 0);
	glutSolidCylinder(0.5, 8.0, 8, 1);
	glPopMatrix();

	//Kaki Kiri
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-3, 0, 1);
	glColor3f(1, 1, 0);
	glRotatef(-15, 0, 1, 0);
	glutSolidCylinder(0.5, 8.0, 8, 1);
	glPopMatrix();

	//Kaki Belakang
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -3, 1);
	glRotatef(15, 1, 0, 0);
	glColor3f(1, 1, 0);
	glutSolidCylinder(0.5, 8.0, 8, 1);
	glPopMatrix();

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	//glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		X += 0.5;
		glutPostRedisplay();
		break;
	case 'd':
		X -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
		Y -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 0.5;
		glutPostRedisplay();
		break;
	case 'q':
		Z -= 0.5;
		glutPostRedisplay();
		break;
	case 'e':
		Z += 0.5;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void RotKeyInput(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'j':
		rotX = 1;
		glutPostRedisplay();
		break;
	case 'l':
		rotX = 1;
		glutPostRedisplay();
		break;
	case 'k':
		rotY = 1;
		glutPostRedisplay();
		break;
	case 'i':
		rotY = 1;
		glutPostRedisplay();
		break;
	case 'o':
		rotZ = 1;
		glutPostRedisplay();
		break;
	case 'u':
		rotZ = 1;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("box.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}