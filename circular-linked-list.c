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
/* �ʿ��� ������� �߰� */

typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

/* �Լ� ����Ʈ */
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
		printf("------------2018038083-----------------���α�-------------------\n");
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

	/* headNode�� NULL�� �ƴϸ�, freeNode�� ȣ���Ͽ� �Ҵ�� �޸� ��� ���� */
	if(*h != NULL)
		freeList(*h);

	/* headNode�� ���� �޸𸮸� �Ҵ��Ͽ� ���� */
	*h = (listNode*)malloc(sizeof(listNode));
	(*h)->rlink = *h;
	(*h)->llink = *h;
	(*h)->key = -9999;
	return 1;
}

/* �޸� ���� */
int freeList(listNode* h){
	listNode* p = h->rlink;	//������p=h->rlink

	listNode* prev = NULL;		//������带 ���� �ӽó��

	if(p==NULL){				//���ۿ� ���� ��
		free(h);				//��带 �����ϰ� �����մϴ�.
		return 0;
	}

	while(p->rlink != h) {	//p->rlink�� NULL�� �ƴ϶��
		prev=p;			//prev�� p�� ���� ��带 �����ϰ�
		p=p->rlink;		//p�� ��ĭ �ű� ��
		free(prev);		//������� ����
	}
	free(h);			//����嵵 ����

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
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(listNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//�� ��� ����
	listNode *p=h->rlink;		//h�� p�� ����Ű�� �մϴ�
	new->key=key;
	
	if(h->rlink==h && h->llink==h){	//���Ḯ��Ʈ�� ����ִٸ�
		new->rlink=h->rlink;		//new->rlink�� ��尡 ����Ű������ ���� �ϰ�
		h->rlink=new;				//��尡 new�� ����Ű�� �ս��ϴ�.
		new->llink=h;				//new->llink�� h�� ����Ű�� �մϴ�.
		new->rlink->llink=new; 		//new�� �����ʳ���� llink�� new������ �̾��ݴϴ�.
	}
	else{
		while(p->rlink!=h){ 	//prev��� ������尡 �������� ������
			p=p->rlink;			//p��带 �Ű��ݴϴ�.
		}
		new->rlink=p->rlink;	//new����� rlink�� p���ٶ󺸴� ��(���)�� �ǰ� �̾��ݴϴ�.
		p->rlink=new;			//p->rlink==new �� �ǰ� �̾��ݴϴ�.
		new->llink=p; 			//new->llink==p �� �ǰ� �̾��ݴϴ�.
		h->llink=new;			//������� llink�� ���� �߰��� ������ ���new�� ���� �մϴ�.
	}
	return 0;
	return 1;
}


/**
 * list�� ������ ��� ����
 */
int deleteLast(listNode* h) {
	listNode *p=h->rlink;	//����� �����͸� ����� �� p
	listNode *prev,*delete;	//������� ������ �ٷ��� ��带 ������ ������
	if(h->rlink==h&&h->llink==h){	//��尡 ���� ��
		printf("����Ʈ�� ����ֽ��ϴ�.\n");	//����Ʈ�� ����ִٴ� ���� ���
		return 0;
	}
	else if(p->rlink==h){ //ù ��尡 ������ ����� ��
		deleteFirst(h);		 //deleteFirst(h) �Լ��� ȣ���ؼ� ����ϴ�.
		return 0;
	}
	else{
		while(p->rlink->rlink!=h){	//���� ��带 p->rlink�� �� �� ������ ��� ������ p�� �Ű��ݴϴ�.
			p=p->rlink;					//p�� ������Ŵ
			}
			prev=p;						//prev�� p�� �ְ�
			delete=p->rlink;			//������� p �������� �����ϴ�
			prev->rlink=delete->rlink;	//prev->rlink==delete->rlink(���)�� �ǰ� �̾��ݴϴ�.
			free(delete);				//��带 ����ϴ�.
			h->llink=prev;				//����� llink�� prev�� ���� �մϴ�.
	}

	return 0;

	return 1;
}


/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(listNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//�� ��带 �����Ҵ�
	new->key=key;	//������� key�� key���� �ֽ��ϴ�

	new->rlink=h->rlink;	//new->rlink�� ��尡 ����Ű������ ���� �մϴ�.
	h->rlink=new;			//h->rlink==new �� �ǰ� �̾��ݴϴ�.
	new->llink=h;			//new->llink==h �� �ǰ� �̾��ݴϴ�.
	new->rlink->llink=new; 	//new�� �����ʳ���� llink�� new������ �̾��ݴϴ�.
	
	return 1;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(listNode* h) {
	listNode *delete=h->rlink;
	if(h->rlink==h && h->llink==h){	//��尡 ���� ��
		printf("����Ʈ�� ����ֽ��ϴ�.\n");	//����Ʈ�� ����ִٴ� ���� ���
		return 0;
	}
	else {				//��尡 ���� ��
		h->rlink=delete->rlink;	
		//����� ���� ���(ù���)�� ����Ű�°��� ����Ű�� �մϴ�
		h->rlink->llink=h;
		free(delete);			//���� ��带 free�մϴ�.
		return 0;
	}

	return 1;

}


/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(listNode* h) {
	listNode *p=h->rlink;

	return 0;
}



/**
 *  ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ���� 
 **/
int insertNode(listNode* h, int key) {
	listNode *new=(listNode*)malloc(sizeof(listNode));	//���ο���
	listNode *p=h->rlink;

	new->key=key;	//new�� key�� Ű���� �ֽ��ϴ�.
	if(h->rlink==h && h->llink==h){		//��尡 ������
		insertFirst(h,key);	//insertFirst�Լ��� ȣ���� ù ��忡 �� ��带 �ֽ��ϴ�.
		free(new);			//������ �ʴ� new ��带 �����մϴ�.
	}
	else if(new->key < p->key){	//��尡 1������ �� �� ����� key�� ���ο� ����� key���� ũ��
		insertFirst(h,key); //�� ��带ù���� �߰��մϴ�.
		free(new);			//�����ʴ� new�� �������ݴϴ�.
	}
	else{
		while(p->rlink!=h){					//p->rlink==h �̱� ������ �� ��������忡 �����ϱ� ������ ���ư��� �ݺ���
			if(new->key < p->rlink->key){	//���ε��� ������ ū ���� ���� ��带 ������
				new->rlink=p->rlink;	//p�� ����Ű�� ���� new�� ����Ű�� �ϰ�
				p->rlink=new;			//p�� new�� ���ϰ� �մϴ�.
				new->llink=p;			//new->llink=p�� �ǰ� �̾��ݴϴ�.
				new->rlink->llink=new;	//new�� �����ʳ���� llink�� new�� �ǵ��� ���ݴϴ�.
				return 0;
			}
		
			p=p->rlink;				//p�� ��ĭ�� �Ű��ݴϴ�.
		}
		if(p->rlink==h){			//p�� ������ ����� ��
			insertLast(h,key);		//insertLast�Լ��� ȣ���� ��������忡 �� ��带 �ֽ��ϴ�.
			free(new);				//�������ʴ� new��带 �����մϴ�.
		}
	}
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(listNode* h, int key) {
	listNode *p=h->rlink;
	listNode *prev,*delete;
	if(h->rlink==h && h->llink==h){	//��尡 ����ٸ�
		printf("����Ʈ�� ������ϴ�.\n");	//�ȳ��������
		return 0;
	}
	else if(p->key==key){	//���� ù ��尡 ã�� �����
		deleteFirst(h);		//deleteFirst�Լ��� ȣ���� �����ݴϴ�.
		return 1;
	}
	else if(p->rlink->key==key&&p->rlink->rlink==h){//�ι�° ��尡 ã�� ���� ����� ����
		deleteLast(h);								   //2��� deleteLast �Լ��� ȣ���� ����ϴ�.
		return 1;
	}		
	else {
		prev=p;
		delete=p->rlink;	
		while(p->rlink!=h){	
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
		if (p->rlink==h){	//��� if������ �ɸ��� �ʴ´ٸ� ���ڰ� �����Ƿ�
		printf("ã�� key������ ���� �����\n");	//�ȳ��� ���
		return 0;						
		}
	}
	return 0;
}


