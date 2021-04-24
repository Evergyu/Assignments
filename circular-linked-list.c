/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* 함수 리스트 */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{
	char command;
	int key;
	listNode* headnode=NULL;

	do{
		printf("------------2018038083-----------------이인규-------------------\n");
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
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


int initialize(listNode** h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* 메모리 해제 */
int freeList(listNode* h){
	listNode* p = h->rlink;	//포인터p=h->rlink

	listNode* prev = NULL;		//이전노드를 넣을 임시노드

	if(p==NULL){				//헤드밖에 없을 때
		free(h);				//헤드를 해제하고 종료합니다.
		return 0;
	}

	while(p->rlink != h) {	//p->rlink가 NULL이 아니라면
		prev=p;			//prev와 p가 같은 노드를 보게하고
		p=p->rlink;		//p를 한칸 옮긴 후
		free(prev);		//이전노드 해제
	}
	free(h);			//헤드노드도 해제

	return 0;
}



void printList(listNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->rlink;

	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}
	printf("  items = %d\n", i);


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		p = p->rlink;
		i++;
	}

}



/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(listNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//새 노드 생성
	listNode *p=h->rlink;		//h가 p를 가리키게 합니다
	new->key=key;
	
	if(h->rlink==h && h->llink==h){	//연결리스트가 비어있다면
		new->rlink=h->rlink;		//new->rlink가 헤드가 가리키던곳을 보게 하고
		h->rlink=new;				//헤드가 new를 가리키게 잇습니다.
		new->llink=h;				//new->llink는 h를 가리키게 합니다.
		new->rlink->llink=new; 		//new의 오른쪽노드의 llink가 new를보게 이어줍니다.
	}
	else{
		while(p->rlink!=h){ 	//prev노드 다음노드가 마지막일 때까지
			p=p->rlink;			//p노드를 옮겨줍니다.
		}
		new->rlink=p->rlink;	//new노드의 rlink가 p가바라보던 곳(헤드)가 되게 이어줍니다.
		p->rlink=new;			//p->rlink==new 가 되게 이어줍니다.
		new->llink=p; 			//new->llink==p 가 되게 이어줍니다.
		h->llink=new;			//헤드노드의 llink가 새로 추가한 마지막 노드new를 보게 합니다.
	}
	return 0;
	return 1;
}


/**
 * list의 마지막 노드 삭제
 */
int deleteLast(listNode* h) {
	listNode *p=h->rlink;	//헤더의 포인터를 대신해 쓸 p
	listNode *prev,*delete;	//지울노드와 지울노드 바로전 노드를 저장할 포인터
	if(h->rlink==h&&h->llink==h){	//노드가 없을 때
		printf("리스트가 비어있습니다.\n");	//리스트가 비어있다는 문구 출력
		return 0;
	}
	else if(p->rlink==h){ //첫 노드가 마지막 노드일 때
		deleteFirst(h);		 //deleteFirst(h) 함수를 호출해서 지웁니다.
		return 0;
	}
	else{
		while(p->rlink->rlink!=h){	//지울 노드를 p->rlink라 할 때 마지막 노드 전까지 p를 옮겨줍니다.
			p=p->rlink;					//p를 증가시킴
			}
			prev=p;						//prev에 p를 넣고
			delete=p->rlink;			//지울노드는 p 다음노드로 놓습니다
			prev->rlink=delete->rlink;	//prev->rlink==delete->rlink(헤드)가 되게 이어줍니다.
			free(delete);				//노드를 지웁니다.
			h->llink=prev;				//헤드의 llink가 prev를 보게 합니다.
	}

	return 0;

	return 1;
}


/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(listNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//새 노드를 동적할당
	new->key=key;	//새노드의 key에 key값을 넣습니다

	new->rlink=h->rlink;	//new->rlink가 헤드가 가리키던곳을 보게 합니다.
	h->rlink=new;			//h->rlink==new 가 되게 이어줍니다.
	new->llink=h;			//new->llink==h 가 되게 이어줍니다.
	new->rlink->llink=new; 	//new의 오른쪽노드의 llink가 new를보게 이어줍니다.
	
	return 1;
}

/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(listNode* h) {
	listNode *delete=h->rlink;
	if(h->rlink==h && h->llink==h){	//노드가 없을 때
		printf("리스트가 비어있습니다.\n");	//리스트가 비어있다는 문구 출력
		return 0;
	}
	else {				//노드가 있을 때
		h->rlink=delete->rlink;	
		//헤더가 지울 노드(첫노드)가 가리키는것을 가리키게 합니다
		h->rlink->llink=h;
		free(delete);			//지울 노드를 free합니다.
		return 0;
	}

	return 1;

}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(listNode* h) {
	listNode *p=h->rlink;

	return 0;
}



/**
 *  리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 
 **/
int insertNode(listNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//새로운노드
	listNode *p=h->rlink;

	new->key=key;	//new의 key에 키값을 넣습니다.
	if(h->rlink==h && h->llink==h){		//노드가 없을때
		insertFirst(h,key);	//insertFirst함수를 호출해 첫 노드에 새 노드를 넣습니다.
		free(new);			//쓰이지 않는 new 노드를 해제합니다.
	}
	else if(new->key < p->key){	//노드가 1개있을 때 그 노드의 key가 새로운 노드의 key보다 크면
		insertFirst(h,key); //새 노드를첫노드로 추가합니다.
		free(new);			//쓰지않는 new를 해제해줍니다.
	}
	else{
		while(p->rlink!=h){					//p->rlink==h 이기 전까지 즉 마지막노드에 도달하기 전까지 돌아가는 반복문
			if(new->key < p->rlink->key){	//새로들어온 값보다 큰 값을 가진 노드를 만나면
				new->rlink=p->rlink;	//p가 가리키는 곳을 new가 가리키게 하고
				p->rlink=new;			//p가 new를 향하게 합니다.
				new->llink=p;			//new->llink=p가 되게 이어줍니다.
				new->rlink->llink=new;	//new의 오른쪽노드의 llink가 new가 되도록 해줍니다.
				return 0;
			}
		
			p=p->rlink;				//p를 한칸씩 옮겨줍니다.
		}
		if(p->rlink==h){			//p가 마지막 노드일 때
			insertLast(h,key);		//insertLast함수를 호출해 마지막노드에 새 노드를 넣습니다.
			free(new);				//쓰이지않는 new노드를 해제합니다.
		}
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(listNode* h, int key) {
	listNode *p=h->rlink;
	listNode *prev,*delete;
	if(h->rlink==h && h->llink==h){	//노드가 비었다면
		printf("리스트가 비었습니다.\n");	//안내문구출력
		return 0;
	}
	else if(p->key==key){	//제일 첫 노드가 찾는 노드라면
		deleteFirst(h);		//deleteFirst함수를 호출해 지워줍니다.
		return 1;
	}
	else if(p->rlink->key==key&&p->rlink->rlink==h){//두번째 노드가 찾는 노드고 노드의 수가
		deleteLast(h);								   //2라면 deleteLast 함수를 호출해 지웁니다.
		return 1;
	}		
	else {
		prev=p;
		delete=p->rlink;	
		while(p->rlink!=h){	
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
		if (p->rlink==h){	//모든 if문에도 걸리지 않는다면 숫자가 없으므로
		printf("찾는 key를가진 노드는 없어요\n");	//안내문 출력
		return 0;						
		}
	}
	return 0;
}


