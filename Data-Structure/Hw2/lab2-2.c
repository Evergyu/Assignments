#include <stdio.h>
int main()
{
int i;
int *ptr;
int **dptr;

printf("----- [이인규] [2018038083] -----\n");

i = 1234;
printf("[checking values before ptr = &i] \n");     //ptr=&i전
printf("value of i == %d\n", i);    //i의값 == 1234
printf("address of i == %p\n", &i);    //i변수의 주소값 == 0061FF1C 
printf("value of ptr == %p\n", ptr);    //ptr의 값 = 1234 == 0022F000
printf("address of ptr == %p\n", &ptr);     //ptr의 주소값 == 0061FF18 
ptr = &i;

/* ptr is now holding the address of i */
printf("\n[checking values after ptr = &i] \n");    //ptr=&i후
printf("value of i == %d\n", i);    //i의 값 == 1234
printf("address of i == %p\n", &i);     //i의 주소 == 0061FF1C
printf("value of ptr == %p\n", ptr);    //ptr의 값 == 0061FF1C
printf("address of ptr == %p\n", &ptr);     //ptr의 주소값 == 0061FF18
printf("value of *ptr == %d\n", *ptr);  //*ptr의 값 == 1234
dptr = &ptr;

/* dptr is now holding the address of ptr */
printf("\n[checking values after dptr = &ptr] \n"); //dptr=&ptr후
printf("value of i == %d\n", i);    //i의 값 == 1234
printf("address of i == %p\n", &i);     //i의 주소값 == 0061FF1C
printf("value of ptr == %p\n", ptr);    //ptr의 값 == 0061FF1C
printf("address of ptr == %p\n", &ptr);     //ptr의 주소값 == 0061FF18
printf("value of *ptr == %d\n", *ptr);      //*ptr의 값 == 1234
printf("value of dptr == %p\n", dptr);      //dptr의 값 == 0061FF18
printf("address of dptr == %p\n", &dptr);    //dptr의 주소값 == 0061FF14
printf("value of *dptr == %p\n", *dptr);    //*dptr의 값 == 0061FF1C
printf("value of **dptr == %d\n", **dptr);  //**dptr의 값 == 1234
*ptr = 7777;

/* changing the value of *ptr */
printf("\n[after *ptr = 7777] \n"); //*ptr=7777 후
printf("value of i == %d\n", i);    //i의 값 == 7777
printf("value of *ptr == %d\n", *ptr);  //*ptr의 값 == 7777
printf("value of **dptr == %d\n", **dptr);  //**dptr의 값 == 7777
**dptr = 8888;

/* changing the value of **dptr */
printf("\n[after **dptr = 8888] \n");   //**dptr=8888 후
printf("value of i == %d\n", i);    //i의 값 == 8888
printf("value of *ptr == %d\n", *ptr);//*ptr의 값 == 8888
printf("value of **dptr == %d\n", **dptr);  //**dptr의 값 == 8888
return 0;
}