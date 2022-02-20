//**********************************************************************
//                           HW#3-4 : Menu Callback                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 9�� 29�� 
//                                                                      
// ���� ���� :      ���� �޴��� �����ؼ� ũ�Ⱑ �ٸ� ���� �׸��� �� �� �ٲٱ�                                                 
//					- - - - - - -                                         
// ��� :			������ �޴��� �� 10����
//					�� �׸��� -> ���� ��, ū ��
//					���� �׸��� -> ���� ����, ū ����
//					������ �׸��� -> ���� ������, ū ������
//					�� ĥ�ϱ� -> ����, �ʷ� �Ķ�
//					������
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>
float r = 0, g = 0.5, b = 0.5;	//rgb���� ��Ÿ�� ����
//� �޴��� ���õʿ� ���� true,false�� �ٲ� GLboolean Ÿ���� ������
GLboolean SSphere = true; GLboolean BSphere = false;
GLboolean STorus = false; GLboolean BTorus = false;
GLboolean STeapot = false; GLboolean BTeapot = false;	


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	if (SSphere) {	//SSphere=true �� ��
		glutWireSphere(0.5, 30, 30);	//���� ��
	}
	if (BSphere) {	//BSphere=true �� ��
		glutWireSphere(0.7, 30, 30);	//ū ��
	}
	if (STorus) {	//STorus=true �� ��
		glutWireTorus(0.1, 0.3, 20, 20); //���� ����
	}
	if (BTorus) {	//BTorus=true �� ��
		glutWireTorus(0.1, 0.5, 20, 20); //ū ����
	}
	if (STeapot) {	//STeapot=true �� ��
		glutWireTeapot(0.3); //���� ������
	}
	if (BTeapot) {	//BTeapot=true �� ��
		glutWireTeapot(0.5); //ū ������
	}
	glFlush(); //���
}
void MyMainMenu(int entryID) {	
	if (entryID == 5) exit(0);	//entryID�� 5�� �޴��� �������� �� ����
	glutPostRedisplay();	//���α׷� ������ ����Ǿ��� �� �����츦 ����ϵ��� �ϴ� �Լ�
}
void MySphereMenu(int entryID) {
	if (entryID == 1) {			//�޴����� Small Sphere�� ����� ��
		SSphere = true; BSphere = false;
		STorus = false; BTorus = false;
		STeapot = false; BTeapot = false;	//SSphere = true;
}
	else if (entryID == 2) {	//�޴����� Large Sphere�� ����� ��
		SSphere = false; BSphere = true;
		STorus = false; BTorus = false;
		STeapot = false; BTeapot = false;	//BSphere = true;
	}
	glutPostRedisplay();	//���α׷� ������ ����Ǿ��� �� �����츦 ����ϵ��� �ϴ� �Լ�
}
void MyTorusMenu(int entryID) {
	if (entryID == 1) {			//�޴����� Small Torus�� ����� ��
		SSphere = false; BSphere = false;
		STorus = true; BTorus = false;
		STeapot = false; BTeapot = false;	//STorus=true
	}
	else if (entryID == 2) {	//�޴����� Large Torus�� ����� ��
		SSphere = false; BSphere = false;
		STorus = false; BTorus = true;
		STeapot = false; BTeapot = false;	// BTorus = true;
	}
	glutPostRedisplay();	//���α׷� ������ ����Ǿ��� �� �����츦 ����ϵ��� �ϴ� �Լ�
}
void MyTeapotMenu(int entryID) {
	if (entryID == 1) {			//�޴����� Small Teapot�� ����� ��
		SSphere = false; BSphere = false;
		STorus = false; BTorus = false;
		STeapot = true; BTeapot = false;	//STeapot = true;
	}
	else if (entryID == 2) {	//�޴����� Large Teapot�� ����� ��
		SSphere = false; BSphere = false;
		STorus = false; BTorus = false;
		STeapot = false; BTeapot = true;	//BTeapot = true;
	}
	glutPostRedisplay();	//���α׷� ������ ����Ǿ��� �� �����츦 ����ϵ��� �ϴ� �Լ�
}
void MyColorMenu(int entryID) {
	if (entryID == 1) {				//�޴����� Red�� ����� ��
		r = 155; g = 0; b = 0; }	//Mydisplay���� glColor3f()�� rgb ���� (155,0,0) ���� ���� 
	else if (entryID == 2) {		//�޴����� Green�� ����� ��
		r = 0; g = 0.5; b = 0; }	//Mydisplay���� glColor3f()�� rgb ���� (0,0.5,0) ���� ����
	else if (entryID == 3) {		//�޴����� Blue�� ����� ��
		r = 0; g = 0; b = 155;		//Mydisplay���� glColor3f()�� rgb ���� (0,0,155) ���� ����
}
	glutPostRedisplay();	//���α׷� ������ ����Ǿ��� �� �����츦 ����ϵ��� �ϴ� �Լ�
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //��� ���
	glMatrixMode(GL_PROJECTION); //������� ����
	glLoadIdentity(); //��������� �׵���ķ�
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //���ú��� ����

	GLint MySphereID = glutCreateMenu(MySphereMenu);	//���� ����޴�
	glutAddMenuEntry("Small Sphere",1);	//���� ���� �׸��� �޴�, glutAddSubMenu���� MySphereID�κп� 1�� ����
	glutAddMenuEntry("Large Sphere",2); //���� ���� �׸��� �޴�, glutAddSubMenu���� MySphereID�κп� 2�� ����

	GLint MyTorusID = glutCreateMenu(MyTorusMenu);		//������ ����޴�
	glutAddMenuEntry("Small Torus", 1); //���� ������ �׸��� �޴�, glutAddSubMenu���� MyTorusID�κп� 1�� ����
	glutAddMenuEntry("Large Torus", 2); //���� ������ �׸��� �޴�, glutAddSubMenu���� MyTorusID�κп� 2�� ����

	GLint MyTeapotID = glutCreateMenu(MyTeapotMenu);	//�������� ����޴�
	glutAddMenuEntry("Small Teapot", 1); //���� �����ڸ� �׸��� �޴�, glutAddSubMenu���� MyTeapotID�κп� 1�� ����
	glutAddMenuEntry("Large Teapot", 2); //���� �����ڸ� �׸��� �޴�, glutAddSubMenu���� MyTeapotID�κп� 2�� ����

	GLint MyColorID = glutCreateMenu(MyColorMenu);		//���� ���� �޴�
	glutAddMenuEntry("Red", 1); //�������� ĥ�ϴ� �޴� glutAddSubMenu���� MyColorID�κп� 1�� ����
	glutAddMenuEntry("Greeen", 2); //�ʷϻ��� ĥ�ϴ� �޴� glutAddSubMenu���� MyColorID�κп� 2�� ����
	glutAddMenuEntry("Blue", 3); //�Ķ����� ĥ�ϴ� �޴� glutAddSubMenu���� MyColorID�κп� 3�� ����

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu); //���θ޴�
	glutAddSubMenu("Draw Sphere", MySphereID);	//����޴��� �ִ� �޴�
	glutAddSubMenu("Draw Torus", MyTorusID);	//����޴��� �ִ� �޴�
	glutAddSubMenu("Draw Teapot", MyTeapotID);	//����޴��� �ִ� �޴�
	glutAddSubMenu("Change Color",MyColorID);	//����޴��� �ִ� �޴�
	glutAddMenuEntry("Exit", 5);				//entryID�� 5�� �޴�

	glutAttachMenu(GLUT_RIGHT_BUTTON); //��Ŭ���ϸ� �޴��� �������� ��
}
int main(int argc, char** argv) {
	glutInit(&argc, argv); glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500); glutInitWindowPosition(0, 0);	//âũ�� 500 x 500 â��ġ 0,0
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}