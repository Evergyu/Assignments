#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[100];
    char str2[100]="hi";

    strcpy(str1,str2);
    printf("%s",str1);
}