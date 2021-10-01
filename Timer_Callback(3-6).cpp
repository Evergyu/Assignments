//**********************************************************************
//                           HW#3-6 : Timer Callback                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 30�� 
//                                                                      
// ���� ���� :      Timer Callback�� �̿��� ���� ������ ����� ���� �ٲٸ� �����ϴ� ���� �׸���                                                
//					- - - - - - -                                         
// ��� :			Ŭ���� ���ߴ°�, ���� �ε����� ���ƿ��°�
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>

GLdouble Delta = 0.0; 
GLdouble r = 0, g = 0.5, b = 0.8;
GLint direction = 1;
GLboolean keep=true;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //�÷����� �ʱ�ȭ
    glBegin(GL_POLYGON);            //GL_POLYGON, �ٰ��� �׸��� ����
    glColor3f(r, g, b);             //���� �� (0,0.5,0.8) Ǫ����
    glVertex3f(-1.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, 0.5, 0.0);
    glVertex3f(-1.0 + Delta, 0.5, 0.0); //�� �װ��� ��ǥ����
    glEnd();    //��

    glutSwapBuffers(); //����ۿ� ������۸� ����
}
void MyTimer(int Value) {   
    if (direction==1) {     //���������� �����϶��� x��ǥ�� 0.1�� �����ϰ� 
        Delta = Delta + 0.1;    //���� Ǫ�����Դϴ�
        r = 0; g = 0.5; b = 0.8;
        if (Delta > 0.9) direction = -1; //ȭ����� ������ �ʵ��� ������ �����ϰ� ������ �ٲٵ��� �߽��ϴ�
    }
    else if (direction==-1) {   
        Delta = Delta - 0.1;    //�������� �����϶��� x��ǥ�� 0.1�� �����ϰ�
        r = 0.8; g = 0.5; b = 0.0;  //���� �������Դϵ�
        if (Delta < 0.1) direction = 1; //ȭ�� ���� ������ �ʵ��� ������ �����ϰ� ������ �ٲٵ��� �߽��ϴ�.
    }
    
    glutPostRedisplay(); //���α׷� ������ ����Ǿ��� �� �����츦 �ٽ� ����ϵ��� �ϴ� �Լ�
    if (keep) glutTimerFunc(400, MyTimer, 1); //keep�� true�� �� �����մϴ�. ���콺 ��Ŭ���� �ϸ� keep�� false�� �ٲ�� ����ϴ�.
    }

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {    //���콺�� Ŭ�������� �����̴� ������ ����ϴ�.
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {     
        keep = false;       //GLboolean �ڷ����� keep�� false�� �Ǹ鼭 ����ϴ�.
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
    glutCreateWindow("Timer Callback");
    MyInit();
    MyInit(); //�ʱ�ȭ
    glutDisplayFunc(MyDisplay); //display �̺�Ʈ
    glutMouseFunc(MyMouseClick); //���콺 �̺�Ʈ
    glutTimerFunc(40, MyTimer, 1); //Ÿ�̸� �̺�Ʈ
    glutMainLoop();
    return 0;
}