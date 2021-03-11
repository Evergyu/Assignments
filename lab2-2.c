#include <stdio.h>
int main()
{
int i;
int *ptr;
int **dptr;

printf("----- [���α�] [2018038083] -----\n");

i = 1234;
printf("[checking values before ptr = &i] \n");     //ptr=&i��
printf("value of i == %d\n", i);    //i�ǰ� == 1234
printf("address of i == %p\n", &i);    //i������ �ּҰ� == 0061FF1C 
printf("value of ptr == %p\n", ptr);    //ptr�� �� = 1234 == 0022F000
printf("address of ptr == %p\n", &ptr);     //ptr�� �ּҰ� == 0061FF18 
ptr = &i;

/* ptr is now holding the address of i */
printf("\n[checking values after ptr = &i] \n");    //ptr=&i��
printf("value of i == %d\n", i);    //i�� �� == 1234
printf("address of i == %p\n", &i);     //i�� �ּ� == 0061FF1C
printf("value of ptr == %p\n", ptr);    //ptr�� �� == 0061FF1C
printf("address of ptr == %p\n", &ptr);     //ptr�� �ּҰ� == 0061FF18
printf("value of *ptr == %d\n", *ptr);  //*ptr�� �� == 1234
dptr = &ptr;

/* dptr is now holding the address of ptr */
printf("\n[checking values after dptr = &ptr] \n"); //dptr=&ptr��
printf("value of i == %d\n", i);    //i�� �� == 1234
printf("address of i == %p\n", &i);     //i�� �ּҰ� == 0061FF1C
printf("value of ptr == %p\n", ptr);    //ptr�� �� == 0061FF1C
printf("address of ptr == %p\n", &ptr);     //ptr�� �ּҰ� == 0061FF18
printf("value of *ptr == %d\n", *ptr);      //*ptr�� �� == 1234
printf("value of dptr == %p\n", dptr);      //dptr�� �� == 0061FF18
printf("address of dptr == %p\n", &dptr);    //dptr�� �ּҰ� == 0061FF14
printf("value of *dptr == %p\n", *dptr);    //*dptr�� �� == 0061FF1C
printf("value of **dptr == %d\n", **dptr);  //**dptr�� �� == 1234
*ptr = 7777;

/* changing the value of *ptr */
printf("\n[after *ptr = 7777] \n"); //*ptr=7777 ��
printf("value of i == %d\n", i);    //i�� �� == 7777
printf("value of *ptr == %d\n", *ptr);  //*ptr�� �� == 7777
printf("value of **dptr == %d\n", **dptr);  //**dptr�� �� == 7777
**dptr = 8888;

/* changing the value of **dptr */
printf("\n[after **dptr = 8888] \n");   //**dptr=8888 ��
printf("value of i == %d\n", i);    //i�� �� == 8888
printf("value of *ptr == %d\n", *ptr);//*ptr�� �� == 8888
printf("value of **dptr == %d\n", **dptr);  //**dptr�� �� == 8888
return 0;
}