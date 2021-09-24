//**********************************************************************
//                           HW#2-2 : GLU Modeling                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 23�� 
//                                                                      
// ���� ���� :      GL�� �̿��� ���� ���� �׸���                                                  
//					- - - - - - -                                         
// ��� :			����
//					glBegin(enum Mode); ~~ glEnd(); ���� �������� enum Mode��
//					����� ��, ��, �ﰢ��, �簢��, �ٰ����� �׸��� ����
//					�� ������ ���� ��� �� �־����ϴ�.
//					�˸��� enum Mode�� ~~�κп� glVertex2f() �� ��ǥ���� �־�
//					�� �־��� ������ 2�������� ǥ���Ͽ����ϴ�.
//					- - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

int MyList[4];

GLUquadricObj* Sphere = gluNewQuadric();
GLUquadricObj* Cylinder = gluNewQuadric();
GLUquadricObj* Disk = gluNewQuadric();
GLUquadricObj* PartialDisk = gluNewQuadric();


void MyCreateList() {
    MyList[0] = glGenLists(4); // Sphere
    MyList[1] = MyList[0] + 1; // Cylinder
    MyList[2] = MyList[1] + 1; // Disk
    MyList[3] = MyList[2] + 1; // Partial Disk

    //Sphere
    glNewList(MyList[0], GL_COMPILE);
    gluQuadricDrawStyle(Sphere, GLU_FILL);
    gluQuadricNormals(Sphere, GLU_SMOOTH);
    gluQuadricOrientation(Sphere, GLU_OUTSIDE);
    gluQuadricTexture(Sphere, GL_FALSE);
    gluSphere(Sphere, 1.5, 50, 50);
    glEndList();

    //Cylinder
    glNewList(MyList[1], GL_LINE);
    gluQuadricDrawStyle(Sphere, GLU_FILL);
    gluQuadricNormals(Sphere, GLU_SMOOTH);
    gluQuadricOrientation(Sphere, GLU_OUTSIDE);
    gluQuadricTexture(Sphere, GL_FALSE);
    gluCylinder(Cylinder, 1.0, 0.3, 2.0, 20, 8);
    glEndList();

    //Disk
    glNewList(MyList[2], GL_COMPILE);
    gluQuadricDrawStyle(Sphere, GLU_SILHOUETTE);
    gluQuadricNormals(Sphere, GLU_SMOOTH);
    gluQuadricOrientation(Sphere, GLU_OUTSIDE);
    gluQuadricTexture(Sphere, GL_FALSE);
    gluDisk(Disk, 0.5, 2.0, 20, 3);
    glEndList();

    //Partial Disk
    glNewList(MyList[3], GL_COMPILE);
    gluQuadricDrawStyle(Sphere, GLU_POINT);
    gluQuadricNormals(Sphere, GLU_SMOOTH);
    gluQuadricOrientation(Sphere, GLU_OUTSIDE);
    gluQuadricTexture(Sphere, GL_FALSE);
    gluPartialDisk(PartialDisk, 1.5, 3.0, 26, 13, 0, 0);
    glEndList();
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
    glCallList(MyList[0]);
    glCallList(MyList[1]);
    glCallList(MyList[2]);
    glCallList(MyList[3]);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);

  

    glutSwapBuffers();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("GLU Modeling");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(Reshape);
    MyCreateList();

    glutMainLoop();
    return 0;
}



