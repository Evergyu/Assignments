//**********************************************************************
//                           HW#3-4 : Menu Callback                     
//  작성자 : 이인규                              날짜 : 2021년 9월 29일 
//                                                                      
// 문제 정의 :      여러 메뉴를 구현해서 크기가 다른 도형 그리기 및 색 바꾸기                                                 
//					- - - - - - -                                         
// 기능 :			구현한 메뉴는 총 10개로
//					구 그리기 -> 작은 구, 큰 구
//					도넛 그리기 -> 작은 도넛, 큰 도넛
//					주전자 그리기 -> 작은 주전자, 큰 주전자
//					색 칠하기 -> 빨강, 초록 파랑
//					나가기
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>
float r = 0, g = 0.5, b = 0.5;	//rgb값을 나타낼 변수
//어떤 메뉴가 선택됨에 따라 true,false가 바뀔 GLboolean 타입의 변수들
GLboolean SSphere = true; GLboolean BSphere = false;
GLboolean STorus = false; GLboolean BTorus = false;
GLboolean STeapot = false; GLboolean BTeapot = false;	


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	if (SSphere) {	//SSphere=true 일 때
		glutWireSphere(0.5, 30, 30);	//작은 구
	}
	if (BSphere) {	//BSphere=true 일 때
		glutWireSphere(0.7, 30, 30);	//큰 구
	}
	if (STorus) {	//STorus=true 일 때
		glutWireTorus(0.1, 0.3, 20, 20); //작은 도넛
	}
	if (BTorus) {	//BTorus=true 일 때
		glutWireTorus(0.1, 0.5, 20, 20); //큰 도넛
	}
	if (STeapot) {	//STeapot=true 일 때
		glutWireTeapot(0.3); //작은 주전자
	}
	if (BTeapot) {	//BTeapot=true 일 때
		glutWireTeapot(0.5); //큰 주전자
	}
	glFlush(); //출력
}
void MyMainMenu(int entryID) {	
	if (entryID == 5) exit(0);	//entryID가 5인 메뉴를 선택했을 때 종료
	glutPostRedisplay();	//프로그램 내용이 변경되었을 때 윈도우를 출력하도록 하는 함수
}
void MySphereMenu(int entryID) {
	if (entryID == 1) {			//메뉴에서 Small Sphere을 골랐을 때
		SSphere = true; BSphere = false;
		STorus = false; BTorus = false;
		STeapot = false; BTeapot = false;	//SSphere = true;
}
	else if (entryID == 2) {	//메뉴에서 Large Sphere을 골랐을 때
		SSphere = false; BSphere = true;
		STorus = false; BTorus = false;
		STeapot = false; BTeapot = false;	//BSphere = true;
	}
	glutPostRedisplay();	//프로그램 내용이 변경되었을 때 윈도우를 출력하도록 하는 함수
}
void MyTorusMenu(int entryID) {
	if (entryID == 1) {			//메뉴에서 Small Torus을 골랐을 때
		SSphere = false; BSphere = false;
		STorus = true; BTorus = false;
		STeapot = false; BTeapot = false;	//STorus=true
	}
	else if (entryID == 2) {	//메뉴에서 Large Torus을 골랐을 때
		SSphere = false; BSphere = false;
		STorus = false; BTorus = true;
		STeapot = false; BTeapot = false;	// BTorus = true;
	}
	glutPostRedisplay();	//프로그램 내용이 변경되었을 때 윈도우를 출력하도록 하는 함수
}
void MyTeapotMenu(int entryID) {
	if (entryID == 1) {			//메뉴에서 Small Teapot을 골랐을 때
		SSphere = false; BSphere = false;
		STorus = false; BTorus = false;
		STeapot = true; BTeapot = false;	//STeapot = true;
	}
	else if (entryID == 2) {	//메뉴에서 Large Teapot을 골랐을 때
		SSphere = false; BSphere = false;
		STorus = false; BTorus = false;
		STeapot = false; BTeapot = true;	//BTeapot = true;
	}
	glutPostRedisplay();	//프로그램 내용이 변경되었을 때 윈도우를 출력하도록 하는 함수
}
void MyColorMenu(int entryID) {
	if (entryID == 1) {				//메뉴에서 Red를 골랐을 때
		r = 155; g = 0; b = 0; }	//Mydisplay에서 glColor3f()의 rgb 값을 (155,0,0) 으로 변경 
	else if (entryID == 2) {		//메뉴에서 Green을 골랐을 때
		r = 0; g = 0.5; b = 0; }	//Mydisplay에서 glColor3f()의 rgb 값을 (0,0.5,0) 으로 변경
	else if (entryID == 3) {		//메뉴에서 Blue를 골랐을 때
		r = 0; g = 0; b = 155;		//Mydisplay에서 glColor3f()의 rgb 값을 (0,0,155) 으로 변경
}
	glutPostRedisplay();	//프로그램 내용이 변경되었을 때 윈도우를 출력하도록 하는 함수
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경 흰색
	glMatrixMode(GL_PROJECTION); //투영행렬 선택
	glLoadIdentity(); //현재행렬을 항등행렬로
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //가시부피 결정

	GLint MySphereID = glutCreateMenu(MySphereMenu);	//구의 서브메뉴
	glutAddMenuEntry("Small Sphere",1);	//작은 구를 그리는 메뉴, glutAddSubMenu에서 MySphereID부분에 1을 리턴
	glutAddMenuEntry("Large Sphere",2); //작은 구를 그리는 메뉴, glutAddSubMenu에서 MySphereID부분에 2를 리턴

	GLint MyTorusID = glutCreateMenu(MyTorusMenu);		//도넛의 서브메뉴
	glutAddMenuEntry("Small Torus", 1); //작은 도넛을 그리는 메뉴, glutAddSubMenu에서 MyTorusID부분에 1을 리턴
	glutAddMenuEntry("Large Torus", 2); //작은 도넛을 그리는 메뉴, glutAddSubMenu에서 MyTorusID부분에 2를 리턴

	GLint MyTeapotID = glutCreateMenu(MyTeapotMenu);	//주전자의 서브메뉴
	glutAddMenuEntry("Small Teapot", 1); //작은 주전자를 그리는 메뉴, glutAddSubMenu에서 MyTeapotID부분에 1을 리턴
	glutAddMenuEntry("Large Teapot", 2); //작은 주전자를 그리는 메뉴, glutAddSubMenu에서 MyTeapotID부분에 2를 리턴

	GLint MyColorID = glutCreateMenu(MyColorMenu);		//색을 고르는 메뉴
	glutAddMenuEntry("Red", 1); //빨간색을 칠하는 메뉴 glutAddSubMenu에서 MyColorID부분에 1을 리턴
	glutAddMenuEntry("Greeen", 2); //초록색을 칠하는 메뉴 glutAddSubMenu에서 MyColorID부분에 2를 리턴
	glutAddMenuEntry("Blue", 3); //파란색을 칠하는 메뉴 glutAddSubMenu에서 MyColorID부분에 3을 리턴

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //메인메뉴
	glutAddSubMenu("Draw Sphere", MySphereID);	//서브메뉴가 있는 메뉴
	glutAddSubMenu("Draw Torus", MyTorusID);	//서브메뉴가 있는 메뉴
	glutAddSubMenu("Draw Teapot", MyTeapotID);	//서브메뉴가 있는 메뉴
	glutAddSubMenu("Change Color",MyColorID);	//서브메뉴가 있는 메뉴
	glutAddMenuEntry("Exit", 5);				//entryID가 5인 메뉴

	glutAttachMenu(GLUT_RIGHT_BUTTON); //우클릭하면 메뉴가 나오도록 함
}
int main(int argc, char** argv) {
	glutInit(&argc, argv); glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500); glutInitWindowPosition(0, 0);	//창크기 500 x 500 창위치 0,0
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}