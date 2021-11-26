//**********************************************************************
//                           HW#8 : ����                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 11�� 24�� 
//                                                                      
// ���� ���� :      �̴Ϸκ� ������ ����                                                
//					- - - - - - -                                         
// ��� :			�����¿� ��ġ�ű��
//					e : ���ȸ�� q : �·�ȸ��
//					- - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // ���ο� Quadric ����
GLint lleg_angle = 1, rleg_angle = 1;
GLfloat move_x = 0, move_y = 0;
GLfloat white[] = { 1, 1, 1, 1.0 };
GLfloat green[] = { 0, 1, 0, 1.0 };
GLfloat blue[] = { 0, 0, 1, 1.0 };
GLfloat red[] = { 1,0,0,1.0 };
GLfloat redblue[] = { 1,0,1,1.0 };
GLfloat redgreen[] = { 1,1,0,1.0 };
GLfloat black[] = { 0,0,0 };

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void light() {

	GLfloat global_ambient[] = { 1,1,1,1 };		//���� �ֺ���

	GLfloat light0_ambient[] = { 0,0,0,1.0 };		//light0 �ֺ���
	GLfloat light0_diffuse[] = { 0.5,0.6,0.5,0.5 };		//light0 ���ݻ籤
	GLfloat light0_position[] = { -10,10,20,1 };		//light0 ��ġ
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);	//GL_LIGHT0 Ȱ��ȭ
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);	//��ġ
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);	//�ֺ���
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);	//���ݻ籤
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);	//���ݻ籤 light0 Ư���ο�

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);	//������ Ư���ο�

}
void Character() {
	light();
	glPushMatrix();								//�����ϱ� �� Ǫ��

	glTranslatef(0 + move_x, -1 + move_y, 0);
	glScalef((GLfloat)0.8, (GLfloat)0.8, (GLfloat)0.8);
	
	glTranslatef(-1.7, 2.7, 0.1);
	glRotatef(270, 1, 0, 0);
	glPushMatrix();								//Rotate, Translate�� �κ� Ǫ��
	if (move_x < 1.3 && move_y > -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, red);
	else if (move_x < 1.3 && move_y < -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, redblue);
	else if (move_x >1.3 && move_y > -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, redgreen);
	else if (move_x > 1.3 && move_y < -1.3)
		glMaterialfv(GL_FRONT, GL_AMBIENT, white);
	
	glPolygonMode(GL_FRONT, GL_FILL);
	glutSolidCube(0.6);
	glPopMatrix();								//�Ǹ��� �׸� �κ� ��

	//�����ʴ�
	glRotatef(90, 1, 0, 0);					//�Ӹ��� 270�� ���ȱ� ������ ���� ���ư��� ������ ���߱� ����
	glTranslatef(0.15, 0.1, 0.3);				//�� ��ġ�� �°� Translate
	glScalef(0.1, 0.1, 0.1);					//�� ũ�� ����
	glPushMatrix();								//TS�� �κ� Ǫ��
	glColor3f(1, 1, 1);
	glutSolidSphere(1, 20, 8);				//�� �׸���
	glPopMatrix();								//�� �׸��κ� ��

	//���ʴ�
	glTranslatef(-3, 0.0, 0.1);				//�� ��ġ�� �°� Translate
	glPushMatrix();								//TS�� �κ� Ǫ��
	glColor3f(1, 1, 1);
	glutSolidSphere(1, 20, 8);				//�� �׸���
	glPopMatrix();								//�� �׸��κ� ��
	
	//�θ�
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(1.5, 0, -3);
	glutSolidCone(1, 1, 100, 100);
	glPopMatrix();
	
	//����
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(-1.5, -3, 0);
	glRotatef(-30, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();
	
	//������
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(4.5, -3, 0);
	glRotatef(30, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();

	//�����ٸ�
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(3, -3, 4);
	glRotatef(20*rleg_angle, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();

	//�޴ٸ�
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -3, 4);
	glRotatef(-20 * lleg_angle, 0, 1, 0);
	gluCylinder(qobj, 0.3, 0.3, 3, 20, 20);
	glPopMatrix();

	glPopMatrix();								//���� �� ��
}

void DrawWall() {
	glPushMatrix();

	glBegin(GL_LINES);
	glPolygonMode(GL_FRONT, GL_LINE);
	glMaterialfv(GL_FRONT, GL_AMBIENT, red);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-2.7, 2.4,0);	
	glVertex3f(2.7, 2.4,0);	
	
	glVertex3f(-2.7, -3.0,0);	
	glVertex3f(2.7, -3.0,0);	
	
	glVertex3f(-2.7, -3.0, 0);
	glVertex3f(-2.7, 2.4, 0);

	glVertex3f(2.7, -3.0, 0);
	glVertex3f(2.7, 2.4, 0);
	glEnd();
	
	glBegin(GL_LINES);
	glMaterialfv(GL_FRONT, GL_AMBIENT, green);
	glVertex3f(0, -3, 0);
	glVertex3f(0, 2.4, 0);
	glEnd();

	glBegin(GL_LINES);
	glMaterialfv(GL_FRONT, GL_AMBIENT, blue);
	glVertex3f(-2.7, -0.3, 0);
	glVertex3f(2.7, -0.3, 0);

	glEnd();

	glFlush();

	glEnd();
	glPopMatrix();
}


void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	
	Character();	//�Ӹ�
	DrawWall();

	glutSwapBuffers();
}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);  //�𵨺���
	glLoadIdentity();            //�׵���� ����
	gluLookAt(0, 0, 0,
		0, 0, -1,
		0, 1, 0);

	glTranslatef(0.0, 0.0, -5.0);
}
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (move_x < 3.5)	move_x += 0.1;
		lleg_angle *= -1;
		rleg_angle *= -1;
		break;
	case GLUT_KEY_LEFT: 
		if (move_x > -0.9) move_x -= 0.1;
		lleg_angle *= -1;
		rleg_angle *= -1; 
		break;
	case GLUT_KEY_UP:
		if (move_y < 0.9)move_y += 0.1;
		break;
	case GLUT_KEY_DOWN:
		if (move_y > -3.5) move_y -= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //���÷��� GLUT_RGB���
	glutInitWindowSize(600, 480);                   //���÷��� ������ 800*1200
	glutInitWindowPosition(10, 10);               //������ ��ġ 100*100
	glutCreateWindow("Color Study");                   //â �̸� Can Robot
	MyInit();   //�ʱ�ȭ
	glutDisplayFunc(MyDisplay); //display �̺�Ʈ
	glutReshapeFunc(MyReshape);  //â ũ�Ⱑ �������� �̺�Ʈ
	glutSpecialFunc(MySpecial);

	glutMainLoop();
	return 0;
}