#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct node {       //노드의 구조체입니다.
    int count;              //빈도수
    char alphabet;          //문자
    char *code;
    struct node* left;      //트리에서 쓰일 엣지 두개
    struct node* right;
    struct node* next;      //최소값을 찾을때 연결리스트에 쓰이는 엣지
}NODE;
int countt = 0;

char stack[MAX];            //스택
int top = -1,               //스택에쓰일 top
    height=0;               //높이에 쓰일 변수 height

NODE* CountString(char str[]);              //빈도수를 계산하는 함수입니다
void LinkNode(NODE* head, char character);  //노드를 추가해서 잇는 함수입니다.
NODE* AddNode(char character);              //노드를 추가하는 함수입니다.

NODE* FindSmall(NODE* head);                //연결리스트에서 가장 작은 값 찾기
NODE* RemoveLink(NODE* head, NODE* min);    //Min노드를 연결리스트에서 빼내기            
NODE* HuffmanTree(NODE* head);              //허프만트리 만들기

void Traversal(NODE* cur);                  //중위순회하며 각 노드에 코드추가
void push(char n);                          //스택에쓰일 푸시
char pop();                                 //팝

void encoding(char str[],NODE* TreeRoot);
void printcode(char c, NODE* p);

int main() {
    char str[MAX];                          //MAX만큼의 크기를 가진 캐릭터형 배열 str
    NODE* head, * TreeRoot;                             //빈도수 계산을 linked list로 해서 그 시작점을 맡을 노드포인터 
    int i;

    printf("Put the string to encode:");
    scanf("%s", str);                       //문자열 입력
    head = CountString(str);                //빈도수를 세서 연결리스트 생성 후 헤드노드 리턴 
    TreeRoot = HuffmanTree(head);           //헤드노드를 인자로받아 트리의 루트노드를 리턴
    Traversal(TreeRoot);                    //허프만트리의 리프노드에 각 변수에 대응하는 코드 리턴
    
    printf("\nencoding...\n\n");
    printf("Encoded Result : ");
    encoding(str,TreeRoot);
    return 0;
}

//빈도수 계산을 할 때 엣지들중 right엣지를 사용하여 linked list를 만들어 계산했습니다.
NODE* CountString(char str[]) {
    int i, j, k;
    NODE* prev = NULL, * p = NULL, * current = NULL;    //linkedlist 빈도수 계산에 쓰일 노드포인터들
    NODE* TEST;
    if (str[0] != '\0') p = AddNode(str[0]);        //가장 첫 노드는 추가합니다.
    current = p;

    for (i = 1; i < MAX; i++) {     //문자열의 크기만큼 반복문을 돌립니다
        if (str[i] == '\0') break;  //문자열이 끝나면 종료
        p = current;                //노드포인터 p에 current를 저장. 반복문이 돌면서 p가 다음 노드로이동하기 때문입니다.
        k = 0;
        while (p != NULL) {                  //p가 NULL이 아니면
            if (p->alphabet == str[i]) {    //노드 p의 문자와 문자열의 문자 str[i]를 비교하여 같으면
                p->count++;                 //count를 +1하고
                k = 1;                      //k=1로 만들어 밑에서 새 노드를 잇도록 하지 않습니다.
                break;
            }
            prev = p;
            p = p->next;
        }
        if (k == 0)    LinkNode(prev, str[i]);  //문자열의 문자가 linked list에 없다면 새로 노드를 만들어 이어줍니다.
    }

    TEST = current;
    while (TEST != NULL) {
        printf("%c : %d\n", TEST->alphabet, TEST->count);
        TEST = TEST->next;
    }
    printf("\n");

    return current; //시작점을 가리키는 노드포인터 current를 리턴
}

void LinkNode(NODE* head, char character) {     //malloc으로 노드를 새로 동적할당하여 이어줍니다.
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->left = NULL; new->right = NULL;
    new->next = NULL;
    new->alphabet = character;
    new->count = 1;

    head->next = new;
}

NODE* AddNode(char character) {                 //malloc으로 노드를 새로 동적할당하여 리턴합니다. 
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->left = NULL; new->right = NULL;
    new->next = NULL;
    new->alphabet = character;
    new->count = 1;

    return new;
}

NODE* FindSmall(NODE* head) {   //연결리스트를 돌면서 count값이 가장 적은 노드를 리턴
    NODE* min = head;
    while (head != NULL) {
        if (head->count < min->count) min = head;
        head = head->next;
    }

    return min;
}

/*min노드를 연결리스트에서 삭제
  경우1 : min노드가 가장 앞에있을경우
  경우2 : min노드가 중간에 있을 경우
  경우3 : min노드가 가장 끝에 있을 경우*/
NODE* RemoveLink(NODE* head, NODE* min) {
    NODE* p = head, * prev = head, * cur = NULL;

    if (head == NULL) return 0;

    while (p != NULL) {     //먼저 p를 이동시켜가며 min노드의 주소에 p를 이동시킵니다
        cur = p;
        if (p == min) {
            break;
        }
        prev = p;
        p = p->next;
    }

    if (prev == p) {        //prev와 p가 같으면 케이스1번입니다
        p->next == NULL;    //다음 노드로 연결된 엣지를 끊고
        return cur->next;   //헤드주소값으로 p다음 노드가 가야하므로 cur->next 리턴
    }
    if (p->next != NULL) {          //케이스2 min이 중간에 있을때
        prev->next = cur->next;     //이전노드와 다음노드를 이어주고
        cur->next = NULL;           //현재노드의 연결된 엣지를 끊어줍니다
        return head;                //헤드 리턴
    }
    if (p->next == NULL) {          //케이스3 min이 마지막노드일 때
        prev->next = NULL;          //min 노드와 연결된 엣지를 끊고
        return head;                //헤드 리턴
    }
}

NODE* HuffmanTree(NODE* head) {
    NODE* One, * Two, * parent = NULL;

    while (head->next != NULL) {            //head->next==NULL일 때 haed==루트
        One = FindSmall(head);              //연결리스트에서 가장 작은것을 One
        head = RemoveLink(head, One);       //One 노드의 엣지들을 끊고 헤드를 리턴
        Two = FindSmall(head);              //One이 없는 연결리스트에서 가장 작은것을 Two
        head = RemoveLink(head, Two);       //Two 노드의 엣지들을 끊고 헤드를 리턴


        //printf("%c : %d\n", One->alphabet, One->count);
        //printf("%c : %d\n", Two->alphabet, Two->count);
        //printf("\n");

        parent = (NODE*)malloc(sizeof(NODE));       //parent노드를 하나 만들어
        parent->left = One; parent->right = Two;    //최소노드 두개를 left,right엣지로 연결합니다.
        parent->next = NULL;
        parent->alphabet = '\0';
        parent->count = One->count + Two->count;    //count값은 두 노드의 합으로 합니다.

        parent->next = head;                        //연결리스트의 첫 노드인 헤드에 panrent를 잇고
        head = parent;                              //parent를 헤드로 초기화합니다.
    }

    return parent;  //반복문을 나왔을 때 parent==루트노드 이므로 return parent 해줍니다.
}

void Traversal(NODE* cur) //중위순회를 하면서
{
    if (cur == NULL){   //빈노드면
        pop();          //pop해주고 
        height--;       //높이 1감소
        return;         //종료
    }
    push('0');              //왼쪽으로 이동하면 스택에 0추가
    height++;               //높이 1증가
    Traversal(cur->left);   
    if (cur->left == 0 && cur->right == 0)                  //리프노드이면
    {
        cur->code = (char*)malloc(sizeof(char) * height);   //높이만큼 노드의 code를 동적할당
        strcpy(cur->code, stack);                           //스택에 쌓인 문자열 카피
        printf("%c : %s\n", cur->alphabet, cur->code);
    }
    push('1');              //오른쪽으로 이동하면 스택에 1추가
    height++;               //높이 1추가
    Traversal(cur->right);
    pop();                  //스택에서 한칸 제거
    height--;               //위 노드로 돌아가므로 1감소
}

void push(char c){                  //스택 푸시
    top += 1;                       //top을 1칸늘리고
    stack[top] = c;                 //stack[top]를 c(0 또는 1)로 초기화
}

char pop(){                         //스택 팝
    char result = stack[top];
    if(top>0) stack[top] = '\0';    //top을 한칸 줄이면서 스택에 초기화된 0또는 1을 NUL로 초기화
    top -= 1;                       //top--
    return result;
}

void encoding(char str[], NODE* TreeRoot){
    int i;
    
    for (i = 0; i < strlen(str); i++) {
        printcode(str[i], TreeRoot);
    }
}

void printcode(char c, NODE* p){
    if (p->left == NULL && p->right == NULL) {
        if (c == p->alphabet)  printf("%s ", p->code);
        return;
    }
    if (p->left != NULL) printcode(c, p);
    if (p->right != NULL) printcode(c, p);
}

