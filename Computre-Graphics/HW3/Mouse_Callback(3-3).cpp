//**********************************************************************
//                           HW#3-3 : Mouse Callback(1)                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 29�� 
//                                                                      
// ���� ���� :      ���ʸ��콺�� ������ ���콺Ŭ���� �����ϵ��� �Լ� ����                                                 
//					- - - - - - -                                         
// ��� :			���� ���콺�� Ŭ���ϸ� �� ���� x��ǥ�� 0.1�� ���������� �̵��մϴ�
//                  ������ ���콺�� Ŭ���ϸ� �� ���� �����ֽ��ϴ�.
//                  - - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
GLdouble left = 0, right = 0, up = 0, down = 0; //���μ��� ��ǥ�� ������ ������ ����
GLdouble r = 0.5, g = 0.5, b = 0.5; //RGB �ʱ�� ȸ���̹Ƿ� ��� 0.5
GLboolean keep = true;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //�÷����� �ʱ�ȭ
    glColor3f(r, g, b);             //���� �� (0.5,0.5,0.5) ȸ��
    glBegin(GL_POLYGON);            //GL_POLYGON, �ٰ��� �׸��� ����
    glVertex3f(-0.5 + left, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, -0.5 + down, 0.0);
    glVertex3f(0.5 + right, 0.5 + up, 0.0);
    glVertex3f(-0.5 + left, 0.5 + up, 0.0);    //�� �װ��� ��ǥ����
    glEnd();                        //��
    glFlush();  //���
}

/*keep�� true�� �� 500msec ���� 0.1�� �̵��ϴµ�
  ��Ŭ�����ؼ� keep�� false�� �Ǹ� �������� ����ϴ�.*/
void MyTimer(int Value) {
    if (keep) {
        if (right < 0.5) {
            left = left + 0.1; right = right + 0.1;
        }
    }
    glutTimerFunc(500, MyTimer, 1);
    glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

    //���ʹ�ư�� ������ �� ���� x��ǥ�� ���������� �̵��մϴ�
    //�����ʺ��� �հ� ���������� ���մϴ�.
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        glutTimerFunc(500, MyTimer, 1); //Ÿ�̸� �̺�Ʈ  
    }
    //������ ��ư�� ������ GLboolean Ÿ���� ������ false�� ���ϸ� �����ֽ��ϴ�.
    if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN) {
        keep = false;
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
    glutInitDisplayMode(GLUT_RGB); //���÷��� GLUT_RGB���
    glutInitWindowSize(300, 300); //300 X 300
    glutInitWindowPosition(0, 0); //������ ��ġ (0,0)
    glutCreateWindow("Mouse Callback(1)");
    MyInit(); //�ʱ�ȭ
    glutDisplayFunc(MyDisplay); //display �̺�Ʈ
    glutMouseFunc(MyMouseClick); //Mouse �̺�Ʈ

    glutMainLoop();
    return 0;
}