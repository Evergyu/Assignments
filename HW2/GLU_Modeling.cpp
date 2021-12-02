//**********************************************************************
//                           HW#2-2 : GLU Modeling                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 25�� 
//                                                                      
// ���� ���� :      GLU�� �̿��� ���� ���� �׸���                                                  
//					- - - - - - -                                         
// ��� :			���� Displaylist�� �Ҵ��ϱ� ���� ���������� ������ �־����ϴ�.
//                  �׸��� �� ����Ʈ���� �׸��� �׸� GLUquadricObj�� �����Ͽ����ϴ�.
//                  glNewList ~ glEndList ���̿��� ���� �׸��� �׸����� ���� ����Ʈ����
//                  MyDisplay���� glCallList �ϸ鼭 ������ݴϴ�.
//					- - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

int MyList[4]; //DisplayList�� �Ҵ��ϱ� ���� ������ ũ��4�� �迭 

GLUquadricObj* Sphere = gluNewQuadric();    //Sphere�� �׸��� ���� Quadric ����
GLUquadricObj* Cylinder = gluNewQuadric();  //Cylinder�� �׸��� ���� Quadric ����
GLUquadricObj* Disk = gluNewQuadric();      //Disk�� �׸��� ���� Quadric ����
GLUquadricObj* PartialDisk = gluNewQuadric();   //PartialDisk�� �׸��� ���� Quadric ����


void MyCreateList() {
    MyList[0] = glGenLists(4); // Sphere        //Display List ���̵� �Ҵ�
    MyList[1] = MyList[0] + 1; // Cylinder      //Display List ���̵� �Ҵ�
    MyList[2] = MyList[1] + 1; // Disk          //Display List ���̵� �Ҵ�
    MyList[3] = MyList[2] + 1; // Partial Disk  //Display List ���̵� �Ҵ�

    //Sphere
    glNewList(MyList[0], GL_COMPILE); //Display List ����, �������� �ʰ� ������ �Ϸ�� �����Դϴ�
    gluQuadricDrawStyle(Sphere, GLU_FILL); //������ �׸���
    gluQuadricNormals(Sphere, GLU_SMOOTH); //�������� ����
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //�������� ���� or �ܺ� ��������
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture ��ǥ ��� ����
    gluSphere(Sphere, 1.5, 50, 50); //Sphere ���� ������1.5 slices ���� 50x50
    glEndList();    //Display List�� ��

    //Cylinder
    glNewList(MyList[1], GL_COMPILE);   //Display List ����, �������� �ʰ� ������ �Ϸ�� �����Դϴ�
    gluQuadricDrawStyle(Cylinder, GLU_LINE); //������ �׸���
    gluQuadricNormals(Sphere, GLU_SMOOTH); //�������� ����
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //�������� ���� or �ܺ� ��������
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture ��ǥ ��� ����
    gluCylinder(Cylinder, 1, 0.5, 1.5, 20, 8); //Cylinder ���� �Ʒ������� 1, �������� 0.5 ���� 1.5
    glEndList();    //Display List�� ��                           slices 20�� stack 8��           

    //Disk
    glNewList(MyList[2], GL_COMPILE);   //Display List ����, �������� �ʰ� ������ �Ϸ�� �����Դϴ�
    gluQuadricDrawStyle(Disk, GLU_SILHOUETTE); //�Ƿ翧���� �׸���
    gluQuadricNormals(Sphere, GLU_SMOOTH); //�������� ����
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //�������� ���� or �ܺ� ��������
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture ��ǥ ��� ����
    gluDisk(Disk, 0.5, 2.0, 20, 3); //Disk ���� ���ʹ����� 0.5, ū�� ������ 2, Slices 20, ���ɿ� 3�� 
    glEndList();    //Display List�� ��

    //Partial Disk
    glNewList(MyList[3], GL_COMPILE);   //Display List ����, �������� �ʰ� ������ �Ϸ�� �����Դϴ�
    gluQuadricDrawStyle(PartialDisk, GLU_POINT); //������ �׸���
    gluQuadricNormals(Sphere, GLU_SMOOTH); //�������� ����
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //�������� ���� or �ܺ� ��������
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture ��ǥ ��� ����
    gluPartialDisk(PartialDisk, 1, 2.0, 26, 13, 0, 270); //PartialDisk ����, ���� ������ 1, ū�� ������ 2
    glEndList();    //Display List�� ��                                     Slices 26��, loops 13��, ���� 0~270 
}
void MyInit(void) {
    GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(1, 1, 1, 0, 0, 0.1, 0, 0, 1); //���� (1,1,1)�� �ִ� ī�޶� (0,0,0.1)�� �ٶ󺾴ϴ�. 
                                            //ī�޶��� �Ӹ��� ����(0,0,1)�� ����ŵ�ϴ�
    /*����Ʈ�� ȣ���ؼ� �����ϴ� �κ��Դϴ�. ������� Sphere, Cylinder, Disk, PartialDisk �Դϴ�*/
    glCallList(MyList[0]); //Sphere (��)
    //glCallList(MyList[1]); //Cylinder (��)
    //glCallList(MyList[2]); //Disk (�Ƿ翧)
    //glCallList(MyList[3]); //PartialDisk (��)
    
    glMatrixMode(GL_MODELVIEW); //������� ����
    glLoadIdentity(); //���� �𵨺� ����� �׵���ķ� �ʱ�ȭ
    glEnable(GL_LIGHTING); //������ Ȱ��ȭ
    glShadeModel(GL_SMOOTH);    //���º��� ����

    glutSwapBuffers();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); //����� â�� ����� �޾� 0,0���� �����Ͽ� �ʺ�, ���̸�ŭ�� â �籸��
    glMatrixMode(GL_PROJECTION); //������� ����
    glLoadIdentity();   //���� �𵨺� ����� �׵���ķ� �ʱ�ȭ

    glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //���ú��Ǹ� ������ ����� ������ �缳��
    glMatrixMode(GL_MODELVIEW); //������� ����
    glLoadIdentity();   //���� �𵨺� ����� �׵���ķ� �ʱ�ȭ
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(800, 600);   //âũ�� 800 * 600
    glutInitWindowPosition(0, 0);   //â ��ġ (0,0)
    glutCreateWindow("GLU Modeling"); //â �̸� GLU Modeling
    MyInit(); //�ʱ⼳���Լ�
    glutDisplayFunc(MyDisplay); //DisplayFunc
    glutReshapeFunc(Reshape);   //âũ�� ���� ��
    MyCreateList(); //DisplayList ����

    glutMainLoop(); //���η���
    return 0;
}



