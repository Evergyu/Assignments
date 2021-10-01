//**********************************************************************
//                           HW#3-1 : Keyboard Callback(1)                     
//  작성자 : 이인규                              날짜 : 2021년 9월 29일 
//                                                                      
// 문제 정의 :      입력받은 키에 따라 해당하는 기능 수행                                                 
//					- - - - - - -                                         
// 기능 :			A를 입력하면 사각형이 왼쪽으로 0.1씩 이동
//                  F를 입력하면 사각형이 오른쪽으로 0.1씩 이동
//                  R을 입력하면 사각형이 아래쪽으로 0.1씩 이동하고 빨간색으로 변함                 
//                  V를 입력하면 사각형이 위로 0.1씩 이동
//                  B를 입력하면 사각형이 파란색으로 변함
// - - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
float horizon = 0,vertical = 0; //가로세로 좌표의 증감을 조절할 변수
float r = 0.5, g = 0.5, b = 0.5; //RGB 초기는 회색이므로 모두 0.5
    
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //컬러버퍼 초기화
    glColor3f(r, g, b);             //도형 색 (0.5,0.5,0.5) 회색
    glBegin(GL_POLYGON);            //GL_POLYGON, 다각형 그리기 시작
    glVertex3f(-0.5 + horizon, -0.5 + vertical, 0.0);
    glVertex3f(0.5 + horizon, -0.5 + vertical, 0.0);
    glVertex3f(0.5 + horizon, 0.5 + vertical, 0.0);
    glVertex3f(-0.5 + horizon, 0.5 + vertical, 0.0);    //점 네개의 좌표설정
    glEnd();                        //끝
    glFlush();  //출력
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    //A를 입력하면 x좌표에 horizon이 0.1씩 줄어 도형이 왼쪽으로 이동
    case 'A':
        horizon = horizon - 0.1; break;
    case 'a':
        horizon = horizon - 0.1; break;        
    //F를 입력하면 x좌표에 horizon이 0.1씩 늘어 도형이 오른쪽으로 이동
    case 'F':
        horizon = horizon + 0.1; break;
    case 'f':
        horizon = horizon + 0.1; break;
    //R을 입력하면 x좌표에 horizon이 0.1씩 줄어 도형이 아래로 이동, 색은 빨간색이 된다
    case 'r':
        r = 153; g = 0; b = 0; vertical = vertical - 0.1; break;
    case 'R':
        r = 153; g = 0; b = 0; vertical = vertical - 0.1;; break;
    //V를 입력하면 y좌표에 vertical이 0.1씩 늘어 도형이 위로 이동
    case 'v':
        vertical = vertical + 0.1; break;
    case 'V':
        vertical = vertical + 0.1; break;
    //B를 입력하면 rgb가 (0,0,153)으로 초기화 되어 있다.
    case 'b':
        r = 0; g = 0; b = 153; break;
    case 'B':
        r = 0; g = 0; b = 153; break;
    }
    glutPostRedisplay(); //윈도우를 다시 그리도록 요청
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); //배경색 흰색
    glMatrixMode(GL_PROJECTION); //투영행렬 선택
    glLoadIdentity();   //현재 행렬을 항등행렬로 선택

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //가시부피 설정
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB); //디스플레이 GLUT_RGB모드
    glutInitWindowSize(300, 300); //300 X 300
    glutInitWindowPosition(0, 0); //윈도우 위치 (0,0)
    glutCreateWindow("Keyboard Callback(1)");
    MyInit(); //초기화
    glutDisplayFunc(MyDisplay); //display 이벤트
    glutKeyboardFunc(MyKeyboard); //키보드 이벤트

    glutMainLoop();
    return 0;
}