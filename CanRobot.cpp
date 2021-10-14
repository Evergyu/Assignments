//**********************************************************************
//                           HW#4-2 : Robot Arms                     
//  작성자 : 이인규                              날짜 : 2021년 10월 14일 
//                                                                      
// 문제 정의 :      깡통 로봇 만들기                                                
//					- - - - - - -                                         
// 기능 :			메뉴1. 머리움직이기
//					메뉴2. 오른팔 움직이기
//					메뉴3. 왼쪽팔 움직이기
//					메뉴4. 오른다리 움직이기
//					메뉴5. 왼쪽다리 움직이기
//					S 누르기 : 멈춤 
//					- - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // 새로운 Quadric 생성

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void body() {
	glPushMatrix(); //항등행렬 푸시
	glColor3f(0, 0.5, 0.6);
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(50, 0, 0, 1);
	gluCylinder(qobj, 0.6, 0.6, 1.5, 20, 20);

	glPopMatrix(); //항등행렬 팝
}
void Right_Arm() {
	//윗팔
	glColor3f(0, 100, 255);
	glPushMatrix();
		glTranslatef(0.6, 1.5, 0);
		glRotatef(90, 0, 1, 0);
		glRotatef(60, 1, 0, 0);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//아랫팔
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0.6, 0.5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//손
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0.5, 0.35, 0);
	glScalef(0.2, 0.2, 0.2);
	glutWireSphere(1, 10, 10);
	glPopMatrix();
}
void Left_Arm() {
	//윗팔
	glColor3f(0, 100, 255);
	glPushMatrix();
	glTranslatef(-0.6, 1.5, 0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(60, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//아랫팔
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(-0.6, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//손
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(-0.5, 0.35, 0);
	glScalef(0.2, 0.2, 0.2);
	glutWireSphere(1, 10, 10);
	glPopMatrix();
}
void Right_Leg() {
	//윗다리
	glPushMatrix();
	glColor3f(1.0, 0, 0.5);
	glTranslatef(0.3, 0, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();
	
	//아랫다리
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0.3, -0.6, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.2, 0.5);
	glTranslatef(0.4, -1.2, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);
	glPopMatrix();
}
void Left_Leg(){
	//윗다리
	glPushMatrix();
	glColor3f(1.0, 0, 0.5);
	glTranslatef(-0.3, 0, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//아랫다리
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(-0.3, -0.6, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//발
	glPushMatrix();
	glColor3f(0.0, 0.2, 0.5);
	glTranslatef(-0.4, -1.2, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);
	glPopMatrix();
}
void neck() {
	glPushMatrix();
	glColor3f(0, 0.5, 1);
	glTranslatef(0, 1.7, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 5);
	glPopMatrix();
}
void head() {
	glPushMatrix();
	glColor3f(1, 0.6, 0.5);
	glTranslatef(0, 2.5, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.5, 0.6, 0.8, 20, 5);
	glPopMatrix();

	//오른쪽눈
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(1.0,20,8);
	glPopMatrix();

	//오른쪽 눈동자
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(0.3, 20, 8);
	glPopMatrix();

	//왼쪽눈
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(1.0, 20, 8);
	glPopMatrix();

	//왼쪽 눈동자
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(0.3, 20, 8);
	glPopMatrix();
}
void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_LINE);
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0); //시점조절
	body();	//몸
	Right_Arm();	//오른팔
	Left_Arm();	//왼팔
	Right_Leg();	//오른다리
	Left_Leg();	//왼쪽다리
	neck();	//목
	head(); //머리

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);  //모델뷰모드
	
	glLoadIdentity();            //항등행렬 설정
	glTranslatef(0.0, 0.0, -5.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //디스플레이 GLUT_RGB모드
	glutInitWindowSize(800, 1200);                   //디스플레이 사이즈 800*1200
	glutInitWindowPosition(100, 100);               //윈도우 위치 100*100
	glutCreateWindow("Can Robot");                   //창 이름 Can Robot
	MyInit();   //초기화
	glutDisplayFunc(MyDisplay); //display 이벤트
	glutReshapeFunc(MyReshape);  //창 크기가 변했을때 이벤트

	glutMainLoop();
	return 0;
}