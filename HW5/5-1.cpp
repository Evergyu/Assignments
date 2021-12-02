//**********************************************************************
//                           HW#5-1 : gluLookAt()                    
//  작성자 : 이인규                              날짜 : 2021년 10월 28일 
//                                                                      
// 문제 정의 :      키보드를 이용한 시점 제어                                                
//					- - - - - - -                                         
// 기능 :			윗키 : Camera의 Y축 좌표가 0.1씩 증가
//                  아랫키 : Camera의 Y축 좌표가 0.1씩 감소
//                  왼쪽키 : Camera의 X축 좌표가 0.1씩 감소
//                  오른쪽키 : Camera의 X축 좌표가 0.1씩 증가
// 
//                  A키 : 초점(Focus)의 X축 좌표가 0.1씩 증가
//                  F키 : 초점(Focus)의 X축 좌표가 0.1씩 감소
//                  R키 : 초점(Focus)의 Y축 좌표가 0.1씩 증가
//                  F키 : 초점(Focus)의 Y축 좌표가 0.1씩 감소
//                  Z키 : 초점(Focus)의 Z축 좌표가 0.1씩 증가                 
//                  T키 : 초점(Focus)의 Z축 좌표가 0.1씩 감소                                        
//**********************************************************************
#include <GL/glut.h>
GLdouble Camera_x = 0, Camera_y = 0;
GLdouble Focus_x = 0, Focus_y = 0, Focus_z = 0; //시점을 변화시키기 위한 변수들
int bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
int bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
void DrawGround() {
     glColor3f( 0.5, 0.5, 0.5);
     glBegin(GL_POLYGON);                  //바닥 그리기
          glVertex3f(-2.0,-0.71, 2.0);
          glVertex3f( 2.0,-0.71, 2.0);
          glVertex3f( 2.0,-0.71,-2.0);
          glVertex3f(-2.0,-0.71,-2.0);
     glEnd();

     glColor3f(0.3, 0.3, 0.3);
     glBegin(GL_LINES);                                 //그리드무늬 선 그리기
          for (float x = -2.0; x <= 2.2; x += 0.2) {
               glVertex3f(x,-0.7,-2.0);
               glVertex3f(x,-0.7, 2.0);
          }

          for (float z = -2.0; z <= 2.2; z += 0.2) {
               glVertex3f(-2.0,-0.7, z);
               glVertex3f( 2.0,-0.7, z);
          }
     glEnd();
}

void MyDisplay( ) {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);    //모델뷰행렬로 바꾸기
     glLoadIdentity( );             //항등행렬로 설정

     gluLookAt(Camera_x, Camera_y, 3.5, Focus_x, Focus_y, Focus_z, 0.0, 1.0, 0.0); //시점설정

     DrawGround();

     glColor3f(1.0, 1.0, 0.0);
     glutWireTeapot(1.0);           //주전자 그리기

     glFlush();                     //화면에 보이게 출력
}

void MyReshape (int w, int h) {
     glViewport (0, 0, (GLsizei) w, (GLsizei) h);           //바뀐 창으로 뷰폿설정
     glMatrixMode (GL_PROJECTION);                          //프로젝션 행렬로 변결
     glLoadIdentity( );                                     //항등행렬로 설정

     gluPerspective(45.0, (GLsizei)w/(GLsizei)h, 0.0, 100); //시야각을 설정하는 원근투영함수
}

/*MyTimer_a~t는 KeyboardFunc로 A,F,R,V,Z,T를 입력받을 때 실행하는 타이머함수입니다.
  연속적으로 움직여야 해서 타이머콜백을 썼습니다.
  처음에 Idle로 구현했는데 제어할수없을 정도로 빨라서 타이머로 교체했습니다.
  int형 변수와 if문을 추가해 다른 버튼을 누르면 Focus 그 버튼에 해당하지 않는 시점은 움직이지 않도록 했습니다. */
void MyTimer_a(int Value) {
    if (bool_a == 1) {
        Focus_x = Focus_x + 0.1;        //Focus_x좌표 + 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_a, 1);
}
void MyTimer_f(int Value) {
    if (bool_f == 1) {                  
        Focus_x = Focus_x - 0.1;        //Focus_x좌표 - 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_f, 1);
}
void MyTimer_r(int Value) {
    if (bool_r == 1) {
        Focus_y = Focus_y + 0.1;        //Focus_y좌표 + 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_r, 1);
}
void MyTimer_v(int Value) {
    if (bool_v == 1) {
        Focus_y = Focus_y - 0.1;        //Focus_y좌표 - 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_v, 1);
}
void MyTimer_z(int Value) {
    if (bool_z == 1) {
        Focus_z = Focus_z + 0.1;        //Focus_z좌표 + 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_z, 1);
}
void MyTimer_t(int Value) {
    if (bool_t == 1) {
        Focus_z = Focus_z - 0.1;        //Focus_z좌표 - 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_t, 1);
}
/*키보드콜백입니다. 각 키를 누르면 그 키에 해당하는 bool_키값 의 값을 1로 만들어주고 타이머콜백을 실행해줍니다.*/
void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    //A를 눌렀을때
    case 'a':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 1, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_a, 1);
         break;
    case 'A':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 1, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_a, 1);
         break;
    //F를 눌렀을때
    case 'f':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 1, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_f, 1);
         break;
    case 'F':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 1, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_f, 1);
        break;
    //R을 눌렀을때
    case 'r':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 1, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_r, 1);
        break;
    case 'R':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 1, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_r, 1);
        break;
    //V를 눌렀을때
    case 'v':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 1, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_v, 1);
        break;
    case 'V':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 1, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_v, 1);
        break;
    //Z를 눌렀을때
    case 'z':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 1, bool_t = 0;
        glutTimerFunc(100, MyTimer_z, 1);
        break;
    case 'Z':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 1, bool_t = 0;
        glutTimerFunc(100, MyTimer_z, 1);
        break;
    //T를 눌렀을때
    case 't':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 1;
        glutTimerFunc(100, MyTimer_t, 1);
        break;
    case 'T':
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 1;
        glutTimerFunc(100, MyTimer_t, 1);
        break;
    }
    glutPostRedisplay();
}

/*특수키를 위한 타이머 함수들입니다. 원리는 위에 키보드와 똑같이 on/off를 위한 인트형 변수와 if문을 사용했습니다.*/
void MyTimer_up(int Value) {
    if (bool_up == 1) {
        Camera_y = Camera_y + 0.1;        //Camera_y좌표 + 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_up, 1);
}
void MyTimer_down(int Value) {
    if (bool_down == 1) {
        Camera_y = Camera_y - 0.1;        //Camera_y좌표 - 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_down, 1);
}
void MyTimer_left(int Value) {
    if (bool_left == 1) {
        Camera_x = Camera_x - 0.1;        //Camera_x좌표 - 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_left, 1);
}
void MyTimer_right(int Value) {
    if (bool_right == 1) {
        Camera_x = Camera_x + 0.1;        //Camera_x좌표 + 0.1씩

        glutPostRedisplay();            //화면에 나타나도록 glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_right, 1);
}
/*특수키 콜백입니다. 여기서도 마찬가지로 자기에 해당 안하는 bool_키값 변수를 모두 0으로 초기화합니다.*/
void MySpecial(int key, int x, int y) {
    switch (key) {
    //윗키
    case GLUT_KEY_UP:
        bool_up = 1, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_up, 1);
        break;
    //아래키
    case GLUT_KEY_DOWN:
        bool_up = 0, bool_down = 1, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_down, 1);
        break;
    //왼쪽키
    case GLUT_KEY_LEFT:
        bool_up = 0, bool_down = 0, bool_left = 1, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_left, 1);
        break;
    //오른쪽키
    case GLUT_KEY_RIGHT:
        bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 1;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_right, 1);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);      //디스플레이 모드
     glutInitWindowSize(500, 500);                      //사이즈 500*500
     glutInitWindowPosition(0, 0);                      //창 위치
     glutCreateWindow("VCS (View Coordinate System)");  //창 이름 
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glutKeyboardFunc(MyKeyboard);      //키보드콜백
     glutSpecialFunc(MySpecial);        //특수키콜백
     glutDisplayFunc(MyDisplay);        //화면콜백
     glutReshapeFunc(MyReshape);        //화면크기변화 콜백

     glutMainLoop( );
     return 0;
}