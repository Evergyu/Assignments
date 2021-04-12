/*
 * singly linked list
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
}headNode;


/* �Լ� ����Ʈ */
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
		printf("=====================2018038083 ���α�==========================\n");
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

	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(h != NULL)
		freeList(h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h){
	/* h�� ����� listNode �޸� ����
	 * headNode�� �����Ǿ�� ��.
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
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;

	node->link = h->first;
	h->first = node;

	return 0;
}


/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� */
int insertNode(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//�� ��� ����
	listNode *p=h->first;

	new->key=key;	//�� ��忡 �� �ֱ�
	if(h->first==NULL){	//ù��尡 ������ ����̸�
		new->link = h->first;	//new�� ù��尡 ����Ű�� ���� ����Ű���ϰ�
		h->first = new;			//h�� new�� ����Ű�� �մϴ�.
		return 0;	
	}
	if(h->first->key > new->key){
		insertFirst(h,key);
	}
	else{
	while(p->link!=NULL){

		if(new->key < p->link->key){
			new->link=p->link;					//�����ִ�
			p->link=new;
			return 0;
		}
		p=p->link;
	}
	if(p->link==NULL){
		p->link=new;
		new->link=NULL;
		return 0;
	}
	return 0;
	}
}

/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//���λ����� ������
	listNode *p=h->first;	//����� �����͸� ����� �� p
	new->key=key;	
	if(h->first==NULL){	//���Ḯ��Ʈ�� ����ִٸ�
		h->first=new;	//����� new�� �հ�
		new->link=NULL;	//new�� NULL�� ����Ű�� �մϴ�
	}
	else {
		while(p->link!=NULL){	//���Ḯ��Ʈ�� ��������ʴٸ�
			p=p->link;	//��������带 ã�ư������� �ݺ����� ������
		}
		p->link=new;	//��������尡 new�� ����Ű�� �Ѵ���
		new->link=NULL;	//new���� NULL���� �ֽ��ϴ�.
	}
	
	return 0;
}


/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
	listNode *p=h->first;//����� �����͸� ����� �� p
	if(h->first==NULL){	//��尡 �������̸�
		return 0;		//�Լ��� �����ϴ�
	}
	else{						//��尡 �������� �ƴϸ�
		 h->first = p->link;	//��带 �� �ڿ� �ִ� ���� �̾��ݴϴ�
     	free(p);				//ù��°����� p�� �����մϴ�
	}
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {
	listNode *p=h->first;//����� �����͸� ����� �� p
	listNode *delete_p;//���� ��带 ����Ű�� delete_p

	if(h->first==NULL){	//��尡 ����ٸ�
		return 0;		//�����մϴ�
	}
	else if (p->key==key){	//��尡 ã�°��̶��
		deleteFirst(h);
		return 0;		//deleteFirst�Լ��� ȣ���� ù ��带 ����ϴ�
	}
	while(p->link!=NULL){		
		if(p->link->key==key){
			delete_p=p->link; //p�� delete�� ����Ű�� �մϴ�
			if(delete_p->link!=NULL){//������ ��尡 �ƴϸ� p��带 delete_p�� ����Ű�°Ͱ� �̾��ݴϴ�.
				p->link=delete_p->link;	//p�� delete_p�� ����Ű�°����� �̾��ݴϴ�
				free(delete_p);
			}
			else{
				p->link=NULL;
				free(delete_p);	
			}			//������ ���� p�� ������������ ���ݴϴ�.
			return 0;		
		}	
		p=p->link;	//p ��带 ��ĭ�� �̵���ŵ�ϴ�
	}
	if(p->link==NULL){	//���� �������� �ɸ��� �ʰ� NULL���� �Դٸ� ���ڴ� �����Ƿ�
		printf("���ڰ� �����!\n");	//���ڰ����ٴ� �ȳ����� ����մϴ�.
		return 0;
	}
}

/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
	listNode *p=h->first;//����� �����͸� ����� �� p
	listNode *first_p,*prev_p,*delete_p;	//���� ���� ������ ��� ���� ��带 ����Ű�� ������ ����� prev_p

	if(h->first==NULL){	//����尡 ����������
		printf("����ֽ��ϴ�\n");
		return 0;		//�����մϴ�.
	}
	
	if(h->first->link==NULL){	//��尡 �ϳ� �ִٸ�
		deleteFirst(h);			//ù���=��������� �̹Ƿ� deleteFirst(h) �Լ��� �������ݴϴ�
	}
	else {						//����尡 ��������尡 �ƴϸ�
		prev_p=p;				//prev_p->p
		delete_p=p->link;		//delete_p�� p�� ����Ű�°��� ����ŵ�ϴ�
		while(delete_p->link!=NULL){	//������ ��带 ã���ϴ� 
			prev_p=delete_p;			//delete_p�ڸ��� prev_p�� �ֽ��ϴ�
			delete_p=delete_p->link;			//delete_p�� �������� �ű�ϴ�
			}
			free(delete_p);						//delete_p�� NULL�� �ɶ� �ݺ����� ������ free ���ݴϴ�
			prev_p->link=NULL;					//prev_p�� ������ ��尡 �ǵ��� �մϴ�
		}	
	return 0;
}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
	listNode *p=h->first;		//����� �����͸� ����� �� p
	listNode *prev_p,*next_p;	//�ӽ÷� ���� ������ �����͵�
	prev_p=NULL;
	while(p->link!=NULL){	//p->link�� ���������̱� ������ �ݺ����� �����ϴ�
		next_p=prev_p;	//next_p�� prev_p�� ����Ű�� �մϴ�
		prev_p=p;		//prev_p�� p�� ����Ű�� �մϴ�
		p=p->link;		//p�� ��ĭ �Ű��ݴϴ�
		prev_p->link=next_p;	//prev_p�� �����̵Ǹ� ������ ��尡 �����Ѿ� �� ���� ���� next_p�� ����Ű���� �մϴ�
		h->first=prev_p;	//���� ù ��带 prev_p�� �̾��ݴϴ�.
	}
	if(p->link==NULL){	//p->link�� NULL�̸� �ݺ������� �ð� �����Ƿ� if������ �ѹ� �������ݴϴ�.
		next_p=prev_p;
		prev_p=p;
		p=p->link;
		prev_p->link=next_p;
		h->first=prev_p;
	}
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

