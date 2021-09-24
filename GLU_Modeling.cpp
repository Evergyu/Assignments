#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

GLUquadricObj* Sphere = gluNewQuadric();
GLUquadricObj* Cylinder = gluNewQuadric();
GLUquadricObj* Disk = gluNewQuadric();
GLUquadricObj* PartialDisk = gluNewQuadric();

int MyListID; // DisplayList�� ���� ID�� ���� �ĺ�
// Display List ����
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //���� ���
	glMatrixMode(GL_PROJECTION); //������� ����
	glLoadIdentity(); //�׵����
	glOrtho(-5, 5, -5, 5, 5, -5); //glortho ����
}
void MyCreateList() {
	

	GLuint list[4]; //GLuint �� ũ�� 4�� �迭
	list[0] = glGenLists(4);//Range 4�� ù��° list[0]
	list[1] = list[0] + 1;	//Range 4�� ù��° list[1]
	list[2] = list[1] + 1;	//Range 4�� ù��° list[2]
	list[3] = list[2] + 1;	//Range 4�� ù��° list[3]

	glNewList(list[0], GL_COMPILE);
	
	gluQuadricDrawStyle(Sphere, GLU_FILL); // Quadric�� ���� ���ϴ� Draw Style ����
	gluQuadricNormals(Sphere, GLU_SMOOTH); // �������� ����
	gluQuadricOrientation(Sphere, GLU_OUTSIDE); // �������� ���� �� �ܺ� ��� ���� ���� ����
	gluQuadricTexture(Sphere, GL_FALSE); // Texture ��ǥ ����� �������� ���� ����
	gluSphere(Sphere, 1.5, 50, 50); // Sphere ����

	/*glNewList(list[1], GL_COMPILE);
	glBegin()
	glNewList(list[2], GL_COMPILE);
	glNewList(list[3], GL_COMPILE);
	*/	glEndList();}void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 500, 500);
	// �������� �Ϸ�� ����Ʈ�� ������ ����
	glCallList(MyListID);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); //displaymode RGB
	glutInitWindowSize(500, 500); //â�� ũ�� 500 x 500
	glutInitWindowPosition(0, 0); //ȭ����ġ (0,0)
	glutCreateWindow("GLU Modeling Test");
	MyInit(); //�ʱ�ȭ


	glutDisplayFunc(MyDisplay);
	MyCreateList(); // Display List ����
	glutMainLoop();
	return 0;
}