//**********************************************************************
//                           HW#2-2 : GLU Modeling                     
//  작성자 : 이인규                              날짜 : 2021년 9월 25일 
//                                                                      
// 문제 정의 :      GLU를 이용한 여러 도형 그리기                                                  
//					- - - - - - -                                         
// 기능 :			먼저 Displaylist를 할당하기 위해 정수형으로 선언해 주었습니다.
//                  그리고 각 리스트에서 그림을 그릴 GLUquadricObj를 선언하였습니다.
//                  glNewList ~ glEndList 사이에서 여러 그림을 그리도록 만든 리스트들을
//                  MyDisplay에서 glCallList 하면서 출력해줍니다.
//					- - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

int MyList[4]; //DisplayList를 할당하기 위해 선언한 크기4의 배열 

GLUquadricObj* Sphere = gluNewQuadric();    //Sphere를 그리기 위한 Quadric 생성
GLUquadricObj* Cylinder = gluNewQuadric();  //Cylinder를 그리기 위한 Quadric 생성
GLUquadricObj* Disk = gluNewQuadric();      //Disk를 그리기 위한 Quadric 생성
GLUquadricObj* PartialDisk = gluNewQuadric();   //PartialDisk를 그리기 위한 Quadric 생성


void MyCreateList() {
    MyList[0] = glGenLists(4); // Sphere        //Display List 아이디 할당
    MyList[1] = MyList[0] + 1; // Cylinder      //Display List 아이디 할당
    MyList[2] = MyList[1] + 1; // Disk          //Display List 아이디 할당
    MyList[3] = MyList[2] + 1; // Partial Disk  //Display List 아이디 할당

    //Sphere
    glNewList(MyList[0], GL_COMPILE); //Display List 생성, 실행하지 않고 컴파일 완료된 버전입니다
    gluQuadricDrawStyle(Sphere, GLU_FILL); //면으로 그리기
    gluQuadricNormals(Sphere, GLU_SMOOTH); //법선벡터 제어
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //법선벡터 내부 or 외부 방향지정
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture 좌표 사용 유무
    gluSphere(Sphere, 1.5, 50, 50); //Sphere 생성 반지름1.5 slices 개수 50x50
    glEndList();    //Display List의 끝

    //Cylinder
    glNewList(MyList[1], GL_COMPILE);   //Display List 생성, 실행하지 않고 컴파일 완료된 버전입니다
    gluQuadricDrawStyle(Cylinder, GLU_LINE); //선으로 그리기
    gluQuadricNormals(Sphere, GLU_SMOOTH); //법선벡터 제어
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //법선벡터 내부 or 외부 방향지정
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture 좌표 사용 유무
    gluCylinder(Cylinder, 1, 0.5, 1.5, 20, 8); //Cylinder 생성 아래반지름 1, 윗반지름 0.5 높이 1.5
    glEndList();    //Display List의 끝                           slices 20개 stack 8개           

    //Disk
    glNewList(MyList[2], GL_COMPILE);   //Display List 생성, 실행하지 않고 컴파일 완료된 버전입니다
    gluQuadricDrawStyle(Disk, GLU_SILHOUETTE); //실루엣으로 그리기
    gluQuadricNormals(Sphere, GLU_SMOOTH); //법선벡터 제어
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //법선벡터 내부 or 외부 방향지정
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture 좌표 사용 유무
    gluDisk(Disk, 0.5, 2.0, 20, 3); //Disk 생성 안쪽반지름 0.5, 큰원 반지름 2, Slices 20, 동심원 3개 
    glEndList();    //Display List의 끝

    //Partial Disk
    glNewList(MyList[3], GL_COMPILE);   //Display List 생성, 실행하지 않고 컴파일 완료된 버전입니다
    gluQuadricDrawStyle(PartialDisk, GLU_POINT); //점으로 그리기
    gluQuadricNormals(Sphere, GLU_SMOOTH); //법선벡터 제어
    gluQuadricOrientation(Sphere, GLU_OUTSIDE); //법선벡터 내부 or 외부 방향지정
    gluQuadricTexture(Sphere, GL_FALSE);    //Texture 좌표 사용 유무
    gluPartialDisk(PartialDisk, 1, 2.0, 26, 13, 0, 270); //PartialDisk 생성, 안쪽 반지름 1, 큰원 반지름 2
    glEndList();    //Display List의 끝                                     Slices 26개, loops 13개, 각도 0~270 
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
    gluLookAt(1, 1, 1, 0, 0, 0.1, 0, 0, 1); //시점 (1,1,1)에 있는 카메라가 (0,0,0.1)을 바라봅니다. 
                                            //카메라의 머리는 벡터(0,0,1)을 가리킵니다
    /*리스트를 호출해서 실행하는 부분입니다. 순서대로 Sphere, Cylinder, Disk, PartialDisk 입니다*/
    glCallList(MyList[0]); //Sphere (면)
    //glCallList(MyList[1]); //Cylinder (선)
    //glCallList(MyList[2]); //Disk (실루엣)
    //glCallList(MyList[3]); //PartialDisk (점)
    
    glMatrixMode(GL_MODELVIEW); //투영행렬 선택
    glLoadIdentity(); //현재 모델뷰 행렬을 항등행렬로 초기화
    glEnable(GL_LIGHTING); //조명모드 활성화
    glShadeModel(GL_SMOOTH);    //상태변수 설정

    glutSwapBuffers();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); //변경된 창의 사이즈를 받아 0,0부터 시작하여 너비, 높이만큼의 창 재구성
    glMatrixMode(GL_PROJECTION); //투영행렬 선택
    glLoadIdentity();   //현재 모델뷰 행렬을 항등행렬로 초기화

    glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0); //가시부피를 위에서 계산한 비율로 재설정
    glMatrixMode(GL_MODELVIEW); //투영행렬 선택
    glLoadIdentity();   //현재 모델뷰 행렬을 항등행렬로 초기화
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(800, 600);   //창크기 800 * 600
    glutInitWindowPosition(0, 0);   //창 위치 (0,0)
    glutCreateWindow("GLU Modeling"); //창 이름 GLU Modeling
    MyInit(); //초기설정함수
    glutDisplayFunc(MyDisplay); //DisplayFunc
    glutReshapeFunc(Reshape);   //창크기 변할 때
    MyCreateList(); //DisplayList 생성

    glutMainLoop(); //메인루프
    return 0;
}



