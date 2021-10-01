//**********************************************************************
//                           HW#3-2 : Keyboard Callback(1)                     
//  작성자 : 이인규                              날짜 : 2021년 9월 29일 
//                                                                      
// 문제 정의 :      입력받은 키에 따라 해당하는 기능 수행                                                 
//					- - - - - - -                                         
// 기능 :			<-를 입력하면 사각형이 왼쪽으로 0.1씩 이동
//                  ->를 입력하면 사각형이 오른쪽으로 0.1씩 이동
//                  위 방향키를 입력하면 사각형이 아래쪽으로 0.1씩 이동하고 빨간색으로 변함                 
//                  아래 방향키를 입력하면 사각형이 위로 0.1씩 이동
//                  Page Down을 누르면 축소
//                  Page Up을 누르면 확대
//                  인데 여기서 도형이 윈도우를 벗어나지 않게 했습니다.
// - - - - - - -                                         
//**********************************************************************

#include <GL/glut.h>
GLdouble left=0, right = 0 , up = 0, down = 0; //가로세로 좌표의 증감을 조절할 변수
GLdouble r = 0.5, g = 0.5, b = 0.5; //RGB 초기는 회색이므로 모두 0.5

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);   //컬러버퍼 초기화
    glColor3f(r, g, b);             //도형 색 (0.5,0.5,0.5) 회색
    glBegin(GL_POLYGON);            //GL_POLYGON, 다각형 그리기 시작
    glVertex3f(-0.5 + left, -0.5 + down, 0.0);  
    glVertex3f(0.5 + right, -0.5 + down, 0.0);  
    glVertex3f(0.5 + right, 0.5 + up, 0.0); 
    glVertex3f(-0.5 + left, 0.5 + up, 0.0);    //점 네개의 좌표설정
    glEnd();                        //끝
    glFlush();  //출력
}

void MySpecial(int key, int x, int y) {
    switch (key) {
        /*오른쪽 화살표를 누르면 x좌표가 0.1씩 늘어나고
          화면에 벗어나지 않도록 범위를 조절했습니다*/
    case GLUT_KEY_RIGHT:
        if (right < 0.5) {
            left = left + 0.1; right = right + 0.1;
        }
            break;
        /*왼쪽 화살표를 누르면 x좌표가 0.1씩 줄어들고
          화면에 벗어나지 않도록 범위를 조절했습니다*/
    case GLUT_KEY_LEFT:
        if (left > -0.5) {
            left = left - 0.1; right = right - 0.1;
        }
        
        break;
        /*아래쪽 화살표를 누르면 x좌표가 0.1씩 줄어들고
          화면에 벗어나지 않도록 범위를 조절했습니다*/
    case GLUT_KEY_DOWN:
        if (down > -0.5) {
            up = up - 0.1; down = down - 0.1;
        }
        break;
        /*위쪽 화살표를 누르면 x좌표가 0.1씩 늘어나고
          화면에서 벗어나지 않도록 범위를 조절했습니다*/
    case GLUT_KEY_UP:
        if (up < 0.5) {
            up = up + 0.1; down = down + 0.1;
        }break;
        /*PAGE_DOWN을 누르면 각 좌표가 서로 중심을 향해 줄어들고
          화면에서 벗어나지 않도록 범위를 조절했습니다*/
    case GLUT_KEY_PAGE_DOWN:
        if (left < 0.5 && right>-0.5 && down<0.5 && up > -0.5) {
            left += 0.1; right -= 0.1; up -= 0.1; down += 0.1;
        }
        break;
        /*PAGE_DOWN을 누르면 각 좌표가 서로 중심에 반대를 향해 줄어들고
          화면에서 사라져 없어지지는 않게 범위를 조절했습니다*/
    case GLUT_KEY_PAGE_UP:
        if (left > -0.5 && right<0.5 && down>-0.5 &&  up < 0.5) {
            left -= 0.1; right += 0.1; up += 0.1; down -= 0.1; break;
        }
    default:
        break;
    }
    glutPostRedisplay(); //프로그램 내용이 변경되었을 때 윈도우를 출력하도록 하는 함수
}
void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0); //배경색 흰색
    glMatrixMode(GL_PROJECTION); //투영행렬 선택
    glLoadIdentity();   //현재 행렬을 항등행렬로 선택

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //가시부피 설정
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB); //디스플레이 GLUT_RGB모드
    glutInitWindowSize(300, 300); //300 X 300
    glutInitWindowPosition(0, 0); //윈도우 위치 (0,0)
    glutCreateWindow("Keyboard Callback(2)");
    MyInit(); //초기화
    glutDisplayFunc(MyDisplay); //display 이벤트
    glutSpecialFunc(MySpecial); //키보드 이벤트

    glutMainLoop();
    return 0;
}