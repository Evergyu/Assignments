/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해 할것 */
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
        - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
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
		printf("                     Doubly Linked  List                        \n");
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
			initialize(&headnode);
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


int initialize(headNode** h) {
	if (*h!=NULL){
		freeList(*h);	//헤드노드가 비어있지 않다면 모두 초기화 해줍니다.
	}
	
	headNode* temp = (headNode*)malloc(sizeof(headNode));	//새로운 헤드노드 동적할당
	temp->first = NULL;	//새 헤드노드->first에 NULL 값을 넣고
	*h=temp;		//헤드노드 와 temp가 같은곳을 가리키게 잇습니다.	
	return 1;
}

int freeList(headNode* h){
	listNode* p = h->first;	//h->p를 가리킨다

	listNode* prev = NULL;		//이전노드를 넣을 임시노드

	if(p==NULL){				//헤드밖에 없을 때
		free(h);				//헤드를 해제하고 종료합니다.
		return 0;
	}

	while(p->rlink != NULL) {	//p->rlink가 NULL이 아니라면
		prev=p;			//prev와 p가 같은 노드를 보게하고
		p=p->rlink;		//p를 한칸 옮긴 후
		p->llink=NULL;	//p->llink에 NULL값을 넣은 후
		free(prev);		//이전노드 해제
	}
	free(h);			//헤드노드도 해제

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
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}




/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//새 노드 생성
	listNode *prev=h->first;		//h가 prev를 가리키게 합니다
	new->key=key;
	if(h->first==NULL){	//연결리스트가 비어있다면
		h->first=new;	//h가 new를 가리키게 잇고
		new->rlink=NULL;//new->rlink==NULL 이게 한 다음
		new->llink=NULL;//new의 llinks는 NULL을 가리키게 합니다.
	}
	else{
		while(prev->rlink!=NULL){ 	//prev노드 다음노드가 마지막일 때까지
			prev=prev->rlink;		//prev노드를 옮겨줍니다.
		}
		new->rlink=prev->rlink;		//new노드의 rlink에 NULL값을 넣은다음
		prev->rlink=new; 			//prev->new 가 되게 이어줍니다.
		new->llink=prev;			//new노드의 llink가 이전노드를 보게 합니다.
	}
	return 0;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	listNode *p=h->first;	//헤더의 포인터를 대신해 쓸 p
	listNode *prev,*delete;	//지울노드와 지울노드 바로전 노드를 저장할 포인터
	if(h->first==NULL){	//노드가 없을 때
		printf("리스트가 비어있습니다.\n");	//리스트가 비어있다는 문구 출력
		return 0;
	}
	else if(p->rlink==NULL){ //첫 노드가 마지막 노드일 때
		deleteFirst(h);		 //deleteFirst(h) 함수를 호출해서 지웁니다.
		return 0;
	}
	else{
		while(p->rlink->rlink!=NULL){	//지울노드->rlink 가 NULL이 될때까지
			p=p->rlink;					//p를 증가시킴
			}
			prev=p;						//prev에 p를 넣고
			delete=p->rlink;			//지울노드는 p 다음노드로 놓습니다
			free(delete);				//노드를 지우고
			prev->rlink=NULL;			//prev가 마지막 노드이므로 rlink에 NULL
			prev->llink=p->llink;		//llink에는 p->llink를 넣습니다.		
	}

	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//새 노드를 동적할당
	new->key=key;	//새노드의 key에 key값을 넣습니다

	new->rlink=h->first;	//new->rlink가 헤드가 가리키던곳을 보게 하고
	h->first=new;			//헤드가 new를 가리키게 잇습니다.
	new->llink=NULL;			//new->llink는 자신을 가리키게 합니다.

	return 0;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {
	listNode *delete=h->first;
	if(h->first==NULL){	//노드가 없을 때
		printf("리스트가 비어있습니다.\n");	//리스트가 비어있다는 문구 출력
		return 0;
	}
	else {				//노드가 있을 때
		h->first=delete->rlink;	//헤더가 지울 노드(첫노드)가 가리키는것을 가리키게 합니다
		free(delete);			//지울 노드를 free합니다.
		return 0;
	}
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
	listNode *p=h->first;			//헤드가 가리키는곳을 가리키는 p
	listNode *reverse,*next,*head;	//임시 변수들
	if(h->first==NULL){				//노드가 없다면
		printf("리스트가 비어있습니다.\n");	//안내문구 출력 후 종료
		return 0;
	}
	else if(h->first->rlink==NULL){			//노드가 하나면 역순이 의미가 없으므로 종료
		return 0;
	}	
	else{
		while(p->rlink!=NULL){		//먼저 p를 마지막노드로 이동시킵니다.		
			p=p->rlink;
		}	
		reverse=p;					//마지막노드를 가리키는 두 포인터 reverse,head
		head=p;
		while(reverse->llink!=NULL){	//reverse를 왼쪽으로 이동시키며 노드를 바꿉니다,
			next=reverse->llink;		//reverse->llink 값을 갖고있을 next
			reverse->llink=reverse->rlink;	//reverse->llink를 rlink로
			reverse->rlink=next;			//reverse->rlink=reverse->llink로 바꿔줍니다,
			reverse=reverse->rlink;			//reverse를 한칸 이동시키고
		}
			next=reverse->llink;			//reverse가 마지막노드일 때는 실행을 안하기때문에
			reverse->llink=reverse->rlink;	//한번 더 실행해줍니다.
			reverse->rlink=next;
			reverse=reverse->rlink;
			h->first=head;					//헤드는 마지막노드 head에 붙입니다.
	}
	return 0;
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//새로운노드
	listNode *p=h->first;
	new->key=key;	//new의 key에 키값을 넣습니다.
	if(h->first==NULL){		//노드가 없을때
		insertFirst(h,key);	//insertFirst함수를 호출해 첫 노드에 새 노드를 넣습니다.
		free(new);			//쓰이지 않는 new 노드를 해제합니다.
	}
	else if(new->key < p->key){	//첫노드가 입력받은 값보다 클때
		insertFirst(h,key);				//insertFirst함수를 호출해 첫 노드에 새 노드를 넣습니다.
		free(new);						//쓰이지 않는 new 노드를 해제합니다.
	}
	else{
		while(p->rlink!=NULL){
			if(new->key < p->rlink->key){	//새로들어온 값보다 큰 값을 가진 노드를 만나면
				new->rlink=p->rlink;	//p가 가리키는 곳을 new가 가리키게 하고
				p->rlink=new;			//p가 new를 향하게 합니다.
				new->llink=p;
				new->rlink->llink=new;
				return 0;
			}
			p=p->rlink;				//p를 한칸씩 옮겨줍니다.
		}
		if(p->rlink==NULL){			//p가 마지막 노드일 때
			insertLast(h,key);		//insertLast함수를 호출해 마지막노드에 새 노드를 넣습니다.
			free(new);				//쓰이지않는 new노드를 해제합니다.
		}
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
	listNode *p=h->first;
	listNode *prev,*delete;
	if(h->first==NULL){	//노드가 비었다면
		printf("리스트가 비었습니다.\n");	//안내문구출력
		return 1;
	}
	else if(p->key==key){	//제일 첫 노드가 찾는 노드라면
		deleteFirst(h);		//deleteFirst함수를 호출해 지워줍니다.
		return 1;
	}
	else if(p->rlink->key==key&&p->rlink->rlink==NULL){//두번째 노드가 찾는 노드고 노드의 수가
		deleteLast(h);								   //2라면 deleteLast 함수를 호출해 지웁니다.
		return 1;
		
	}		
	else {
		prev=p;
		delete=p->rlink;	
		while(p->rlink!=NULL){	
			if(delete->key==key){	//p가 마지막노드가 아니고 p의 다음노드가 key를 갖고있다면
				prev->rlink=delete->rlink;	//prev를 delete가 가리키는 곳을 가리키게 하고
				delete->rlink->llink=prev;	//delete 다음노드의 llink를 prev에 연결
				free(delete);				//후 delete를 free합니다.
				return 1;
			}
		p=p->rlink;	//while문 한루프당 p한칸씩 이동
		}
		if(p->key==key){	//마지막노드가 key를 가지고 있을 때 
			deleteLast(h);	//deleteLast함수를 호출해 지워줍니다.
			return 1;	
		}
		if (p->rlink==NULL){
		printf("찾는 key를가진 노드는 없어요\n");	//모든 if문에도 걸리지 않는다면 숫자가 없으므로
		return 1;						//안내문 출력
		}
	}
}



