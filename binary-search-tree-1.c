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
		printf("---------------2018038083-------���α�--------------------------\n");
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
	if (ptr != NULL) {					//��尡 �ִٸ�
		inorderTraversal(ptr->left);	//�������� ������ ���� �������� ��� �� �� parent ��带 ����մϴ�. 
		printf(" [%d] ",ptr->key);		//�� �� ������ �ڽ��� �ִٸ�
		inorderTraversal(ptr->right);	//parent����� ���������� ���� ��� �մϴ�.
	}
}

void preorderTraversal(Node* ptr){
	if(ptr != NULL){					//��尡 �ִٸ�
		printf(" [%d] ",ptr->key);		//parent��带 ���� ����� ��
		preorderTraversal(ptr->left);	//���ʳ��� ���� ���� ��尡 �ִٸ� ���ʳ�带 ����ϰ�
		preorderTraversal(ptr->right);	//�� �����ʳ��� ���� ������ ��尡 �ִٸ� ������ ��带 ����ϴ� ���� �ݺ��մϴ�.
	}
}

void postorderTraversal(Node* ptr){
	if(ptr != NULL){					//��尡 �ִٸ�
		postorderTraversal(ptr->left);	//���� ���� ���� �湮�� �� ����Ѵ��� 
		postorderTraversal(ptr->right); //�� �� ���������� ���� ��� �մϴ�. 
		printf("[%d] ",ptr->key);		//���������� parent��带 ����մϴ�.
	}
	
}


int insert(Node* head, int key){
	Node *new=(Node *)malloc(sizeof(Node));	//�� ��� �����Ҵ�
	Node *p=head->left,*prev;	//�μ�Ʈ�� ���� �����͵�

	new->key=key;		//�� ��忡 ������ �ֽ��ϴ�.
	new->left=NULL;
	new->right=NULL;
	
	if(p==NULL){		//��Ʈ��尡 ���ٸ�
		head->left=new;	//�߰��մϴ�.									
	}
	else {				//��Ʈ��尡 �ִٸ�
		while(p!=NULL){	//������ ���� �����̴� ������ p�� NULL�϶����� �ݺ����� �����ϴ�.
		prev=p;	//p�� NULL�� �Ǳ� �� ��带 ����ų ������ prev
			if(key == p->key){								//���� ���ڸ� �Է¹�����
				printf("���� ���ڴ� ���� �� �����ϴ�.\n");	//�ȵǹǷ� �ȳ��� ��� �� ����
				return 0;									
			}
			else if(key < p->key){	//���� �Է¹��� Ű�� p�� ����Ű���ִ� ����� Ű���� ������
				p=p->left;			//p�� �������� �̵�
			}
			else {
				p=p->right;			//�ƴϸ� p�� ���������� �̵�
			}
		}
		if(key < prev->key){		//������ �ʱ�ȭ���� prev�� key���� ��������
			prev->left=new;			//���ο� key�� ���ʿ� new�� �̾��ְ�
		}
		else if(key > prev->key){	//���ο� key�� ũ��
			prev->right=new;		//�����ʿ� �̾��ݴϴ�.
		}
	}
return 0;
}

int deleteLeafNode(Node* head, int key){
	Node *delete=NULL,*prev=NULL,*p=head->left;
	int node_case;	//������带 ����� �θ��忡�� left�� right�� NULL�� ���� �� ���̽� ������ ���� ����
	if(p==NULL){							//��Ʈ��尡 ���°��
		printf("Ʈ���� ����ֽ��ϴ�.\n");	//Ʈ���� ����ִٴ� �ȳ��� ��� �� ����
		return 0;									
	}				
	while(p->key != key){		//������ p�� ����Ű�� ����� key�� �Է¹��� key�� ���� �� ���� �ݺ����� �����ϴ�.
		if(key < p->key){		//�Է¹��� key�� p->key�� ������ ������
				prev=p;				//���� p�� prev�� �ְ�
				p=p->left;			//p�� �������� �ű�ϴ�
				node_case=0;		//node_case�� 0�� �ֽ��ϴ�.
			}
			else if(key > p->key){	//�Է¹��� key�� p->key�� ������ ũ��
				prev=p;				//���� p�� prev�� �ְ�
				p=p->right;			//p�� �������� �ű�ϴ�
				node_case=1;		//node_case�� 1�� �ֽ��ϴ�.
			}
			if(p==NULL){			//p�� NULL�̶�� �ݺ����� �����ϴ�.
				break;				
			}
		}	
		delete=p;	//�� �̵���Ų p�� delete�� �ְ�
		if(delete!=NULL){	//delete�� NULL�� �ƴ϶��
			if(delete->left==NULL && delete->right==NULL){	//delete�� �������� 
				if(node_case==0){		//���̽��� 0�϶�
					free(delete);		//delete�� �����
					prev->left=NULL;	//prev->left�� NULL�� �ֽ��ϴ�.
				}
				else if(node_case==1){	//���̽��� 1�϶�
					free(delete);		//delete�� �����
					prev->right=NULL;	//prev->right�� NULL�� �ֽ��ϴ�.
				}
			}
			else{
				printf("������尡 �ƴմϴ�.\n");	//������尡 �ƴҶ� ��¹���
			}
		}
		else{
			printf("��ġ�ϴ� key�� ���� ��尡 �����ϴ�.\n");	//delete�� NULL�϶� ��¹���
		}														//��ġ�ϴ� key�� ���� ��尡 ������ delete==NULL
	
	return 0;
}

Node* searchRecursive(Node* ptr, int key){
	
}

Node* searchIterative(Node* head, int key){
	
}


int freeBST(Node* head)
{	
	
}





