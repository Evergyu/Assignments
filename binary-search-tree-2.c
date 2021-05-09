/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */
//void printStack();

int main()
{
	char command;
	int key;
	Node* head = NULL;

	do{
		printf("\n\n");
		printf("-------------[2018038083]------------[���α�]-------------------\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		case 'p': case 'P':
			//printStack();
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}

/**
 * textbook: p 224s
 */
void iterativeInorder(Node* node)
{
	top=-1;					//top�� -1�� �ʱ�ȭ�ϰ�
	while(1){				
		while(node!=NULL){	//���� �ڽĳ�尡 NULL�϶�����
			push(node);		//Ǫ��
			node=node->left;
		}
		node=pop();			//�� ���ؼ� node�� �ְ�

		if(node==NULL) {
			break;	//node�� NULL�̸� ����
		}
		printf(" [%d] ", node->key);	//node�� Ű ���
		node=node->right;				//����� ������ �ڽĳ��� �̵�
	}
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)
{
	front=rear=-1;
	if(ptr==NULL){						//��Ʈ��尡 ����ִٸ�
		printf("BST tree is empty\n");	//����ִٴ� ���� ���
	}
	enQueue(ptr);						//��Ʈ��带 ť�� �ְ�

	while(1){
		ptr=deQueue();					//ptr�� front�� ����Ű�� ��带 �ְ�
		if (ptr!=NULL){					//ptr�� NULL�� �� ������
			printf(" [%d] ",ptr->key);	//ptr->key�� ����ϰ�
			if(ptr->left!=NULL){		//���� �ڽĳ�尡 ������� �ʴٸ�
				enQueue(ptr->left);		//ť�� ���ʳ�带 �߰�
			}
			if(ptr->right!=NULL){		//������ �ڽĳ�尡 ������� �ʴٸ�
				enQueue(ptr->right);	//ť�� ������ ��带 �߰�
			}
		}
		else break;						//ptr�� NULL���� ������ ����
	}
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}


int deleteNode(Node* head, int key)
{
	Node*p=head->left,*prev=head,*right_root,*right_parent;		//head�� �ޱ� ������ ��Ʈ��带 ����Ű�� p�� parent��带 ����Ű�� prev
	int parent_case=0;
	while(p!=NULL){				//p�� NULL�̸� �ݺ����� �����ϴ�
		if (key==p->key){		//key�� ã����
			break;				//p�� ����
		}
		prev=p;					//key�� �������� �ű�� ���� p�� prev�� �ֽ��ϴ�.
		if(key < p->key){		//key�� p->key���� ������
			parent_case=0;
			p=p->left;			//p�� �������� �̵�
		}
		else if(key > p->key){	//key�� p->key���� ũ��
			parent_case=1;
			p=p->right;			//p�� ���������� �̵�
		}	
	}
	if (p==NULL){								//p�� NULL�� ��
		printf("��ġ�ϴ� ��尡 �����ϴ�\n");	//��ġ�ϴ� ��带 ã�� �������Ƿ� ���
		return 0;
	}

	//case1 ���� ��尡 ��������ΰ��
	if (p->right==NULL && p->left==NULL){	
		if(parent_case==0){		//prev->left==p �� ��
			prev->left=NULL;	//prev->left=NULL
			free(p);
		}
		if(parent_case==1){		//prev->right==p �� ��			
			prev->right=NULL;	//prev->left=NULL
			free(p);
		}	
		return 0;
	}

	//case2 ���� ����� �ڽĳ�尡 1�� �������									
	if(p->left==NULL && p->right!=NULL){	//���� ����� �������� ������� �������
		if(parent_case==0){					//p==prev->left�϶�
			prev->left=p->right;			//prev->left=p->left
			free(p);						//��������
		}
		else if(parent_case==1){			//p==prev->right�϶�
			prev->right=p->right;			//prev->right=p->left
			free(p);						//��������
		}
		return 0;
	}
	if(p->left!=NULL && p->right==NULL){	//���� ����� ������ ������� ���� ���
		if(parent_case==0){					//p==prev->left�϶�
			prev->left=p->left;				//prev->left=p->left
			free(p);						//��������
		}
		else if(parent_case==1){			//p==prev->right�϶�
			prev->right=p->left;			//prev->right=p->left
			free(p);						//��������
		}
		return 0;
	}

	//case3 ���� ����� �ڽĳ�ΰ� �ΰ��ΰ��
	if(p->left!=NULL && p->right!=NULL){					
		right_root=p->right;				//������ Ʈ������ ���� ���� ã������ �ӽó�� ����
		if(right_root->left==NULL){
			if(parent_case==0) prev->left=right_root;			//p==prev->left�϶�		prev->left=right_root
			else if(parent_case==1)	prev->right=right_root;		//p==prev->right�϶�	prev->right=right_root
			right_root->left=p->left;							//right_root->left�� p->left�� �ּҸ� �ְ�
			free(p);	//free
			return 0;
		}
		while(right_root->left==NULL){		//right_root->left�� NULL�϶�����
			right_parent=right_root;		//right_parent�� right_root�� �ּҸ� �ְ�
			right_root=right_root->left;	//right_root�� �������� �ű�ϴ�.
		}
		if(parent_case==0){					//p==prev->left�϶�
			prev->left=right_root;			//prev->left=right_root;
			right_root->left=p->left;		//right_root���� p�� �̾������͵��� �ս��ϴ�.
			right_root->right=p->right;
			free(p);						//���������� p�� free
		}
		else if(parent_case==1){			//p==prev->right�϶�		
			prev->right=right_root;			//prev->right=right_root;
			right_root->left=p->left;		//right_root���� p�� �̾������͵��� �ս��ϴ�.
			right_root->right=p->right;
			free(p);						//���������� p�� free
		}
		return 0;	
	}
}


void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{

	if(head->left == head)
	{
		free(head);
		return 1;
	}

	Node* p = head->left;

	freeNode(p);

	free(head);
	return 1;
}



Node* pop()
{
	if(top==-1){						//top��-1�̸�
		return NULL;					//NULL�� ��ȯ
	}
	else {
		return stack[top--];			//��������ʴٸ� stack[top]�� �������ְ� top�� -- ���ݴϴ�.
	}
}

void push(Node* aNode)
{
	if(top==MAX_STACK_SIZE-1){		//top�� ���ù迭 ���� �ִٸ� 
		printf("Stack is FULL!\n");	//������ ����á�ٴ� ���� ���	
		printf("Stack's size is %d\n",MAX_STACK_SIZE);
	}
	else {						//�������� �ʾҴٸ�
		stack[++top]=aNode;		//++top�� ���ְ� stack[top]�ڸ��� ����� �ּ� �߰�
	}
}

Node* deQueue()
{
	if(front==rear){			//front==rear �̸�
		return NULL;			//NULL ����
	}
	else{						//ť�� ��������ʴٸ� front�� ��ĭ �÷���
		return queue[++front];	//++front�� ���ְ� queue[front]�� ����
	}
}

void enQueue(Node* aNode)
{
	if  (rear==MAX_QUEUE_SIZE-1){	//rear�� �迭�� ���� �ִٸ�
		printf("Queue is FUll\n");	//ť�� ����á�ٰ� ���
		printf("Queue's size is %d\n",MAX_QUEUE_SIZE);
	}
	else{						//�������� �ʾҴٸ�
		queue[++rear]=aNode;	//++rear�� ���ְ� queue[rear]�ڸ��� ����� �ּ� �߰�
	}
}
