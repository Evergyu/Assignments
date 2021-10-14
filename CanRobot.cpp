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
static int RightShoulder = 60,RightElbow=-120,LeftShoulder = 60, LeftElbow = -120;
static int RightLeg = 0, LeftLeg = 0, neck=0;
void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void body() {
	//�������� �� ������ 0.6,0.6 ���� 1.5�� �����
	glPushMatrix(); //���� Ǫ�� 
	glColor3f(0, 0.5, 0.6);
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
		glRotatef((GLfloat)RightShoulder, 1, 0, 0); //Rotate �ǽ�
		glPushMatrix();								//TRR�� ���� Ǫ��
		glColor3f(0, 100, 255);
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
		glTranslatef(0.6, 0, 0.0);					//Translate
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);					
		glScalef(0.2, 0.2, 0.2);					//ũ������
		glutWireSphere(1, 10, 10);					//�� �׸���
		glPopMatrix();								//���� �׸� �κ� ��
	glPopMatrix();									//�̸� Ǫ���Ѻκ� ��
}
void Left_Arm() {
	//����
	glPushMatrix();									//�����ϱ� �� �̸� Ǫ��
		glTranslatef(-0.6, 1.5, 0);					
		glRotatef(-90, 0, 1, 0);					//Translate, Rotate �ǽ�
		glRotatef((GLfloat)LeftShoulder, 1, 0, 0);	//Rotate �ǽ�
		glPushMatrix();								//TRR�� ���� Ǫ��
		glColor3f(0, 100, 255);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//�Ʒ���
		glRotatef((GLfloat)LeftElbow, 1, 0, 0);
		glTranslatef(0, -0.5, -1);					//�Ʒ��� �κп� RT
		glPushMatrix();								//RT�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//��
		glTranslatef(-0.6, 0, 0.0);					//Translate
		glPushMatrix();								//T�� �κ� Ǫ��
		glColor3f(0.6, 0.6, 0.5);
		glScalef(0.2, 0.2, 0.2);					//ũ������
		glutWireSphere(1, 10, 10);					//�� �׸���
		glPopMatrix();								//���� �׸� �κ� ��
	glPopMatrix();									//�̸� Ǫ���Ѻκ� ��
}
void Right_Leg() {
	//���ٸ�
	glPushMatrix();									//�����ϱ� �� �̸� Ǫ��
		glTranslatef(0.3, 0, 0);					
		glRotatef(90, 1, 0, 0);						//��ġ�� �°� Translate, Rotate �ǽ�
		glRotatef(RightLeg, 0, 1, 0);				//Rotate �ǽ� �����ٸ��� �����̱� ���� ��ݺκ��� ������ ������ ����
		glPushMatrix();								//TRR�� ���� Ǫ��
		glColor3f(1.0, 0, 0.5);			
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��
		
		//�Ʒ��ٸ�
		glTranslatef(0, 0, 0.6);					//��ġ�� �°� Translate
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
		glRotatef(LeftLeg, 0, 1, 0);				//Rotate �ǽ� �����ٸ��� �����̱� ���� ��ݺκ��� ������ ������ ����
		glPushMatrix();								//TRR�� ���� Ǫ��
		glColor3f(1.0, 0, 0.5);
		gluCylinder(qobj, 0.2, 0.2, 0.6, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ����� �׸� �κ� ��

		//�Ʒ��ٸ�
		glTranslatef(0, 0, 0.6);					//��ġ�� �°� Translate
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


�Ӹ� ���ľ���
void neckAndhead() {
	glPushMatrix();									//�����ϱ��� �̸� Ǫ��
		//��
		glTranslatef(0, 1.7, 0);
		glRotatef(90, 1, 0, 0);						//���� ���°� �˸°� Translate, Rotate
		�̺κ�glRotatef(neck, 0, 1, 0);					//���� �����϶� �������� ������ ������ ���� Rotate
		glPushMatrix();								//TRR�� �κ� Ǫ��
		glColor3f(0, 0.5, 1);
		gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ��� �׸��κ� ��
		
		//�Ӹ���
		glRotatef(180, 1, 0, 0);					
		glRotatef(neck, 1, 0, 0);					//���� �����϶� �������� ������ ������ ���� Rotate
		glPushMatrix();								//Rotate, Translate�� �κ� Ǫ��
		glColor3f(1, 0.6, 0.5);
		gluCylinder(qobj, 0.4, 0.3, 0.5, 20, 5);	//�Ǹ��� �׸���
		glPopMatrix();								//�Ǹ��� �׸� �κ� ��
		
		glPushMatrix();								//�Ӹ����±��� ���� �� Ǫ��

		//�����ʴ�
		glTranslatef(0.15, -0.8, 0);				//�� ��ġ�� �°� Translate
		glScalef(0.1, 0.1, 0.1);					//�� ũ�� ����
		glPushMatrix();								//TS�� �κ� Ǫ��
		glColor3f(1, 1, 1);
		glutSolidSphere(0.5, 20, 8);				//�� �׸���
		glPopMatrix();								//�� �׸��κ� ��

		//������ ������
		glPushMatrix();								//��ġ�� �ű� �ʿ� �����Ƿ� �׳� Ǫ��
		glColor3f(0, 0, 0);							
		glScalef(0.1, 0.1, 0.1);					//������ �ٲ��ְ�
		glutSolidSphere(2, 20, 8);					//�� �׸���
		glPopMatrix();								//������ �ٲ� �� �� �׸��κ� ��
		
		glPopMatrix();								//�Ӹ����±��� ���� �� ��

		glPushMatrix();								//�Ӹ����±��� ���� �� Ǫ��
		//���ʴ�
		glTranslatef(-0.15, -0.8, 0);				//�� ��ġ�� �°� Translate
		glScalef(0.1, 0.1, 0.1);					//�� ũ�� ����
		glPushMatrix();								//TS�� �κ� Ǫ��
		glColor3f(1, 1, 1);
		glutSolidSphere(0.5, 20, 8);				//�� �׸���
		glPopMatrix();								//�� �׸��κ� ��

		//���� ������
		glPushMatrix();								//��ġ�� �ű� �ʿ� �����Ƿ� �׳� Ǫ��
		glColor3f(0, 0, 0);
		glScalef(0.1, 0.1, 0.1);					//������ �ٲ��ְ�
		glutSolidSphere(2, 20, 8);					//�� �׸���
		glPopMatrix();								//������ �ٲ� �� �� �׸��κ� ��
		
		glPopMatrix();								//�Ӹ����±��� ���� �� ��

	glPopMatrix();									//�����ϱ��� �̸� Ǫ���Ѻκ� ��
}

void MyMenu(int entryID) {
	if (entryID == 1) {
		neck = (neck + 5) % 90;
	}
	if (entryID == 2) {
		neck = (neck - 5) % 90;
	}
	if (entryID == 3) {
		LeftShoulder = (LeftShoulder + 5) % 90;
	}
	if (entryID == 4) {
		RightLeg = (RightLeg + 5) % 60;
	}
	if (entryID == 5) {
		LeftLeg = (LeftLeg + 5) % 60;
	}
	
	glutPostRedisplay();	//���α׷� ������ ����Ǿ��� �� �����츦 ����ϵ��� �ϴ� �Լ�
}
void MyDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	gluQuadricDrawStyle(qobj, GLU_LINE);
	body();	//��
	Right_Arm();	//������
	Left_Arm();	//����
	Right_Leg();	//�����ٸ�
	Left_Leg();	//���ʴٸ�
	neckAndhead();	//��

	GLint MyMenuID = glutCreateMenu(MyMenu);	//�޴�
	glutAddMenuEntry("Move Head", 1);			//�Ӹ������̱�
	glutAddMenuEntry("Move Right Hand", 2);		//������ �����̱�
	glutAddMenuEntry("Move Left Hand", 3);		//������ �����̱�
	glutAddMenuEntry("Move Right Leg", 4);		//�����ٸ� �����̱�
	glutAddMenuEntry("Move Left Leg", 5);		//���ʴٸ� �����̱�

	glutAttachMenu(GLUT_RIGHT_BUTTON); //��Ŭ���ϸ� �޴��� �������� ��
	
	glutSwapBuffers();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':
		RightShoulder = (RightShoulder + 5) % 180;
		break;
		glutPostRedisplay();
	
	case 'd':
		LeftShoulder = (LeftShoulder + 5) % 180;
		break;
		glutPostRedisplay();
}
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
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}