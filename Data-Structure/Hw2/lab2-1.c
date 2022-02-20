#include <stdio.h>
int main()
{
char charType;
int integerType;
float floatType;
double doubleType;

printf("----- [이인규] [2018038083] -----\n");

printf("Size of char: %ld byte\n",sizeof(charType));        //char 변수형 변수의 크기
printf("Size of int: %ld bytes\n",sizeof(integerType));     //int 변수형 변수의 크기
printf("Size of float: %ld bytes\n",sizeof(floatType));     //float 변수형 변수의 크기
printf("Size of double: %ld bytes\n",sizeof(doubleType));   //double 변수형 변수의 크기
    
printf("-----------------------------------------\n");
    
printf("Size of char: %ld byte\n",sizeof(char));    //char 변수형의 크기
printf("Size of int: %ld bytes\n",sizeof(int));     //int 변수형의 크기
printf("Size of float: %ld bytes\n",sizeof(float));     //float 변수형의 크기
printf("Size of double: %ld bytes\n",sizeof(double));   //double 변수형의 크기
    
    printf("-----------------------------------------\n");
    
printf("Size of char*: %ld byte\n",sizeof(char*));  //char형 포인터의 크기
printf("Size of int*: %ld bytes\n",sizeof(int*));   //int형 변수형의 크기
printf("Size of float*: %ld bytes\n",sizeof(float*));   //float형 변수형의 크기
printf("Size of double*: %ld bytes\n",sizeof(double*));     //double형 변수형의 크기

return 0;
}