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
    printf("[----- [�� �� ��]  [2018038083] -----]\n");

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
        printf(" Check the sizes of row and col!\n" );  //row,col ���� ������ �Է¹����� 
        return NULL;                                    //��ȯ���� �����ͱ� ������ NULL�� ��ȯ�մϴ�.
    }
    int **created_matrix = malloc(sizeof(int *) * row);
    if (created_matrix == NULL){
          printf("malloc ����\n");
          return -1; //�����Ҵ� ������ �߰ߵǸ� return -1
     }
    for (int i = 0; i < row; i++)            // ���� ũ�⸸ŭ �ݺ�
{
    created_matrix[i] = malloc(sizeof(int) * col);    // (int�� ũ�� * col)��ŭ ���� �޸� �Ҵ�. �迭�� ����
    if (created_matrix[i] == NULL){
          printf("malloc ����\n");
          return -1; //�����Ҵ� ������ �߰ߵǸ� return -1
     }
}
    return created_matrix;  //���� ������� matrix�� ��ȯ�մϴ�.
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    int i,j;
    for (i=0;i<row;i++){ //iXj ����̶� ����for������ iXj�� ���� ����մϴ�.
        for(j=0;j<col;j++){
            printf("%5d",matrix[i][j]); //matrix�� ���� ����մϴ�
        }
        printf("\n");   //���� col�� ����ϸ� ���� �ٲ��ݴϴ�
    }
    printf("\n");
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)    // ���� ũ�⸸ŭ �ݺ�
{
    free(matrix[i]);                  // 2���� �迭�� ���� ���� �޸� ����
    if(matrix[i]!=NULL){
        printf("free ����\n");      //free�� �����Ҵ��� ������������ �޸𸮰� �����ִٸ� -1�� ��ȯ
        return -1;
    }
}
free(matrix);
    if(matrix!=NULL){
        printf("free ����\n");  //free�� �����Ҵ��� ������������ �޸𸮰� �����ִٸ� -1�� ��ȯ
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
            matrix[i][j]=rand()%20; //rand()�Լ��� �̿��� 1~19�� ���ڸ� �������� �־��ݴϴ�
        }
    }
    return 1;
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i,j;
    int** matrix_add=create_matrix(row,col);    //�� matrix�� ���� ���� ������ matrix�� ������ݴϴ�.
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            matrix_add[i][j]=matrix_a[i][j]+matrix_b[i][j]; //�� matrix�� ���ؼ� matrix_add�� �־��ݴϴ�.
        }
    }
    print_matrix(matrix_add, row, col); //���� matrix�� ����մϴ�
    free_matrix(matrix_add,row,col);    //�� �� matrix�� �޸𸮸� �����մϴ�
    return 1;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i,j;
    int** matrix_sub=create_matrix(row,col);   //�� matrix�� �� ���� ������ matrix�� ������ݴϴ�.  
    
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            matrix_sub[i][j]=matrix_a[i][j]-matrix_b[i][j]; //�� matrix�� ���� matrix_add�� �־��ݴϴ�.
        }
    }
    print_matrix(matrix_sub, row, col); //�� matrix�� ����մϴ�.
    free_matrix(matrix_sub,row,col);    //�� �� matrix�� �޸𸮸� �����մϴ�.
    return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    int i,j=0;
    for (i=0;i<row;i++){
        for(j=0;j<col;j++){
            matrix_t[i][j]=matrix[j][i];    //matrix_t[i][j]�� matrix[j][i]�� ���� �ֽ��ϴ�.
        }
    }
    return 1;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    int i,j,k;
    int **matrix_mul=create_matrix(row,row);    //�� matrix�� ���� ���� ������ matrix�� ������ݴϴ�.
    for(i = 0; i < row; i++)
		for(j = 0; j < row; j++){
		matrix_mul[i][j] = 0;   //�� ���� ���� ���� �־�� �ϹǷ� 0���� �ʱ�ȭ���ݴϴ�.
			for(k = 0; k < col; k++)	
				matrix_mul[i][j] += matrix_a[i][k] * matrix_t[k][j];
                /*����� ���� ����� �� ���� 3X3��� a,b�� ���� �� 
                matrix_mul[2][2]=matrix_a[2][0]*matrix_b[0][2]+matrix_a[2][1]*matrix_b[1][2]+matrix[2][2]*matrix[2][2]
                �̷������� �ݺ����� k�ڸ��� ���ڸ� ���ϹǷ� i,j�� ���� ������ �ΰ� k�� ���� ��ȭ��Ű��
                ���� for������ ����� ���� �����ݴϴ�.*/
		}
    print_matrix(matrix_mul,row,row);    
    free_matrix(matrix_mul,row,row);   //�� �� matrix�� �޸𸮸� �����մϴ� 
    return 1;
}

