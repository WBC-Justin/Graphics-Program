#include<stdio.h>
#include<iostream>
#include <gl/glut.h>
#include <windows.h>
#define G_PI 3.14159265358979323846f
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
float leaf_rot1_x = 0;
float leaf_rot1_y = 0;
float leaf_rot1_z = 0;
float leaf_rot2_x = 0;
float leaf_rot2_y = 0;
float leaf_rot2_z = 0;

float xdiff = 100.0f;
float ydiff = 100.0f;

float tra_x = 0.0f;
float tra_y = 0.0f;
float tra_z = 0.0f;

float grow_shrink = 70.0f;
float resize_f = 1.0f;


int old_rot_x = 0;                       //剛按下滑鼠時的視窗座標
int old_rot_y = 0;

int rot_x = 0;                           //拖曳後的相對座標，用這決定要旋轉幾度
int rot_y = 0;

int record_x = 0;                        //紀錄上一次旋轉的角度
int record_y = 0;
float gg = 3.0;
int _switch = 1;
int _switch_2 = 1;
int true_switch = 0;
int true_switch2_for_cup = 0;
int true_seitch_for_cup2 = 0;
int true_switch_for_cup4 = 0;
int _switch_base = 0;
int latte = 0;
int water = 0;
int Grass_tea = 0;
static int du = 90, oldmy = -1, oldmx = -1; //du是視點繞y軸的角度,opengl裡預設y軸是上方向
static double r = 1.5f, h = 0.0f; //r是視點繞y軸的半徑,h是視點高度即在y軸上的座標
static double c = G_PI / 180.0f; //弧度和角度轉換引數
static double theta = 0, phi = 0;
void _idle();
void SetLightSource(void);               //設定光源屬性
void SetMaterial(void);                  //設定材質屬性
void SetLightSource2(void);               //設定光源屬性
void SetMaterial2(void);                  //設定材質屬性
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
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, 0.6, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, -0.6, -0.2);
	//右側面
	glNormal3f(0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, -0.2);
	//左側面
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.2, -0.6, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, 0.2);
	//上面
	glNormal3f(0, 0.2, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.2, 0.6, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, 0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.6, -0.2);

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
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.1, 0.6, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255);	glVertex3f(0.1, 0.6, 0.2);

	//背面
	glNormal3f(0, 0, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.1, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1, 0.6, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255);	glVertex3f(-0.2, -0.6, -0.2);

	//右側面
	glNormal3f(0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.6, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, -0.6, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.6, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.6, -0.2);

	//左側面
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.1, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.2, -0.6, -0.2);
	glColor4ub(0, 255, 0, 255);	glVertex3f(-0.2, -0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.1, 0.6, 0.2);

	//上面
	glNormal3f(0, 0.2, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.1, 0.6, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.1, 0.6, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.1, 0.6, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.6, -0.2);

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
//	glTranslatef(0.0,-0.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 5.5);
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 1.0f);
	gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14, 132);
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

void base() {
	glTranslatef(0.3 , -1.2 , -0.2);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(112, 128, 105, 255);
	glVertex3f(-0.2, 0.1, 0.2);
	glVertex3f(-0.2, -0.1, 0.2);
	 glVertex3f(0.2, -0.1, 0.2);
	 glVertex3f(0.2, 0.1, 0.2);
	//背面
	glNormal3f(0, 0, -0.2);
	 glVertex3f(-0.2, 0.1, -0.2);
	 glVertex3f(0.2, 0.1, -0.2);
	 glVertex3f(0.2, -0.1, -0.2);
	glVertex3f(-0.2, -0.1, -0.2);
	//右側面
	glNormal3f(0.2, 0, 0);
	 glVertex3f(0.2, 0.1, 0.2);
	glVertex3f(0.2, -0.1, 0.2);
	 glVertex3f(0.2, -0.1, -0.2);
	 glVertex3f(0.2, 0.1, -0.2);
	//左側面
	glNormal3f(-0.2, 0, 0);
	glVertex3f(-0.2, 0.1, -0.2);
	 glVertex3f(-0.2, -0.1, -0.2);
	 glVertex3f(-0.2, -0.1, 0.2);
	 glVertex3f(-0.2, 0.1, 0.2);
	//上面
	glNormal3f(0, 0.2, 0);
	 glVertex3f(-0.2, 0.1, -0.2);
	 glVertex3f(-0.2, 0.1, 0.2);
	 glVertex3f(0.2, 0.1, 0.2);
	 glVertex3f(0.2, 0.1, -0.2);

	//下面
	glVertex3f(0.2, -0.1, 0.2);
	glVertex3f(0.2, -0.1, -0.2);
	glVertex3f(-0.2, -0.1, -0.2);
	glVertex3f(-0.2, -0.1, 0.2);


	glEnd();	glTranslatef(-0.3, 1.2, 0.2);
}

void provide_cup() {
	glTranslatef(-2.0, -2.2, -2.0);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(156, 102, 31, 255);
	glVertex3f(-1.1, 0.2, 1.4);
	glVertex3f(-1.1, -0.2, 1.4);
	glVertex3f(5.3, -0.2, 1.4);
	glVertex3f(5.3, 0.2, 1.4);
	//背面
	glNormal3f(0, 0, -0.2);
	glVertex3f(-1.1, 0.2, -1.0);
	glVertex3f(5.3, 0.2, -1.0);
	glVertex3f(5.3, -0.2, -1.0);
	glVertex3f(-1.1, -0.2, -1.0);
	//右側面
	glNormal3f(0.2, 0, 0);
	glVertex3f(5.3, 0.2, 1.4);
	glVertex3f(5.3, -0.2, 1.4);
	glVertex3f(5.3, -0.2, -1.0);
	glVertex3f(5.3, 0.2, -1.0);
	//左側面
	glNormal3f(-0.2, 0, 0);
	glVertex3f(-1.1, 0.2, -1.0);
	glVertex3f(-1.1, -0.2, -1.0);
	glVertex3f(-1.1, -0.2, 1.4);
	glVertex3f(-1.1, 0.2, 1.4);
	//上面
	glNormal3f(0, 0.2, 0);
	glVertex3f(-1.1, 0.2, -1.0);
	glVertex3f(-1.1, 0.2, 1.4);
	glVertex3f(5.3, 0.2, 1.4);
	glVertex3f(5.3, 0.2, -1.0);

	//下面
	glVertex3f(5.3, -0.2, 1.4);
	glVertex3f(5.3, -0.2, -1.0);
	glVertex3f(-1.1, -0.2, -1.0);
	glVertex3f(-1.1, -0.2, 1.4);


	glEnd();	glTranslatef(2.0, 2.2, 2.0);

	glTranslatef(-2.8, -0.2, -2.0);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(156, 102, 31, 255);
	glVertex3f(-0.3, 0.2, 0.3);
	glVertex3f(-0.3, -2.0, 0.3);
	glVertex3f(0.3, -2.0, 0.3);
	glVertex3f(0.3, 0.2, 0.3);
	//背面
	glNormal3f(0, 0, -0.2);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(0.3, 0.2, -0.3);
	glVertex3f(0.3, -2.0, -0.3);
	glVertex3f(-0.3, -2.0, -0.3);
	//右側面
	glNormal3f(0.2, 0, 0);
	glVertex3f(0.3, 0.2, 0.3);
	glVertex3f(0.3, -2.0, 0.3);
	glVertex3f(0.3, -2.0, -0.3);
	glVertex3f(0.3, 0.2, -0.3);
	//左側面
	glNormal3f(-0.2, 0, 0);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(-0.3, -2.0, -0.3);
	glVertex3f(-0.3, -2.0, 0.3);
	glVertex3f(-0.3, 0.2, 0.3);
	//上面
	glNormal3f(0, 0.2, 0);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(-0.3, 0.2, 0.3);
	glVertex3f(0.3, 0.2, 0.3);
	glVertex3f(0.3, 0.2, -0.3);

	//下面
	glVertex3f(0.3, -2.0, 0.3);
	glVertex3f(0.3, -2.0, -0.3);
	glVertex3f(-0.3, -2.0, -0.3);
	glVertex3f(-0.3, -2.0, 0.3);


	glEnd();	glTranslatef(2.8, 0.2, 2.0);


	glTranslatef(-2.0, -0.2, -2.0);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(112, 128, 105, 255);
	glVertex3f(-0.3, 0.2, 0.3);
	glVertex3f(-0.3, -0.2, 0.3);
	glVertex3f(0.3, -0.2, 0.3);
	glVertex3f(0.3, 0.2, 0.3);
	//背面
	glNormal3f(0, 0, -0.2);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(0.3, 0.2, -0.3);
	glVertex3f(0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, -0.3);
	//右側面
	glNormal3f(0.2, 0, 0);
	glVertex3f(0.3, 0.2, 0.3);
	glVertex3f(0.3, -0.2, 0.3);
	glVertex3f(0.3, -0.2, -0.3);
	glVertex3f(0.3, 0.2, -0.3);
	//左側面
	glNormal3f(-0.2, 0, 0);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(-0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, 0.3);
	glVertex3f(-0.3, 0.2, 0.3);
	//上面
	glNormal3f(0, 0.2, 0);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(-0.3, 0.2, 0.3);
	glVertex3f(0.3, 0.2, 0.3);
	glVertex3f(0.3, 0.2, -0.3);

	//下面
	glVertex3f(0.3, -0.2, 0.3);
	glVertex3f(0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, 0.3);


	glEnd();	glTranslatef(2.0, 0.2, 2.0);

	
	glPushMatrix();
	glTranslatef(-1.7, -0.3, -2.0);
	glRotatef(90, 0.0, 180.0, 0.0);
	glRotatef(180, 1.0, 0.0, 0.0);
	glScalef(0.4, 0.4, 5.5);
	GLUquadric* pobj2;
	pobj2 = gluNewQuadric();
	glColor4ub(128, 142, 72, 255);
	gluCylinder(pobj2, 0.6f, 0.6f, 0.15f, 14, 132);
	glPopMatrix();


	glTranslatef(-1.7, -0.2, -2.0);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(112, 128, 105, 255);
	glVertex3f(-0.3, 0.2, 0.3);
	glVertex3f(-0.3, -0.2, 0.3);
	glVertex3f(0.3, -0.2, 0.3);
	glVertex3f(0.3, 0.2, 0.3);
	//背面
	glNormal3f(0, 0, -0.2);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(0.3, 0.2, -0.3);
	glVertex3f(0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, -0.3);
	//右側面
	glNormal3f(0.2, 0, 0);
	glVertex3f(0.3, 0.2, 0.3);
	glVertex3f(0.3, -0.2, 0.3);
	glVertex3f(0.3, -0.2, -0.3);
	glVertex3f(0.3, 0.2, -0.3);
	//左側面
	glNormal3f(-0.2, 0, 0);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(-0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, 0.3);
	glVertex3f(-0.3, 0.2, 0.3);
	//上面
	glNormal3f(0, 0.2, 0);
	glVertex3f(-0.3, 0.2, -0.3);
	glVertex3f(-0.3, 0.2, 0.3);
	glVertex3f(0.3, 0.2, 0.3);
	glVertex3f(0.3, 0.2, -0.3);

	//下面
	glVertex3f(0.3, -0.2, 0.3);
	glVertex3f(0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, -0.3);
	glVertex3f(-0.3, -0.2, 0.3);


	glEnd();	glTranslatef(1.7, 0.2, 2.0);


		glPushMatrix();
		glTranslatef(-1.7, -0.3, -2.0);
		glRotatef(90, 0.0, 180.0, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.5, 0.5, 7.5);
		GLUquadric* pobj;
		pobj = gluNewQuadric();
		glColor4ub(128, 142, 72, 255);
		gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14, 132);
		glPopMatrix();

}

void cup() {
	if (yyyrot > 360.0) yyyrot -= 360.0;
	if (xrot > 360.0)  xrot -= 360.0;
	if (xxrot > 360.0)  xxrot -= 360.0;
	if (yyyrot < -360.0) yyyrot += 360.0;
	if (xrot < -360.0)  xrot += 360.0;
	if (xxrot < -360.0)  xxrot += 360.0;
	if (yyyrot < -110 && xrot > 170 && xxrot < -80) {
		true_switch2_for_cup = 1;
	}
	else {
		true_switch2_for_cup = 0;
	}
	
	if (leaf_rot1_z < 8.0f && _switch_2 == 1 && true_switch2_for_cup ==1) {

		float n = 20;
		glTranslatef(-1.7, -1.5, -1.3);
		glRotatef(90, 1.0, 0.0, 0.0);

		glBegin(GL_POLYGON);

		glColor4ub(235, 142, 85, 255);
		for (int i = 0; i < n; i++)
		{
			glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
		}

		glEnd();
		glRotatef(-90, 1.0, 0.0, 0.0);
		glTranslatef(1.7, 1.5, 1.3);

		glPushMatrix();
		glTranslatef(-2.0, -1.13, -1);
		glRotatef(90, 0.0, 180.0, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.3, 0.3, 2.5);
		GLUquadric* pobj;
		pobj = gluNewQuadric();
		glColor4ub(128, 42, 42, 255);
		gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14, 132);
		glPopMatrix();

	}
	else {
		_switch_2 = 0;
	}
}
void table(void)
{
	glPushMatrix();
	glTranslatef(1.5, -1.0, -1);
	glRotatef(90, 0.0, 180.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 5.5);
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 1.0f);
	gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14, 132);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.5, -1.0, -1);
	glRotatef(90, 0.0, 180.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 5.5);
	GLUquadric* pobj2;
	pobj2 = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 1.0f);
	gluCylinder(pobj2, 0.6f, 0.6f, 0.15f, 14, 132);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, -1.0, -1.5);
	glRotatef(90, 0.0, 180.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 5.5);
	GLUquadric* pobj4;
	pobj4 = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 1.0f);
	gluCylinder(pobj4, 0.6f, 0.6f, 0.15f, 14, 132);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, -1.0, -1.5);
	glRotatef(90, 0.0, 180.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.3, 0.3, 5.5);
	GLUquadric* pobj3;
	pobj3 = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 1.0f);
	gluCylinder(pobj3, 0.6f, 0.6f, 0.15f, 14, 132);
	glPopMatrix();

	glTranslatef(2.0, -1.0, -1);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面

	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.7, 0.2, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.7, -0.2, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.7, -0.2, 0.2);
	glColor4ub(255, 0, 0, 255);	glVertex3f(0.7, 0.2, 0.2);

	//背面
	glNormal3f(0, 0, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.7, 0.2, -0.6);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.7, 0.2, -0.6);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.7, -0.2, -0.6);
	glColor4ub(255, 0, 0, 255);	glVertex3f(-0.7, -0.2, -0.6);

	//右側面
	glNormal3f(0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.2, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, -0.2, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, -0.2, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.2, -0.2);

	//左側面
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.7, 0.2, -0.6);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.7, -0.2, -0.6);
	glColor4ub(0, 255, 0, 255);	glVertex3f(-0.7, -0.2, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.7, 0.2, 0.2);

	//上面
	glNormal3f(0, 0.2, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.7, 0.2, -0.6);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.7, 0.2, 0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.7, 0.2, 0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.7, 0.2, -0.6);

	//下面

	glColor4ub(255, 0, 0, 255); glVertex3f(0.7, -0.2, 0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.7, -0.2, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.7, -0.2, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.7, -0.2, 0.2);
	
	glEnd();
	glTranslatef(-2.0, 1.0, 1);
}
void coffee_m() {

	glPushMatrix();
	glTranslatef(0.9, 0.48, -0.11);
	glRotatef(90, 0.0, 180.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.35, 0.35, 1.5);
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor4ub(128, 42, 42, 255);
	gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14, 132);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.8, -0.17, -0.11);
	glRotatef(90, 0.0, 180.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glScalef(0.35, 0.35, 1.0);
	GLUquadric* pobj1;
	pobj1 = gluNewQuadric();
	glColor4ub(128, 42, 42, 255);
	gluCylinder(pobj1, 0.6f, 0.6f, 0.15f, 14, 132);
	glPopMatrix();

	glTranslatef(1.1, 0.08, -0.1);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);


	//正面
	glColor4ub(41, 36, 33, 255);
	glNormal3f(0, 0, 0.4);        //設定法向量
	glVertex3f(-0.1, 0.4, 0.2);
	glVertex3f(-0.2, -0.25, 0.2);
	glVertex3f(0.2, -0.25, 0.2);
	glVertex3f(0.1, 0.4, 0.2);

	//正面長方形
	glColor4ub(128, 42, 42, 255);
	glNormal3f(0, 0, 0.4);        //設定法向量
	glVertex3f(-0.4, -0.4, 0.2);
	glVertex3f(-0.4, -0.25, 0.2);
	glVertex3f(0.2, -0.25, 0.2);
	glVertex3f(0.2, -0.4, 0.2);
	//另一側的長方形

	glNormal3f(0, 0, -0.4);        //設定法向量
	glVertex3f(-0.4, -0.4, -0.2);
	glVertex3f(-0.4, -0.25, -0.2);
	glVertex3f(0.2, -0.25, -0.2);
	glVertex3f(0.2, -0.4, -0.2);



	//背面
	glColor4ub(41, 36, 33, 255);
	glNormal3f(0, 0, -0.2);
	glVertex3f(-0.1, 0.4, -0.2);
	glVertex3f(0.1, 0.4, -0.2);
	glVertex3f(0.2, -0.4, -0.2);
	glVertex3f(-0.2, -0.4, -0.2);

	//右側面
	glNormal3f(0.2, 0, 0);
	 glVertex3f(0.1, 0.4, 0.2);
	 glVertex3f(0.2, -0.4, 0.2);
	 glVertex3f(0.2, -0.4, -0.2);
	 glVertex3f(0.1, 0.4, -0.2);

	//左側面
	glNormal3f(-0.2, 0, 0);
	glVertex3f(-0.1, 0.2, -0.2);
	glVertex3f(-0.2, -0.4, -0.2);
	glVertex3f(-0.2, -0.4, 0.2);
	glVertex3f(-0.1, 0.2, 0.2);

	//上面
	glNormal3f(0, 0.2, 0);
	 glVertex3f(-0.1, 0.4, -0.2);
	 glVertex3f(-0.1, 0.4, 0.2);
	 glVertex3f(0.1, 0.4, 0.2);
	 glVertex3f(0.1, 0.4, -0.2);

	//下面

	glVertex3f(0.2, -0.4, 0.2);
	glVertex3f(0.2, -0.4, -0.2);
	glVertex3f(-0.2, -0.4, -0.2);
	glVertex3f(-0.2, -0.4, 0.2);



	glEnd();
}



void cyclinder4() {
	glPushMatrix();
	glTranslatef(-0.1, 0.5, -0.15);
	glRotatef(0.0, 0.0, 180.0, 0.0);
	
	glScalef(0.08, 0.08, 3.0);                //條大小
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor3f(0.3f, 0.0f, 1.0f);
	gluCylinder(pobj, 0.6f, 0.6f, 0.1f, 32, 32);
	glPopMatrix();
}
void cyclinder5() {
	glPushMatrix();
	glTranslatef(0.1, 0.5, -0.15);
	glRotatef(0.0, 0.0, 180.0, 0.0);
	glScalef(0.08, 0.08, 3.0);                //條大小
	GLUquadric* pobj;
	pobj = gluNewQuadric();
	glColor3f(0.3f, 0.0f, 1.0f);
	gluCylinder(pobj, 0.6f, 0.6f, 0.1f, 32, 32);
	glPopMatrix();
}

void drawBox6() {
	glTranslatef(0.04 , 0.4 , 0.1);
	glRotatef(leaf_rot1_x, 1.0f, 0.0f, 0.0f);
	glRotatef(leaf_rot1_y, 0.0f, 1.0f, 0.0f);
	glRotatef(leaf_rot1_z, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
/*
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(255, 0, 0, 255);	glVertex3f(0.0 , 0.0 , 0.0);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.1 , 0.0 , 0.0);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1 , 0.2 , 0.0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.0 , 0.2 , 0.0);
	glColor4ub(150, 150, 150, 255);	glVertex3f(0.021, 0.161, 0.0);
	glColor4ub(0, 150, 150, 255);	glVertex3f(0.021, 0.121, 0.0);
	glColor4ub(150, 0, 150, 255);	glVertex3f(0.0, 0.1 ,0.0);
	*/
	
	
/*	//背面
	glNormal3f(0, 0, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.1, 0.3, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1, 0.3, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.1 , -0.3, -0.1);
	glColor4ub(255, 0, 0, 255);	glVertex3f(-0.1, -0.3, -0.1);
*/
	//右側面
	glNormal3f(0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.4, 0.1);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, 0.1, 0.1);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.1, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, 0.4, -0.2);


	//左側面1
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.1, 0.1);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1, 0.3, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.1, 0.3, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.1, -0.2);

	//左側面2
	
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.3, 0.1);
	glColor4ub(0, 0, 255, 255);	glVertex3f(0.121, 0.321, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.121, 0.321, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.3, -0.2);


	//左側面3
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.321, 0.1);
	glColor4ub(0, 0, 255, 255);	glVertex3f(0.121, 0.361, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.121, 0.361, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.321, -0.2);

	//左側面4

	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.361, 0.1);
	glColor4ub(0, 0, 255, 255);	glVertex3f(0.1, 0.4, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.1, 0.4, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.361, -0.2);

	//上面
	glNormal3f(0, 0.2, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.4, 0.1);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.1, 0.4, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.4, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, 0.4, 0.1);
	

	
	//下面

	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.1, 0.1);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1, 0.1, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, 0.1, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.1, 0.1);
	
	glEnd();
}
void drawBox7() {
	glTranslatef(-0.065, -0.01, -0.1);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glRotatef(leaf_rot1_x, 1.0f, 0.0f, 0.0f);
	glRotatef(leaf_rot1_y, 0.0f, 1.0f, 0.0f);
	glRotatef(-1*leaf_rot1_z, 0.0f, 0.0f, -1.0f);
	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	//正面
/**
	glNormal3f(0, 0, 0.4);        //設定法向量
	glColor4ub(255, 0, 0, 255);	glVertex3f(0.0 , 0.0 , 0.0);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.1 , 0.0 , 0.0);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1 , 0.2 , 0.0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.0 , 0.2 , 0.0);
	glColor4ub(150, 150, 150, 255);	glVertex3f(0.021, 0.161, 0.0);
	glColor4ub(0, 150, 150, 255);	glVertex3f(0.021, 0.121, 0.0);
	glColor4ub(150, 0, 150, 255);	glVertex3f(0.0, 0.1 ,0.0);
	*/


	/*	//背面
		glNormal3f(0, 0, -0.2);
		glColor4ub(255, 0, 0, 255); glVertex3f(-0.1, 0.3, -0.2);
		glColor4ub(0, 0, 255, 255); glVertex3f(0.1, 0.3, -0.2);
		glColor4ub(0, 255, 0, 255); glVertex3f(0.1 , -0.3, -0.1);
		glColor4ub(255, 0, 0, 255);	glVertex3f(-0.1, -0.3, -0.1);
	*/
	//右側面
	glNormal3f(0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.4, 0.1);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, 0.1, 0.1);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.1, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, 0.4, -0.2);


	//左側面1
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.1, 0.1);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1, 0.3, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.1, 0.3, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.1, -0.2);

	//左側面2

	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.3, 0.1);
	glColor4ub(0, 0, 255, 255);	glVertex3f(0.121, 0.321, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.121, 0.321, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.3, -0.2);


	//左側面3
	glNormal3f(-0.2, 0, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.321, 0.1);
	glColor4ub(0, 0, 255, 255);	glVertex3f(0.121, 0.361, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.121, 0.361, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.321, -0.2);

	//左側面4

	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.361, 0.1);
	glColor4ub(0, 0, 255, 255);	glVertex3f(0.1, 0.4, 0.1);
	glColor4ub(0, 255, 0, 255);	glVertex3f(0.1, 0.4, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.121, 0.361, -0.2);

	//上面
	glNormal3f(0, 0.2, 0);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.4, 0.1);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.1, 0.4, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.4, -0.2);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2, 0.4, 0.1);



	//下面

	glColor4ub(255, 0, 0, 255); glVertex3f(0.1, 0.1, 0.1);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.1, 0.1, -0.2);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2, 0.1, -0.2);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.2, 0.1, 0.1);

	glEnd();
}
void cup2() {
	//printf("%f", xxrot);
	if (yyyrot < -110 && xrot > 170 && xxrot < -80) {
		true_switch = 1;
	}



	glTranslatef(2.0, 1.5 , 1.2);
	if (_switch_2 == 0 && leaf_rot1_z > -6.0f && true_switch == 1) {

		float n = 20;
		glTranslatef(-1.7, -0.85, -1.37);
		glRotatef(180, 1.0, 0.0, 0.0);

		glBegin(GL_POLYGON);

		glColor4ub(235, 142, 85, 255);
		for (int i = 0; i < n; i++)
		{
			glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
		}

		glEnd();
		glRotatef(-180, 1.0, 0.0, 0.0);
		glTranslatef(1.7, 0.85, 1.37);

		glPushMatrix();
		glTranslatef(-2.0, -1.13, -1);
	//	glRotatef(90, 0.0, 180.0, 0.0);
		glRotatef(180, 1.0, 0.0, 0.0);
		glScalef(0.3, 0.3, 2.5);
		GLUquadric* pobj;
		pobj = gluNewQuadric();
		glColor4ub(128, 42, 42, 255);
		gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14, 132);
		glPopMatrix();


		if (latte == 1) {
			glTranslatef(-1.7, -0.85, -1.15);
			glRotatef(180, 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glColor4ub(244, 164, 96, 255);
			for (int i = 0; i < n; i++)
			{
				glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
			}

			glEnd();
			glRotatef(-180, 1.0, 0.0, 0.0);
			glTranslatef(1.7, 0.85, 1.15);
		}
		if (water == 1) {
			glTranslatef(-1.7, -0.85, -1.15);
			glRotatef(180, 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glColor4ub(65, 105, 225, 255);
			for (int i = 0; i < n; i++)
			{
				glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
			}

			glEnd();
			glRotatef(-180, 1.0, 0.0, 0.0);
			glTranslatef(1.7, 0.85, 1.15);
		}
		if (Grass_tea == 1) {
			glTranslatef(-1.7, -0.85, -1.15);
			glRotatef(180, 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glColor4ub(124, 252, 0, 255);
			for (int i = 0; i < n; i++)
			{
				glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
			}

			glEnd();
			glRotatef(-180, 1.0, 0.0, 0.0);
			glTranslatef(1.7, 0.85, 1.15);
		}
		_switch_base = 1;
		
	}
	else {
		_switch_2 = 1;
	}
}
void cup4() {
	printf(".1%f " ,yyyrot);
	printf("2.%f ", xrot);
	printf("3.%f ", xxrot);
	if (yyyrot > 360.0) yyyrot -= 360.0;
	if (xrot > 360.0)  xrot -= 360.0;
	if (xxrot > 360.0)  xxrot -= 360.0;
	if (yyyrot < -360.0) yyyrot += 360.0;
	if (xrot < -360.0)  xrot += 360.0;
	if (xxrot < -360.0)  xxrot += 360.0;
	if (yyyrot < -11 && xrot > 75 && xxrot < 9) {
		true_seitch_for_cup2 = 1;
	}
	else {
		//true_seitch_for_cup2 = 0;
	}

	if (_switch_base == 1 && leaf_rot1_z < -5.0f && true_seitch_for_cup2 == 1) {
		glTranslatef(2.3, 0.4, 0.9);

		float n = 20;
		glTranslatef(-1.7, -1.5, -1.3);
		glRotatef(90, 1.0, 0.0, 0.0);

		glBegin(GL_POLYGON);

		glColor4ub(235, 142, 85, 255);
		for (int i = 0; i < n; i++)
		{
			glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
		}

		glEnd();
		glRotatef(-90, 1.0, 0.0, 0.0);
		glTranslatef(1.7, 1.5, 1.3);

		glPushMatrix();
		glTranslatef(-2.0, -1.13, -1);
		glRotatef(90, 0.0, 180.0, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		glScalef(0.3, 0.3, 2.5);
		GLUquadric* pobj;
		pobj = gluNewQuadric();
		glColor4ub(128, 42, 42, 255);
		gluCylinder(pobj, 0.6f, 0.6f, 0.15f, 14, 132);
		glPopMatrix();

		glTranslatef(-2.3, -0.4, -0.9);

		if (latte == 1) {
			glTranslatef(0.6, -0.85, -0.4);
			glRotatef(90, 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glColor4ub(244, 164, 96, 255);
			for (int i = 0; i < n; i++)
			{
				glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
			}

			glEnd();
			glRotatef(-90, 1.0, 0.0, 0.0);
			glTranslatef(-0.6, 0.85, 0.4);
		}
		if (water == 1) {
			glTranslatef(0.6, -0.85, -0.4);
			glRotatef(90, 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glColor4ub(65, 105, 225, 255);
			for (int i = 0; i < n; i++)
			{
				glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
			}

			glEnd();
			glRotatef(-90, 1.0, 0.0, 0.0);
			glTranslatef(-0.6, 0.85, 0.4);
		}
		if (Grass_tea == 1) {
			glTranslatef(0.6, -0.85, -0.4);
			glRotatef(90, 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glColor4ub(124, 252, 0, 255);
			for (int i = 0; i < n; i++)
			{
				glVertex2f(0.2f * sin(2 * (3.1415926 / n) * i) - 0.3f, 0.2f * cos(2 * (3.1415926 / n) * i) + 0.3f);
			}

			glEnd();
			glRotatef(-90, 1.0, 0.0, 0.0);
			glTranslatef(-0.6, 0.85, 0.4);
		}
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                           //您??上??前?移到了屏幕中心：?似于一?复位操作


	

	gluLookAt(
		0.0f, 0.0f, gg,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 5.0f);

	glRotatef((float)rot_y + (float)record_y, 1.0, 0.0, 0.0);   //以x軸當旋轉軸
	glRotatef((float)rot_x + (float)record_x, 0.0, 1.0, 0.0);   //以y軸當旋轉軸

	base();
	provide_cup();
	glTranslatef(-0.2, -0.1, 0.0);
	table();
	glTranslatef(0.2, 0.1, 0.0);
	cup4();
	glTranslatef(0.0, -0.1, 0.0);
	glTranslatef(0.7, -0.5, -1.0);
	coffee_m();
	glTranslatef(-1.5, -0.08, 0.1);
	glTranslatef(0.0, 0.1, 0.0);
	cup();

	



	//glTranslatef(-1.8, -1.2, -0.5);
	glTranslatef(-0.5, -0.7, -1);
	//	drawBox2();
	glRotatef(xxxrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yyyrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zzzrot, 0.0f, 0.0f, 1.0f);
	cyclinder1();
	glTranslatef(-0.6, 0.15, 0);
	//drawBox();
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);

	cyclinder2();
	glTranslatef(1.0, 0.3, 0);
	drawBox3();
	glTranslatef(0.2, 0.4, 0);
	glRotatef(xxrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yyrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zzrot, 0.0f, 0.0f, 1.0f);
	cyclinder3();
	//drawBox4();
	glTranslatef(0.35, 0.3, 0);
	drawBox5();

	
	cyclinder4();
	cyclinder5();

	drawBox6();
	drawBox7();
	cup2();
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
	//	printf("%f", yyyrot);
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
		xxrot -= 5.0f;
		if (xxrot > 360.0) xxrot -= 360.0;
		glutPostRedisplay();
		break;
	case 'c':
	case 'C':
		xxrot += 5.0f;
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
		gg++;
		glutPostRedisplay();
		break;
	case 'o':   // z -> g
	case 'O':
		//	grow_shrink--;
		//	resize(600, 500);
		gg++;
		glutPostRedisplay();
		break;
	case 'p':
	case 'P':
		//	grow_shrink++;
		//	resize(600, 500);
		gg--;
		glutPostRedisplay();
		break;
	case 'f':
	case 'F':
		//	grow_shrink++;
		//	resize(600, 500);
		
	//	leaf_rot2_z -= 2.0f;
		if (leaf_rot1_z < 10.0f) {
			leaf_rot1_z += 2.0f;
		}
		if (leaf_rot1_z > 360.0) leaf_rot1_z -= 360.0;
//		if (leaf_rot2_z > 360.0) leaf_rot2_z -= 360.0;
		glutPostRedisplay();
		break;
	case 'v':
	case 'V':
		//	grow_shrink++;
		//	resize(600, 500);
//		leaf_rot2_z += 2.0f;
		if (leaf_rot1_z > -10.0f) {
			leaf_rot1_z -= 2.0f;
		}
		if (leaf_rot1_z > 360.0) leaf_rot1_z -= 360.0;
//		if (leaf_rot2_z > 360.0) leaf_rot2_z -= 360.0;
		glutPostRedisplay();
		break;

	case '1':
		latte = 1;
		glutPostRedisplay();
		break;
	case '2':
		water = 1;
		glutPostRedisplay();
		break;
	case '3':
		Grass_tea = 1;
		glutPostRedisplay();
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
	//	printf("%d", _switch);
		if (_switch == 1) {
			glutIdleFunc(_idle);	//可以執行連續動畫			
		}

		break;
	case 2:

		_switch = 0;

		break;
	}
}
void light__1(int index) {
	switch (index) {
	case 1:
		glEnable(GL_LIGHT0);
		glutPostRedisplay();
		break;
	case 2:
		glDisable(GL_LIGHT0);
		glutPostRedisplay();
		break;
	}
}
void light__2(int index) {
	switch (index) {
	case 1:
		glEnable(GL_LIGHT1);
		glutPostRedisplay();
		break;
	case 2:
		glDisable(GL_LIGHT1);
		glutPostRedisplay();
		break;
	}
}
void _light(int index) {


}
void sub_coffee(int index) {
	switch (index) {
	case 1:
		 fullscreen = 0;
		 mouseDown = 0;

		 xrot = 0;
		 yrot = 0;
		 zrot = 0;
		 xxrot = 0;
		 yyrot = 0;
		 zzrot = 0;
		 xxxrot = 0;
		 yyyrot = 0;
		 zzzrot = 0;
		 leaf_rot1_x = 0;
		 leaf_rot1_y = 0;
		 leaf_rot1_z = 0;
		 leaf_rot2_x = 0;
		 leaf_rot2_y = 0;
		 leaf_rot2_z = 0;

		 xdiff = 100.0f;
		 ydiff = 100.0f;

		 tra_x = 0.0f;
		 tra_y = 0.0f;
		 tra_z = 0.0f;

		 grow_shrink = 70.0f;
		 resize_f = 1.0f;

		 old_rot_x = 0;                       //剛按下滑鼠時的視窗座標
		 old_rot_y = 0;

		 rot_x = 0;                           //拖曳後的相對座標，用這決定要旋轉幾度
		 rot_y = 0;

		 record_x = 0;                        //紀錄上一次旋轉的角度
		 record_y = 0;
		 gg = 3.0;
		 _switch = 1;
		 _switch_2 = 1;
		 true_switch = 0;
		 true_switch2_for_cup = 0;
		 true_seitch_for_cup2 == 0;
		 _switch_base = 0;
		 latte = 0;
		 water = 0;
		 Grass_tea = 0;
		 glutPostRedisplay();
		break;
	case 2:
		exit(1);
		break;
	}
}
void createMenu()											        //做按右鍵後，顯示的東西
{
	int  coffee = glutCreateMenu(sub_coffee);
	glutAddMenuEntry("Yes!", 1);
	glutAddMenuEntry("No!", 2);

	int _3D_Gasket = glutCreateMenu(sub_3D_Gasket);
	glutAddMenuEntry("on", 1);
	glutAddMenuEntry("off", 2);

	int light_1 = glutCreateMenu(light__1);
	glutAddMenuEntry("open", 1);
	glutAddMenuEntry("close", 2);
	int light_2 = glutCreateMenu(light__2);
	glutAddMenuEntry("open", 1);
	glutAddMenuEntry("close", 2);


	int light = glutCreateMenu(_light);
	glutAddSubMenu("frist light", light_1);
	glutAddSubMenu("sec light", light_2);


	int Menu = glutCreateMenu(mainMenu);
	glutAddSubMenu("10元謝謝，然後再來一杯?", coffee);
	glutAddSubMenu("Automation", _3D_Gasket);
	glutAddSubMenu("open or close light", light);




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

void Mouse(int button, int state, int x, int y)
{
	if (state)
	{
		record_x += x - old_rot_x;
		record_y += y - old_rot_y;

		rot_x = 0;   //沒有歸零會有不理想的結果
		rot_y = 0;
	}
	else
	{
		old_rot_x = x;
		old_rot_y = y;
	}

}

void MotionMouse(int x, int y)
{
	rot_x = x - old_rot_x;
	rot_y = y - old_rot_y;
	glutPostRedisplay();

}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(1000, 1000);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("13 - Solid Shapes");
	createMenu();
	glutMouseFunc(Mouse);
	glutMotionFunc(MotionMouse);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);

//	SetLightSource();
//	SetMaterial();
//	SetLightSource2();
//	SetMaterial2();

	//glutMouseFunc(mouse);
	//glutMotionFunc(mouseMotion);
	glutReshapeFunc(resize);


	if (!init())
		return 1;

	glutMainLoop();

	return 0;
}
float light_position[] = { 10 , 0, 10 };  //光源的位置
void SetLightSource()
{

	float light_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	float light_diffuse[] = { 0.4f, 0.4f, 0.4f, 1.0 };
	float light_specular[] = { 0.5f, 0.5f, 0.5f, 1.0 };

	glEnable(GL_LIGHTING);                                 //開燈

	// 設定發光體的光源的特性
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);      //環境光(Ambient Light)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);      //散射光(Diffuse Light)
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);     //反射光(Specular Light)

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);     //光的座標

	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);                               //啟動深度測試
}
void SetMaterial()
{
	float material_ambient[] = { 0.20, 0.2, 0.2, 1.0 };
	float material_diffuse[] = { 5.5, 1, 0.5, 1.0 };
	float material_specular[] = { 0.0, 0.2, 0.2, 1.0 };
	//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//	GLfloat mat_shininess[] = { 50.0 };
	//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
}


float light_position2[] = { 0 , 10, 0 };  //光源的位置
void SetLightSource2()
{

	float light_ambient[] = { 1.4f, 1.4, 1.4f, 1.0 };
	float light_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0 };
	float light_specular[] = { 0.4f, 0.4f, 0.4f, 1.0 };        //反射光越大反射越強   r g b

	glEnable(GL_LIGHTING);                                 //開燈

	// 設定發光體的光源的特性
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);      //環境光(Ambient Light)
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);      //散射光(Diffuse Light)
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);     //反射光(Specular Light)

	glLightfv(GL_LIGHT1, GL_POSITION, light_position2);     //光的座標

	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);                               //啟動深度測試
}
void SetMaterial2()
{
	float material_ambient[] = { 0.10, 0.1, 0.1, 1.0 };
	float material_diffuse[] = { 4.4, 0.9, 0.4, 1.0 };
	float material_specular[] = { 0.0, 0.1, 0.1, 1.0 };
	//	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	//	GLfloat mat_shininess[] = { 50.0 };
	//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
}



