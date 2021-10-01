//**********************************************************************
//                           HW#3-2 : Keyboard Callback(1)                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 29�� 
//                                                                      
// ���� ���� :      �Է¹��� Ű�� ���� �ش��ϴ� ��� ����                                                 
//					- - - - - - -                                         
// ��� :			<-�� �Է��ϸ� �簢���� �������� 0.1�� �̵�
//                  ->�� �Է��ϸ� �簢���� ���������� 0.1�� �̵�
//                  �� ����Ű�� �Է��ϸ� �簢���� �Ʒ������� 0.1�� �̵��ϰ� ���������� ����                 
//                  �Ʒ� ����Ű�� �Է��ϸ� �簢���� ���� 0.1�� �̵�
//                  Page Down�� ������ ���
//                  Page Up�� ������ Ȯ��
//                  �ε� ���⼭ ������ �����츦 ����� �ʰ� �߽��ϴ�.
// - - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
GLdouble left=0, right = 0 , up = 0, down = 0; //���μ��� ��ǥ�� ������ ������ ����
GLdouble r = 0.5, g = 0.5, b = 0.5; //RGB �ʱ�� ȸ���̹Ƿ� ��� 0.5

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

void MySpecial(int key, int x, int y) {
    switch (key) {
        /*������ ȭ��ǥ�� ������ x��ǥ�� 0.1�� �þ��
          ȭ�鿡 ����� �ʵ��� ������ �����߽��ϴ�*/
    case GLUT_KEY_RIGHT:
        if (right < 0.5) {
            left = left + 0.1; right = right + 0.1;
        }
            break;
        /*���� ȭ��ǥ�� ������ x��ǥ�� 0.1�� �پ���
          ȭ�鿡 ����� �ʵ��� ������ �����߽��ϴ�*/
    case GLUT_KEY_LEFT:
        if (left > -0.5) {
            left = left - 0.1; right = right - 0.1;
        }
        
        break;
        /*�Ʒ��� ȭ��ǥ�� ������ x��ǥ�� 0.1�� �پ���
          ȭ�鿡 ����� �ʵ��� ������ �����߽��ϴ�*/
    case GLUT_KEY_DOWN:
        if (down > -0.5) {
            up = up - 0.1; down = down - 0.1;
        }
        break;
        /*���� ȭ��ǥ�� ������ x��ǥ�� 0.1�� �þ��
          ȭ�鿡�� ����� �ʵ��� ������ �����߽��ϴ�*/
    case GLUT_KEY_UP:
        if (up < 0.5) {
            up = up + 0.1; down = down + 0.1;
        }break;
        /*PAGE_DOWN�� ������ �� ��ǥ�� ���� �߽��� ���� �پ���
          ȭ�鿡�� ����� �ʵ��� ������ �����߽��ϴ�*/
    case GLUT_KEY_PAGE_DOWN:
        if (left < 0.5 && right>-0.5 && down<0.5 && up > -0.5) {
            left += 0.1; right -= 0.1; up -= 0.1; down += 0.1;
        }
        break;
        /*PAGE_DOWN�� ������ �� ��ǥ�� ���� �߽ɿ� �ݴ븦 ���� �پ���
          ȭ�鿡�� ����� ���������� �ʰ� ������ �����߽��ϴ�*/
    case GLUT_KEY_PAGE_UP:
        if (left > -0.5 && right<0.5 && down>-0.5 &&  up < 0.5) {
            left -= 0.1; right += 0.1; up += 0.1; down -= 0.1; break;
        }
    default:
        break;
    }
    glutPostRedisplay(); //���α׷� ������ ����Ǿ��� �� �����츦 ����ϵ��� �ϴ� �Լ�
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
    glutCreateWindow("Keyboard Callback(2)");
    MyInit(); //�ʱ�ȭ
    glutDisplayFunc(MyDisplay); //display �̺�Ʈ
    glutSpecialFunc(MySpecial); //Ű���� �̺�Ʈ

    glutMainLoop();
    return 0;
}