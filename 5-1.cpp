//**********************************************************************
//                           HW#5-1 : gluLookAt()                    
//  �ۼ��� : ���α�                              ��¥ : 2021�� 10�� 28�� 
//                                                                      
// ���� ���� :      Ű���带 �̿��� ���� ����                                                
//					- - - - - - -                                         
// ��� :			��Ű : Camera�� Y�� ��ǥ�� 0.1�� ����
//                  �Ʒ�Ű : Camera�� Y�� ��ǥ�� 0.1�� ����
//                  ����Ű : Camera�� X�� ��ǥ�� 0.1�� ����
//                  ������Ű : Camera�� X�� ��ǥ�� 0.1�� ����
// 
//                  AŰ : ����(Focus)�� X�� ��ǥ�� 0.1�� ����
//                  FŰ : ����(Focus)�� X�� ��ǥ�� 0.1�� ����
//                  RŰ : ����(Focus)�� Y�� ��ǥ�� 0.1�� ����
//                  FŰ : ����(Focus)�� Y�� ��ǥ�� 0.1�� ����
//                  ZŰ : ����(Focus)�� Z�� ��ǥ�� 0.1�� ����                 
//                  TŰ : ����(Focus)�� Z�� ��ǥ�� 0.1�� ����                                        
//**********************************************************************
#include <GL/glut.h>
GLdouble Camera_x = 0, Camera_y = 0;
GLdouble Focus_x = 0, Focus_y = 0, Focus_z = 0; //������ ��ȭ��Ű�� ���� ������
int bool_up = 0, bool_down = 0, bool_left = 0, bool_right = 0;
int bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
void DrawGround() {
     glColor3f( 0.5, 0.5, 0.5);
     glBegin(GL_POLYGON);                  //�ٴ� �׸���
          glVertex3f(-2.0,-0.71, 2.0);
          glVertex3f( 2.0,-0.71, 2.0);
          glVertex3f( 2.0,-0.71,-2.0);
          glVertex3f(-2.0,-0.71,-2.0);
     glEnd();

     glColor3f(0.3, 0.3, 0.3);
     glBegin(GL_LINES);                                 //�׸��幫�� �� �׸���
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
     glMatrixMode(GL_MODELVIEW);    //�𵨺���ķ� �ٲٱ�
     glLoadIdentity( );             //�׵���ķ� ����

     gluLookAt(Camera_x, Camera_y, 3.5, Focus_x, Focus_y, Focus_z, 0.0, 1.0, 0.0); //��������

     DrawGround();

     glColor3f(1.0, 1.0, 0.0);
     glutWireTeapot(1.0);           //������ �׸���

     glFlush();                     //ȭ�鿡 ���̰� ���
}

void MyReshape (int w, int h) {
     glViewport (0, 0, (GLsizei) w, (GLsizei) h);           //�ٲ� â���� ��������
     glMatrixMode (GL_PROJECTION);                          //�������� ��ķ� ����
     glLoadIdentity( );                                     //�׵���ķ� ����

     gluPerspective(45.0, (GLsizei)w/(GLsizei)h, 0.0, 100); //�þ߰��� �����ϴ� ���������Լ�
}

/*MyTimer_a~t�� KeyboardFunc�� A,F,R,V,Z,T�� �Է¹��� �� �����ϴ� Ÿ�̸��Լ��Դϴ�.
  ���������� �������� �ؼ� Ÿ�̸��ݹ��� ����ϴ�.
  ó���� Idle�� �����ߴµ� �����Ҽ����� ������ ���� Ÿ�̸ӷ� ��ü�߽��ϴ�.
  int�� ������ if���� �߰��� �ٸ� ��ư�� ������ Focus �� ��ư�� �ش����� �ʴ� ������ �������� �ʵ��� �߽��ϴ�. */
void MyTimer_a(int Value) {
    if (bool_a == 1) {
        Focus_x = Focus_x + 0.1;        //Focus_x��ǥ + 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_a, 1);
}
void MyTimer_f(int Value) {
    if (bool_f == 1) {                  
        Focus_x = Focus_x - 0.1;        //Focus_x��ǥ - 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_f, 1);
}
void MyTimer_r(int Value) {
    if (bool_r == 1) {
        Focus_y = Focus_y + 0.1;        //Focus_y��ǥ + 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_r, 1);
}
void MyTimer_v(int Value) {
    if (bool_v == 1) {
        Focus_y = Focus_y - 0.1;        //Focus_y��ǥ - 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_v, 1);
}
void MyTimer_z(int Value) {
    if (bool_z == 1) {
        Focus_z = Focus_z + 0.1;        //Focus_z��ǥ + 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_z, 1);
}
void MyTimer_t(int Value) {
    if (bool_t == 1) {
        Focus_z = Focus_z - 0.1;        //Focus_z��ǥ - 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_t, 1);
}
/*Ű�����ݹ��Դϴ�. �� Ű�� ������ �� Ű�� �ش��ϴ� bool_Ű�� �� ���� 1�� ������ְ� Ÿ�̸��ݹ��� �������ݴϴ�.*/
void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    //A�� ��������
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
    //F�� ��������
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
    //R�� ��������
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
    //V�� ��������
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
    //Z�� ��������
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
    //T�� ��������
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

/*Ư��Ű�� ���� Ÿ�̸� �Լ����Դϴ�. ������ ���� Ű����� �Ȱ��� on/off�� ���� ��Ʈ�� ������ if���� ����߽��ϴ�.*/
void MyTimer_up(int Value) {
    if (bool_up == 1) {
        Camera_y = Camera_y + 0.1;        //Camera_y��ǥ + 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_up, 1);
}
void MyTimer_down(int Value) {
    if (bool_down == 1) {
        Camera_y = Camera_y - 0.1;        //Camera_y��ǥ - 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_down, 1);
}
void MyTimer_left(int Value) {
    if (bool_left == 1) {
        Camera_x = Camera_x - 0.1;        //Camera_x��ǥ - 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_left, 1);
}
void MyTimer_right(int Value) {
    if (bool_right == 1) {
        Camera_x = Camera_x + 0.1;        //Camera_x��ǥ + 0.1��

        glutPostRedisplay();            //ȭ�鿡 ��Ÿ������ glut{ostRedisplay
    }
    glutTimerFunc(100, MyTimer_right, 1);
}
/*Ư��Ű �ݹ��Դϴ�. ���⼭�� ���������� �ڱ⿡ �ش� ���ϴ� bool_Ű�� ������ ��� 0���� �ʱ�ȭ�մϴ�.*/
void MySpecial(int key, int x, int y) {
    switch (key) {
    //��Ű
    case GLUT_KEY_UP:
        bool_up = 1, bool_down = 0, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_up, 1);
        break;
    //�Ʒ�Ű
    case GLUT_KEY_DOWN:
        bool_up = 0, bool_down = 1, bool_left = 0, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_down, 1);
        break;
    //����Ű
    case GLUT_KEY_LEFT:
        bool_up = 0, bool_down = 0, bool_left = 1, bool_right = 0;
        bool_a = 0, bool_f = 0, bool_r = 0, bool_v = 0, bool_z = 0, bool_t = 0;
        glutTimerFunc(100, MyTimer_left, 1);
        break;
    //������Ű
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
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);      //���÷��� ���
     glutInitWindowSize(500, 500);                      //������ 500*500
     glutInitWindowPosition(0, 0);                      //â ��ġ
     glutCreateWindow("VCS (View Coordinate System)");  //â �̸� 
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glutKeyboardFunc(MyKeyboard);      //Ű�����ݹ�
     glutSpecialFunc(MySpecial);        //Ư��Ű�ݹ�
     glutDisplayFunc(MyDisplay);        //ȭ���ݹ�
     glutReshapeFunc(MyReshape);        //ȭ��ũ�⺯ȭ �ݹ�

     glutMainLoop( );
     return 0;
}