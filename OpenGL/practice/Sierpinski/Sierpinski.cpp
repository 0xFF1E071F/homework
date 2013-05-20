// Sierpinski.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void myinit();
void display();

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simple OpenGL example");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}

void myinit()
{
	// ��������
	glClearColor(1.0, 1.0, 1.0, 1.0);	// ��ɫ�ı���
	glColor3f(1.0, 0.0, 0.0);	// �ú�ɫ������

	// ���ù۲����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	// ������
	GLfloat vertices[3][2] = {{0.0, 0.0},{25.0, 50.0},{50.0, 0.0}};

	int i, j, k;
	int rand();
	GLfloat p[2] = {7.5, 5.0};	// ��������һ��

	glClear(GL_COLOR_BUFFER_BIT);	// ��մ���

	// ���㲢���5000����
	glBegin(GL_POINTS);
	for(k = 0; k < 5000; k++)
	{
		j = rand() % 3;

		// ���㶥������һ��֮�����ߵ��е�
		p[0] = (p[0] + vertices[j][0]) / 2;
		p[1] = (p[1] + vertices[j][1]) / 2;

		// ���Ƶ�
		glVertex2fv(p);
	}
	glEnd();
	glFlush();
}