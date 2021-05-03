/*
 * Binary Search Tree #1
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

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("---------------2018038083-------이인규--------------------------\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f \n");
		printf(" Postorder Traversal  = t      Quit                         = q \n");
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
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
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
	return 1;
}



void inorderTraversal(Node* ptr){
	if (ptr != NULL) {					//노드가 있다면
		inorderTraversal(ptr->left);	//왼쪽으로 끝가지 가서 끝에것을 출력 후 그 parent 노드를 출력합니다. 
		printf(" [%d] ",ptr->key);		//그 후 오른쪽 자식이 있다면
		inorderTraversal(ptr->right);	//parent노드의 오른쪽으로 가서 출력 합니다.
	}
}

void preorderTraversal(Node* ptr){
	if(ptr != NULL){					//노드가 있다면
		printf(" [%d] ",ptr->key);		//parent노드를 먼저 출력한 후
		preorderTraversal(ptr->left);	//왼쪽노드로 가서 왼쪽 노드가 있다면 왼쪽노드를 출력하고
		preorderTraversal(ptr->right);	//또 오른쪽노드로 가서 오른쪽 노드가 있다면 오른쪽 노드를 출력하는 것을 반복합니다.
	}
}

void postorderTraversal(Node* ptr){
	if(ptr != NULL){					//노드가 있다면
		postorderTraversal(ptr->left);	//왼쪽 노드로 먼저 방문한 후 출력한다음 
		postorderTraversal(ptr->right); //그 후 오른쪽으로 가서 출력 합니다. 
		printf("[%d] ",ptr->key);		//마지막으로 parent노드를 출력합니다.
	}
	
}


int insert(Node* head, int key){
	Node *new=(Node *)malloc(sizeof(Node));	//새 노드 동적할당
	Node *p=head->left,*prev;	//인서트에 쓰일 포인터들

	new->key=key;		//새 노드에 값들을 넣습니다.
	new->left=NULL;
	new->right=NULL;
	
	if(p==NULL){		//루트노드가 없다면
		head->left=new;	//추가합니다.									
	}
	else {				//루트노드가 있다면
		while(p!=NULL){	//노드들을 따라 움직이는 포인터 p가 NULL일때까지 반복문을 돌립니다.
		prev=p;	//p가 NULL이 되기 전 노드를 가리킬 포인터 prev
			if(key == p->key){								//같은 숫자를 입력받으면
				printf("같은 숫자는 넣을 수 없습니다.\n");	//안되므로 안내문 출력 후 종료
				return 0;									
			}
			else if(key < p->key){	//새로 입력받은 키가 p가 가리키고있는 노드의 키보다 작으면
				p=p->left;			//p를 왼쪽으로 이동
			}
			else {
				p=p->right;			//아니면 p를 오른쪽으로 이동
			}
		}
		if(key < prev->key){		//이전에 초기화해준 prev의 key값을 기준으로
			prev->left=new;			//새로운 key가 왼쪽에 new를 이어주고
		}
		else if(key > prev->key){	//새로운 key가 크면
			prev->right=new;		//오른쪽에 이어줍니다.
		}
	}
return 0;
}

int deleteLeafNode(Node* head, int key){
	Node *delete=NULL,*prev=NULL,*p=head->left;
	int node_case;	//리프노드를 지우고 부모노드에서 left나 right에 NULL을 넣을 때 케이스 구분을 위한 변수
	if(p==NULL){							//루트노드가 없는경우
		printf("트리가 비어있습니다.\n");	//트리가 비어있다는 안내문 출력 후 종료
		return 0;									
	}				
	while(p->key != key){		//포인터 p가 가리키는 노드의 key가 입력받은 key와 같을 때 까지 반복문을 돌립니다.
		if(key < p->key){		//입력받은 key가 p->key의 값보다 작으면
				prev=p;				//현재 p를 prev에 넣고
				p=p->left;			//p를 왼쪽으로 옮깁니다
				node_case=0;		//node_case에 0을 넣습니다.
			}
			else if(key > p->key){	//입력받은 key가 p->key의 값보다 크면
				prev=p;				//현재 p를 prev에 넣고
				p=p->right;			//p를 왼쪽으로 옮깁니다
				node_case=1;		//node_case에 1을 넣습니다.
			}
			if(p==NULL){			//p가 NULL이라면 반복문을 나갑니다.
				break;				
			}
		}	
		delete=p;	//다 이동시킨 p를 delete에 넣고
		if(delete!=NULL){	//delete가 NULL이 아니라면
			if(delete->left==NULL && delete->right==NULL){	//delete가 리프노드면 
				if(node_case==0){		//케이스가 0일때
					free(delete);		//delete를 지우고
					prev->left=NULL;	//prev->left에 NULL을 넣습니다.
				}
				else if(node_case==1){	//케이스가 1일때
					free(delete);		//delete를 지우고
					prev->right=NULL;	//prev->right에 NULL을 넣습니다.
				}
			}
			else{
				printf("리프노드가 아닙니다.\n");	//리프노드가 아닐때 출력문구
			}
		}
		else{
			printf("일치하는 key를 가진 노드가 없습니다.\n");	//delete가 NULL일때 출력문구
		}														//일치하는 key를 가진 노드가 없으면 delete==NULL
	
	return 0;
}

Node* searchRecursive(Node* ptr, int key){
	
}

Node* searchIterative(Node* head, int key){
	
}


int freeBST(Node* head)
{	
	
}





