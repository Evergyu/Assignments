//**********************************************************************
//                           HW#4-1 : Robot Arms                     
//  작성자 : 이인규                              날짜 : 2021년 10월 14일 
//                                                                      
// 문제 정의 :      손가락 3개를 가진 로봇 팔 만들기                                                
//					- - - - - - -                                         
// 기능 :			1을 누르면 손가락 1이 움직입니다
//                  2을 누르면 손가락 2가 움직입니다
//                  3을 누르면 손가락 3이 움직입니다
//                  4를 누르면 모든 손가락이 움직입니다.
//                  S를 누르면 손가락이 멈춥니다.
//                  우클릭을 하면 손이 초기 모양으로 돌아옵니다.
//                  - - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>

static int shoulder = -50, elbow=30;
static int joint_1_1 = 30, joint_1_2 = 30, joint_1_3 = 30;
static int joint_2_1 = 20, joint_2_2 = 20, joint_2_3 = 20;
static int joint_3_1 = 10, joint_3_2 = 10, joint_3_3 = 10;
static int active = 1,active1=1;

void MyInit(void) {
   glClearColor (0.0, 0.0, 0.0, 1.0);
   glShadeModel (GL_FLAT);
}

void MyDisplay(void) {
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix(); //항등행렬 푸시 
		glTranslatef (-3.0, 0.0, 0.0);	//어깨부분을 원하는 위치인 x축으로 -3만큼 이동시킵니다.
		glRotatef ((GLfloat)shoulder, 0.0, 0.0, 1.0); // 어깨부분을 기준으로 -30도 회전시킵니다
		glTranslatef (1.0, 0.0, 0.0);	// 회전축으로 이용할 부분을 끝부분에 위치하도록 x축으로 1만큼 이동
		glPushMatrix();	//윗팔 푸시
            glColor3f(1.0, 1.0, 1.0);   //윗팔부분 색설정
			glScalef (2.0, 0.4, 1.0);   //윗팔부분 크기설정 
			glutWireCube (1.0);         //윗팔부분 도형설정
		glPopMatrix(); //윗팔생성 후 스택에서 팝
        
		glTranslatef (1.0, 0.0, 0.0);	// 팔꿈치부분을 맞추기 위해 x축으로 1만큼 이동
		glRotatef ((GLfloat)elbow, 0.0, 0.0, 1.0); // 팔꿈치부분을 기준으로 30도만큼 회전
		glTranslatef (1.0, 0.0, 0.0);	// 회전축으로 이용할 부분을 끝부분에 위치하도록 x축으로 1만큼 이동합니다
		glPushMatrix();	//아랫팔 푸시
            glColor3f(1.0, 1.0, 1.0);   //아랫팔 색 설정
			glScalef (2.0, 0.4, 1.0);   //아랫팔 크기 설정
            glutWireCube(1.0);          //아랫팔 도형
		glPopMatrix(); //아랫팔 팝
        
        glPushMatrix(); //1 여기까지 만든 손목부분을 푸시해 줍니다.
        //손가락1_1
        glTranslatef(1, 0, 0); //손목부분을 맞추기 위해 x축만큼 1 이동
        glRotatef((GLfloat)joint_1_1, 0,0, 1); //손목부분을 기준으로 회전
        glTranslatef(0.3, 0, 0);    //도형의 크기를 (0.6,0.1,0.1)배 할 것이므로 그 반인 0.3을 이동시켜 회전축에 끝부분이 위치하도록 이동
        glPushMatrix(); //b
            glColor3f(1.0, 1.0, 1.0);   //손가락1_1의 색 설정
            glScalef(0.6, 0.1, 0.1);    //손가락1_1의 크기 설정
            glutWireCube(1.0);          //손가락의 도형 설정
        glPopMatrix(); //b
                
        //손가락 1_2
        glTranslatef(0.3, 0, 0);                //손가락 1_1의 끝에 맞춰 이동
        glRotatef((GLfloat)joint_1_2, 0,0, 0.1);//손가락1_1 끝부분을 기준으로 회전
        glTranslatef(0.3, 0, 0);                //도형의 끝부분이 회전축에 위치하도록 이동    
        glPushMatrix(); //d               
            glColor3f(1.0, 1.0, 1.0);           //손가락1_2의 색 설정
            glScalef(0.6, 0.1, 0.1);            //손가락1_2의 크기 설정
            glutWireCube(1.0);                  //손가락의 도형 설정
        glPopMatrix(); //d
                
        //손가락 1_3
        glTranslatef(0.3, 0.0, 0.0);            //손가락 1_2의 끝에 맞춰 이동
        glRotatef((GLfloat)joint_1_3, 0, 0, 1); //손가락1_1 끝부분을 기준으로 회전
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
        glRotatef((GLfloat)joint_2_1, 0, 0, 1); //손목 끝부분을 기준으로 회전
        glTranslatef(0.3, 0, 0);                //도형의 끝부분이 회전축에 위치하도록 이동
        glPushMatrix(); //b
        glColor3f(1.0, 1.0, 1.0);               //손가락2_1의 색 설정
        glScalef(0.6, 0.1, 0.1);                //손가락2_1의 크기 설정
        glutWireCube(1.0);                      //손가락의 도형 설정
        glPopMatrix(); //b

        //손가락 2_2
        glTranslatef(0.3, 0, 0);                    //손가락 2_1의 끝에 맞춰 이동
        glRotatef((GLfloat)joint_2_2, 0, 0, 0.1);   //손가락 2_1 끝부분을 기준으로 회전
        glTranslatef(0.3, 0, 0);                    //도형의 끝부분이 회전축에 위치하도록 이동
        glPushMatrix(); //d               
        glColor3f(1.0, 1.0, 1.0);                   //손가락2_2의 색 설정
        glScalef(0.6, 0.1, 0.1);                    //손가락2_2의 크기 설정
        glutWireCube(1.0);                          //손가락의 도형 설정
        glPopMatrix(); //d

        //손가락 2_3
        glTranslatef(0.3, 0.0, 0.0);            //손가락 2_2의 끝에 맞춰 이동
        glRotatef((GLfloat)joint_2_3, 0, 0, 1); //손가락 2_2 끝부분을 기준으로 회전
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
        glRotatef((GLfloat)joint_3_1, 0, 0, 1); //손목 끝부분을 기준으로 회전
        glTranslatef(0.3, 0, 0);                //도형의 끝부분이 회전축에 위치하도록 이동
        glPushMatrix(); //b
        glColor3f(1.0, 1.0, 1.0);               //손가락 3_1의 색 설정
        glScalef(0.6, 0.1, 0.1);                //손가락 3_1의 크기 설정
        glutWireCube(1.0);                      //손가락의 도형 설정
        glPopMatrix(); //b

        //손가락 3_2
        glTranslatef(0.3, 0, 0);                    //손가락 3_1의 끝에 맞춰 이동
        glRotatef((GLfloat)joint_3_2, 0, 0, 0.1);   //손가락 3_1 끝부분을 기준으로 회전
        glTranslatef(0.3, 0, 0);                    //도형의 끝부분이 회전축에 위치하도록 이동
        glPushMatrix(); //d               
        glColor3f(1.0, 1.0, 1.0);                   //손가락3_2의 색 설정
        glScalef(0.6, 0.1, 0.1);                    //손가락3_2의 크기 설정
        glutWireCube(1.0);                          //손가락의 도형 설정
        glPopMatrix(); //d

        //손가락 3_3
        glTranslatef(0.3, 0.0, 0.0);            //손가락 3_2의 끝에 맞춰 이동
        glRotatef((GLfloat)joint_3_3, 0, 0, 1); //손가락3_2 끝부분을 기준으로 회전
        glTranslatef(0.3, 0.0, 0.0);            //도형의 끝부분이 회전축에 위치하도록 이동
        glPushMatrix(); //e
        glColor3f(1.0, 1.0, 1.0);               //손가락3_2의 색 설정
        glScalef(0.6, 0.1, 0.1);                //손가락3_2의 크기 설정
        glutWireCube(1.0);                      //손가락의 도형 설정
        glPopMatrix();//e

        glPopMatrix();//3 //손가락3 팝

        glPopMatrix();//손목부분 팝        
   glPopMatrix(); //항등행렬 팝
   
   glutSwapBuffers();
}

void MyReshape (int w, int h) {
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);  //모델뷰모드
   glLoadIdentity();            //항등행렬 설정
   glTranslatef (0.0, 0.0, -5.0);
}

void MyTimer1(int Value) {  //손가락 1 움직이기
        joint_1_1 = (joint_1_1 + 5) % 60;
        joint_1_2 = (joint_1_2 + 5) % 60;
        joint_1_3 = (joint_1_3 + 5) % 60;

    glutPostRedisplay();
    if (active == 1) {  //active가 1일때 재귀호출
        glutTimerFunc(40, MyTimer1, 1);
    }
}
void MyTimer2(int Value) {  //손가락 2 움직이기

    joint_2_1 = (joint_2_1 + 5) % 60;
    joint_2_2 = (joint_2_2 + 5) % 60;
    joint_2_3 = (joint_2_3 + 5) % 60;

    glutPostRedisplay();    

    if (active == 1) {  //active가 1일때 재귀호출
        glutTimerFunc(40, MyTimer2, 1);
    }
}
void MyTimer3(int Value) {
        joint_3_1 = (joint_3_1 + 5) % 60;
        joint_3_2 = (joint_3_2 + 5) % 60;
        joint_3_3 = (joint_3_3 + 5) % 60;
    
    glutPostRedisplay();
    if (active == 1) {  //active가 1일때 재귀호출
        glutTimerFunc(40, MyTimer3, 1);
    }
}

void MyKeyboard (unsigned char key, int x, int y) {
   switch (key) {
      case '1':
          glutTimerFunc(40, MyTimer1, 1);   //1을 누르면 MyTimer1을 호출
         break;
      case '2':
          glutTimerFunc(40, MyTimer2, 1);   //2를 누르면 MyTimer2를 호출
         break;
      case '3':
          glutTimerFunc(40, MyTimer3, 1);   //3을 누르면 MyTimer3을 호출
         break;
      case '4':
          glutTimerFunc(40, MyTimer1, 1);   //4를 누르면 MyTimer1,2,3을 호출
          glutTimerFunc(40, MyTimer2, 1);
          glutTimerFunc(40, MyTimer3, 1);
         break;
      case 'S':             //S를 누르면 active변수의 값을 1 또는 -1로 바꿔
          active *= -1;     //움직이고 있던 손가락을 멈춥니다
          break;
      case 's':
          active *= -1;
          break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
   glutPostRedisplay();
}


void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
    
    }

    //오른쪽버튼을 누르면 어깨,팔꿈치,손가락 관절들이 모두 초기 각도로 돌아옵니다.
    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
        shoulder = -50;
        elbow = 30;
        joint_1_1 = 30;
        joint_1_2 = 30;
        joint_1_3 = 30;
        
        joint_2_1 = 20;
        joint_2_2 = 20;
        joint_2_3 = 20;
        
        joint_3_1 = 10;
        joint_3_2 = 10;
        joint_3_3 = 10;
    }
    
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
   glutKeyboardFunc(MyKeyboard);    //키보드 이벤트
   glutMouseFunc(MyMouseClick); //마우스 이벤트
   glutMainLoop();
   return 0;
}