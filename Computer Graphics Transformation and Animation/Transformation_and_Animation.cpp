#include<stdio.h>
#include<iostream>
#include <gl/glut.h>
#include <windows.h>
#define KEY_ESC 27 /* GLUT doesn't supply this */

int fullscreen = 0;
int mouseDown = 0;

float xrot = 0;
float yrot = 0;
float zrot = 0;
float xxrot = 0;
float yyrot = 0;
float zzrot = 0;
float xxxrot = 0;
float yyyrot = 0;
float zzzrot = 0;

float xdiff = 100.0f;
float ydiff = 100.0f;

float tra_x = 0.0f;
float tra_y = 0.0f;
float tra_z = 0.0f;

float grow_shrink = 70.0f;
float resize_f = 1.0f;
int _switch = 1;
static int day = 180;
void _idle();

void drawBox3() {
	glTranslatef(tra_x, tra_y, tra_z);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, 0.2);
	glColor4ub(0, 0, 255, 255);	glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, 0.2);
	//背面
	glNormal3f(0, 0, -0.2);
	glColor4ub(255, 0, 0, 255);glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(0.2, 0.6, -0.2);
	glColor4ub(0, 255, 0, 255);glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, -0.6, -0.2);
	//右側面
	glNormal3f(0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, -0.2);	
	//左側面
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255);glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(-0.2, -0.6, -0.2);
	glColor4ub(0, 255, 0, 255);glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, 0.2);		
	//上面
	glNormal3f(0, 0.2, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(-0.2, 0.6, 0.2);
	glColor4ub(0, 255, 0, 255);glVertex3f(0.2, 0.6, 0.2);
	glColor4ub(255, 0, 0, 255);glVertex3f(0.2, 0.6, -0.2);
	
	//下面
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255);
	glColor4ub(0, 0, 255, 255);
	glColor4ub(0, 255, 0, 255);
	glColor4ub(255, 0, 0, 255);

	glEnd();
}

void drawBox5() {
	glTranslatef(tra_x, tra_y, tra_z);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, 0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(0, 255, 0, 255);glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255);	glVertex3f(0.2, 0.6, 0.2);	

	//背面
	glNormal3f(0, 0, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(0.2, 0.6, -0.2);
	glColor4ub(0, 255, 0, 255);glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255);	glVertex3f(-0.2, -0.6, -0.2);

	//右側面
	glNormal3f(0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, 0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(0, 255, 0, 255);glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255);glVertex3f(0.2, 0.6, -0.2);	
	
	//左側面
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255);glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(-0.2, -0.6, -0.2);
	glColor4ub(0, 255, 0, 255);	glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, 0.2);
	
	//上面
	glNormal3f(0, 0.2, 0);
	glColor4ub(255, 0, 0, 255);glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255);glVertex3f(-0.2, 0.6, 0.2);
	glColor4ub(0, 255, 0, 255);glVertex3f(0.2, 0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, -0.2);	
	
	//下面

	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, -0.6, 0.2);
	
	glEnd();
}

int init(void)
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	return 1;
}
void cyclinder1() {
	glPushMatrix();
//	glTranslatef(0.0, 0.4, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 4.5);
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 1.0f);
	gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14 , 132);
	glPopMatrix();
}
void cyclinder2() {
	glPushMatrix();
	glTranslatef(0.35, 0.0, 0.0);
	glRotatef(90, 0.0, 180.0, 0.0);
	glScalef(0.3, 0.3, 4.5);
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor3f(0.3f, 0.0f, 1.0f);
	gluCylinder(pobj, 0.6f, 0.6f, 0.1f, 32, 32);
	glPopMatrix();
}
void cyclinder3() {
	glPushMatrix();
//	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(90, 0.0, 180.0, 0.0);
	glScalef(0.25, 0.25, 2.0);                //條大小
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor3f(0.3f, 0.0f, 1.0f);
	gluCylinder(pobj, 0.6f, 0.6f, 0.1f, 32, 32);
	glPopMatrix();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                           //您??上??前?移到了屏幕中心：?似于一?复位操作

	gluLookAt(
		0.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 5.0f);

	glTranslatef(-1.8, -1.2, -0.5);
//	drawBox2();
	glRotatef(xxxrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yyyrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zzzrot, 0.0f, 0.0f, 1.0f);
	cyclinder1();
	glTranslatef(-0.6, 0.2, 0);
	//drawBox();
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);

	cyclinder2();
	glTranslatef(1.0, 0.3, 0);
	drawBox3();
	glTranslatef(0.2, 0.4, 0);
	glRotatef(xxrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);
	cyclinder3();
	//drawBox4();
	glTranslatef(0.40, 0.3, 0);
	drawBox5();
	
	glFlush();
	glutSwapBuffers();
}
void resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(grow_shrink, resize_f * w / h, resize_f, 100 * resize_f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
void idle(void)
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}

	glutPostRedisplay();
}

void mySpecialFunction(int key, int x, int y)
{
	
	printf("U -----------> rotate clockwise\n");
	printf("Y -----------> rotate counter clockwise\n");
	printf("I or i ------> Up\n");
	printf("m or M -----> Down\n");
	printf("D or d ------> Right\n");
	printf("A or a ------> Left\n");
	printf("Z or z ------> Shrink\n");
	printf("X or x ------> Grow\n");
	printf("Escape Key ---> exit the program\n\n");
	
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'Q':
	case 'q':
		exit(1);
		break;


	case 'i':
	case 'I':
			tra_x += 0.1f;
		break;
	case 'm':
	case 'M':
			tra_x -= 0.1f;
		break;
	case 'a':
	case 'A':
		yyyrot += 1.0f;
		if (yyyrot > 360.0) yyyrot -= 360.0;
		glutPostRedisplay();
		break;
	case 'z':
	case 'Z':
		yyyrot -= 1.0f;
		if (yyyrot > 360.0) yyyrot -= 360.0;
		glutPostRedisplay();
		break;
	case 'd':
	case 'D':
		xxrot += 5.0f;
		if (xxrot > 360.0) xxrot -= 360.0;
		glutPostRedisplay();
		break;
	case 'c':
	case 'C':
		xxrot -= 5.0f;
		if (xxrot > 360.0) xxrot -= 360.0;
		glutPostRedisplay();
		break;
	case 'X':
	case 'x':
		
		xrot += 2.0f;
		if (xrot > 360.0) xrot -= 360.0;
		glutPostRedisplay();
		break;

	case 's':
	case 'S':
		
		xrot -= 2.0f;
		if (xrot > 360.0) xrot -= 360.0;
		glutPostRedisplay();
		break;

	case '27':
		mySpecialFunction(key, x, y);
		break;
	case 'o':   // z -> g
	case 'O':
		grow_shrink--;
		resize(600, 500);

		break;
	case 'p':
	case 'P':
		grow_shrink++;
		resize(600, 500);

		break;

	}

	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y)
{
	if (key == GLUT_KEY_F1)
	{
		fullscreen = !fullscreen;

		if (fullscreen)
			glutFullScreen();
		else
		{
			glutReshapeWindow(500, 500);
			glutPositionWindow(50, 50);
		}
	}
}

void mainMenu(int index) {									     //開主目錄
	switch (index) {
	case 1:
		break;
	case 2:
		break;
	}
}
void sub_3D_Gasket(int index)									//子目錄要幹嘛(重新定義畫布，和畫上新的)
{
	switch (index) {
	case 1:
		_switch = 1;
		printf("%d", _switch);
		if (_switch == 1) {
			glutIdleFunc(_idle);	//可以執行連續動畫			
		}
		
		break;
	case 2:

		_switch = 0;
		
		break;
	}
}

void createMenu()											        //做按右鍵後，顯示的東西
{
	int _3D_Gasket = glutCreateMenu(sub_3D_Gasket);                 //對應186行
	glutAddMenuEntry("on", 1);
	glutAddMenuEntry("off", 2);


	int Menu = glutCreateMenu(mainMenu);
	glutAddSubMenu("Automation", _3D_Gasket);
	

	glutAttachMenu(GLUT_RIGHT_BUTTON);								//沒這行不會有menu(觸發menu)
}
void _idle()
{
	if (_switch == 1) {
		glutDisplayFunc(display);
		xrot += 2.0f;
		xxrot += 3.0f;
		yyyrot += 1.0f;
		if (xrot > 360.0) xrot -= 360.0;
		if (xxrot > 360.0) xxrot -= 360.0;
		if (yyyrot > 360.0) yyyrot -= 360.0;
		glutPostRedisplay();
	}	
	
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1000, 1000);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("13 - Solid Shapes");
	createMenu();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	
	glutReshapeFunc(resize);
	

	if (!init())
		return 1;
		
	glutMainLoop();

	return 0;
}
