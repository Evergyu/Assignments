#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[100]="\0";
    char str2[100]="hi";
    char str3[100]=" hello";
    strcat(str1,str2);
    strcat(str1,str3);
    printf("%s",str1);

}