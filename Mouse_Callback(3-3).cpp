//**********************************************************************
//                           HW#3-3 : Mouse Callback(1)                     
//  작성자 : 이인규                              날짜 : 2021년 9월 29일 
//                                                                      
// 문제 정의 :      왼쪽마우스와 오른쪽 마우스클릭에 반응하도록 함수 구현                                                 
//					- - - - - - -                                         
// 기능 :			왼쪽 마우스를 클릭하면 네 점의 x좌표가 0.1씩 오른쪽으로 이동합니다
//                  오른쪽 마우스를 클릭하면 네 점은 멈춰있습니다.
//                  - - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
GLdouble left = 0, right = 0, up = 0, down = 0; //가로세로 좌표의 증감을 조절할 변수
GLdouble r = 0.5, g = 0.5, b = 0.5; //RGB 초기는 회색이므로 모두 0.5
GLboolean keep = true;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //컬러버퍼 초기화
    glColor3f(r, g, b);             //도형 색 (0.5,0.5,0.5) 회색
    glBegin(GL_POLYGON);            //GL_POLYGON, 다각형 그리기 시작
    glVertex3f(-0.5 + left, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, 0.5 + up, 0.0);
    glVertex3f(-0.5 + left, 0.5 + up, 0.0);    //점 네개의 좌표설정
    glEnd();                        //끝
    glFlush();  //출력
}

/*keep이 true일 때 500msec 마다 0.1씩 이동하는데
  우클릭을해서 keep이 false가 되면 움직임이 멈춥니다.*/
void MyTimer(int Value) {
    if (keep) {
        if (right < 0.5) {
            left = left + 0.1; right = right + 0.1;
        }
    }
    glutTimerFunc(500, MyTimer, 1);
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

    //왼쪽버튼을 누르면 네 점의 x좌표가 오른쪽으로 이동합니다
    //오른쪽벽을 뚫고 지나가지는 못합니다.
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        glutTimerFunc(500, MyTimer, 1); //타이머 이벤트  
    }
    //오른쪽 버튼을 누르면 GLboolean 타입의 변수가 false로 변하며 멈춰있습니다.
    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
        keep = false;
    }
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
    glutCreateWindow("Mouse Callback(1)");
    MyInit(); //초기화
    glutDisplayFunc(MyDisplay); //display 이벤트
    glutMouseFunc(MyMouseClick); //Mouse 이벤트

    glutMainLoop();
    return 0;
}