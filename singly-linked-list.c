/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
		printf("=====================2018038083 이인규==========================\n");
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while(p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
	
	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//새로삽입할 노드생성
	listNode *p=h->first;	//헤더의 포인터를 대신해 쓸 p
	new->key=key;	
	if(h->first==NULL){	//연결리스트가 비어있다면
		h->first=new;	//헤더와 new를 잇고
		new->link=NULL;	//new는 NULL을 가리키게 합니다
	}
	else {
		while(p->link!=NULL){	//연결리스트가 비어있지않다면
			p=p->link;	//마지막노드를 찾아갈때까지 반복문을 돌리고
		}
		p->link=new;	//마지막노드가 new를 가리키게 한다음
		new->link=NULL;	//new에는 NULL값을 넣습니다.
	}
	
	return 0;
}


/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
	listNode *p=h->first;
	if(h->first==NULL){	//헤드가 마지막이면
		return 0;		//함수를 끝냅니다
	}
	else{						//헤드가 마지막이 아니면
		 h->first = p->link;	//헤드를 그 뒤에 있는 노드와 이어줍니다
     	free(p);				//첫번째노드인 p를 해제합니다
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
	listNode *p=h->first;
	listNode *delete_p;

	if(h->first==NULL){	//헤드가 비었다면
		return 0;		//종료합니다
	}
	else if (p->key==key){	//헤드가 찾는것이라면
		deleteFirst(h);
		return 0;		//deleteFirst함수를 호출해 첫 노드를 지웁니다
	}
	while(p->link!=NULL){		
		if(p->link->key==key){
			delete_p=p->link;
			if(delete_p->link!=NULL){//마지막항이 아니면 prev_p항을 delete_p가 가리키는것과 이어줍니다.
				p->link=delete_p->link;
				free(delete_p);
			}
			else{
				p->link=NULL;
				free(delete_p);	
			}			//마지막항이면 prev_p를 마지막항으로 해줍니다.
			return 0;		
		}	
		p=p->link;	//p 노드를 한칸씩 이동시킵니다
	}
	if(p->link==NULL){
		printf("숫자가 없어요!\n");
		return 0;
	}
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	listNode *p=h->first;
	listNode *prev_p;
	
	if(h->first==NULL){	//헤드노드가 마지막노드면
		return 0;		//종료합니다.
	}
	else {						//헤드노드가 마지막노드가 아니면
		while(p->link!=NULL){	//마지막 노드를 찾습니다 
			prev_p->link=p;		//prev_p가 p를 가리킵니다
			p=p->link;			//p를 다음노드로 옮깁니다
		}		
		free(p);				//마지막노드인 p를 지웁니다
		prev_p->link=NULL;		//마지막 노드의 직전노드인 prev_p를 마지막노드로 만듭니다.
	}
	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {

	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}

