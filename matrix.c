#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [이 인 규]  [2018038083] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;}

    do{
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    if(row <= 0 || col <=0) {
        printf(" Check the sizes of row and col!\n" );  //row,col 값에 음수를 입력받으면 
        return NULL;                                    //반환형이 포인터기 때문에 NULL을 반환합니다.
    }
    int **created_matrix = malloc(sizeof(int *) * row);
    if (created_matrix == NULL){
          printf("malloc 오류\n");
          return -1; //동적할당 오류가 발견되면 return -1
     }
    for (int i = 0; i < row; i++)            // 세로 크기만큼 반복
{
    created_matrix[i] = malloc(sizeof(int) * col);    // (int의 크기 * col)만큼 동적 메모리 할당. 배열의 가로
    if (created_matrix[i] == NULL){
          printf("malloc 오류\n");
          return -1; //동적할당 오류가 발견되면 return -1
     }
}
    return created_matrix;  //새로 만들어진 matrix를 반환합니다.
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    int i,j;
    for (i=0;i<row;i++){ //iXj 행렬이라 이중for문으로 iXj번 돌려 출력합니다.
        for(j=0;j<col;j++){
            printf("%5d",matrix[i][j]); //matrix의 값을 출력합니다
        }
        printf("\n");   //값을 col번 출력하면 행을 바꿔줍니다
    }
    printf("\n");
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
{
    free(matrix[i]);                  // 2차원 배열의 가로 공간 메모리 해제
    if(matrix[i]!=NULL){
        printf("free 오류\n");      //free로 동적할당을 해제했음에도 메모리가 남아있다면 -1을 반환
        return -1;
    }
}
free(matrix);
    if(matrix!=NULL){
        printf("free 오류\n");  //free로 동적할당을 해제했음에도 메모리가 남아있다면 -1을 반환
        return -1;
    }
return 1;
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            matrix[i][j]=rand()%20; //rand()함수를 이용해 1~19의 숫자를 랜덤으로 넣어줍니다
        }
    }
    return 1;
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i,j;
    int** matrix_add=create_matrix(row,col);    //두 matrix를 더한 값을 저장할 matrix를 만들어줍니다.
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            matrix_add[i][j]=matrix_a[i][j]+matrix_b[i][j]; //두 matrix를 더해서 matrix_add에 넣어줍니다.
        }
    }
    print_matrix(matrix_add, row, col); //더한 matrix를 출력합니다
    free_matrix(matrix_add,row,col);    //다 쓴 matrix의 메모리를 해제합니다
    return 1;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i,j;
    int** matrix_sub=create_matrix(row,col);   //두 matrix를 뺀 값을 저장할 matrix를 만들어줍니다.  
    
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j]; //두 matrix를 빼서 matrix_add에 넣어줍니다.
        }
    }
    print_matrix(matrix_sub, row, col); //뺀 matrix를 출력합니다.
    free_matrix(matrix_sub,row,col);    //다 쓴 matrix의 메모리를 해제합니다.
    return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    int i,j=0;
    for (i=0;i<row;i++){
        for(j=0;j<col;j++){
            matrix_t[i][j]=matrix[j][i];    //matrix_t[i][j]에 matrix[j][i]의 값을 넣습니다.
        }
    }
    return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    int i,j,k;
    int **matrix_mul=create_matrix(row,row);    //두 matrix를 곱한 값을 저장할 matrix를 만들어줍니다.
    for(i = 0; i < row; i++)
		for(j = 0; j < row; j++){
		matrix_mul[i][j] = 0;   //각 항을 곱한 값을 넣어야 하므로 0으로 초기화해줍니다.
			for(k = 0; k < col; k++)	
				matrix_mul[i][j] += matrix_a[i][k] * matrix_t[k][j];
                /*행렬의 곱을 계산할 때 만약 3X3행렬 a,b를 곱할 때 
                matrix_mul[2][2]=matrix_a[2][0]*matrix_b[0][2]+matrix_a[2][1]*matrix_b[1][2]+matrix[2][2]*matrix[2][2]
                이런식으로 반복문의 k자리의 숫자만 변하므로 i,j의 값을 고정해 두고 k의 값만 변화시키며
                삼중 for문으로 행렬의 곱을 구해줍니다.*/
		}
    print_matrix(matrix_mul,row,row);    
    free_matrix(matrix_mul,row,row);   //다 쓴 matrix의 메모리를 해제합니다 
    return 1;
}

