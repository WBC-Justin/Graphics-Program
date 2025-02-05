#include <GL/glut.h>
#include<iostream>
// initial triangle 
// GLfloat v[4][3] = { {-1.0, -0.58 },{1.0, -0.58 }, {0.0, 1.15 } };						    //(��)�������ΥΪ��T�I(��))
GLfloat v_Volume[4][2] = { {-1.0, -0.58 },{1.0, -0.58 }, {0.0, 1.15 } , {0.0 , 0.0} };		    //����n���ΤΪ����ΥΪ��|�I
int n; // number of recursive steps 
void triangle(GLfloat* a, GLfloat* b, GLfloat* c)												//�L�X�T����                                            
{
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}
void triangular_Volume(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d) {
	glColor3f(0.0, 0.0, 1.0);																		//�C����
	triangle(a, b, c);                                                                              //triangle�L�X�T����
	glColor3f(0.0, 1.0, 0.0);																	    //�C����
	triangle(a, c, d);
	glColor3f(1.0, 0.0, 0.0);																		//�C����
	triangle(a, b, d);
}
void divide_triangle(GLfloat* a, GLfloat* b, GLfloat* c, int m)
{
	GLfloat v1[3], v2[3], v3[3];
	int j;
	if (m > 0)
	{
		
		for (j = 0; j < 3; j++) v1[j] = (a[j] + b[j]) / 2;
		for (j = 0; j < 3; j++) v2[j] = (a[j] + c[j]) / 2;
		for (j = 0; j < 3; j++) v3[j] = (b[j] + c[j]) / 2;
		divide_triangle(a, v1, v2, m - 1);
		divide_triangle(b, v3, v1, m - 1);
		divide_triangle(c, v2, v3, m - 1);	
	}
	else(triangle(a, b, c));
}
void divide_triangle_Volume(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d, int m) {                                   //���Υ���T����
	GLfloat v1[3], v2[3], v3[3], v4[3], v5[3], v6[3];																   //�n��6�ӥh�s�����I���X�Ӫ��I(6��)
	int j;
	if (m == 0)
	{
		triangular_Volume(a, b, c, d);																				   //���Ƭ�0�ɩI�striangular_Volume
	}
	else{
		//triangle_Volume(a, b, c ,d)
	for (j = 0; j < 3; j++) v1[j] = (a[j] + b[j]) / 2;
	for (j = 0; j < 3; j++) v2[j] = (a[j] + c[j]) / 2;
	for (j = 0; j < 3; j++) v3[j] = (b[j] + c[j]) / 2;
	for (j = 0; j < 3; j++) v4[j] = (a[j] + d[j]) / 2;
	for (j = 0; j < 3; j++) v5[j] = (b[j] + d[j]) / 2;
	for (j = 0; j < 3; j++) v6[j] = (c[j] + d[j]) / 2;
	divide_triangle_Volume(a, v1, v2, v4, m - 1);								//�Ӷ��ǶǤJ�A�����I(���ƴ�@)
	divide_triangle_Volume(v1, b, v3, v5, m - 1);
	divide_triangle_Volume(v2, v3, c, v6, m - 1);
	divide_triangle_Volume(v4, v5, v6, d, m - 1);
   }
}


void tetrahedron(int m)						        
{
	glColor3f(0.0, 1.0, 0.0);					     //�C���C��
	divide_triangle(v_Volume[0], v_Volume[1], v_Volume[2], m);            //�ǤJ3���I�h���� �A m = ���Φ���(�̩��h)
	glColor3f(0.0, 0.0, 1.0);
	divide_triangle(v_Volume[3], v_Volume[2], v_Volume[1], m);
	glColor3f(0.0, 0.0, 0.0);
	divide_triangle(v_Volume[0], v_Volume[3], v_Volume[1], m);
	glColor3f(1.0, 0.0, 0.0);
	divide_triangle(v_Volume[0], v_Volume[2], v_Volume[3], m);
}

void display()													//��ܥ����ϧ�
{
	//int n = 1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			//�M���w�]buffer���e
	glBegin(GL_TRIANGLES);										//�}�l�쵲���n�e���ϧ�line119

//	divide_triangle(v[0], v[1], v[2], n);
	tetrahedron(n);												//�I�stetrahedron
	glEnd();
	glFlush();
}
void tetrahedron_Volume(int m) {
	
	divide_triangle_Volume(v_Volume[0], v_Volume[1], v_Volume[2], v_Volume[3], m);    //�ǤJ4���I�h���έn���ۦP����

}
void display_Volume() {											//��ܥ���ϧ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         //�M���w�]buffer���e
	glBegin(GL_TRIANGLES);										//�}�l�쵲���n�e���ϧ�line119
	tetrahedron_Volume(n);										//�I�stetrahedron_Volume

	glEnd();
	glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);                              //
	glLoadIdentity();										  //(���s�����x�})	
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);					      //�i���d��w�q
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 0.0);						      //��l�Ƶ����C��
}

void mainMenu(int index) {									     //�}�D�ؿ�
	switch (index) {
	case 1 :
		break;
	case 2 :
		break;
	}
}
void sub_3D_Gasket(int index)									//�l�ؿ��n�F��(���s�w�q�e���A�M�e�W�s��)
{
	switch (index) {
	case 1 :
		glutPostRedisplay();
		glutDisplayFunc(display);

		myinit();
		break;
	case 2 :
		glutPostRedisplay();
		glutDisplayFunc(display_Volume);

		myinit();
		break;
	}
}
void sub_Subdivision_Level(int index)							//�l�ؿ��n�F��(�]�w���μ�)
{
	switch (index) {
	case 1:
		n = 2;		
		break;
	case 2:
		n = 3;	
		break;
	case 3:
		n = 4;
		break;
	}
}

void createMenu()											        //�����k���A��ܪ��F��
{
	int _3D_Gasket = glutCreateMenu(sub_3D_Gasket);                 //����186��
	glutAddMenuEntry("Surface Subdivision", 1);
	glutAddMenuEntry("Volume Subdivision", 2);

	int Subdivision_Level = glutCreateMenu(sub_Subdivision_Level);  //����187��
	glutAddMenuEntry("2" , 1);
	glutAddMenuEntry("3" , 2);
	glutAddMenuEntry("4" , 3);

	int Menu = glutCreateMenu(mainMenu);
	glutAddSubMenu("3D_Gasket", _3D_Gasket);
	glutAddSubMenu("Subdivision_Level", Subdivision_Level);

	glutAttachMenu(GLUT_RIGHT_BUTTON);								//�S�o�椣�|��menu(Ĳ�omenu)
}

void keyboard(unsigned char key , int x , int y) {				    //keyboard�禡����q|Q�ɷ|�j����{��		
	if (key == 'q' || key == 'Q') exit(0);
}

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);									//��l�Ƶ����j�p
	glutCreateWindow("3D Gasket");									//�����W��
	
	createMenu();													//���k���k
	glutKeyboardFunc(keyboard);										//����L��k
	glutDisplayFunc(display);										//��ܤ@�}�l���ϧ�
   
	myinit();
	glutMainLoop();													//�L�a�j��ت��O���ϫ������
}
