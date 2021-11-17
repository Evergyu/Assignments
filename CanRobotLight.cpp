//**********************************************************************
//                           HW#7 : ����                     
//  �ۼ��� : ���α�                              ��¥ : 2021�� 11�� 14�� 
//                                                                      
// ���� ���� :      ���� �κ� ������� + �޸���                                                 
//					- - - - - - -                                         
// ��� :			R : �޸���
//					- - - - - - -                                         
//**********************************************************************
#include <stdlib.h>
#include <GL/glut.h>

GLUquadricObj* qobj = gluNewQuadric(); // ���ο� Quadric ����
static int RightLeg = 0, LeftLeg = 0, Rightknee = 0, LeftKnee = 0, LeftArm = 0, RightArm = 0;
static int moving = 1, move = 0, move_count=1;
void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void body() {
	//�������� �� ������ 0.6,0.6 ���� 1.5�� �����
	glPushMatrix(); //���� Ǫ�� 
	GLfloat material_ambient[] = { 0,0.5,0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);			//��ü��
	glTranslatef(0, 0, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(50, 0, 0, 1);
	gluCylinder(qobj, 0.6, 0.6, 1.5, 20, 20);

	glPopMatrix(); //���� ��
}
void Right_Arm() {
	glPushMatrix();									//�����ϱ� �� �̸� Ǫ��
		glTranslatef(0.6, 1.5, 0);					
		glRotatef(90, 0, 1, 0);						//Translate, Rotate �ǽ�
		glRotatef(40, 1, 0, 0);
		glRotatef(RightArm, 0, 1, 0); //Rotate �ǽ�
		glPushMatrix();								//TRR�� ���� Ǫ��
		GLfloat material_ambient[] = { 0.5,0.5,0.25,1.0 };				//��ü ��
		glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//�Ʒ���					
		glRotatef(-120 , 1, 0, 0);					
		glTranslatef(0, -0.5, -1);					//�Ʒ��� �κп� RT
		glPushMatrix();								//RT�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);					
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//��
		glTranslatef(0.0, 0, -0.1);					//Translate
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);					
		glScalef(0.2, 0.2, 0.2);					//ũ������
		glutSolidSphere(1, 10, 10);					//�� �׸���
		glPopMatrix();								//���� �׸� �κ� ��
	glPopMatrix();									//�̸� Ǫ���Ѻκ� ��
}
void Left_Arm() {
	//����
	glPushMatrix();									//�����ϱ� �� �̸� Ǫ��
		glTranslatef(-0.6, 1.5, 0);					
		glRotatef(-90, 0, 1, 0);					//Translate, Rotate �ǽ�
		glRotatef(40, 1, 0, 0);
		glRotatef((GLfloat)LeftArm, 0, 1, 0);	//Rotate �ǽ�
		glPushMatrix();								//TRR�� ���� Ǫ��
		glColor3f(0, 100, 255);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//�Ʒ���
		glRotatef(-120, 1,0, 0);
		glTranslatef(0, -0.5, -1.0);					//�Ʒ��� �κп� RT
		glPushMatrix();								//RT�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//��
		glTranslatef(0, 0, -0.1);					//Translate
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);
		glScalef(0.2, 0.2, 0.2);					//ũ������
		glutSolidSphere(1, 10, 10);					//�� �׸���
		glPopMatrix();								//���� �׸� �κ� ��
	glPopMatrix();									//�̸� Ǫ���Ѻκ� ��
}
void Right_Leg() {
	//���ٸ�
	glPushMatrix();									//�����ϱ� �� �̸� Ǫ��
		glTranslatef(0.3, 0, 0);					
		glRotatef(90, 1, 0, 0);						//��ġ�� �°� Translate, Rotate �ǽ�
		glRotatef(RightLeg, 1, 0, 0);				//Rotate �ǽ� �����ٸ��� �����̱� ���� ��ݺκ��� ������ ������ ����
		glPushMatrix();								//TRR�� ���� Ǫ��
		GLfloat material_ambient[] = { 0,0,1,1.0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��
		
		//�Ʒ��ٸ�
		glTranslatef(0, 0, 0.6);					//��ġ�� �°� Translate
		glRotatef(Rightknee, 1, 0, 0);
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);					
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�ø����� �׸� �κ� ��

		//��
		glTranslatef(0.1, 0, 0.6);					//��ġ�� �°� Translate
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.0, 0.2, 0.5);
		gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ��� �׸��κ� ��
	glPopMatrix();									//�����ϱ� �� Ǫ���� �κ� ��
}
void Left_Leg(){
	glPushMatrix();									//�����ϱ� �� �̸� Ǫ��
		glTranslatef(-0.3, 0, 0);					
		glRotatef(90, 1, 0, 0);						//��ġ�� �°� Translate, Rotate �ǽ�
		glRotatef(LeftLeg, 1, 0, 0);				//Rotate �ǽ� �����ٸ��� �����̱� ���� ��ݺκ��� ������ ������ ����
		glPushMatrix();								//TRR�� ���� Ǫ��
		glColor3f(1.0, 0, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//�Ʒ��ٸ�
		glTranslatef(0, 0, 0.6);					//��ġ�� �°� Translate
		glRotatef(LeftKnee, 1, 0, 0);
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�ø����� �׸� �κ� ��

		//��
		glTranslatef(-0.1, 0, 0.6);					//��ġ�� �°� Translate
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.0, 0.2, 0.5);
		gluCylinder(qobj, 0.3, 0.3, 0.2, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ��� �׸��κ� ��
	glPopMatrix();									//�����ϱ� �� Ǫ���� �κ� ��
}
void Neck() {
	glPushMatrix();									//�����ϱ��� �̸� Ǫ��
		//��
		glTranslatef(0, 1.7, 0);
		glRotatef(90, 1, 0, 0);						//���� ���°� �˸°� Translate, Rotate
		glPushMatrix();								//TRR�� �κ� Ǫ��
		GLfloat material_ambient[] = { 0,0.5,0.5,1.0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
		gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ��� �׸��κ� ��
		
	glPopMatrix();									//�����ϱ��� �̸� Ǫ���Ѻκ� ��
}
void Head() {
	glPushMatrix();								//�����ϱ� �� Ǫ��
	//�Ӹ���
	glTranslatef(0, 1.7, 0.1);
	glRotatef(270, 1, 0, 0);
	glRotatef(0, 0, 1, 0);					//���� �����϶� �������� ������ ������ ���� Rotate
	glTranslatef(0, 0.1, 0);
	glPushMatrix();								//Rotate, Translate�� �κ� Ǫ��
	GLfloat material_ambient[] = { 1,0,0,1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	gluCylinder(qobj, 0.4, 0.3, 0.5, 20, 5);	//�Ǹ��� �׸���
	glPopMatrix();								//�Ǹ��� �׸� �κ� ��

	//�����ʴ�
	glRotatef(90, 1, 0, 0);					//�Ӹ��� 270�� ���ȱ� ������ ���� ���ư��� ������ ���߱� ����
	glTranslatef(0.15, 0.3, 0.5);				//�� ��ġ�� �°� Translate
	glScalef(0.1, 0.1, 0.1);					//�� ũ�� ����
	glPushMatrix();								//TS�� �κ� Ǫ��
	glColor3f(1, 1, 1);
	glutSolidSphere(0.5, 20, 8);				//�� �׸���
	glPopMatrix();								//�� �׸��κ� ��

	//������ ������
	glPushMatrix();								//��ġ�� �ű� �ʿ� �����Ƿ� �׳� Ǫ��
	glScalef(0.1, 0.1, 0.1);					//������ �ٲ��ְ�
	glutSolidSphere(2, 20, 8);					//�� �׸���
	glPopMatrix();								//������ �ٲ� �� �� �׸��κ� ��

	//���ʴ�
	glTranslatef(-3, 0.0, 0.1);				//�� ��ġ�� �°� Translate
	glPushMatrix();								//TS�� �κ� Ǫ��
	glColor3f(1, 1, 1);
	glutSolidSphere(0.5, 20, 8);				//�� �׸���
	glPopMatrix();								//�� �׸��κ� ��

	//���� ������
	glPushMatrix();								//��ġ�� �ű� �ʿ� �����Ƿ� �׳� Ǫ��
	glScalef(0.1, 0.1, 0.1);					//������ �ٲ��ְ�
	glutSolidSphere(2, 20, 8);					//�� �׸���
	glPopMatrix();								//������ �ٲ� �� �� �׸��κ� ��

	glPopMatrix();								//���� �� ��
}
void light() {

	//gluLookAt(0.5, 0.5, 0.5, 0, 0, 0, 0, 1, 0);

	GLfloat global_ambient[] = { 0.5,0.5,0.5,1 };		//���� �ֺ���

	GLfloat light0_ambient[] = { 0.5,0.5,0.5,1.0 };		//light0 �ֺ���
	GLfloat light0_diffuse[] = { 0.5,0.6,0.5,0.5 };		//light0 ���ݻ籤
	GLfloat light0_specular[] = { 1.0,1.0,1.0,1.0 };	//light0 ���ݻ籤

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);	//GL_LIGHT0 Ȱ��ȭ
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);	//light0 Ư���ο�
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);	//������ Ư���ο�

}
void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_FILL);

	light(); //��

	body();	//��
	Right_Arm();	//������
	Left_Arm();	//����
	Right_Leg();	//�����ٸ�
	Left_Leg();	//���ʴٸ�
	Neck(); //��
	Head();	//�Ӹ�

	
	
	glutSwapBuffers();
}


void TimerRun(int Value) {
	if (move_count % 59 == 0) move = (move++) % 4;
	if (move_count % (59 * 2) == 0) moving *= -1;

	if (moving == 1) {
		if (move == 0) {
			Rightknee++;
			RightLeg--;
			LeftArm++;	
			move_count++;
		}
		if (move == 1) {
			Rightknee--;
			RightLeg++;
			LeftArm--;
			move_count++;
		}
	}
	if (moving == -1) {
		if (move == 2) {
			LeftKnee++;
			LeftLeg--;
			RightArm++;
			move_count++;
		}
		if (move == 3) {
			LeftKnee--;
			LeftLeg++;
			RightArm--;
			move_count++;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(10, TimerRun, 1);
}


//S�� ������ �Ǹ� ��� ������ ���� ���� moving1~5�� 0���� �ʱ�ȭ�ؼ� ���߰� �˴ϴ�.
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'r': 
		glutTimerFunc(10, TimerRun, 1);
		
		break; 
	case 'R': 
		Rightknee++;
		RightLeg--;
		LeftArm++;
		break; 
		}
	glutPostRedisplay();

}

void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);  //�𵨺���
	glLoadIdentity();            //�׵���� ����
	gluLookAt(3, 0, 1,
		0, 0, -3,
		0, 1, 0);

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
	glutKeyboardFunc(MyKeyboard); //Ű���� �̺�Ʈ

	glutMainLoop();
	return 0;
}