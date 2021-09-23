//**********************************************************************
//                           HW#2-1 : GL Modeling                     
//  작성자 : 이인규                              날짜 : 2021년 9월 23일 
//                                                                      
// 문제 정의 :      GL을 이용한 여러 도형 그리기                                                  
//					- - - - - - -                                         
// 기능 :			시작
//					glBegin(enum Mode); ~~ glEnd(); 에서 여러가지 enum Mode를
//					사용해 점, 선, 삼각형, 사각형, 다각형을 그리는 법을
//					이 과제를 통해 배울 수 있었습니다.
//					알맞은 enum Mode와 ~~부분에 glVertex2f() 에 좌표값을 넣어
//					각 주어진 도형을 2차원으로 표현하였습니다.
//					- - - - - - -                                         
//**********************************************************************

#include <gl/glut.h> 
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경색 흰색
	glMatrixMode(GL_PROJECTION); //투영행렬 선택
	glLoadIdentity(); //항등행렬
	glOrtho(0.0, 1000.0, 0.0, 1000.0, 1, -1); //glortho 설정
}
void MyDisplay() {
	glColor3f(0.0, 1, 0.0);
	
	
	//물체 1 GL_POINTS
	/*6개의 점을 찍습니다.*/
	glBegin(GL_POINTS);
	glVertex2f(60, 835);
	glVertex2f(100, 900);
	glVertex2f(160, 900);
	glVertex2f(200, 835);
	glVertex2f(160, 760);
	glVertex2f(100, 760);
	glEnd();
	
	//물체 2 GL_LINES
	/*6개의 점들 중에서 순서에 맞게 두개씩 묶어 선을 긋습니다*/
	glBegin(GL_LINES);
	//선1
	glVertex2f(60 + 250, 835);
	glVertex2f(100 + 250, 900);
	//선2
	glVertex2f(160 + 250, 900);
	glVertex2f(200 + 250, 835);
	//선3
	glVertex2f(160 + 250, 760);
	glVertex2f(100 + 250, 760);
	glEnd();
	
	//물체 3 GL_LINE_STRIP
	/*6개의 점들을 순서대로 잇습니다.*/
	glBegin(GL_LINE_STRIP);
	//선1
	glVertex2f(60 + 500, 835);
	glVertex2f(100 + 500, 900);
	//선2
	glVertex2f(160 + 500, 900);
	//선3
	glVertex2f(200 + 500, 835);
	//선4
	glVertex2f(160 + 500, 760);
	//선5
	glVertex2f(100 + 500, 760);
	glEnd();
	
	//물체 4 GL_LINE_LOOP
	/*6개의 점들을 순서대로 모든 점이 이어지도록 잇습니다*/
	glBegin(GL_LINE_LOOP);
	//선1
	glVertex2f(60 + 750, 835);
	glVertex2f(100 + 750, 900);
	//선2
	glVertex2f(160 + 750, 900);
	//선3
	glVertex2f(200 + 750, 835);
	//선4
	glVertex2f(160 + 750, 760);
	//선5
	glVertex2f(100 + 750, 760);
	//첫번째 점과 이어서 선6
	glEnd();
	//물체 5 GL_POLYGON
	/*모든 선을 이어 다각형을 그립니다. 이때 선이 교차하면 안됩니다*/
	glBegin(GL_POLYGON);
	glVertex2f(60 , 495);
	glVertex2f(90, 560);
	glVertex2f(170, 560);
	glVertex2f(200, 495);
	glVertex2f(170, 420);
	glVertex2f(90, 420);
	glEnd();
	//물체 6 GL_TRIANGLES
	/*선을 순서대로 세개씩 묶어 삼각형을 그립니다*/
	glBegin(GL_TRIANGLES);
	//삼각형1
	glVertex2f(60 + 330, 495);
	glVertex2f(90 + 330, 560);
	glVertex2f(170 + 330, 560);
	//삼각형2
	glVertex2f(200 + 330, 495);
	glVertex2f(170 + 330, 420);
	glVertex2f(90 + 330, 420);
	glEnd();
	//물체 7 GL_TRIANGLE_STRIP
	/*선을 처음에 세개를 묶어 삼각형을 그리고 그 후엔 세개의 점 중
	  마지막 점을 기준으로 또 두개의 점을 골라 삼각형을 그리는 식으로
	  여러개의 삼각형을 그립니다*/
	glShadeModel(GL_FLAT); //단색으로 색칠
	glBegin(GL_TRIANGLE_STRIP); 
	glVertex2f(60+660,420);
	glVertex2f(80+660,495); 
	glVertex2f(110+660,430);//여기까지 삼각형1
	//삼각형2
	glColor3f(1, 0, 0.0);
	glVertex2f(130+660,510);
	//삼각형3
	glColor3f(0, 1, 0.0);
	glVertex2f(160+660,440);
	//삼각형4
	glColor3f(1, 0, 0.0);
	glVertex2f(180+660,520);
	//삼각형5
	glColor3f(0, 1, 0.0);
	glVertex2f(200+660,400);
	glEnd();
	//물체 8 GL_TRIANGLE_FAN
	/*첫번째 점을 기준으로 잡고 두개의 점을 골라 삼각형으 그립니다
	  그 후 뒤에 오는 점 1개씩 골라 삼각형을 이어 그립니다.*/
	glColor3f(0.0, 1, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	//기준점 
	glVertex2f(50, 50);
	glVertex2f(100, 280);
	glVertex2f(120, 270); //여기까지 삼각형1
	//삼각형2
	glColor3f(1, 0, 0.0);
	glVertex2f(150, 240);
	//삼각형3
	glColor3f(0, 1, 0.0);
	glVertex2f(180, 230);
	//삼각형4
	glColor3f(1, 0, 0.0);
	glVertex2f(210, 180);
	glEnd();
	//물체 9 GL_QUADS
	/*점을 네개씩 골라 사각형을 그립니다.*/
	glBegin(GL_QUADS);
	//사각형1
	glVertex2f(40 + 330, 200);
	glVertex2f(50 + 330, 270);
	glVertex2f(120 + 330, 280);
	glVertex2f(110 + 330, 160);
	//사각형2
	glVertex2f(130 + 330, 50);
	glVertex2f(160 + 330, 210);
	glVertex2f(210 + 330, 160);
	glVertex2f(190 + 330, 50);
	glEnd();
	//물체 10 GL_QUAD_STRIP
	/*처음에 점을 네개를 골라 사각형을 만들고 그 후에는 앞에서 만든
	  사각형의 점들 중에서 마지막 두 점과 이어서 오는 두 점을 골라
	  사각형을 이어붙여 여러개의 사각형을 만듭니다*/
	glBegin(GL_QUAD_STRIP);
	//사각형1
	glVertex2f(40 + 660, 200);
	glVertex2f(50 + 660, 270);
	glVertex2f(110 + 660, 160);
	glVertex2f(120 + 660, 280);
	//사각형2
	glColor3f(1, 0, 0.0); //빨강
	glVertex2f(130 + 660, 50);
	glVertex2f(160 + 660, 210);
	//사각형3
	glColor3f(0, 1, 0.0); //초록
	glVertex2f(190 + 660, 50);
	glVertex2f(210 + 660, 160);
	
	glEnd();

	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); //displaymode RGB
	glutInitWindowSize(1000, 1000); //창의 크기 1000 x 1000
	glutInitWindowPosition(0, 0); //화면위치 (0,0)
	glutCreateWindow("GL Modeling Test");
	MyInit(); //초기화
	glutDisplayFunc(MyDisplay);
	glutMainLoop(); //메인루프

}