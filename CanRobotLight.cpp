//**********************************************************************
//                           HW#7 : 조명                     
//  작성자 : 이인규                              날짜 : 2021년 11월 14일 
//                                                                      
// 문제 정의 :      깡통 로봇 조명생성 + 달리기                                                 
//					- - - - - - -                                         
// 기능 :			R : 달리기
//					- - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // 새로운 Quadric 생성
static int RightLeg = 0, LeftLeg = 0, Rightknee = 0, LeftKnee = 0, LeftArm = 0, RightArm = 0;
static int moving = 1, move = 0, move_count=1;
void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void body() {
	//몸통으로 쓸 반지름 0.6,0.6 높이 1.5의 원기둥
	glPushMatrix(); //몸통 푸시 
	GLfloat material_ambient[] = { 0,0.5,0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);			//물체색
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
		glRotatef(40, 1, 0, 0);
		glRotatef(RightArm, 0, 1, 0); //Rotate 실시
		glPushMatrix();								//TRR한 것을 푸시
		GLfloat material_ambient[] = { 0.5,0.5,0.25,1.0 };				//물체 색
		glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
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
		glTranslatef(0.0, 0, -0.1);					//Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);					
		glScalef(0.2, 0.2, 0.2);					//크기조절
		glutSolidSphere(1, 10, 10);					//구 그리기
		glPopMatrix();								//구를 그린 부분 팝
	glPopMatrix();									//미리 푸시한부분 팝
}
void Left_Arm() {
	//윗팔
	glPushMatrix();									//수정하기 전 미리 푸시
		glTranslatef(-0.6, 1.5, 0);					
		glRotatef(-90, 0, 1, 0);					//Translate, Rotate 실시
		glRotatef(40, 1, 0, 0);
		glRotatef((GLfloat)LeftArm, 0, 1, 0);	//Rotate 실시
		glPushMatrix();								//TRR한 것을 푸시
		glColor3f(0, 100, 255);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//아랫팔
		glRotatef(-120, 1,0, 0);
		glTranslatef(0, -0.5, -1.0);					//아랫팔 부분에 RT
		glPushMatrix();								//RT한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//손
		glTranslatef(0, 0, -0.1);					//Translate
		glPushMatrix();								//T한 부분 푸시
		glColor3f(0.6, 0.6, 0.5);
		glScalef(0.2, 0.2, 0.2);					//크기조절
		glutSolidSphere(1, 10, 10);					//구 그리기
		glPopMatrix();								//구를 그린 부분 팝
	glPopMatrix();									//미리 푸시한부분 팝
}
void Right_Leg() {
	//윗다리
	glPushMatrix();									//수정하기 전 미리 푸시
		glTranslatef(0.3, 0, 0);					
		glRotatef(90, 1, 0, 0);						//위치에 맞게 Translate, Rotate 실시
		glRotatef(RightLeg, 1, 0, 0);				//Rotate 실시 오른다리를 움직이기 위해 골반부분의 각도에 변수를 삽입
		glPushMatrix();								//TRR한 것을 푸시
		GLfloat material_ambient[] = { 0,0,1,1.0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝
		
		//아랫다리
		glTranslatef(0, 0, 0.6);					//위치에 맞게 Translate
		glRotatef(Rightknee, 1, 0, 0);
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
		glRotatef(LeftLeg, 1, 0, 0);				//Rotate 실시 오른다리를 움직이기 위해 골반부분의 각도에 변수를 삽입
		glPushMatrix();								//TRR한 것을 푸시
		glColor3f(1.0, 0, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더를 그린 부분 팝

		//아랫다리
		glTranslatef(0, 0, 0.6);					//위치에 맞게 Translate
		glRotatef(LeftKnee, 1, 0, 0);
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
		GLfloat material_ambient[] = { 0,0.5,0.5,1.0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
		gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 5);	//실린더 그리기
		glPopMatrix();								//실린더 그린부분 팝
		
	glPopMatrix();									//수정하기전 미리 푸시한부분 팝
}
void Head() {
	glPushMatrix();								//수정하기 전 푸시
	//머리통
	glTranslatef(0, 1.7, 0.1);
	glRotatef(270, 1, 0, 0);
	glRotatef(0, 0, 1, 0);					//목을 움직일때 쓰기위해 각도를 변수로 갖는 Rotate
	glTranslatef(0, 0.1, 0);
	glPushMatrix();								//Rotate, Translate한 부분 푸시
	GLfloat material_ambient[] = { 1,0,0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	gluCylinder(qobj, 0.4, 0.3, 0.5, 20, 5);	//실린더 그리기
	glPopMatrix();								//실린더 그린 부분 팝

	//오른쪽눈
	glRotatef(90, 1, 0, 0);					//머리를 270도 돌렸기 때문에 눈이 돌아가는 각도를 맞추기 위해
	glTranslatef(0.15, 0.3, 0.5);				//눈 위치에 맞게 Translate
	glScalef(0.1, 0.1, 0.1);					//눈 크기 설정
	glPushMatrix();								//TS한 부분 푸시
	glColor3f(1, 1, 1);
	glutSolidSphere(0.5, 20, 8);				//구 그리기
	glPopMatrix();								//구 그린부분 팝

	//오른쪽 눈동자
	glPushMatrix();								//위치는 옮길 필요 없으므로 그냥 푸시
	glScalef(0.1, 0.1, 0.1);					//스케일 바꿔주고
	glutSolidSphere(2, 20, 8);					//구 그리기
	glPopMatrix();								//스케일 바꾼 후 구 그린부분 팝

	//왼쪽눈
	glTranslatef(-3, 0.0, 0.1);				//눈 위치에 맞게 Translate
	glPushMatrix();								//TS한 부분 푸시
	glColor3f(1, 1, 1);
	glutSolidSphere(0.5, 20, 8);				//구 그리기
	glPopMatrix();								//구 그린부분 팝

	//왼쪽 눈동자
	glPushMatrix();								//위치는 옮길 필요 없으므로 그냥 푸시
	glScalef(0.1, 0.1, 0.1);					//스케일 바꿔주고
	glutSolidSphere(2, 20, 8);					//구 그리기
	glPopMatrix();								//스케일 바꾼 후 구 그린부분 팝

	glPopMatrix();								//수정 후 팝
}
void light() {

	//gluLookAt(0.5, 0.5, 0.5, 0, 0, 0, 0, 1, 0);

	GLfloat global_ambient[] = { 0.5,0.5,0.5,1 };		//전역 주변광

	GLfloat light0_ambient[] = { 0.5,0.5,0.5,1.0 };		//light0 주변광
	GLfloat light0_diffuse[] = { 0.5,0.6,0.5,0.5 };		//light0 난반사광
	GLfloat light0_specular[] = { 1.0,1.0,1.0,1.0 };	//light0 전반사광

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);	//GL_LIGHT0 활성화
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);	//light0 특성부여
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);	//전역광 특성부여

}
void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_FILL);

	light(); //빛

	body();	//몸
	Right_Arm();	//오른팔
	Left_Arm();	//왼팔
	Right_Leg();	//오른다리
	Left_Leg();	//왼쪽다리
	Neck(); //목
	Head();	//머리

	
	
	glutSwapBuffers();
}


void TimerRun(int Value) {
	if (move_count % 59 == 0) move = (move++) % 4;
	if (move_count % (59 * 2) == 0) moving *= -1;

	if (moving == 1) {
		if (move == 0) {
			Rightknee++;
			RightLeg--;
			LeftArm++;	
			move_count++;
		}
		if (move == 1) {
			Rightknee--;
			RightLeg++;
			LeftArm--;
			move_count++;
		}
	}
	if (moving == -1) {
		if (move == 2) {
			LeftKnee++;
			LeftLeg--;
			RightArm++;
			move_count++;
		}
		if (move == 3) {
			LeftKnee--;
			LeftLeg++;
			RightArm--;
			move_count++;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(10, TimerRun, 1);
}


//S를 누르게 되면 모든 움직임 제어 변수 moving1~5를 0으로 초기화해서 멈추게 됩니다.
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'r': 
		glutTimerFunc(10, TimerRun, 1);
		
		break; 
	case 'R': 
		Rightknee++;
		RightLeg--;
		LeftArm++;
		break; 
		}
	glutPostRedisplay();

}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);  //모델뷰모드
	glLoadIdentity();            //항등행렬 설정
	gluLookAt(3, 0, 1,
		0, 0, -3,
		0, 1, 0);

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
	glutKeyboardFunc(MyKeyboard); //키보드 이벤트

	glutMainLoop();
	return 0;
}