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
static int RightShoulder = 60,RightElbow=-120,LeftShoulder = 60, LeftElbow = -120;
static int RightLeg = 0, LeftLeg = 0, neck=0;
static int move1 = 1, move2 = 1, move3 = 1, move4 = 1, move5 = 1;
static int move_count1=1, move_count2=1, move_count3=1, move_count4=1, move_count5 = 1;
void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void body() {
	//몸통으로 쓸 반지름 0.6,0.6 높이 1.5의 원기둥
	glPushMatrix(); //몸통 푸시 
	glColor3f(0, 0.5, 0.6);
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(50, 0, 0, 1);
	gluCylinder(qobj, 0.6, 0.6, 1.5, 20, 20);

	glPopMatrix(); //몸통 팝
}
void Right_Arm() {
	glPushMatrix();									//수정하기 전 미리 푸시
		glTranslatef(0.6, 1.5, 0);					
		glRotatef(90, 0, 1, 0);						//Translate, Rotate 실시
		glRotatef((GLfloat)RightShoulder, 1, 0, 0); //Rotate 실시
		glPushMatrix();								//TRR한 것을 푸시
		glColor3f(0, 100, 255);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//아랫팔					
		glRotatef(-120 , 1, 0, 0);					
		glTranslatef(0, -0.5, -1);					//아랫팔 부분에 RT
		glPushMatrix();								//RT한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);					
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//손
		glTranslatef(0.6, 0, 0.0);					//Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);					
		glScalef(0.2, 0.2, 0.2);					//크기조절
		glutWireSphere(1, 10, 10);					//구 그리기
		glPopMatrix();								//구를 그린 부분 팝
	glPopMatrix();									//미리 푸시한부분 팝
}
void Left_Arm() {
	//윗팔
	glPushMatrix();									//수정하기 전 미리 푸시
		glTranslatef(-0.6, 1.5, 0);					
		glRotatef(-90, 0, 1, 0);					//Translate, Rotate 실시
		glRotatef((GLfloat)LeftShoulder, 1, 0, 0);	//Rotate 실시
		glPushMatrix();								//TRR한 것을 푸시
		glColor3f(0, 100, 255);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//아랫팔
		glRotatef((GLfloat)LeftElbow, 1, 0, 0);
		glTranslatef(0, -0.5, -1);					//아랫팔 부분에 RT
		glPushMatrix();								//RT한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//손
		glTranslatef(-0.6, 0, 0.0);					//Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);
		glScalef(0.2, 0.2, 0.2);					//크기조절
		glutWireSphere(1, 10, 10);					//구 그리기
		glPopMatrix();								//구를 그린 부분 팝
	glPopMatrix();									//미리 푸시한부분 팝
}
void Right_Leg() {
	//윗다리
	glPushMatrix();									//수정하기 전 미리 푸시
		glTranslatef(0.3, 0, 0);					
		glRotatef(90, 1, 0, 0);						//위치에 맞게 Translate, Rotate 실시
		glRotatef(RightLeg, 0, 1, 0);				//Rotate 실시 오른다리를 움직이기 위해 골반부분의 각도에 변수를 삽입
		glPushMatrix();								//TRR한 것을 푸시
		glColor3f(1.0, 0, 0.5);			
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝
		
		//아랫다리
		glTranslatef(0, 0, 0.6);					//위치에 맞게 Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);					
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//시린더를 그린 부분 팝

		//발
		glTranslatef(0.1, 0, 0.6);					//위치에 맞게 Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.0, 0.2, 0.5);
		gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더 그린부분 팝
	glPopMatrix();									//수정하기 전 푸시한 부분 팝
}
void Left_Leg(){
	glPushMatrix();									//수정하기 전 미리 푸시
		glTranslatef(-0.3, 0, 0);					
		glRotatef(90, 1, 0, 0);						//위치에 맞게 Translate, Rotate 실시
		glRotatef(LeftLeg, 0, 1, 0);				//Rotate 실시 오른다리를 움직이기 위해 골반부분의 각도에 변수를 삽입
		glPushMatrix();								//TRR한 것을 푸시
		glColor3f(1.0, 0, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//아랫다리
		glTranslatef(0, 0, 0.6);					//위치에 맞게 Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//시린더를 그린 부분 팝

		//발
		glTranslatef(-0.1, 0, 0.6);					//위치에 맞게 Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.0, 0.2, 0.5);
		gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더 그린부분 팝
	glPopMatrix();									//수정하기 전 푸시한 부분 팝
}
void Neck() {
	glPushMatrix();									//수정하기전 미리 푸시
		//목
		glTranslatef(0, 1.7, 0);
		glRotatef(90, 1, 0, 0);						//목의 형태가 알맞게 Translate, Rotate
		glPushMatrix();								//TRR한 부분 푸시
		glColor3f(0, 0.5, 1);
		gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더 그린부분 팝
		
	glPopMatrix();									//수정하기전 미리 푸시한부분 팝
}
void Head() {
	glPushMatrix();								//수정하기 전 푸시
	//머리통
	glTranslatef(0, 1.7, 0);
	glRotatef(270, 1, 0, 0);
	glRotatef(neck, 0, 1, 0);					//목을 움직일때 쓰기위해 각도를 변수로 갖는 Rotate
	glTranslatef(0, 0.1, 0);
	glPushMatrix();								//Rotate, Translate한 부분 푸시
	glColor3f(1, 0.6, 0.5);
	gluCylinder(qobj, 0.4, 0.3, 0.5, 20, 5);	//실린더 그리기
	glPopMatrix();								//실린더 그린 부분 팝

	//오른쪽눈
	glRotatef(90, 1, 0, 0);					//머리를 270도 돌렸기 때문에 눈이 돌아가는 각도를 맞추기 위해
											//Rotate
	
	glTranslatef(0.15, 0.3, 0);				//눈 위치에 맞게 Translate
	glScalef(0.1, 0.1, 0.1);					//눈 크기 설정
	glPushMatrix();								//TS한 부분 푸시
	glColor3f(1, 1, 1);
	glutSolidSphere(0.5, 20, 8);				//구 그리기
	glPopMatrix();								//구 그린부분 팝

	//오른쪽 눈동자
	glPushMatrix();								//위치는 옮길 필요 없으므로 그냥 푸시
	glColor3f(0, 0, 0);
	glScalef(0.1, 0.1, 0.1);					//스케일 바꿔주고
	glutSolidSphere(2, 20, 8);					//구 그리기
	glPopMatrix();								//스케일 바꾼 후 구 그린부분 팝

	//왼쪽눈
	glTranslatef(-3, 0.0, 0);				//눈 위치에 맞게 Translate
	glPushMatrix();								//TS한 부분 푸시
	glColor3f(1, 1, 1);
	glutSolidSphere(0.5, 20, 8);				//구 그리기
	glPopMatrix();								//구 그린부분 팝

	//왼쪽 눈동자
	glPushMatrix();								//위치는 옮길 필요 없으므로 그냥 푸시
	glColor3f(0, 0, 0);
	glScalef(0.1, 0.1, 0.1);					//스케일 바꿔주고
	glutSolidSphere(2, 20, 8);					//구 그리기
	glPopMatrix();								//스케일 바꾼 후 구 그린부분 팝

	glPopMatrix();								//수정 후 팝

}

void TimerHead(int Value) {
	if (neck == 1) move1 = 1;
	if (neck == 39) move1 = -1;
	if (move_count1 == 1) {
		if (move1 == 1) {
			neck = (neck + 1) % 40;
		}
		else if (move1 == -1) {
			neck = (neck - 1) % 40;
			move_count1 = -1;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(10, TimerHead, 1);
}
void TimerRArm(int Value) {
	RightShoulder = (RightShoulder + 1) % 90;

	glutPostRedisplay();
	glutTimerFunc(10, TimerRArm, 1);
}
void TimerLArm(int Value) {
	LeftShoulder = (LeftShoulder + 1) % 90;

	glutPostRedisplay();
	glutTimerFunc(10, TimerLArm, 1);
}
void TimerRLeg(int Value) {
	RightLeg = (RightLeg + 1) % 60;

	glutPostRedisplay();
	glutTimerFunc(10, TimerRLeg, 1);
}
void TimerLLeg(int Value) {
	LeftLeg = (LeftLeg - 1) % 60;

	glutPostRedisplay();
	glutTimerFunc(10, TimerLLeg, 1);
}
void MyMenu(int entryID) {
	if (entryID == 1) {
		glutTimerFunc(10, TimerHead, 1);
	}
	if (entryID == 2) {
		glutTimerFunc(10, TimerRArm, 1);
	}
	if (entryID == 3) {
		glutTimerFunc(10, TimerLArm, 1);
	}
	if (entryID == 4) {
		glutTimerFunc(10, TimerRLeg, 1);
	}
	if (entryID == 5) {
		glutTimerFunc(10, TimerLLeg, 1);
	}
}
void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_LINE);
	body();	//몸
	Right_Arm();	//오른팔
	Left_Arm();	//왼팔
	Right_Leg();	//오른다리
	Left_Leg();	//왼쪽다리
	Neck(); //목
	Head();	//머리

	
	glutSwapBuffers();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':
		RightShoulder = (RightShoulder + 5) % 180;
		break;
		glutPostRedisplay();
	
	case 'd':
		LeftShoulder = (LeftShoulder + 5) % 180;
		break;
		glutPostRedisplay();
}
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
	glutKeyboardFunc(MyKeyboard);
	
	GLint MyMenuID = glutCreateMenu(MyMenu);	//메뉴
	glutAddMenuEntry("Move Head", 1);			//머리움직이기
	glutAddMenuEntry("Move Right Hand", 2);		//오른팔 움직이기
	glutAddMenuEntry("Move Left Hand", 3);		//왼쪽팔 움직이기
	glutAddMenuEntry("Move Right Leg", 4);		//오른다리 움직이기
	glutAddMenuEntry("Move Left Leg", 5);		//왼쪽다리 움직이기

	glutAttachMenu(GLUT_RIGHT_BUTTON); //우클릭하면 메뉴가 나오도록 함

	glutMainLoop();
	return 0;
}