#include <stdio.h>
int main()
{
char charType;
int integerType;
float floatType;
double doubleType;

printf("----- [���α�] [2018038083] -----\n");

printf("Size of char: %ld byte\n",sizeof(charType));        //char ������ ������ ũ��
printf("Size of int: %ld bytes\n",sizeof(integerType));     //int ������ ������ ũ��
printf("Size of float: %ld bytes\n",sizeof(floatType));     //float ������ ������ ũ��
printf("Size of double: %ld bytes\n",sizeof(doubleType));   //double ������ ������ ũ��
    
printf("-----------------------------------------\n");
    
printf("Size of char: %ld byte\n",sizeof(char));    //char �������� ũ��
printf("Size of int: %ld bytes\n",sizeof(int));     //int �������� ũ��
printf("Size of float: %ld bytes\n",sizeof(float));     //float �������� ũ��
printf("Size of double: %ld bytes\n",sizeof(double));   //double �������� ũ��
    
    printf("-----------------------------------------\n");
    
printf("Size of char*: %ld byte\n",sizeof(char*));  //char�� �������� ũ��
printf("Size of int*: %ld bytes\n",sizeof(int*));   //int�� �������� ũ��
printf("Size of float*: %ld bytes\n",sizeof(float*));   //float�� �������� ũ��
printf("Size of double*: %ld bytes\n",sizeof(double*));     //double�� �������� ũ��

return 0;
}