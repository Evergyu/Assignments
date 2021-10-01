//**********************************************************************
//                           HW#3-5 : Idle Callback                     
//  작성자 : 이인규                              날짜 : 2021년 9월 30일 
//                                                                      
// 문제 정의 :      화살표 방향에 따라 도형이 이동하게 만들기                                                 
//					- - - - - - -                                         
// 기능 :			Idle Callback을 사용하여 키보드의 사방향의 화살표에 따라
//                  그 방향으로 도형이 움직이도록 구현했습니다.
//                  이때 도형은 윈도우는 밖을 나가지 않습니다
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>
float left = 0, right = 0, up = 0, down = 0; //가로세로 좌표의 증감을 조절할 변수

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //컬러버퍼 초기화
    glColor3f(0, 0.5, 0.8);             //도형 색 (0,0.3,0.8) 푸른색
    glBegin(GL_POLYGON);            //GL_POLYGON, 다각형 그리기 시작
    glVertex3f(-0.5 + left, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, 0.5 + up, 0.0);
    glVertex3f(-0.5 + left, 0.5 + up, 0.0);    //점 네개의 좌표설정
    glEnd();                        //끝
    glutSwapBuffers();  //백버퍼와 전면버퍼를 스왑합니다
}

void MyIdleRight() {    //오른쪽으로 0.1씩 움직입니다
    if (right < 0.4) {
        left = left + 0.1; right = right + 0.1;
    }
    glutPostRedisplay();//프로그램 내용이 변경되었을 때 윈도우를 다시 출력하도록 하는 함수
}

void MyIdleLeft() {     //왼쪽으로 0.1씩 움직입니다
    if (left > -0.4) {
        left = left - 0.1; right = right - 0.1;
    }
    glutPostRedisplay();//프로그램 내용이 변경되었을 때 윈도우를 다시 출력하도록 하는 함수
}

void MyIdleUp() {      //위쪽으로 0.1씩 움직입니다
    if (up < 0.4) {
        up = up + 0.1; down = down + 0.1;
    }
    glutPostRedisplay();
}

void MyIdleDown() {    //아래쪽으로 0.1씩 움직입니다
    if (down > -0.4) {
        up = up - 0.1; down = down - 0.1;
    }
    glutPostRedisplay();//프로그램 내용이 변경되었을 때 윈도우를 다시 출력하도록 하는 함수
}

void MySpecial(int key, int x, int y) {
    switch (key) {
        /*오른쪽 화살표를 누르면 MyIdleRight를 호출합니다.*/
    case GLUT_KEY_RIGHT:
        glutIdleFunc(MyIdleRight);
        break;
    /*왼쪽 화살표를 누르면 MyIdleLeft를 호출합니다.*/
    case GLUT_KEY_LEFT:
        glutIdleFunc(MyIdleLeft);
        break;
    /*아래쪽 화살표를 누르면 MyIdleDown을 호출합니다.*/
    case GLUT_KEY_DOWN:
        glutIdleFunc(MyIdleDown);
        break;
    /*위쪽 화살표를 누르면 MyIdleUp을 호출합니다.*/
    case GLUT_KEY_UP:
        glutIdleFunc(MyIdleUp);
        break;
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
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //디스플레이모드 
    glutInitWindowSize(300, 300); //300 X 300
    glutInitWindowPosition(0, 0); //윈도우 위치 (0,0)
    glutCreateWindow("Keyboard Callback(2)");
    MyInit(); //초기화
    glutDisplayFunc(MyDisplay); //display 이벤트
    glutSpecialFunc(MySpecial); //키보드 이벤트

    glutMainLoop();
    return 0;
}