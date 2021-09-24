#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

GLUquadricObj* Sphere = gluNewQuadric();
GLUquadricObj* Cylinder = gluNewQuadric();
GLUquadricObj* Disk = gluNewQuadric();
GLUquadricObj* PartialDisk = gluNewQuadric();

int MyListID; // DisplayList는 정수 ID에 의해 식별
// Display List 생성
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //배경색 흰색
	glMatrixMode(GL_PROJECTION); //투영행렬 선택
	glLoadIdentity(); //항등행렬
	glOrtho(-5, 5, -5, 5, 5, -5); //glortho 설정
}
void MyCreateList() {
	

	GLuint list[4]; //GLuint 형 크기 4인 배열
	list[0] = glGenLists(4);//Range 4중 첫번째 list[0]
	list[1] = list[0] + 1;	//Range 4중 첫번째 list[1]
	list[2] = list[1] + 1;	//Range 4중 첫번째 list[2]
	list[3] = list[2] + 1;	//Range 4중 첫번째 list[3]

	glNewList(list[0], GL_COMPILE);
	
	gluQuadricDrawStyle(Sphere, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정
	gluQuadricNormals(Sphere, GLU_SMOOTH); // 법선벡터 제어
	gluQuadricOrientation(Sphere, GLU_OUTSIDE); // 법선벡터 내부 및 외부 등과 같은 방향 지정
	gluQuadricTexture(Sphere, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
	gluSphere(Sphere, 1.5, 50, 50); // Sphere 생성

	/*glNewList(list[1], GL_COMPILE);
	glBegin()
	glNewList(list[2], GL_COMPILE);
	glNewList(list[3], GL_COMPILE);
	*/	glEndList();}void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 500, 500);
	// 컴파일이 완료된 리스트가 실제로 실행
	glCallList(MyListID);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); //displaymode RGB
	glutInitWindowSize(500, 500); //창의 크기 500 x 500
	glutInitWindowPosition(0, 0); //화면위치 (0,0)
	glutCreateWindow("GLU Modeling Test");
	MyInit(); //초기화


	glutDisplayFunc(MyDisplay);
	MyCreateList(); // Display List 생성
	glutMainLoop();
	return 0;
}