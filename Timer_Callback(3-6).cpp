//**********************************************************************
//                           HW#3-6 : Timer Callback                     
//  작성자 : 이인규                              날짜 : 2021년 9월 30일 
//                                                                      
// 문제 정의 :      Timer Callback을 이용해 벽에 닿으면 방향과 색을 바꾸며 진행하는 도형 그리기                                                
//					- - - - - - -                                         
// 기능 :			클릭시 멈추는것, 벽에 부딪히면 돌아오는것
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>

GLdouble Delta = 0.0; 
GLdouble r = 0, g = 0.5, b = 0.8;
GLint direction = 1;
GLboolean keep=true;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //컬러버퍼 초기화
    glBegin(GL_POLYGON);            //GL_POLYGON, 다각형 그리기 시작
    glColor3f(r, g, b);             //도형 색 (0,0.5,0.8) 푸른색
    glVertex3f(-1.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, 0.5, 0.0);
    glVertex3f(-1.0 + Delta, 0.5, 0.0); //점 네개의 좌표설정
    glEnd();    //끝

    glutSwapBuffers(); //백버퍼와 전면버퍼를 스왑
}
void MyTimer(int Value) {   
    if (direction==1) {     //오른쪽으로 움직일때는 x좌표가 0.1씩 증가하고 
        Delta = Delta + 0.1;    //색은 푸른색입니다
        r = 0; g = 0.5; b = 0.8;
        if (Delta > 0.9) direction = -1; //화면밖을 나가지 않도록 범위를 설정하고 방향을 바꾸도록 했습니다
    }
    else if (direction==-1) {   
        Delta = Delta - 0.1;    //왼쪽으로 움직일때는 x좌표가 0.1씩 감소하고
        r = 0.8; g = 0.5; b = 0.0;  //색은 붉은색입니디ㅏ
        if (Delta < 0.1) direction = 1; //화면 밖을 나가지 않도록 범위를 설정하고 방향을 바꾸도록 했습니다.
    }
    
    glutPostRedisplay(); //프로그램 내용이 변경되었을 때 윈도우를 다시 출력하도록 하는 함수
    if (keep) glutTimerFunc(400, MyTimer, 1); //keep이 true일 때 실행합니다. 마우스 왼클릭을 하면 keep이 false로 바뀌며 멈춥니다.
    }

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {    //마우스를 클릭했을때 움직이던 도형이 멈춥니다.
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {     
        keep = false;       //GLboolean 자료형의 keep이 false가 되면서 멈춥니다.
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
    glutCreateWindow("Timer Callback");
    MyInit();
    MyInit(); //초기화
    glutDisplayFunc(MyDisplay); //display 이벤트
    glutMouseFunc(MyMouseClick); //마우스 이벤트
    glutTimerFunc(40, MyTimer, 1); //타이머 이벤트
    glutMainLoop();
    return 0;
}