#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[100];
    int i,j;
    scanf("%s",str);
    
    for(i=0;i<100;i++){
        for(j=0;j<26;j++){
    if(str[i]==(char)(65 + j)||str[i]==(char)(97 + j)) {
                printf("%c",str[i]);    
            }
        }
        if(str[i]=='\0') break;
    }


}