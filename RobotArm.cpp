//**********************************************************************
//                           HW#4-1 : Robot Arms                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 10�� 14�� 
//                                                                      
// ���� ���� :      �հ��� 3���� ���� �κ� �� �����                                                
//					- - - - - - -                                         
// ��� :			1�� ������ �հ��� 1�� �����Դϴ�
//                  2�� ������ �հ��� 2�� �����Դϴ�
//                  3�� ������ �հ��� 3�� �����Դϴ�
//                  4�� ������ ��� �հ����� �����Դϴ�.
//                  S�� ������ �հ����� ����ϴ�.
//                  ��Ŭ���� �ϸ� ���� �ʱ� ������� ���ƿɴϴ�.
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
   glPushMatrix(); //�׵���� Ǫ�� 
		glTranslatef (-3.0, 0.0, 0.0);	//����κ��� ���ϴ� ��ġ�� x������ -3��ŭ �̵���ŵ�ϴ�.
		glRotatef ((GLfloat)shoulder, 0.0, 0.0, 1.0); // ����κ��� �������� -30�� ȸ����ŵ�ϴ�
		glTranslatef (1.0, 0.0, 0.0);	// ȸ�������� �̿��� �κ��� ���κп� ��ġ�ϵ��� x������ 1��ŭ �̵�
		glPushMatrix();	//���� Ǫ��
            glColor3f(1.0, 1.0, 1.0);   //���Ⱥκ� ������
			glScalef (2.0, 0.4, 1.0);   //���Ⱥκ� ũ�⼳�� 
			glutWireCube (1.0);         //���Ⱥκ� ��������
		glPopMatrix(); //���Ȼ��� �� ���ÿ��� ��
        
		glTranslatef (1.0, 0.0, 0.0);	// �Ȳ�ġ�κ��� ���߱� ���� x������ 1��ŭ �̵�
		glRotatef ((GLfloat)elbow, 0.0, 0.0, 1.0); // �Ȳ�ġ�κ��� �������� 30����ŭ ȸ��
		glTranslatef (1.0, 0.0, 0.0);	// ȸ�������� �̿��� �κ��� ���κп� ��ġ�ϵ��� x������ 1��ŭ �̵��մϴ�
		glPushMatrix();	//�Ʒ��� Ǫ��
            glColor3f(1.0, 1.0, 1.0);   //�Ʒ��� �� ����
			glScalef (2.0, 0.4, 1.0);   //�Ʒ��� ũ�� ����
            glutWireCube(1.0);          //�Ʒ��� ����
		glPopMatrix(); //�Ʒ��� ��
        
        glPushMatrix(); //1 ������� ���� �ո�κ��� Ǫ���� �ݴϴ�.
        //�հ���1_1
        glTranslatef(1, 0, 0); //�ո�κ��� ���߱� ���� x�ุŭ 1 �̵�
        glRotatef((GLfloat)joint_1_1, 0,0, 1); //�ո�κ��� �������� ȸ��
        glTranslatef(0.3, 0, 0);    //������ ũ�⸦ (0.6,0.1,0.1)�� �� ���̹Ƿ� �� ���� 0.3�� �̵����� ȸ���࿡ ���κ��� ��ġ�ϵ��� �̵�
        glPushMatrix(); //b
            glColor3f(1.0, 1.0, 1.0);   //�հ���1_1�� �� ����
            glScalef(0.6, 0.1, 0.1);    //�հ���1_1�� ũ�� ����
            glutWireCube(1.0);          //�հ����� ���� ����
        glPopMatrix(); //b
                
        //�հ��� 1_2
        glTranslatef(0.3, 0, 0);                //�հ��� 1_1�� ���� ���� �̵�
        glRotatef((GLfloat)joint_1_2, 0,0, 0.1);//�հ���1_1 ���κ��� �������� ȸ��
        glTranslatef(0.3, 0, 0);                //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�    
        glPushMatrix(); //d               
            glColor3f(1.0, 1.0, 1.0);           //�հ���1_2�� �� ����
            glScalef(0.6, 0.1, 0.1);            //�հ���1_2�� ũ�� ����
            glutWireCube(1.0);                  //�հ����� ���� ����
        glPopMatrix(); //d
                
        //�հ��� 1_3
        glTranslatef(0.3, 0.0, 0.0);            //�հ��� 1_2�� ���� ���� �̵�
        glRotatef((GLfloat)joint_1_3, 0, 0, 1); //�հ���1_1 ���κ��� �������� ȸ��
        glTranslatef(0.3, 0.0, 0.0);            //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
        glPushMatrix(); //e
        glColor3f(1.0, 1.0, 1.0);   //�հ���1_3�� �� ����1_3�� �� ����
        glScalef(0.6, 0.1, 0.1);    //�հ���1_3�� ũ�� ����1_3�� ũ�� ����
        glutWireCube(1.0);          //�հ����� ���� ������ ���� ����
        glPopMatrix();//e
        
        glPopMatrix();//1 //�հ���1 ��

        glPushMatrix();//2 //�հ���2�� ���� Ǫ��
        //�հ��� 2_1
        glTranslatef(1, 0, 0);                  //�ո��� ���� ���� �̵�
        glRotatef((GLfloat)joint_2_1, 0, 0, 1); //�ո� ���κ��� �������� ȸ��
        glTranslatef(0.3, 0, 0);                //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
        glPushMatrix(); //b
        glColor3f(1.0, 1.0, 1.0);               //�հ���2_1�� �� ����
        glScalef(0.6, 0.1, 0.1);                //�հ���2_1�� ũ�� ����
        glutWireCube(1.0);                      //�հ����� ���� ����
        glPopMatrix(); //b

        //�հ��� 2_2
        glTranslatef(0.3, 0, 0);                    //�հ��� 2_1�� ���� ���� �̵�
        glRotatef((GLfloat)joint_2_2, 0, 0, 0.1);   //�հ��� 2_1 ���κ��� �������� ȸ��
        glTranslatef(0.3, 0, 0);                    //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
        glPushMatrix(); //d               
        glColor3f(1.0, 1.0, 1.0);                   //�հ���2_2�� �� ����
        glScalef(0.6, 0.1, 0.1);                    //�հ���2_2�� ũ�� ����
        glutWireCube(1.0);                          //�հ����� ���� ����
        glPopMatrix(); //d

        //�հ��� 2_3
        glTranslatef(0.3, 0.0, 0.0);            //�հ��� 2_2�� ���� ���� �̵�
        glRotatef((GLfloat)joint_2_3, 0, 0, 1); //�հ��� 2_2 ���κ��� �������� ȸ��
        glTranslatef(0.3, 0.0, 0.0);            //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
        glPushMatrix(); //e
        glColor3f(1.0, 1.0, 1.0);               //�հ��� 2_3�� �� ����
        glScalef(0.6, 0.1, 0.1);                //�հ��� 2_3�� ũ�� ����
        glutWireCube(1.0);                      //�հ����� ���� ����
        glPopMatrix();//e

        glPopMatrix();//2 //�հ���2 ��

        glPushMatrix();//3 //�հ���3�� ���� Ǫ��

        //�հ��� 3_1
        glTranslatef(1, 0, 0);                  //�ո��� ���� ���� �̵�
        glRotatef((GLfloat)joint_3_1, 0, 0, 1); //�ո� ���κ��� �������� ȸ��
        glTranslatef(0.3, 0, 0);                //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
        glPushMatrix(); //b
        glColor3f(1.0, 1.0, 1.0);               //�հ��� 3_1�� �� ����
        glScalef(0.6, 0.1, 0.1);                //�հ��� 3_1�� ũ�� ����
        glutWireCube(1.0);                      //�հ����� ���� ����
        glPopMatrix(); //b

        //�հ��� 3_2
        glTranslatef(0.3, 0, 0);                    //�հ��� 3_1�� ���� ���� �̵�
        glRotatef((GLfloat)joint_3_2, 0, 0, 0.1);   //�հ��� 3_1 ���κ��� �������� ȸ��
        glTranslatef(0.3, 0, 0);                    //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
        glPushMatrix(); //d               
        glColor3f(1.0, 1.0, 1.0);                   //�հ���3_2�� �� ����
        glScalef(0.6, 0.1, 0.1);                    //�հ���3_2�� ũ�� ����
        glutWireCube(1.0);                          //�հ����� ���� ����
        glPopMatrix(); //d

        //�հ��� 3_3
        glTranslatef(0.3, 0.0, 0.0);            //�հ��� 3_2�� ���� ���� �̵�
        glRotatef((GLfloat)joint_3_3, 0, 0, 1); //�հ���3_2 ���κ��� �������� ȸ��
        glTranslatef(0.3, 0.0, 0.0);            //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
        glPushMatrix(); //e
        glColor3f(1.0, 1.0, 1.0);               //�հ���3_2�� �� ����
        glScalef(0.6, 0.1, 0.1);                //�հ���3_2�� ũ�� ����
        glutWireCube(1.0);                      //�հ����� ���� ����
        glPopMatrix();//e

        glPopMatrix();//3 //�հ���3 ��

        glPopMatrix();//�ո�κ� ��        
   glPopMatrix(); //�׵���� ��
   
   glutSwapBuffers();
}

void MyReshape (int w, int h) {
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);  //�𵨺���
   glLoadIdentity();            //�׵���� ����
   glTranslatef (0.0, 0.0, -5.0);
}

void MyTimer1(int Value) {  //�հ��� 1 �����̱�
        joint_1_1 = (joint_1_1 + 5) % 60;
        joint_1_2 = (joint_1_2 + 5) % 60;
        joint_1_3 = (joint_1_3 + 5) % 60;

    glutPostRedisplay();
    if (active == 1) {  //active�� 1�϶� ���ȣ��
        glutTimerFunc(40, MyTimer1, 1);
    }
}
void MyTimer2(int Value) {  //�հ��� 2 �����̱�

    joint_2_1 = (joint_2_1 + 5) % 60;
    joint_2_2 = (joint_2_2 + 5) % 60;
    joint_2_3 = (joint_2_3 + 5) % 60;

    glutPostRedisplay();    

    if (active == 1) {  //active�� 1�϶� ���ȣ��
        glutTimerFunc(40, MyTimer2, 1);
    }
}
void MyTimer3(int Value) {
        joint_3_1 = (joint_3_1 + 5) % 60;
        joint_3_2 = (joint_3_2 + 5) % 60;
        joint_3_3 = (joint_3_3 + 5) % 60;
    
    glutPostRedisplay();
    if (active == 1) {  //active�� 1�϶� ���ȣ��
        glutTimerFunc(40, MyTimer3, 1);
    }
}

void MyKeyboard (unsigned char key, int x, int y) {
   switch (key) {
      case '1':
          glutTimerFunc(40, MyTimer1, 1);   //1�� ������ MyTimer1�� ȣ��
         break;
      case '2':
          glutTimerFunc(40, MyTimer2, 1);   //2�� ������ MyTimer2�� ȣ��
         break;
      case '3':
          glutTimerFunc(40, MyTimer3, 1);   //3�� ������ MyTimer3�� ȣ��
         break;
      case '4':
          glutTimerFunc(40, MyTimer1, 1);   //4�� ������ MyTimer1,2,3�� ȣ��
          glutTimerFunc(40, MyTimer2, 1);
          glutTimerFunc(40, MyTimer3, 1);
         break;
      case 'S':             //S�� ������ active������ ���� 1 �Ǵ� -1�� �ٲ�
          active *= -1;     //�����̰� �ִ� �հ����� ����ϴ�
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

    //�����ʹ�ư�� ������ ���,�Ȳ�ġ,�հ��� �������� ��� �ʱ� ������ ���ƿɴϴ�.
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
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);    //���÷��� GLUT_RGB���
   glutInitWindowSize (800, 600);                   //���÷��� ������ 800*600
   glutInitWindowPosition (100, 100);               //������ ��ġ 100*100
   glutCreateWindow("Robot Arm");                   //â �̸� Robot Arm
   MyInit ();   //�ʱ�ȭ
   glutDisplayFunc(MyDisplay); //display �̺�Ʈ
   glutReshapeFunc(MyReshape);  //â ũ�Ⱑ �������� �̺�Ʈ
   glutKeyboardFunc(MyKeyboard);    //Ű���� �̺�Ʈ
   glutMouseFunc(MyMouseClick); //���콺 �̺�Ʈ
   glutMainLoop();
   return 0;
}