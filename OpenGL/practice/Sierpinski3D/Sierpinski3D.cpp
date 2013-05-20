// Sierpinski3D.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void display();
void triangle(GLfloat *a, GLfloat *b, GLfloat *c);
void tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d);
void divide_tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m);
void myReshape(int w, int h);

// ����һ��������Ķ���
//GLfloat vertices[4][3] = {{0.0, 0.0 ,1.0}, {0.0, 0.94, 10.0},
//						{50.0, 25.0, 25.0}, {25.0, 10.0, 25.0}};
// ��������������һ����Ϊ��ʼλ��
//GLfloat p[3] = {25.0, 10.0, 25.0};

// ��ɫ
GLfloat colors[4][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}};

// ϸ�ִ���
int n = 10;

// ��ʼ��������
GLfloat v[4][3] = {{0.0, 0.0, 1.0}, {0.0, 0.94, -0.33}, {-0.81, -0.48, -0.33}, {0.8, -0.48, -0.33}};

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Gasket");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	divide_tetra(v[0], v[1], v[2], v[3], n);
	glEnd();
	glFlush();
	// ���㲢����һ����λ��
	//int rand();
	//int j;
	//j = rand() % 4;// �����ѡһ������

	// ���㶥�����һ������֮�����ߵ��е�
	//p[0] = (p[0] + vertices[j][0]) / 2;
	//p[1] = (p[1] + vertices[j][1]) / 2;
	//p[2] = (p[2] + vertices[j][2]) / 2;

	// ���Ƶ�
	//glBegin(GL_POINTS);
		//glColor3f(p[0]/250.0, p[1]/250.0, p[2]/250.0);
		//glVertex3fv(p);
	//glEnd();
	//glFlush();
}

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}

void tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)
{
	glColor3fv(colors[0]);
	triangle(a, b, c);
	glColor3fv(colors[1]);
	triangle(a, c, d);
	glColor3fv(colors[2]);
	triangle(a, d, b);
	glColor3fv(colors[3]);
	triangle(b, d, c);
}

void divide_tetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{
	GLfloat mid[6][3];
	int j;
	if(m > 0)
	{
		// ����6���е�
		for(j = 0; j < 3; j++)
			mid[0][j] = (a[j] + b[j]) / 2;
		for(j = 0; j < 3; j++)
			mid[1][j] = (a[j] + c[j]) / 2;
		for(j = 0; j < 3; j++)
			mid[2][j] = (a[j] + d[j]) / 2;
		for(j = 0; j < 3; j++)
			mid[3][j] = (c[j] + b[j]) / 2;
		for(j = 0; j < 3; j++)
			mid[4][j] = (c[j] + d[j]) / 2;
		for(j = 0; j < 3; j++)
			mid[5][j] = (d[j] + b[j]) / 2;

		// ͨ��ϸ������4��������
		divide_tetra(a, mid[0], mid[1], mid[2], m-1);
		divide_tetra(mid[0], b, mid[3], mid[5], m-1);
		divide_tetra(mid[1], mid[3], c, mid[4], m-1);
		divide_tetra(mid[2], mid[4], d, mid[5], m-1);
	}
	else
		tetra(a, b, c, d);
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glOrtho(-2.0, 2.0, -2.0*(GLfloat)h / (GLfloat)w, 
			2.0*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0*(GLfloat)w / (GLfloat)h, 
			2.0*(GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}