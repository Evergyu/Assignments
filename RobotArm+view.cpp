//**********************************************************************
//                           HW#5-2 : Robot Arms + view                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 10�� 28�� 
//                                                                      
// ���� ���� :      �հ��� 3���� ���� �κ� ���� ȸ������ ������������ ������ �ϱ�                                                
//					- - - - - - -                                         
// ��� :			ȭ��ǥ ��,��,��,�츦 �����ø� �� �������� ���� ȸ���մϴ�.
//                  ���ñ� ���ϵ��� 4���� �ߴ� ��ɵ��� ��� �������Ƚ��ϴ�.
//                  - - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>           //���� ����� ���� �߰��� �������

const double PI = 3.1415926;                    //���̰�
static float angle_height = 0,angle_flat=0;     //����
static float Cx = 0, Cy = 0, Cz = 0;            //ī�޶� ��ġ

void MyInit(void) {
   glClearColor (0.0, 0.0, 0.0, 1.0);
   glShadeModel (GL_FLAT);
}

void drawArm() {
    glPushMatrix(); //�׵���� Ǫ�� 
    glTranslatef(-3.0, 1.0, 0.0);	//����κ��� ���ϴ� ��ġ�� x������ -3��ŭ �̵���ŵ�ϴ�.
    glRotatef(-50, 0.0, 0.0, 1.0); // ����κ��� �������� -30�� ȸ����ŵ�ϴ�
    glTranslatef(1.0, 0.0, 0.0);	// ȸ�������� �̿��� �κ��� ���κп� ��ġ�ϵ��� x������ 1��ŭ �̵�
    glPushMatrix();	//���� Ǫ��
    glColor3f(1.0, 1.0, 1.0);   //���Ⱥκ� ������
    glScalef(2.0, 0.4, 1.0);   //���Ⱥκ� ũ�⼳�� 
    glutWireCube(1.0);         //���Ⱥκ� ��������
    glPopMatrix(); //���Ȼ��� �� ���ÿ��� ��

    glTranslatef(1.0, 0.0, 0.0);	// �Ȳ�ġ�κ��� ���߱� ���� x������ 1��ŭ �̵�
    glRotatef(30, 0.0, 0.0, 1.0); // �Ȳ�ġ�κ��� �������� 30����ŭ ȸ��
    glTranslatef(1.0, 0.0, 0.0);	// ȸ�������� �̿��� �κ��� ���κп� ��ġ�ϵ��� x������ 1��ŭ �̵��մϴ�
    glPushMatrix();	//�Ʒ��� Ǫ��
    glColor3f(1.0, 1.0, 1.0);   //�Ʒ��� �� ����
    glScalef(2.0, 0.4, 1.0);   //�Ʒ��� ũ�� ����
    glutWireCube(1.0);          //�Ʒ��� ����
    glPopMatrix(); //�Ʒ��� ��

    glPushMatrix(); //1 ������� ���� �ո�κ��� Ǫ���� �ݴϴ�.
    //�հ���1_1
    glTranslatef(1, 0, 0); //�ո�κ��� ���߱� ���� x�ุŭ 1 �̵�
    glRotatef(-60, 0, 1, 0);    //�հ��� ��������
    glRotatef(20, 0, 0, 1); //�ո�κ��� �������� ȸ��
    glTranslatef(0.3, 0, 0);    //������ ũ�⸦ (0.6,0.1,0.1)�� �� ���̹Ƿ� �� ���� 0.3�� �̵����� ȸ���࿡ ���κ��� ��ġ�ϵ��� �̵�
    glPushMatrix(); //b
    glColor3f(1.0, 1.0, 1.0);   //�հ���1_1�� �� ����
    glScalef(0.6, 0.1, 0.1);    //�հ���1_1�� ũ�� ����
    glutWireCube(1.0);          //�հ����� ���� ����
    glPopMatrix(); //b

    //�հ��� 1_2
    glTranslatef(0.3, 0, 0);                //�հ��� 1_1�� ���� ���� �̵�
    glRotatef(20, 0, 0, 0.1);//�հ���1_1 ���κ��� �������� ȸ��
    glTranslatef(0.3, 0, 0);                //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�    
    glPushMatrix(); //d               
    glColor3f(1.0, 1.0, 1.0);           //�հ���1_2�� �� ����
    glScalef(0.6, 0.1, 0.1);            //�հ���1_2�� ũ�� ����
    glutWireCube(1.0);                  //�հ����� ���� ����
    glPopMatrix(); //d

    //�հ��� 1_3
    glTranslatef(0.3, 0.0, 0.0);            //�հ��� 1_2�� ���� ���� �̵�
    glRotatef(20, 0, 0, 1); //�հ���1_1 ���κ��� �������� ȸ��
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
    glRotatef(20, 0, 0, 1); //�ո� ���κ��� �������� ȸ��
    glTranslatef(0.3, 0, 0);                //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
    glPushMatrix(); //b
    glColor3f(1.0, 1.0, 1.0);               //�հ���2_1�� �� ����
    glScalef(0.6, 0.1, 0.1);                //�հ���2_1�� ũ�� ����
    glutWireCube(1.0);                      //�հ����� ���� ����
    glPopMatrix(); //b

    //�հ��� 2_2
    glTranslatef(0.3, 0, 0);                    //�հ��� 2_1�� ���� ���� �̵�
    glRotatef(20, 0, 0, 0.1);   //�հ��� 2_1 ���κ��� �������� ȸ��
    glTranslatef(0.3, 0, 0);                    //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
    glPushMatrix(); //d               
    glColor3f(1.0, 1.0, 1.0);                   //�հ���2_2�� �� ����
    glScalef(0.6, 0.1, 0.1);                    //�հ���2_2�� ũ�� ����
    glutWireCube(1.0);                          //�հ����� ���� ����
    glPopMatrix(); //d

    //�հ��� 2_3
    glTranslatef(0.3, 0.0, 0.0);            //�հ��� 2_2�� ���� ���� �̵�
    glRotatef(20, 0, 0, 1); //�հ��� 2_2 ���κ��� �������� ȸ��
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
    glRotatef(60, 0, 1, 0);
    glRotatef(20, 0, 0, 1); //�ո� ���κ��� �������� ȸ��
    glTranslatef(0.3, 0, 0);                //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
    glPushMatrix(); //b
    glColor3f(1.0, 1.0, 1.0);               //�հ��� 3_1�� �� ����
    glScalef(0.6, 0.1, 0.1);                //�հ��� 3_1�� ũ�� ����
    glutWireCube(1.0);                      //�հ����� ���� ����
    glPopMatrix(); //b

    //�հ��� 3_2
    glTranslatef(0.3, 0, 0);                    //�հ��� 3_1�� ���� ���� �̵�
    glRotatef(20, 0, 0, 0.1);   //�հ��� 3_1 ���κ��� �������� ȸ��
    glTranslatef(0.3, 0, 0);                    //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
    glPushMatrix(); //d               
    glColor3f(1.0, 1.0, 1.0);                   //�հ���3_2�� �� ����
    glScalef(0.6, 0.1, 0.1);                    //�հ���3_2�� ũ�� ����
    glutWireCube(1.0);                          //�հ����� ���� ����
    glPopMatrix(); //d

    //�հ��� 3_3
    glTranslatef(0.3, 0.0, 0.0);            //�հ��� 3_2�� ���� ���� �̵�
    glRotatef(20, 0, 0, 1); //�հ���3_2 ���κ��� �������� ȸ��
    glTranslatef(0.3, 0.0, 0.0);            //������ ���κ��� ȸ���࿡ ��ġ�ϵ��� �̵�
    glPushMatrix(); //e
    glColor3f(1.0, 1.0, 1.0);               //�հ���3_2�� �� ����
    glScalef(0.6, 0.1, 0.1);                //�հ���3_2�� ũ�� ����
    glutWireCube(1.0);                      //�հ����� ���� ����
    glPopMatrix();//e

    glPopMatrix();//3 //�հ���3 ��

    glPopMatrix();//�ո�κ� ��        
    glPopMatrix(); //�׵���� ��
}

void MyDisplay(void) {
   glPushMatrix();                          //���� ���� ��Ǫ��
   glClear (GL_COLOR_BUFFER_BIT);           
   Cx = 5 * cos(angle_flat * PI / 180);     //ī�޶� �ʱ� ��ġ x��ǥ
   Cy = 5 * sin(angle_height * PI / 180);   //ī�޶� �ʱ� ��ġ y��ǥ
   Cz = 5 * sin(angle_flat * PI / 180);     //ī�޶� �ʱ� ��ġ z��ǥ
   gluLookAt(Cx, Cy, Cz,                    //gluLookAt���� ����,���� ����
       -1, 0, 0,                            //(Cx,Cy,Cz) ��ġ���� (-1,0,0)�� �ٶ󺾴ϴ�
       0.0, 1.0, 0.0);
   drawArm();                             //�ȱ׸��� �Լ�

   glPopMatrix();                         //��
   glutSwapBuffers();                   
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);  //�𵨺���
    
    glLoadIdentity();            //�׵���� ����
}
void MySpecial(int key, int x, int y) {
    switch (key) {
        
    case GLUT_KEY_LEFT:                         //����Ű�� ������ �������� 360�� ���� 
        if (angle_flat == 360 || angle_flat == -360) angle_flat = 0;
        else angle_flat -= 10;                  //���ǿ� ���� ���� ��ȭ
        Cx = 5 * cos(angle_flat * PI / 180);    //�� ��ǥ���
        Cz = 5 * sin(angle_flat * PI / 180);    
    break;
    
    case GLUT_KEY_RIGHT:                        //����Ű�� ������ ���������� 360�� ����
        if (angle_flat == 360 || angle_flat == -360) angle_flat = 0;
        else angle_flat += 10;                  //���ǿ� ���� ���� ��ȭ
        Cx = 5 * cos(angle_flat * PI / 180);    //�� ��ǥ���
        Cz = 5 * sin(angle_flat *PI/180);
        break;
    
    //���Ʒ� �����̴� ���� ���� xz��ǥ��鿡�� ó�� 360�� ���� ���� �����ߴµ� �װ��� �ȵǾ� ����������
    //angle_height�� ������ 360������ ������ ���Ʒ��� 180�� �����̸� ������ �� �ֵ��� �����߽��ϴ�.
    case GLUT_KEY_UP:                           //�� Ű�� ������ ���Ʒ��� 180��(���� 90 �Ʒ��� 90) ����
        if (angle_height == 360 || angle_height == -360) angle_height = 0;
        else angle_height += 10;                //���ǿ� ���� ���� ��ȭ
        Cy = 5 * sin(angle_height * PI / 180);  //�� ��ǥ���
        break;
    case GLUT_KEY_DOWN:                         //�Ʒ� Ű�� ������ �Ʒ����� 180��(���� 90 �Ʒ��� 90) ����
        if (angle_height == 180 || angle_height == -180) angle_height = 0;
        else angle_height -= 10;                //���ǿ� ���� ���� ��ȭ
        Cy = 5 * sin(angle_height * PI / 180);  //�� ��ǥ���
        break;
    default:
        break;
    }
    glutPostRedisplay();
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

   glutSpecialFunc(MySpecial);  //Ư��Ű �̺�Ʈ
   glutMainLoop();
   return 0;
}