//**********************************************************************
//                           HW#6-1 : ����Ʈ ��ȯ                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 11�� 3�� 
//                                                                      
// ���� ���� :      â�� ũ�� ��ȭ���� ���� ��׷����� �ʵ��� �ϰ�
//                  Ű����, ���콺�ݹ����� ������ȯ                                                
//					- - - - - - -                                         
// ��� :			ȭ��ǥ ��,��,��,�츦 �����ø� ī�޶��� ��ġ�� �Ű� ������ �ٲ�� �߽��ϴ�.
//                  �׸��� Reshape �ݹ��� ����� â�� ũ�⺯ȭ�� �°�
//                  ȭ���� �ٲ�� �߽��ϴ�.
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>

int Width, Height;
GLfloat AspectRatio=1.0;    //glPerspective�� ���� ��Ⱦ�� ����
GLdouble Cx_O = 0, Cy_O = 0, Cx_P = 0, Cy_P = 0;    //ī�޶� ������ ���� ����

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);            
    glLoadIdentity( );

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);    //�⺻ glOrtho
    glMatrixMode(GL_MODELVIEW);                 //��Ʈ�������
    glLoadIdentity( );
}

void DrawScene() {
    glColor3f(0.7, 0.7, 0.7);           //����
    glPushMatrix();
        glTranslatef(0.0, -1.0, 0.0);   //��ġ �̵�
        glBegin(GL_QUADS);
            glVertex3f(2.0, 0.0, 2.0);  //�� �װ�
            glVertex3f(2.0, 0.0, -2.0);
            glVertex3f(-2.0, 0.0, -2.0);
            glVertex3f(-2.0, 0.0, 2.0);
        glEnd();
    glPopMatrix();                      //�ٴڸ�

    glColor3f(0.3, 0.3, 0.7);           //����
    glPushMatrix();                     
        glTranslatef(0.0, 0.0, -0.5);   //��ġ �̵�
        glutWireTeapot(1.0);            //������ �׸���
    glPopMatrix();
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glViewport(0, 0, Width/2, Height/2);                //�����ϴ� ����
    
    glPushMatrix();
    gluLookAt(0.0 + Cx_O, 0.0 + Cy_O, 1.0 , 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  //���� (0,Cx_O,Cy_O) ����(1,0,0) ī�޶� ������(0,1,0)
        DrawScene();            
    glPopMatrix();
    
    glViewport(Width/2, 0, Width/2, Height/2);          //�������ϴ� ����
    glPushMatrix();
        gluLookAt(1.0, 0.0+Cy_O, 0.0 + Cx_O, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //���� (1.0, 0.0+Cy_O, 0.0 + Cx_O) ����(0,0,0) ī�޶� ������(0,1,0)
        DrawScene();
    glPopMatrix();
    
    glViewport(0, Height/2, Width/2, Height/2);         //���ʻ�� ����
    glPushMatrix();
        gluLookAt(0.0 + Cx_O, 1.0 , 0.0+Cy_O,   0.0, 0.0, 0.0,   0.0, 0.0, -1.0); //���� (0.0 + Cx_O, 1.0 , 0.0+Cy_O) ����(0,0,0) ī�޶� ������(0,0,-1)
        DrawScene();
    glPopMatrix();
    
    glViewport(Width/2, Height/2, Width/2, Height/2);   //�����ʻ�� ����
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluPerspective(30, AspectRatio, 0.5, 50.0);     //���� 30 ��Ⱦ�� AspectRatio (Reshape�ݹ鿡�� ����), 0.5~50.0
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            gluLookAt(5.0+Cx_P, 5.0+Cy_P, 5.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //���� (5.0+Cx_P, 5.0+Cy_P, 5.0) ����(0,0,0) ī�޶� ������(0,1,0)
            DrawScene();
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}

void MyReshape(int w, int h) {
    Width = w;
    Height = h;                                             // ���μ��� �ʱ�ȭ
    glViewport(0, 0, Width, Height);						// ���� �����ʱ�ȭ

    GLfloat WidthFactor = (GLfloat)Width / (GLfloat)500;
    GLfloat HeightFactor = (GLfloat)Height / (GLfloat)500;

    glMatrixMode(GL_PROJECTION);						// �������� ��Ʈ���� ����
    glLoadIdentity();									// �׵���ķ� ����

    // Calculate The Aspect Ratio Of The Window
    glOrtho(-2.0 * WidthFactor, 2.0 * WidthFactor,
        -2.0 * HeightFactor, 2.0 * HeightFactor, 0.5, 5.0); //�þ ���̴�� glOrtho ���ΰ��
    AspectRatio = (GLfloat)Width / (GLfloat)Height;       //��Ⱦ�� �����ϱ����� gluPersepctive�� ��Ⱦ�� ���� AspectRatio �ʱ�ȭ
}

//glOrtho�� ǥ���� �κа� glPerspective���� ǥ���� �κ��� ī�޶� �̵��� �� �ִ� �ִ� �Ÿ��� �ٸ��ϴ�.
//�׷��� if������ �ΰ��� �����ؼ� ����������ϴ�. �ʹ� �����ϰ� �������� �ʴ´ٰ� �����ϴ� ������ �����߽��ϴ�. 
void MySpecial(int key, int x, int y) {
    switch (key) {

    case GLUT_KEY_LEFT:                         //����Ű�� ������ �������� ���ϴ�.
        if(Cx_O>-4) Cx_O -= 0.1;
        if (Cx_P > -9) Cx_P -= 0.1;
        break;

    case GLUT_KEY_RIGHT:                        //����Ű�� ������ ���������� ���ϴ�
        if(Cx_O<4) Cx_O += 0.1;
        if (Cx_P < 4) Cx_P += 0.1;
        break;

        case GLUT_KEY_UP:                           //�� Ű�� ������ �������� ���ϴ�
        if(Cy_O<3) Cy_O += 0.1;
        if (Cy_P < 10) Cy_P += 0.1;
        break;
    case GLUT_KEY_DOWN:                         //�Ʒ� Ű�� ������ �Ʒ������� ���ϴ�
        if(Cy_O>-3)Cy_O -= 0.1;
        if (Cy_P > -10) Cy_P -= 0.1;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    Width = 500;
    Height = 500;                                   
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGBA);
    glutInitWindowSize(Width, Height);              //âũ�� 500*500
    glutInitWindowPosition(0, 0);                   //â��ġ (0.0)
    glutCreateWindow("Viewpory Partition");         //â�̸� Viewpory Paritiion
    MyInit();
    glutDisplayFunc(MyDisplay);                     //���÷����ݹ�
    glutReshapeFunc(MyReshape);                     //�������� �ݹ�
    glutSpecialFunc(MySpecial);                     //Ű���� Ư��Ű �ݹ�
    glutMainLoop();
    return 0;
}
