#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int key;
   struct node* left;
   struct node* right;
} Node;

int CreateNode(Node* h,int number);
int CreateFirstNode(Node** h);
Node* searchIterative(Node* head, int key);

int main(void)
{
   FILE* pFile = fopen("test.txt", "r"); //read mode 
   int intTemp=-1,number=0,i=0,check;
   Node* head = NULL,*find=NULL;

   if (pFile == NULL)
   {
      printf("File does not exist");
      return 0;
   }


   // 파일 읽기 성공
   while (1) {
      fscanf(pFile, "%d", &intTemp);
      if (intTemp < 0) break;
       // 트리생성
      if (head == NULL) {
         CreateFirstNode(&head);
      }
      if (head!=NULL) {
         check=CreateNode(head, intTemp);
         if(check==1)
         printf("Node Created %d %d\n",intTemp,++i);
      }
    }

	printf("Tree has created\n");
   //파일 형태로 반환
   fclose(pFile);          //close file
   
   while(1){
	   printf("\nNumber you are Finding (End:-1):");
		scanf("%d",&number);
		if(number<0) return 0;
		find = searchIterative(head, number);
			if(find != NULL)
				printf("node [%d] found at %p\n", find->key, find);
			else
				printf("Cannot find the node [%d]\n", number);		
   }

   return 0;
}

int CreateFirstNode(Node** h) {
   *h = (Node*)malloc(sizeof(Node));
   (*h)->left = NULL;   /* root */
   (*h)->right = *h;
   (*h)->key = -1;
   
   return 1;
}

int CreateNode(Node* head,int key) {
   Node* new = (Node*)malloc(sizeof(Node));   //새 노드 동적할당
   Node* p = head->left, * prev;   //인서트에 쓰일 포인터들

   new->key = key;      //새 노드에 값들을 넣습니다.
   new->left = NULL;
   new->right = NULL;

   if (p == NULL) {      //루트노드가 없다면
      head->left = new;   //추가합니다.                           
   }
   else {            //루트노드가 있다면
      while (p != NULL) {   //노드들을 따라 움직이는 포인터 p가 NULL일때까지 반복문을 돌립니다.
         prev = p;   //p가 NULL이 되기 전 노드를 가리킬 포인터 prev
         if (key == p->key) {                        //같은 숫자를 입력받으면
            printf("같은 숫자는 넣을 수 없습니다.\n");   //안되므로 안내문 출력 후 종료
            return 0;
         }
         else if (key < p->key) {   //새로 입력받은 키가 p가 가리키고있는 노드의 키보다 작으면
            p = p->left;         //p를 왼쪽으로 이동
         }
         else {
            p = p->right;         //아니면 p를 오른쪽으로 이동
         }
      }
      
	  if (key < prev->key) {      //이전에 초기화해준 prev의 key값을 기준으로
         prev->left = new;         //새로운 key가 왼쪽에 new를 이어주고
         return 1;
      }
      else if (key > prev->key) {   //새로운 key가 크면
         prev->right = new;      //오른쪽에 이어줍니다.
         return 1;
      }
   }
   return 0;
}

Node* searchIterative(Node* head, int key){
	Node*p=head->left;		//head를 받기 때문에 루트노드를 가리키는 p를 만듭니다
	while(p!=NULL){			//p가 NULL이면 반복문을 끝냅니다
		if (key==p->key){	//key를 찾으면
			return p;		//p를 리턴
		}
		if(key < p->key){	//key가 p->key보다 작으면
			p=p->left;		//p를 왼쪽으로 이동
		}
		else if(key > p->key){	//key가 p->key보다 크면
			p=p->right;			//p를 오른쪽으로 이동
		}	
	}
	if (p==NULL){		//p가 NULL이면 key를가진 노드를 찾지 못하고 반복문을 빠져나온 것이므로
		return NULL;	//리턴 NULL
	}
}