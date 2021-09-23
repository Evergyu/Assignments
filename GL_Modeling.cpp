//**********************************************************************
//                           HW#2-1 : GL Modeling                     
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

#include <gl/glut.h> 
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0); //���� ���
	glMatrixMode(GL_PROJECTION); //������� ����
	glLoadIdentity(); //�׵����
	glOrtho(0.0, 1000.0, 0.0, 1000.0, 1, -1); //glortho ����
}
void MyDisplay() {
	glColor3f(0.0, 1, 0.0);
	
	
	//��ü 1 GL_POINTS
	/*6���� ���� ����ϴ�.*/
	glBegin(GL_POINTS);
	glVertex2f(60, 835);
	glVertex2f(100, 900);
	glVertex2f(160, 900);
	glVertex2f(200, 835);
	glVertex2f(160, 760);
	glVertex2f(100, 760);
	glEnd();
	
	//��ü 2 GL_LINES
	/*6���� ���� �߿��� ������ �°� �ΰ��� ���� ���� �߽��ϴ�*/
	glBegin(GL_LINES);
	//��1
	glVertex2f(60 + 250, 835);
	glVertex2f(100 + 250, 900);
	//��2
	glVertex2f(160 + 250, 900);
	glVertex2f(200 + 250, 835);
	//��3
	glVertex2f(160 + 250, 760);
	glVertex2f(100 + 250, 760);
	glEnd();
	
	//��ü 3 GL_LINE_STRIP
	/*6���� ������ ������� �ս��ϴ�.*/
	glBegin(GL_LINE_STRIP);
	//��1
	glVertex2f(60 + 500, 835);
	glVertex2f(100 + 500, 900);
	//��2
	glVertex2f(160 + 500, 900);
	//��3
	glVertex2f(200 + 500, 835);
	//��4
	glVertex2f(160 + 500, 760);
	//��5
	glVertex2f(100 + 500, 760);
	glEnd();
	
	//��ü 4 GL_LINE_LOOP
	/*6���� ������ ������� ��� ���� �̾������� �ս��ϴ�*/
	glBegin(GL_LINE_LOOP);
	//��1
	glVertex2f(60 + 750, 835);
	glVertex2f(100 + 750, 900);
	//��2
	glVertex2f(160 + 750, 900);
	//��3
	glVertex2f(200 + 750, 835);
	//��4
	glVertex2f(160 + 750, 760);
	//��5
	glVertex2f(100 + 750, 760);
	//ù��° ���� �̾ ��6
	glEnd();
	//��ü 5 GL_POLYGON
	/*��� ���� �̾� �ٰ����� �׸��ϴ�. �̶� ���� �����ϸ� �ȵ˴ϴ�*/
	glBegin(GL_POLYGON);
	glVertex2f(60 , 495);
	glVertex2f(90, 560);
	glVertex2f(170, 560);
	glVertex2f(200, 495);
	glVertex2f(170, 420);
	glVertex2f(90, 420);
	glEnd();
	//��ü 6 GL_TRIANGLES
	/*���� ������� ������ ���� �ﰢ���� �׸��ϴ�*/
	glBegin(GL_TRIANGLES);
	//�ﰢ��1
	glVertex2f(60 + 330, 495);
	glVertex2f(90 + 330, 560);
	glVertex2f(170 + 330, 560);
	//�ﰢ��2
	glVertex2f(200 + 330, 495);
	glVertex2f(170 + 330, 420);
	glVertex2f(90 + 330, 420);
	glEnd();
	//��ü 7 GL_TRIANGLE_STRIP
	/*���� ó���� ������ ���� �ﰢ���� �׸��� �� �Ŀ� ������ �� ��
	  ������ ���� �������� �� �ΰ��� ���� ��� �ﰢ���� �׸��� ������
	  �������� �ﰢ���� �׸��ϴ�*/
	glShadeModel(GL_FLAT); //�ܻ����� ��ĥ
	glBegin(GL_TRIANGLE_STRIP); 
	glVertex2f(60+660,420);
	glVertex2f(80+660,495); 
	glVertex2f(110+660,430);//������� �ﰢ��1
	//�ﰢ��2
	glColor3f(1, 0, 0.0);
	glVertex2f(130+660,510);
	//�ﰢ��3
	glColor3f(0, 1, 0.0);
	glVertex2f(160+660,440);
	//�ﰢ��4
	glColor3f(1, 0, 0.0);
	glVertex2f(180+660,520);
	//�ﰢ��5
	glColor3f(0, 1, 0.0);
	glVertex2f(200+660,400);
	glEnd();
	//��ü 8 GL_TRIANGLE_FAN
	/*ù��° ���� �������� ��� �ΰ��� ���� ��� �ﰢ���� �׸��ϴ�
	  �� �� �ڿ� ���� �� 1���� ��� �ﰢ���� �̾� �׸��ϴ�.*/
	glColor3f(0.0, 1, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	//������ 
	glVertex2f(50, 50);
	glVertex2f(100, 280);
	glVertex2f(120, 270); //������� �ﰢ��1
	//�ﰢ��2
	glColor3f(1, 0, 0.0);
	glVertex2f(150, 240);
	//�ﰢ��3
	glColor3f(0, 1, 0.0);
	glVertex2f(180, 230);
	//�ﰢ��4
	glColor3f(1, 0, 0.0);
	glVertex2f(210, 180);
	glEnd();
	//��ü 9 GL_QUADS
	/*���� �װ��� ��� �簢���� �׸��ϴ�.*/
	glBegin(GL_QUADS);
	//�簢��1
	glVertex2f(40 + 330, 200);
	glVertex2f(50 + 330, 270);
	glVertex2f(120 + 330, 280);
	glVertex2f(110 + 330, 160);
	//�簢��2
	glVertex2f(130 + 330, 50);
	glVertex2f(160 + 330, 210);
	glVertex2f(210 + 330, 160);
	glVertex2f(190 + 330, 50);
	glEnd();
	//��ü 10 GL_QUAD_STRIP
	/*ó���� ���� �װ��� ��� �簢���� ����� �� �Ŀ��� �տ��� ����
	  �簢���� ���� �߿��� ������ �� ���� �̾ ���� �� ���� ���
	  �簢���� �̾�ٿ� �������� �簢���� ����ϴ�*/
	glBegin(GL_QUAD_STRIP);
	//�簢��1
	glVertex2f(40 + 660, 200);
	glVertex2f(50 + 660, 270);
	glVertex2f(110 + 660, 160);
	glVertex2f(120 + 660, 280);
	//�簢��2
	glColor3f(1, 0, 0.0); //����
	glVertex2f(130 + 660, 50);
	glVertex2f(160 + 660, 210);
	//�簢��3
	glColor3f(0, 1, 0.0); //�ʷ�
	glVertex2f(190 + 660, 50);
	glVertex2f(210 + 660, 160);
	
	glEnd();

	glFlush();
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB); //displaymode RGB
	glutInitWindowSize(1000, 1000); //â�� ũ�� 1000 x 1000
	glutInitWindowPosition(0, 0); //ȭ����ġ (0,0)
	glutCreateWindow("GL Modeling Test");
	MyInit(); //�ʱ�ȭ
	glutDisplayFunc(MyDisplay);
	glutMainLoop(); //���η���

}