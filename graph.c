/*
 * Graph Representation : Adjacent List
 *
 * Data Structures
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {     //Vertex�� ����
	int index;
	struct Vertex *next;
} ver;

#define MAX_VERTEX_SIZE 10  //������ 10
int visited[MAX_VERTEX_SIZE];     //Vertex DFS,BFS�� �� ����Ʈ
ver ADJList[MAX_VERTEX_SIZE]={{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL}};

/*�Լ���*/
void initialize();
void freeList(ver* ptr);
void insertVertex(int key);
void insertEdge(int from,int to);
int FindMinimumVertex();
void DFS(int v);

/* for queue */
#define MAX_QUEUE_SIZE 10
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;
int deQueue();
void enQueue(int key);

void BFS(int v);
void printGraph();

int main(){
    char command;
    int key,from,to,i;
    do{
    		printf("\n\n");
    		printf("-------------[2018038083]------------[���α�]-------------------\n");
    		printf("----------------------------------------------------------------\n");
            printf("                       Graph Searches\n");
            printf("----------------------------------------------------------------\n");
            printf("  Initialize Graph   = z\n");
            printf("  Insert Vertex      = v               Insert Edge         = e  \n");
            printf("  Depth First Search = d               Breath First Search = b\n");
            printf("  Print Graph        = p               Quit                = q\n");
            printf("----------------------------------------------------------------\n");
    
            printf("Command = ");
    		scanf(" %c", &command);

    		switch(command) {
    		case 'z': case 'Z':
                initialize();   //Vertex_count�� 0���θ���� �����Ҵ��� �͵� ��� free
    			break;
    		case 'q': case 'Q':
                initialize();   //freeList�� ��� �������ֱ� ������ Q���� �־����ϴ�.
    			break;
    		case 'v': case 'V':
                printf("Vertex Index(0~9) :");    //������ �Է¹ޱ�
                scanf("%d",&key);
                insertVertex(key);
    			break;
    		case 'e': case 'E':
                printf("from Index(0~9) :");    //������ �Է¹ޱ�
                scanf("%d",&from);
                printf("to Index(0~9) :");      //���� �Է¹ޱ�
                scanf("%d",&to);
                insertEdge(from,to);   //��Vertex�� �մ��Լ� ȣ��
    			break;
    		case 'd': case 'D':
                key=FindMinimumVertex();
                DFS(key);
    			break;
    		case 'b': case 'B':
                key=FindMinimumVertex();
                BFS(2);
    			break;
    		case 'p': case 'P':
                printGraph();   //����Ʈ�� ���·� �׷����� ����մϴ�.
    			break;
    		default:
    			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
    			break;
    		}
	}while(command != 'q' && command != 'Q');

	return 1;
}

void initialize(){
    int i=0;
    front=rear=-1;
    for(i;i<MAX_VERTEX_SIZE;i++){   //Vertex�� �����ŭ �ݺ����� ����
        ADJList[i].index=-1;
        freeList(&ADJList[i]);      //Vertex�� �̾��� Edge���� free���ݴϴ�.
    }
}

void freeList(ver* ptr){
    ver* prev;              
    if(ptr->index!=-1){
        ptr=ptr->next;
        while(ptr->next!=NULL){         //edge�� NULL�� �ɶ�����
            prev=ptr;                   //�ű���� ptr�� prev�� �ְ�
            ptr=ptr->next;              //ptr�� ��ĭ �ű�ϴ�
            free(prev);                 //prev�� �������ݴϴ�.
        }
        free(ptr);
    }
}

void insertVertex(int key){
    if (key<=9 && key>=0){
        if(ADJList[key].index==key){
            printf("Vertex[%d]�� �̹� �ֽ��ϴ�.\n",key);
        }
        if(ADJList[key].index==-1){
        ADJList[key].index=key;
        printf("Vertex[%d] has created.\n",key);
        }
        
    }
    else{
        printf("���ڸ� ����� �Է��ϼ���\n");
    }
}
void insertEdge(int from, int to){
    ver* new,*next,*temp;
    new=malloc(sizeof(ver));
    new->next=NULL;
    new->index=to;
    if(ADJList[from].index==-1){
        printf("%d�� Index�� ���� Vertex�� �����ϴ�.\n",from);
        insertVertex(from);
        printf("�ٽ� Edge�� �õ��ϼ���");
        free(new);
        return;
    }
    if(ADJList[to].index==-1){
        printf("%d�� Index�� ���� Vertex�� �����ϴ�.\n",to);
        insertVertex(to);
        printf("�ٽ� Edge�� �õ��ϼ���");
        free(new);
        return;
    }
    if(ADJList[from].index!=-1 && ADJList[to].index!=-1){
        if(ADJList[from].next==NULL){
            ADJList[from].next=new;
        }
        else{
            next=ADJList[from].next;
            while(next->next!=NULL){
                if(next->index > to)
                    break;
                next=next->next;
                temp=ADJList[from].next;
            }
            if(next->next==NULL){
                next->next=new;
            }
            else{
                next=new;
                new->next=temp->next;
            }
        }
        printf("Edge has created.");
    }  
}
int FindMinimumVertex(){
    int i;
    for(i=0;i<MAX_VERTEX_SIZE;i++){
        visited[i]=0;
    }
    for(i=0;i<MAX_VERTEX_SIZE;i++){
        if(ADJList[i].next!=NULL){
            return i;
        }
    }
    return -1;
}
void DFS(int v){
   ver* w;
   visited[v]=1;
   printf(" <%d> ", v);
   for(w=&ADJList[v];w;w=w->next){
       if(!visited[w->index]){
           DFS(w->index);
       }
   }
}
void BFS(int v){
    ver* w;
    printf(" <%d> ",v);
    enQueue(v);
    rear++;
    visited[v]=v;
    
    while(front<rear){
        v=deQueue();
        for(w=&ADJList[v];w;w=w->next){
            if(!visited[w->index]){
                printf(" <%d> ",w->index);
                enQueue(w->index);
                visited[w->index]=1;
            }
        }
    }
}
void printGraph(){
    int i;
    ver* ptr;
    for(i=0;i<MAX_VERTEX_SIZE;i++){
        if(ADJList[i].index!=-1){
            printf("Vertex : [%d]\tEdge : ",i);
            ptr=ADJList[i].next;
            while(ptr!=NULL){
                printf(" [%d] ",ptr->index);
                ptr=ptr->next;
            }
            printf("\n");
        }
    }
}
int deQueue()
{
	if(front==rear){			//front==rear �̸�
		return 0;			//NULL ����
	}
	else{						//ť�� ��������ʴٸ� front�� ��ĭ �÷���
		return queue[++front];	//++front�� ���ְ� queue[front]�� ����
	}
}

void enQueue(int key)
{
	if  (rear==MAX_QUEUE_SIZE-1){	//rear�� �迭�� ���� �ִٸ�
		printf("Queue is FUll\n");	//ť�� ����á�ٰ� ���
		printf("Queue's size is %d\n",MAX_QUEUE_SIZE);
	}
	else{						//�������� �ʾҴٸ�
		queue[++rear]=key;	//++rear�� ���ְ� queue[rear]�ڸ��� key�� �߰�
	}
}