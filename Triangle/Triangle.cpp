#include <GL/glut.h>
#include<iostream>
// initial triangle 
// GLfloat v[4][3] = { {-1.0, -0.58 },{1.0, -0.58 }, {0.0, 1.15 } };						    //(略)做表面切割用的三點(略))
GLfloat v_Volume[4][2] = { {-1.0, -0.58 },{1.0, -0.58 }, {0.0, 1.15 } , {0.0 , 0.0} };		    //做體積切割及表面切割用的四點
int n; // number of recursive steps 
void triangle(GLfloat* a, GLfloat* b, GLfloat* c)												//印出三角形                                            
{
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}
void triangular_Volume(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d) {
	glColor3f(0.0, 0.0, 1.0);																		//顏色選取
	triangle(a, b, c);                                                                              //triangle印出三角形
	glColor3f(0.0, 1.0, 0.0);																	    //顏色選取
	triangle(a, c, d);
	glColor3f(1.0, 0.0, 0.0);																		//顏色選取
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
void divide_triangle_Volume(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d, int m) {                                   //切割立體三角體
	GLfloat v1[3], v2[3], v3[3], v4[3], v5[3], v6[3];																   //要有6個去存任兩點切出來的點(6邊)
	int j;
	if (m == 0)
	{
		triangular_Volume(a, b, c, d);																				   //切數為0時呼叫triangular_Volume
	}
	else{
		//triangle_Volume(a, b, c ,d)
	for (j = 0; j < 3; j++) v1[j] = (a[j] + b[j]) / 2;
	for (j = 0; j < 3; j++) v2[j] = (a[j] + c[j]) / 2;
	for (j = 0; j < 3; j++) v3[j] = (b[j] + c[j]) / 2;
	for (j = 0; j < 3; j++) v4[j] = (a[j] + d[j]) / 2;
	for (j = 0; j < 3; j++) v5[j] = (b[j] + d[j]) / 2;
	for (j = 0; j < 3; j++) v6[j] = (c[j] + d[j]) / 2;
	divide_triangle_Volume(a, v1, v2, v4, m - 1);								//照順序傳入再切的點(切數減一)
	divide_triangle_Volume(v1, b, v3, v5, m - 1);
	divide_triangle_Volume(v2, v3, c, v6, m - 1);
	divide_triangle_Volume(v4, v5, v6, d, m - 1);
   }
}


void tetrahedron(int m)						        
{
	glColor3f(0.0, 1.0, 0.0);					     //每面顏色
	divide_triangle(v_Volume[0], v_Volume[1], v_Volume[2], m);            //傳入3個點去切割 ， m = 切割次數(最底層)
	glColor3f(0.0, 0.0, 1.0);
	divide_triangle(v_Volume[3], v_Volume[2], v_Volume[1], m);
	glColor3f(0.0, 0.0, 0.0);
	divide_triangle(v_Volume[0], v_Volume[3], v_Volume[1], m);
	glColor3f(1.0, 0.0, 0.0);
	divide_triangle(v_Volume[0], v_Volume[2], v_Volume[3], m);
}

void display()													//顯示平面圖形
{
	//int n = 1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			//清楚預設buffer內容
	glBegin(GL_TRIANGLES);										//開始到結束要畫的圖形line119

//	divide_triangle(v[0], v[1], v[2], n);
	tetrahedron(n);												//呼叫tetrahedron
	glEnd();
	glFlush();
}
void tetrahedron_Volume(int m) {
	
	divide_triangle_Volume(v_Volume[0], v_Volume[1], v_Volume[2], v_Volume[3], m);    //傳入4個點去切割要有相同順序

}
void display_Volume() {											//顯示立體圖形
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         //清楚預設buffer內容
	glBegin(GL_TRIANGLES);										//開始到結束要畫的圖形line119
	tetrahedron_Volume(n);										//呼叫tetrahedron_Volume

	glEnd();
	glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);                              //
	glLoadIdentity();										  //(重製成單位矩陣)	
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);					      //可視範圍定義
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
		glColor3f(0.0, 0.0, 0.0);						      //初始化視窗顏色
}

void mainMenu(int index) {									     //開主目錄
	switch (index) {
	case 1 :
		break;
	case 2 :
		break;
	}
}
void sub_3D_Gasket(int index)									//子目錄要幹嘛(重新定義畫布，和畫上新的)
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
void sub_Subdivision_Level(int index)							//子目錄要幹嘛(設定切割數)
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

void createMenu()											        //做按右鍵後，顯示的東西
{
	int _3D_Gasket = glutCreateMenu(sub_3D_Gasket);                 //對應186行
	glutAddMenuEntry("Surface Subdivision", 1);
	glutAddMenuEntry("Volume Subdivision", 2);

	int Subdivision_Level = glutCreateMenu(sub_Subdivision_Level);  //對應187行
	glutAddMenuEntry("2" , 1);
	glutAddMenuEntry("3" , 2);
	glutAddMenuEntry("4" , 3);

	int Menu = glutCreateMenu(mainMenu);
	glutAddSubMenu("3D_Gasket", _3D_Gasket);
	glutAddSubMenu("Subdivision_Level", Subdivision_Level);

	glutAttachMenu(GLUT_RIGHT_BUTTON);								//沒這行不會有menu(觸發menu)
}

void keyboard(unsigned char key , int x , int y) {				    //keyboard函式做按q|Q時會強制結束程式		
	if (key == 'q' || key == 'Q') exit(0);
}

int main(int argc, char** argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);									//初始化視窗大小
	glutCreateWindow("3D Gasket");									//視窗名稱
	
	createMenu();													//做右鍵方法
	glutKeyboardFunc(keyboard);										//做鍵盤方法
	glutDisplayFunc(display);										//顯示一開始的圖形
   
	myinit();
	glutMainLoop();													//無窮迴圈目的是讓圖持續顯示
}
