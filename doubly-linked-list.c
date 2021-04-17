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
		new->llink=new;	//new�� llink�� �ڱ��ڽ��� ����Ű�� �մϴ�.
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
	new->llink=new;			//new->llink�� �ڽ��� ����Ű�� �մϴ�.

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

	return 0;
}



/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {

	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {

	return 1;
}


