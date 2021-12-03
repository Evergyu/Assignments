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
		printf("-------------[2018038083]------------[이인규]-------------------\n");
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
	top=-1;					//top을 -1로 초기화하고
	while(1){				
		while(node!=NULL){	//왼쪽 자식노드가 NULL일때까지
			push(node);		//푸시
			node=node->left;
		}
		node=pop();			//후 팝해서 node에 넣고

		if(node==NULL) {
			break;	//node가 NULL이면 종료
		}
		printf(" [%d] ", node->key);	//node의 키 출력
		node=node->right;				//노드의 오른쪽 자식노드로 이동
	}
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)
{
	front=rear=-1;
	if(ptr==NULL){						//루트노드가 비어있다면
		printf("BST tree is empty\n");	//비어있다는 문구 출력
	}
	enQueue(ptr);						//루트노드를 큐에 넣고

	while(1){
		ptr=deQueue();					//ptr에 front가 가리키는 노드를 넣고
		if (ptr!=NULL){					//ptr이 NULL이 될 때까지
			printf(" [%d] ",ptr->key);	//ptr->key를 출력하고
			if(ptr->left!=NULL){		//왼쪽 자식노드가 비어있지 않다면
				enQueue(ptr->left);		//큐에 왼쪽노드를 추가
			}
			if(ptr->right!=NULL){		//오른쪽 자식노드가 비어있지 않다면
				enQueue(ptr->right);	//큐에 오른쪽 노드를 추가
			}
		}
		else break;						//ptr이 NULL값을 받으면 종료
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
	Node*p=head->left,*prev=head,*right_root,*right_parent;		//head를 받기 때문에 루트노드를 가리키는 p와 parent노드를 가리키는 prev
	int parent_case=0;
	while(p!=NULL){				//p가 NULL이면 반복문을 끝냅니다
		if (key==p->key){		//key를 찾으면
			break;				//p를 리턴
		}
		prev=p;					//key의 값에따라 옮기기 전의 p를 prev에 넣습니다.
		if(key < p->key){		//key가 p->key보다 작으면
			parent_case=0;
			p=p->left;			//p를 왼쪽으로 이동
		}
		else if(key > p->key){	//key가 p->key보다 크면
			parent_case=1;
			p=p->right;			//p를 오른쪽으로 이동
		}	
	}
	if (p==NULL){								//p가 NULL일 때
		printf("일치하는 노드가 없습니다\n");	//일치하는 노드를 찾지 못했으므로 출력
		return 0;
	}

	//case1 지울 노드가 리프노드인경우
	if (p->right==NULL && p->left==NULL){	
		if(parent_case==0){		//prev->left==p 일 때
			prev->left=NULL;	//prev->left=NULL
			free(p);
		}
		if(parent_case==1){		//prev->right==p 일 때			
			prev->right=NULL;	//prev->left=NULL
			free(p);
		}	
		return 0;
	}

	//case2 지울 노드의 자식노드가 1개 있을경우									
	if(p->left==NULL && p->right!=NULL){	//지울 노드의 오른쪽이 비어있지 않은경우
		if(parent_case==0){					//p==prev->left일때
			prev->left=p->right;			//prev->left=p->left
			free(p);						//노드지우기
		}
		else if(parent_case==1){			//p==prev->right일때
			prev->right=p->right;			//prev->right=p->left
			free(p);						//노드지우기
		}
		return 0;
	}
	if(p->left!=NULL && p->right==NULL){	//지울 노드의 왼쪽이 비어있지 않은 경우
		if(parent_case==0){					//p==prev->left일때
			prev->left=p->left;				//prev->left=p->left
			free(p);						//노드지우기
		}
		else if(parent_case==1){			//p==prev->right일때
			prev->right=p->left;			//prev->right=p->left
			free(p);						//노드지우기
		}
		return 0;
	}

	//case3 지울 노드의 자식노두가 두개인경우
	if(p->left!=NULL && p->right!=NULL){					
		right_root=p->right;				//오른쪽 트리에서 작은 수를 찾기위한 임시노드 설정
		if(right_root->left==NULL){
			if(parent_case==0) prev->left=right_root;			//p==prev->left일때		prev->left=right_root
			else if(parent_case==1)	prev->right=right_root;		//p==prev->right일때	prev->right=right_root
			right_root->left=p->left;							//right_root->left에 p->left의 주소를 넣고
			free(p);	//free
			return 0;
		}
		while(right_root->left==NULL){		//right_root->left가 NULL일때까지
			right_parent=right_root;		//right_parent에 right_root의 주소를 넣고
			right_root=right_root->left;	//right_root를 왼쪽으로 옮깁니다.
		}
		if(parent_case==0){					//p==prev->left일때
			prev->left=right_root;			//prev->left=right_root;
			right_root->left=p->left;		//right_root에는 p에 이어졌던것들을 잇습니다.
			right_root->right=p->right;
			free(p);						//마지막으로 p를 free
		}
		else if(parent_case==1){			//p==prev->right일때		
			prev->right=right_root;			//prev->right=right_root;
			right_root->left=p->left;		//right_root에는 p에 이어졌던것들을 잇습니다.
			right_root->right=p->right;
			free(p);						//마지막으로 p를 free
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
	if(top==-1){						//top이-1이면
		return NULL;					//NULL값 반환
	}
	else {
		return stack[top--];			//비어있지않다면 stack[top]을 리턴해주고 top을 -- 해줍니다.
	}
}

void push(Node* aNode)
{
	if(top==MAX_STACK_SIZE-1){		//top이 스택배열 끝에 있다면 
		printf("Stack is FULL!\n");	//스택이 가득찼다는 문구 출력	
		printf("Stack's size is %d\n",MAX_STACK_SIZE);
	}
	else {						//가득차지 않았다면
		stack[++top]=aNode;		//++top을 해주고 stack[top]자리에 노드의 주소 추가
	}
}

Node* deQueue()
{
	if(front==rear){			//front==rear 이면
		return NULL;			//NULL 리턴
	}
	else{						//큐가 비어있지않다면 front를 한칸 늘려서
		return queue[++front];	//++front를 해주고 queue[front]를 리턴
	}
}

void enQueue(Node* aNode)
{
	if  (rear==MAX_QUEUE_SIZE-1){	//rear가 배열의 끝에 있다면
		printf("Queue is FUll\n");	//큐가 가득찼다고 출력
		printf("Queue's size is %d\n",MAX_QUEUE_SIZE);
	}
	else{						//가득차지 않았다면
		queue[++rear]=aNode;	//++rear를 해주고 queue[rear]자리에 노드의 주소 추가
	}
}
