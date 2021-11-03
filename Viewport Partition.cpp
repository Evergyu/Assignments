//**********************************************************************
//                           HW#6-1 : 뷰포트 변환                     
//  작성자 : 이인규                              날짜 : 2021년 11월 3일 
//                                                                      
// 문제 정의 :      창의 크기 변화에도 모델이 어그러지지 않도록 하고
//                  키보드, 마우스콜백으로 시점변환                                                
//					- - - - - - -                                         
// 기능 :			화살표 상,하,좌,우를 누르시면 카메라의 위치를 옮겨 시점이 바뀌도록 했습니다.
//                  그리고 Reshape 콜백을 사용해 창의 크기변화에 맞게
//                  화면이 바뀌도록 했습니다.
//                  - - - - - - -                                         
//**********************************************************************
#include <GL/glut.h>

int Width, Height;
GLfloat AspectRatio=1.0;    //glPerspective에 쓰일 종횡비 변수
GLdouble Cx_O = 0, Cy_O = 0, Cx_P = 0, Cy_P = 0;    //카메라 시점에 쓰일 변수

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);            
    glLoadIdentity( );

    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);    //기본 glOrtho
    glMatrixMode(GL_MODELVIEW);                 //매트릭스모드
    glLoadIdentity( );
}

void DrawScene() {
    glColor3f(0.7, 0.7, 0.7);           //색깔
    glPushMatrix();
        glTranslatef(0.0, -1.0, 0.0);   //위치 이동
        glBegin(GL_QUADS);
            glVertex3f(2.0, 0.0, 2.0);  //점 네개
            glVertex3f(2.0, 0.0, -2.0);
            glVertex3f(-2.0, 0.0, -2.0);
            glVertex3f(-2.0, 0.0, 2.0);
        glEnd();
    glPopMatrix();                      //바닥면

    glColor3f(0.3, 0.3, 0.7);           //색깔
    glPushMatrix();                     
        glTranslatef(0.0, 0.0, -0.5);   //위치 이동
        glutWireTeapot(1.0);            //주전자 그리기
    glPopMatrix();
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glViewport(0, 0, Width/2, Height/2);                //왼쪽하단 뷰폿
    
    glPushMatrix();
    gluLookAt(0.0 + Cx_O, 0.0 + Cy_O, 1.0 , 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);  //시점 (0,Cx_O,Cy_O) 초점(1,0,0) 카메라 정수리(0,1,0)
        DrawScene();            
    glPopMatrix();
    
    glViewport(Width/2, 0, Width/2, Height/2);          //오른쪽하단 뷰폿
    glPushMatrix();
        gluLookAt(1.0, 0.0+Cy_O, 0.0 + Cx_O, 0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //시점 (1.0, 0.0+Cy_O, 0.0 + Cx_O) 초점(0,0,0) 카메라 정수리(0,1,0)
        DrawScene();
    glPopMatrix();
    
    glViewport(0, Height/2, Width/2, Height/2);         //왼쪽상단 뷰폿
    glPushMatrix();
        gluLookAt(0.0 + Cx_O, 1.0 , 0.0+Cy_O,   0.0, 0.0, 0.0,   0.0, 0.0, -1.0); //시점 (0.0 + Cx_O, 1.0 , 0.0+Cy_O) 초점(0,0,0) 카메라 정수리(0,0,-1)
        DrawScene();
    glPopMatrix();
    
    glViewport(Width/2, Height/2, Width/2, Height/2);   //오른쪽상단 뷰폿
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluPerspective(30, AspectRatio, 0.5, 50.0);     //각도 30 종횡비 AspectRatio (Reshape콜백에서 조정), 0.5~50.0
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            gluLookAt(5.0+Cx_P, 5.0+Cy_P, 5.0,  0.0, 0.0, 0.0,  0.0, 1.0, 0.0); //시점 (5.0+Cx_P, 5.0+Cy_P, 5.0) 초점(0,0,0) 카메라 정수리(0,1,0)
            DrawScene();
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glFlush();
}

void MyReshape(int w, int h) {
    Width = w;
    Height = h;                                             // 가로세로 초기화
    glViewport(0, 0, Width, Height);						// 현재 뷰폿초기화

    GLfloat WidthFactor = (GLfloat)Width / (GLfloat)500;
    GLfloat HeightFactor = (GLfloat)Height / (GLfloat)500;

    glMatrixMode(GL_PROJECTION);						// 프로젝션 매트릭스 선택
    glLoadIdentity();									// 항등행렬로 설정

    // Calculate The Aspect Ratio Of The Window
    glOrtho(-2.0 * WidthFactor, 2.0 * WidthFactor,
        -2.0 * HeightFactor, 2.0 * HeightFactor, 0.5, 5.0); //늘어난 길이대로 glOrtho 새로계산
    AspectRatio = (GLfloat)Width / (GLfloat)Height;       //종횡비를 유지하기위해 gluPersepctive에 종횡비 변수 AspectRatio 초기화
}

//glOrtho로 표현한 부분과 glPerspective에서 표현한 부분의 카메라가 이동할 수 있는 최대 거리가 다릅니다.
//그래서 if문으로 두개를 구분해서 제한해줬습니다. 너무 과도하게 움직이지 않는다고 생각하는 범위로 제한했습니다. 
void MySpecial(int key, int x, int y) {
    switch (key) {

    case GLUT_KEY_LEFT:                         //좌측키를 누르면 왼쪽으로 돕니다.
        if(Cx_O>-4) Cx_O -= 0.1;
        if (Cx_P > -9) Cx_P -= 0.1;
        break;

    case GLUT_KEY_RIGHT:                        //우측키를 누르면 오른쪽으로 돕니다
        if(Cx_O<4) Cx_O += 0.1;
        if (Cx_P < 4) Cx_P += 0.1;
        break;

        case GLUT_KEY_UP:                           //윗 키를 누르면 위쪽으로 돕니다
        if(Cy_O<3) Cy_O += 0.1;
        if (Cy_P < 10) Cy_P += 0.1;
        break;
    case GLUT_KEY_DOWN:                         //아래 키를 누르면 아래쪽으로 돕니다
        if(Cy_O>-3)Cy_O -= 0.1;
        if (Cy_P > -10) Cy_P -= 0.1;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    Width = 500;
    Height = 500;                                   
    glutInitDisplayMode(GLUT_SINGLE |GLUT_RGBA);
    glutInitWindowSize(Width, Height);              //창크기 500*500
    glutInitWindowPosition(0, 0);                   //창위치 (0.0)
    glutCreateWindow("Viewpory Partition");         //창이름 Viewpory Paritiion
    MyInit();
    glutDisplayFunc(MyDisplay);                     //디스플레이콜백
    glutReshapeFunc(MyReshape);                     //리사이즈 콜백
    glutSpecialFunc(MySpecial);                     //키보드 특수키 콜백
    glutMainLoop();
    return 0;
}
