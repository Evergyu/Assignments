#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct node {       //노드의 구조체입니다.
    int count;              //빈도수
    char alphabet;          //문자
    struct node* left;      //트리에서 쓰일 엣지 두개
    struct node* right;
}NODE;


NODE* CountString(char str[]);              //빈도수를 계산하는 함수입니다
void LinkNode(NODE* head, char character);  //노드를 추가해서 잇는 함수입니다.
NODE* AddNode(char character);              //노드를 추가하는 함수입니다.

int main() {
    char str[MAX];                          //MAX만큼의 크기를 가진 캐릭터형 배열 str
    NODE* node;                             //빈도수 계산을 linked list로 해서 그 시작점을 맡을 노드포인터 

    printf("Put the string to encode:");    
    scanf("%s", str);                       //문자열 입력
    node=CountString(str);

    while (node != NULL) {
        printf("%c : %d\n", node->alphabet, node->count);
        node = node->right;
    }
    return 0;
}

//빈도수 계산을 할 때 엣지들중 right엣지를 사용하여 linked list를 만들어 계산했습니다.
NODE* CountString(char str[]) {
    int i, j, k;
    NODE* prev = NULL, * p = NULL,*current=NULL;    //linkedlist 빈도수 계산에 쓰일 노드포인터들

    if (str[0] != '\0') p = AddNode(str[0]);        //가장 첫 노드는 추가합니다.
    current = p;

    for (i = 1; i < MAX; i++) {     //문자열의 크기만큼 반복문을 돌립니다
        if (str[i] == '\0') break;  //문자열이 끝나면 종료
        p = current;                //노드포인터 p에 current를 저장. 반복문이 돌면서 p가 다음 노드로이동하기 때문입니다.
        k = 0;
        while (p!= NULL) {                  //p가 NULL이 아니면
            if (p->alphabet == str[i]) {    //노드 p의 문자와 문자열의 문자 str[i]를 비교하여 같으면
                p->count++;                 //count를 +1하고
                k = 1;                      //k=1로 만들어 밑에서 새 노드를 잇도록 하지 않습니다.
                break;
            }
            prev = p;
            p = p->right;
        }
        if (k == 0)    LinkNode(prev, str[i]);  //문자열의 문자가 linked list에 없다면 새로 노드를 만들어 이어줍니다.
    }
   
    return current; //시작점을 가리키는 노드포인터 current를 리턴
}

void LinkNode(NODE* head, char character) {     //malloc으로 노드를 새로 동적할당하여 이어줍니다.
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->left = NULL; new->right = NULL;
    new->alphabet = character;
    new->count = 1;

    head->right = new;
}

NODE* AddNode(char character) {                 //malloc으로 노드를 새로 동적할당하여 리턴합니다. 
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->left = NULL; new->right = NULL;
    new->alphabet = character;
    new->count = 1;
    
    return new;
}