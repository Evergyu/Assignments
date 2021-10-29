//**********************************************************************
//                           HW#5-2 : Robot Arms + view                     
//  작성자 : 이인규                              날짜 : 2021년 10월 28일 
//                                                                      
// 문제 정의 :      손가락 3개를 가진 로봇 팔을 회전시켜 여러각도에서 보도록 하기                                                
//					- - - - - - -                                         
// 기능 :			화살표 상,하,좌,우를 누르시면 그 방향으로 팔이 회전합니다.
//                  보시기 편하도록 4에서 했던 기능들은 모두 지워버렸습니다.
//                  - - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

const double PI = 3.1415926;
static float angle = 0.0;
static float x = 0, y = 0, z = 0;     //카메라 위치

void MyInit(void) {
   glClearColor (0.0, 0.0, 0.0, 1.0);
   glShadeModel (GL_FLAT);
}

void drawArm() {
    glPushMatrix(); //항등행렬 푸시 
    glTranslatef(-3.0, 1.0, 0.0);	//어깨부분을 원하는 위치인 x축으로 -3만큼 이동시킵니다.
    glRotatef(-50, 0.0, 0.0, 1.0); // 어깨부분을 기준으로 -30도 회전시킵니다
    glTranslatef(1.0, 0.0, 0.0);	// 회전축으로 이용할 부분을 끝부분에 위치하도록 x축으로 1만큼 이동
    glPushMatrix();	//윗팔 푸시
    glColor3f(1.0, 1.0, 1.0);   //윗팔부분 색설정
    glScalef(2.0, 0.4, 1.0);   //윗팔부분 크기설정 
    glutWireCube(1.0);         //윗팔부분 도형설정
    glPopMatrix(); //윗팔생성 후 스택에서 팝

    glTranslatef(1.0, 0.0, 0.0);	// 팔꿈치부분을 맞추기 위해 x축으로 1만큼 이동
    glRotatef(30, 0.0, 0.0, 1.0); // 팔꿈치부분을 기준으로 30도만큼 회전
    glTranslatef(1.0, 0.0, 0.0);	// 회전축으로 이용할 부분을 끝부분에 위치하도록 x축으로 1만큼 이동합니다
    glPushMatrix();	//아랫팔 푸시
    glColor3f(1.0, 1.0, 1.0);   //아랫팔 색 설정
    glScalef(2.0, 0.4, 1.0);   //아랫팔 크기 설정
    glutWireCube(1.0);          //아랫팔 도형
    glPopMatrix(); //아랫팔 팝

    glPushMatrix(); //1 여기까지 만든 손목부분을 푸시해 줍니다.
    //손가락1_1
    glTranslatef(1, 0, 0); //손목부분을 맞추기 위해 x축만큼 1 이동
    glRotatef(-60, 0, 1, 0);    //손가락 각도조절
    glRotatef(20, 0, 0, 1); //손목부분을 기준으로 회전
    glTranslatef(0.3, 0, 0);    //도형의 크기를 (0.6,0.1,0.1)배 할 것이므로 그 반인 0.3을 이동시켜 회전축에 끝부분이 위치하도록 이동
    glPushMatrix(); //b
    glColor3f(1.0, 1.0, 1.0);   //손가락1_1의 색 설정
    glScalef(0.6, 0.1, 0.1);    //손가락1_1의 크기 설정
    glutWireCube(1.0);          //손가락의 도형 설정
    glPopMatrix(); //b

    //손가락 1_2
    glTranslatef(0.3, 0, 0);                //손가락 1_1의 끝에 맞춰 이동
    glRotatef(20, 0, 0, 0.1);//손가락1_1 끝부분을 기준으로 회전
    glTranslatef(0.3, 0, 0);                //도형의 끝부분이 회전축에 위치하도록 이동    
    glPushMatrix(); //d               
    glColor3f(1.0, 1.0, 1.0);           //손가락1_2의 색 설정
    glScalef(0.6, 0.1, 0.1);            //손가락1_2의 크기 설정
    glutWireCube(1.0);                  //손가락의 도형 설정
    glPopMatrix(); //d

    //손가락 1_3
    glTranslatef(0.3, 0.0, 0.0);            //손가락 1_2의 끝에 맞춰 이동
    glRotatef(20, 0, 0, 1); //손가락1_1 끝부분을 기준으로 회전
    glTranslatef(0.3, 0.0, 0.0);            //도형의 끝부분이 회전축에 위치하도록 이동
    glPushMatrix(); //e
    glColor3f(1.0, 1.0, 1.0);   //손가락1_3의 색 설정1_3의 색 설정
    glScalef(0.6, 0.1, 0.1);    //손가락1_3의 크기 설정1_3의 크기 설정
    glutWireCube(1.0);          //손가락의 도형 설정의 도형 설정
    glPopMatrix();//e

    glPopMatrix();//1 //손가락1 팝

    glPushMatrix();//2 //손가락2를 위한 푸시

    //손가락 2_1
    glTranslatef(1, 0, 0);                  //손목의 끝에 맞춰 이동
    glRotatef(20, 0, 0, 1); //손목 끝부분을 기준으로 회전
    glTranslatef(0.3, 0, 0);                //도형의 끝부분이 회전축에 위치하도록 이동
    glPushMatrix(); //b
    glColor3f(1.0, 1.0, 1.0);               //손가락2_1의 색 설정
    glScalef(0.6, 0.1, 0.1);                //손가락2_1의 크기 설정
    glutWireCube(1.0);                      //손가락의 도형 설정
    glPopMatrix(); //b

    //손가락 2_2
    glTranslatef(0.3, 0, 0);                    //손가락 2_1의 끝에 맞춰 이동
    glRotatef(20, 0, 0, 0.1);   //손가락 2_1 끝부분을 기준으로 회전
    glTranslatef(0.3, 0, 0);                    //도형의 끝부분이 회전축에 위치하도록 이동
    glPushMatrix(); //d               
    glColor3f(1.0, 1.0, 1.0);                   //손가락2_2의 색 설정
    glScalef(0.6, 0.1, 0.1);                    //손가락2_2의 크기 설정
    glutWireCube(1.0);                          //손가락의 도형 설정
    glPopMatrix(); //d

    //손가락 2_3
    glTranslatef(0.3, 0.0, 0.0);            //손가락 2_2의 끝에 맞춰 이동
    glRotatef(20, 0, 0, 1); //손가락 2_2 끝부분을 기준으로 회전
    glTranslatef(0.3, 0.0, 0.0);            //도형의 끝부분이 회전축에 위치하도록 이동
    glPushMatrix(); //e
    glColor3f(1.0, 1.0, 1.0);               //손가락 2_3의 색 설정
    glScalef(0.6, 0.1, 0.1);                //손가락 2_3의 크기 설정
    glutWireCube(1.0);                      //손가락의 도형 설정
    glPopMatrix();//e

    glPopMatrix();//2 //손가락2 팝

    glPushMatrix();//3 //손가락3을 위한 푸시

    //손가락 3_1
    glTranslatef(1, 0, 0);                  //손목의 끝에 맞춰 이동
    glRotatef(60, 0, 1, 0);
    glRotatef(20, 0, 0, 1); //손목 끝부분을 기준으로 회전
    glTranslatef(0.3, 0, 0);                //도형의 끝부분이 회전축에 위치하도록 이동
    glPushMatrix(); //b
    glColor3f(1.0, 1.0, 1.0);               //손가락 3_1의 색 설정
    glScalef(0.6, 0.1, 0.1);                //손가락 3_1의 크기 설정
    glutWireCube(1.0);                      //손가락의 도형 설정
    glPopMatrix(); //b

    //손가락 3_2
    glTranslatef(0.3, 0, 0);                    //손가락 3_1의 끝에 맞춰 이동
    glRotatef(20, 0, 0, 0.1);   //손가락 3_1 끝부분을 기준으로 회전
    glTranslatef(0.3, 0, 0);                    //도형의 끝부분이 회전축에 위치하도록 이동
    glPushMatrix(); //d               
    glColor3f(1.0, 1.0, 1.0);                   //손가락3_2의 색 설정
    glScalef(0.6, 0.1, 0.1);                    //손가락3_2의 크기 설정
    glutWireCube(1.0);                          //손가락의 도형 설정
    glPopMatrix(); //d

    //손가락 3_3
    glTranslatef(0.3, 0.0, 0.0);            //손가락 3_2의 끝에 맞춰 이동
    glRotatef(20, 0, 0, 1); //손가락3_2 끝부분을 기준으로 회전
    glTranslatef(0.3, 0.0, 0.0);            //도형의 끝부분이 회전축에 위치하도록 이동
    glPushMatrix(); //e
    glColor3f(1.0, 1.0, 1.0);               //손가락3_2의 색 설정
    glScalef(0.6, 0.1, 0.1);                //손가락3_2의 크기 설정
    glutWireCube(1.0);                      //손가락의 도형 설정
    glPopMatrix();//e

    glPopMatrix();//3 //손가락3 팝

    glPopMatrix();//손목부분 팝        
    glPopMatrix(); //항등행렬 팝
}

void MyDisplay(void) {
   glPushMatrix();                        //시점 설정 전푸시
   glClear (GL_COLOR_BUFFER_BIT);
   gluLookAt(-1+x, 0+y, 5+z,
       -1, 0, 0, 
       0.0, 1.0, 0.0);
   drawArm();                             //팔그리는 함수

   glPopMatrix();                         //팝
   glutSwapBuffers();                   
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);  //모델뷰모드
    
    glLoadIdentity();            //항등행렬 설정
}
void MySpecial(int key, int x, int y) {
    switch (key) {
        
    case GLUT_KEY_LEFT:
        x = x++;
        //z = 5 * sin(angle * PI / 180);
        if (angle == 360) angle = 0;
        else angle += 10;
        break;
    case GLUT_KEY_RIGHT:
        x = 5 * cos(angle*PI/180);
        z = 5 * sin(angle*PI/180);
        if (angle == 360) angle = 0;
        else angle -= 10;
        break;
    case GLUT_KEY_UP:
        y = 5 * sin(angle * PI / 180);
        if (angle == 360) angle = 0;
        else angle -= 10;
        break;
    case GLUT_KEY_DOWN:
        y = 5 * sin(angle * PI / 180);
        if (angle == 360) angle = 0;
        else angle -= 10;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);    //디스플레이 GLUT_RGB모드
   glutInitWindowSize (800, 600);                   //디스플레이 사이즈 800*600
   glutInitWindowPosition (100, 100);               //윈도우 위치 100*100
   glutCreateWindow("Robot Arm");                   //창 이름 Robot Arm
   MyInit ();   //초기화
   glutDisplayFunc(MyDisplay); //display 이벤트
   glutReshapeFunc(MyReshape);  //창 크기가 변했을때 이벤트
   
   glutSpecialFunc(MySpecial);
   glutMainLoop();
   return 0;
}