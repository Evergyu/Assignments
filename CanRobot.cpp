//**********************************************************************
//                           HW#4-2 : Robot Arms                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 10�� 14�� 
//                                                                      
// ���� ���� :      ���� �κ� �����                                                
//					- - - - - - -                                         
// ��� :			�޴�1. �Ӹ������̱�
//					�޴�2. ������ �����̱�
//					�޴�3. ������ �����̱�
//					�޴�4. �����ٸ� �����̱�
//					�޴�5. ���ʴٸ� �����̱�
//					S ������ : ���� 
//					- - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // ���ο� Quadric ����

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void body() {
	glPushMatrix(); //�׵���� Ǫ��
	glColor3f(0, 0.5, 0.6);
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(50, 0, 0, 1);
	gluCylinder(qobj, 0.6, 0.6, 1.5, 20, 20);

	glPopMatrix(); //�׵���� ��
}
void Right_Arm() {
	//����
	glColor3f(0, 100, 255);
	glPushMatrix();
		glTranslatef(0.6, 1.5, 0);
		glRotatef(90, 0, 1, 0);
		glRotatef(60, 1, 0, 0);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//�Ʒ���
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0.6, 0.5, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//��
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0.5, 0.35, 0);
	glScalef(0.2, 0.2, 0.2);
	glutWireSphere(1, 10, 10);
	glPopMatrix();
}
void Left_Arm() {
	//����
	glColor3f(0, 100, 255);
	glPushMatrix();
	glTranslatef(-0.6, 1.5, 0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(60, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//�Ʒ���
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(-0.6, 0.5, 0);
	glRotatef(-90, 0, 1, 0);
	glRotatef(-60, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//��
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(-0.5, 0.35, 0);
	glScalef(0.2, 0.2, 0.2);
	glutWireSphere(1, 10, 10);
	glPopMatrix();
}
void Right_Leg() {
	//���ٸ�
	glPushMatrix();
	glColor3f(1.0, 0, 0.5);
	glTranslatef(0.3, 0, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();
	
	//�Ʒ��ٸ�
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(0.3, -0.6, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.2, 0.5);
	glTranslatef(0.4, -1.2, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);
	glPopMatrix();
}
void Left_Leg(){
	//���ٸ�
	glPushMatrix();
	glColor3f(1.0, 0, 0.5);
	glTranslatef(-0.3, 0, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//�Ʒ��ٸ�
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.5);
	glTranslatef(-0.3, -0.6, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);
	glPopMatrix();

	//��
	glPushMatrix();
	glColor3f(0.0, 0.2, 0.5);
	glTranslatef(-0.4, -1.2, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);
	glPopMatrix();
}
void neck() {
	glPushMatrix();
	glColor3f(0, 0.5, 1);
	glTranslatef(0, 1.7, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 5);
	glPopMatrix();
}
void head() {
	glPushMatrix();
	glColor3f(1, 0.6, 0.5);
	glTranslatef(0, 2.5, 0);
	glRotatef(90, 1, 0, 0);
	gluCylinder(qobj, 0.5, 0.6, 0.8, 20, 5);
	glPopMatrix();

	//�����ʴ�
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(1.0,20,8);
	glPopMatrix();

	//������ ������
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(0.3, 20, 8);
	glPopMatrix();

	//���ʴ�
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(-0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(1.0, 20, 8);
	glPopMatrix();

	//���� ������
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.2, 2.2, 0);
	glScalef(0.1, 0.1, 0.1);
	glutSolidSphere(0.3, 20, 8);
	glPopMatrix();
}
void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_LINE);
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0); //��������
	body();	//��
	Right_Arm();	//������
	Left_Arm();	//����
	Right_Leg();	//�����ٸ�
	Left_Leg();	//���ʴٸ�
	neck();	//��
	head(); //�Ӹ�

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);  //�𵨺���
	
	glLoadIdentity();            //�׵���� ����
	glTranslatef(0.0, 0.0, -5.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //���÷��� GLUT_RGB���
	glutInitWindowSize(800, 1200);                   //���÷��� ������ 800*1200
	glutInitWindowPosition(100, 100);               //������ ��ġ 100*100
	glutCreateWindow("Can Robot");                   //â �̸� Can Robot
	MyInit();   //�ʱ�ȭ
	glutDisplayFunc(MyDisplay); //display �̺�Ʈ
	glutReshapeFunc(MyReshape);  //â ũ�Ⱑ �������� �̺�Ʈ

	glutMainLoop();
	return 0;
}