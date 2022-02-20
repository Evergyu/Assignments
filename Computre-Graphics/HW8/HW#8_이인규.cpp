//**********************************************************************
//                           HW#8 : 종합                     
//  작성자 : 이인규                              날짜 : 2021년 11월 24일 
//                                                                      
// 문제 정의 :      미니로봇 움직임 제어                                                
//					- - - - - - -                                         
// 기능 :			상하좌우 위치옮기기
//					e : 우로회전 q : 좌로회전
//					- - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // 새로운 Quadric 생성
GLint lleg_angle = 1, rleg_angle = 1;
GLfloat move_x = 0, move_y = 0;
GLfloat white[] = { 1, 1, 1, 1.0 };
GLfloat green[] = { 0, 1, 0, 1.0 };
GLfloat blue[] = { 0, 0, 1, 1.0 };
GLfloat red[] = { 1,0,0,1.0 };
GLfloat redblue[] = { 1,0,1,1.0 };
GLfloat redgreen[] = { 1,1,0,1.0 };
GLfloat black[] = { 0,0,0 };

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void light() {

	GLfloat global_ambient[] = { 1,1,1,1 };		//전역 주변광

	GLfloat light0_ambient[] = { 0,0,0,1.0 };		//light0 주변광
	GLfloat light0_diffuse[] = { 0.5,0.6,0.5,0.5 };		//light0 난반사광
	GLfloat light0_position[] = { -10,10,20,1 };		//light0 위치
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);	//GL_LIGHT0 활성화
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);	//위치
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);	//주변광
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);	//난반사광
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);	//전반사광 light0 특성부여

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);	//전역광 특성부여

}
void Character() {
	light();
	glPushMatrix();								//수정하기 전 푸시

	glTranslatef(0 + move_x, -1 + move_y, 0);
	glScalef((GLfloat)0.8, (GLfloat)0.8, (GLfloat)0.8);
	
	glTranslatef(-1.7, 2.7, 0.1);
	glRotatef(270, 1, 0, 0);
	glPushMatrix();								//Rotate, Translate한 부분 푸시
	if (move_x < 1.3 && move_y > -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, red);
	else if (move_x < 1.3 && move_y < -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, redblue);
	else if (move_x >1.3 && move_y > -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, redgreen);
	else if (move_x > 1.3 && move_y < -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	
	glPolygonMode(GL_FRONT, GL_FILL);
	glutSolidCube(0.6);
	glPopMatrix();								//실린더 그린 부분 팝

	//오른쪽눈
	glRotatef(90, 1, 0, 0);					//머리를 270도 돌렸기 때문에 눈이 돌아가는 각도를 맞추기 위해
	glTranslatef(0.15, 0.1, 0.3);				//눈 위치에 맞게 Translate
	glScalef(0.1, 0.1, 0.1);					//눈 크기 설정
	glPushMatrix();								//TS한 부분 푸시
	glColor3f(1, 1, 1);
	glutSolidSphere(1, 20, 8);				//구 그리기
	glPopMatrix();								//구 그린부분 팝

	//왼쪽눈
	glTranslatef(-3, 0.0, 0.1);				//눈 위치에 맞게 Translate
	glPushMatrix();								//TS한 부분 푸시
	glColor3f(1, 1, 1);
	glutSolidSphere(1, 20, 8);				//구 그리기
	glPopMatrix();								//구 그린부분 팝
	
	//부리
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(1.5, 0, -3);
	glutSolidCone(1, 1, 100, 100);
	glPopMatrix();
	
	//왼팔
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-1.5, -3, 0);
	glRotatef(-30, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();
	
	//오른팔
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(4.5, -3, 0);
	glRotatef(30, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();

	//오른다리
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(3, -3, 4);
	glRotatef(20*rleg_angle, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();

	//왼다리
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -3, 4);
	glRotatef(-20 * lleg_angle, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();

	glPopMatrix();								//수정 후 팝
}

void DrawWall() {
	glPushMatrix();

	glBegin(GL_LINES);
	glPolygonMode(GL_FRONT, GL_LINE);
	glMaterialfv(GL_FRONT, GL_AMBIENT, red);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-2.7, 2.4,0);	
	glVertex3f(2.7, 2.4,0);	
	
	glVertex3f(-2.7, -3.0,0);	
	glVertex3f(2.7, -3.0,0);	
	
	glVertex3f(-2.7, -3.0, 0);
	glVertex3f(-2.7, 2.4, 0);

	glVertex3f(2.7, -3.0, 0);
	glVertex3f(2.7, 2.4, 0);
	glEnd();
	
	glBegin(GL_LINES);
	glMaterialfv(GL_FRONT, GL_AMBIENT, green);
	glVertex3f(0, -3, 0);
	glVertex3f(0, 2.4, 0);
	glEnd();

	glBegin(GL_LINES);
	glMaterialfv(GL_FRONT, GL_AMBIENT, blue);
	glVertex3f(-2.7, -0.3, 0);
	glVertex3f(2.7, -0.3, 0);

	glEnd();

	glFlush();

	glEnd();
	glPopMatrix();
}


void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	
	Character();	//머리
	DrawWall();

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);  //모델뷰모드
	glLoadIdentity();            //항등행렬 설정
	gluLookAt(0, 0, 0,
		0, 0, -1,
		0, 1, 0);

	glTranslatef(0.0, 0.0, -5.0);
}
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (move_x < 3.5)	move_x += 0.1;
		lleg_angle *= -1;
		rleg_angle *= -1;
		break;
	case GLUT_KEY_LEFT: 
		if (move_x > -0.9) move_x -= 0.1;
		lleg_angle *= -1;
		rleg_angle *= -1; 
		break;
	case GLUT_KEY_UP:
		if (move_y < 0.9)move_y += 0.1;
		break;
	case GLUT_KEY_DOWN:
		if (move_y > -3.5) move_y -= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //디스플레이 GLUT_RGB모드
	glutInitWindowSize(600, 480);                   //디스플레이 사이즈 800*1200
	glutInitWindowPosition(10, 10);               //윈도우 위치 100*100
	glutCreateWindow("Color Study");                   //창 이름 Can Robot
	MyInit();   //초기화
	glutDisplayFunc(MyDisplay); //display 이벤트
	glutReshapeFunc(MyReshape);  //창 크기가 변했을때 이벤트
	glutSpecialFunc(MySpecial);

	glutMainLoop();
	return 0;
}