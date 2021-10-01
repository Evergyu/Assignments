//**********************************************************************
//                           HW#3-5 : Idle Callback                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 30�� 
//                                                                      
// ���� ���� :      ȭ��ǥ ���⿡ ���� ������ �̵��ϰ� �����                                                 
//					- - - - - - -                                         
// ��� :			Idle Callback�� ����Ͽ� Ű������ ������� ȭ��ǥ�� ����
//                  �� �������� ������ �����̵��� �����߽��ϴ�.
//                  �̶� ������ ������� ���� ������ �ʽ��ϴ�
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>
float left = 0, right = 0, up = 0, down = 0; //���μ��� ��ǥ�� ������ ������ ����

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //�÷����� �ʱ�ȭ
    glColor3f(0, 0.5, 0.8);             //���� �� (0,0.3,0.8) Ǫ����
    glBegin(GL_POLYGON);            //GL_POLYGON, �ٰ��� �׸��� ����
    glVertex3f(-0.5 + left, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, 0.5 + up, 0.0);
    glVertex3f(-0.5 + left, 0.5 + up, 0.0);    //�� �װ��� ��ǥ����
    glEnd();                        //��
    glutSwapBuffers();  //����ۿ� ������۸� �����մϴ�
}

void MyIdleRight() {    //���������� 0.1�� �����Դϴ�
    if (right < 0.4) {
        left = left + 0.1; right = right + 0.1;
    }
    glutPostRedisplay();//���α׷� ������ ����Ǿ��� �� �����츦 �ٽ� ����ϵ��� �ϴ� �Լ�
}

void MyIdleLeft() {     //�������� 0.1�� �����Դϴ�
    if (left > -0.4) {
        left = left - 0.1; right = right - 0.1;
    }
    glutPostRedisplay();//���α׷� ������ ����Ǿ��� �� �����츦 �ٽ� ����ϵ��� �ϴ� �Լ�
}

void MyIdleUp() {      //�������� 0.1�� �����Դϴ�
    if (up < 0.4) {
        up = up + 0.1; down = down + 0.1;
    }
    glutPostRedisplay();
}

void MyIdleDown() {    //�Ʒ������� 0.1�� �����Դϴ�
    if (down > -0.4) {
        up = up - 0.1; down = down - 0.1;
    }
    glutPostRedisplay();//���α׷� ������ ����Ǿ��� �� �����츦 �ٽ� ����ϵ��� �ϴ� �Լ�
}

void MySpecial(int key, int x, int y) {
    switch (key) {
        /*������ ȭ��ǥ�� ������ MyIdleRight�� ȣ���մϴ�.*/
    case GLUT_KEY_RIGHT:
        glutIdleFunc(MyIdleRight);
        break;
    /*���� ȭ��ǥ�� ������ MyIdleLeft�� ȣ���մϴ�.*/
    case GLUT_KEY_LEFT:
        glutIdleFunc(MyIdleLeft);
        break;
    /*�Ʒ��� ȭ��ǥ�� ������ MyIdleDown�� ȣ���մϴ�.*/
    case GLUT_KEY_DOWN:
        glutIdleFunc(MyIdleDown);
        break;
    /*���� ȭ��ǥ�� ������ MyIdleUp�� ȣ���մϴ�.*/
    case GLUT_KEY_UP:
        glutIdleFunc(MyIdleUp);
        break;
     }
}
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); //���� ���
    glMatrixMode(GL_PROJECTION); //������� ����
    glLoadIdentity();   //���� ����� �׵���ķ� ����

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //���ú��� ����
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //���÷��̸�� 
    glutInitWindowSize(300, 300); //300 X 300
    glutInitWindowPosition(0, 0); //������ ��ġ (0,0)
    glutCreateWindow("Keyboard Callback(2)");
    MyInit(); //�ʱ�ȭ
    glutDisplayFunc(MyDisplay); //display �̺�Ʈ
    glutSpecialFunc(MySpecial); //Ű���� �̺�Ʈ

    glutMainLoop();
    return 0;
}