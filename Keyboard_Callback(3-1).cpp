//**********************************************************************
//                           HW#3-1 : Keyboard Callback(1)                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 29�� 
//                                                                      
// ���� ���� :      �Է¹��� Ű�� ���� �ش��ϴ� ��� ����                                                 
//					- - - - - - -                                         
// ��� :			A�� �Է��ϸ� �簢���� �������� 0.1�� �̵�
//                  F�� �Է��ϸ� �簢���� ���������� 0.1�� �̵�
//                  R�� �Է��ϸ� �簢���� �Ʒ������� 0.1�� �̵��ϰ� ���������� ����                 
//                  V�� �Է��ϸ� �簢���� ���� 0.1�� �̵�
//                  B�� �Է��ϸ� �簢���� �Ķ������� ����
// - - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
float horizon = 0,vertical = 0; //���μ��� ��ǥ�� ������ ������ ����
float r = 0.5, g = 0.5, b = 0.5; //RGB �ʱ�� ȸ���̹Ƿ� ��� 0.5
    
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //�÷����� �ʱ�ȭ
    glColor3f(r, g, b);             //���� �� (0.5,0.5,0.5) ȸ��
    glBegin(GL_POLYGON);            //GL_POLYGON, �ٰ��� �׸��� ����
    glVertex3f(-0.5 + horizon, -0.5 + vertical, 0.0);
    glVertex3f(0.5 + horizon, -0.5 + vertical, 0.0);
    glVertex3f(0.5 + horizon, 0.5 + vertical, 0.0);
    glVertex3f(-0.5 + horizon, 0.5 + vertical, 0.0);    //�� �װ��� ��ǥ����
    glEnd();                        //��
    glFlush();  //���
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    //A�� �Է��ϸ� x��ǥ�� horizon�� 0.1�� �پ� ������ �������� �̵�
    case 'A':
        horizon = horizon - 0.1; break;
    case 'a':
        horizon = horizon - 0.1; break;        
    //F�� �Է��ϸ� x��ǥ�� horizon�� 0.1�� �þ� ������ ���������� �̵�
    case 'F':
        horizon = horizon + 0.1; break;
    case 'f':
        horizon = horizon + 0.1; break;
    //R�� �Է��ϸ� x��ǥ�� horizon�� 0.1�� �پ� ������ �Ʒ��� �̵�, ���� �������� �ȴ�
    case 'r':
        r = 153; g = 0; b = 0; vertical = vertical - 0.1; break;
    case 'R':
        r = 153; g = 0; b = 0; vertical = vertical - 0.1;; break;
    //V�� �Է��ϸ� y��ǥ�� vertical�� 0.1�� �þ� ������ ���� �̵�
    case 'v':
        vertical = vertical + 0.1; break;
    case 'V':
        vertical = vertical + 0.1; break;
    //B�� �Է��ϸ� rgb�� (0,0,153)���� �ʱ�ȭ �Ǿ� �ִ�.
    case 'b':
        r = 0; g = 0; b = 153; break;
    case 'B':
        r = 0; g = 0; b = 153; break;
    }
    glutPostRedisplay(); //�����츦 �ٽ� �׸����� ��û
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); //���� ���
    glMatrixMode(GL_PROJECTION); //������� ����
    glLoadIdentity();   //���� ����� �׵���ķ� ����

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //���ú��� ����
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB); //���÷��� GLUT_RGB���
    glutInitWindowSize(300, 300); //300 X 300
    glutInitWindowPosition(0, 0); //������ ��ġ (0,0)
    glutCreateWindow("Keyboard Callback(1)");
    MyInit(); //�ʱ�ȭ
    glutDisplayFunc(MyDisplay); //display �̺�Ʈ
    glutKeyboardFunc(MyKeyboard); //Ű���� �̺�Ʈ

    glutMainLoop();
    return 0;
}