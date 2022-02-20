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
/* �ʿ��� ������� �߰� if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* �Լ� ����Ʈ */

/* note: initialize�� ���������͸� �Ű������� ����
         singly-linked-list�� initialize�� �������� ���� �Ұ� */
int initialize(headNode** h);

/* note: freeList�� �̱������͸� �Ű������� ����
        - initialize�� �� �ٸ��� ���� �Ұ�
        - ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� */
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
		printf("=====================2018038083 ���α�==========================\n");
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
		freeList(*h);	//����尡 ������� �ʴٸ� ��� �ʱ�ȭ ���ݴϴ�.
	}
	
	headNode* temp = (headNode*)malloc(sizeof(headNode));	//���ο� ����� �����Ҵ�
	temp->first = NULL;	//�� �����->first�� NULL ���� �ְ�
	*h=temp;		//����� �� temp�� �������� ����Ű�� �ս��ϴ�.	
	return 1;
}

int freeList(headNode* h){
	listNode* p = h->first;	//h->p�� ����Ų��

	listNode* prev = NULL;		//������带 ���� �ӽó��

	if(p==NULL){				//���ۿ� ���� ��
		free(h);				//��带 �����ϰ� �����մϴ�.
		return 0;
	}

	while(p->rlink != NULL) {	//p->rlink�� NULL�� �ƴ϶��
		prev=p;			//prev�� p�� ���� ��带 �����ϰ�
		p=p->rlink;		//p�� ��ĭ �ű� ��
		p->llink=NULL;	//p->llink�� NULL���� ���� ��
		free(prev);		//������� ����
	}
	free(h);			//����嵵 ����

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
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//�� ��� ����
	listNode *prev=h->first;		//h�� prev�� ����Ű�� �մϴ�
	new->key=key;
	if(h->first==NULL){	//���Ḯ��Ʈ�� ����ִٸ�
		h->first=new;	//h�� new�� ����Ű�� �հ�
		new->rlink=NULL;//new->rlink==NULL �̰� �� ����
		new->llink=NULL;//new�� llinks�� NULL�� ����Ű�� �մϴ�.
	}
	else{
		while(prev->rlink!=NULL){ 	//prev��� ������尡 �������� ������
			prev=prev->rlink;		//prev��带 �Ű��ݴϴ�.
		}
		new->rlink=prev->rlink;		//new����� rlink�� NULL���� ��������
		prev->rlink=new; 			//prev->new �� �ǰ� �̾��ݴϴ�.
		new->llink=prev;			//new����� llink�� ������带 ���� �մϴ�.
	}
	return 0;
}



/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
	listNode *p=h->first;	//����� �����͸� ����� �� p
	listNode *prev,*delete;	//������� ������ �ٷ��� ��带 ������ ������
	if(h->first==NULL){	//��尡 ���� ��
		printf("����Ʈ�� ����ֽ��ϴ�.\n");	//����Ʈ�� ����ִٴ� ���� ���
		return 0;
	}
	else if(p->rlink==NULL){ //ù ��尡 ������ ����� ��
		deleteFirst(h);		 //deleteFirst(h) �Լ��� ȣ���ؼ� ����ϴ�.
		return 0;
	}
	else{
		while(p->rlink->rlink!=NULL){	//������->rlink �� NULL�� �ɶ�����
			p=p->rlink;					//p�� ������Ŵ
			}
			prev=p;						//prev�� p�� �ְ�
			delete=p->rlink;			//������� p �������� �����ϴ�
			free(delete);				//��带 �����
			prev->rlink=NULL;			//prev�� ������ ����̹Ƿ� rlink�� NULL
			prev->llink=p->llink;		//llink���� p->llink�� �ֽ��ϴ�.		
	}

	return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//�� ��带 �����Ҵ�
	new->key=key;	//������� key�� key���� �ֽ��ϴ�

	new->rlink=h->first;	//new->rlink�� ��尡 ����Ű������ ���� �ϰ�
	h->first=new;			//��尡 new�� ����Ű�� �ս��ϴ�.
	new->llink=NULL;			//new->llink�� �ڽ��� ����Ű�� �մϴ�.

	return 0;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
	listNode *delete=h->first;
	if(h->first==NULL){	//��尡 ���� ��
		printf("����Ʈ�� ����ֽ��ϴ�.\n");	//����Ʈ�� ����ִٴ� ���� ���
		return 0;
	}
	else {				//��尡 ���� ��
		h->first=delete->rlink;	//����� ���� ���(ù���)�� ����Ű�°��� ����Ű�� �մϴ�
		free(delete);			//���� ��带 free�մϴ�.
		return 0;
	}
}



/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
	listNode *p=h->first;			//��尡 ����Ű�°��� ����Ű�� p
	listNode *reverse,*next,*head;	//�ӽ� ������
	if(h->first==NULL){				//��尡 ���ٸ�
		printf("����Ʈ�� ����ֽ��ϴ�.\n");	//�ȳ����� ��� �� ����
		return 0;
	}
	else if(h->first->rlink==NULL){			//��尡 �ϳ��� ������ �ǹ̰� �����Ƿ� ����
		return 0;
	}	
	else{
		while(p->rlink!=NULL){		//���� p�� ���������� �̵���ŵ�ϴ�.		
			p=p->rlink;
		}	
		reverse=p;					//��������带 ����Ű�� �� ������ reverse,head
		head=p;
		while(reverse->llink!=NULL){	//reverse�� �������� �̵���Ű�� ��带 �ٲߴϴ�,
			next=reverse->llink;		//reverse->llink ���� �������� next
			reverse->llink=reverse->rlink;	//reverse->llink�� rlink��
			reverse->rlink=next;			//reverse->rlink=reverse->llink�� �ٲ��ݴϴ�,
			reverse=reverse->rlink;			//reverse�� ��ĭ �̵���Ű��
		}
			next=reverse->llink;			//reverse�� ����������� ���� ������ ���ϱ⶧����
			reverse->llink=reverse->rlink;	//�ѹ� �� �������ݴϴ�.
			reverse->rlink=next;
			reverse=reverse->rlink;
			h->first=head;					//���� ��������� head�� ���Դϴ�.
	}
	return 0;
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//���ο���
	listNode *p=h->first;
	new->key=key;	//new�� key�� Ű���� �ֽ��ϴ�.
	if(h->first==NULL){		//��尡 ������
		insertFirst(h,key);	//insertFirst�Լ��� ȣ���� ù ��忡 �� ��带 �ֽ��ϴ�.
		free(new);			//������ �ʴ� new ��带 �����մϴ�.
	}
	else if(new->key < p->key){	//ù��尡 �Է¹��� ������ Ŭ��
		insertFirst(h,key);				//insertFirst�Լ��� ȣ���� ù ��忡 �� ��带 �ֽ��ϴ�.
		free(new);						//������ �ʴ� new ��带 �����մϴ�.
	}
	else{
		while(p->rlink!=NULL){
			if(new->key < p->rlink->key){	//���ε��� ������ ū ���� ���� ��带 ������
				new->rlink=p->rlink;	//p�� ����Ű�� ���� new�� ����Ű�� �ϰ�
				p->rlink=new;			//p�� new�� ���ϰ� �մϴ�.
				new->llink=p;
				new->rlink->llink=new;
				return 0;
			}
			p=p->rlink;				//p�� ��ĭ�� �Ű��ݴϴ�.
		}
		if(p->rlink==NULL){			//p�� ������ ����� ��
			insertLast(h,key);		//insertLast�Լ��� ȣ���� ��������忡 �� ��带 �ֽ��ϴ�.
			free(new);				//�������ʴ� new��带 �����մϴ�.
		}
	}
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {
	listNode *p=h->first;
	listNode *prev,*delete;
	if(h->first==NULL){	//��尡 ����ٸ�
		printf("����Ʈ�� ������ϴ�.\n");	//�ȳ��������
		return 1;
	}
	else if(p->key==key){	//���� ù ��尡 ã�� �����
		deleteFirst(h);		//deleteFirst�Լ��� ȣ���� �����ݴϴ�.
		return 1;
	}
	else if(p->rlink->key==key&&p->rlink->rlink==NULL){//�ι�° ��尡 ã�� ���� ����� ����
		deleteLast(h);								   //2��� deleteLast �Լ��� ȣ���� ����ϴ�.
		return 1;
		
	}		
	else {
		prev=p;
		delete=p->rlink;	
		while(p->rlink!=NULL){	
			if(delete->key==key){	//p�� ��������尡 �ƴϰ� p�� ������尡 key�� �����ִٸ�
				prev->rlink=delete->rlink;	//prev�� delete�� ����Ű�� ���� ����Ű�� �ϰ�
				delete->rlink->llink=prev;	//delete ��������� llink�� prev�� ����
				free(delete);				//�� delete�� free�մϴ�.
				return 1;
			}
		p=p->rlink;	//while�� �ѷ����� p��ĭ�� �̵�
		}
		if(p->key==key){	//��������尡 key�� ������ ���� �� 
			deleteLast(h);	//deleteLast�Լ��� ȣ���� �����ݴϴ�.
			return 1;	
		}
		if (p->rlink==NULL){
		printf("ã�� key������ ���� �����\n");	//��� if������ �ɸ��� �ʴ´ٸ� ���ڰ� �����Ƿ�
		return 1;						//�ȳ��� ���
		}
	}
}



