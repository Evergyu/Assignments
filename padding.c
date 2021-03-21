#include <stdio.h>

struct student{
    char lastName[13];  /* 13 bytes */
    int studentId;  /* 4 bytes */
    short grade;    /* 2 bytes */
};

int main(){
    struct student pst;

    printf("----2018038083----¿Ã¿Œ±‘----\n");
    printf("size of student = %ld\n",sizeof(struct student));
    printf("size of int = %ld\n",sizeof(int));
    printf("size of short = %ld\n",sizeof(short));

    return 0;
}