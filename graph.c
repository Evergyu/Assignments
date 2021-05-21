/*
 * Graph Representation : Adjacent List
 *
 * Data Structures
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex {     //Vertex의 형태
	int index;
	struct Vertex *next;
} ver;

#define MAX_VERTEX_SIZE 10  //사이즈 10
int visited[MAX_VERTEX_SIZE];     //Vertex DFS,BFS에 쓸 리스트
ver ADJList[MAX_VERTEX_SIZE]={{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL},{-1,NULL}};

/*함수들*/
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
    		printf("-------------[2018038083]------------[이인규]-------------------\n");
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
                initialize();   //Vertex_count를 0으로만들고 동적할당한 것들 모두 free
    			break;
    		case 'q': case 'Q':
                initialize();   //freeList를 모두 실행해주기 때문에 Q에도 넣었습니다.
    			break;
    		case 'v': case 'V':
                printf("Vertex Index(0~9) :");    //시작점 입력받기
                scanf("%d",&key);
                insertVertex(key);
    			break;
    		case 'e': case 'E':
                printf("from Index(0~9) :");    //시작점 입력받기
                scanf("%d",&from);
                printf("to Index(0~9) :");      //끝점 입력받기
                scanf("%d",&to);
                insertEdge(from,to);   //두Vertex를 잇는함수 호출
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
                printGraph();   //리스트의 형태로 그래프를 출력합니다.
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
    for(i;i<MAX_VERTEX_SIZE;i++){   //Vertex의 사이즈만큼 반복문을 돌려
        ADJList[i].index=-1;
        freeList(&ADJList[i]);      //Vertex에 이어진 Edge들을 free해줍니다.
    }
}

void freeList(ver* ptr){
    ver* prev;              
    if(ptr->index!=-1){
        ptr=ptr->next;
        while(ptr->next!=NULL){         //edge가 NULL이 될때까지
            prev=ptr;                   //옮기기전 ptr을 prev에 넣고
            ptr=ptr->next;              //ptr을 한칸 옮깁니다
            free(prev);                 //prev를 해제해줍니다.
        }
        free(ptr);
    }
}

void insertVertex(int key){
    if (key<=9 && key>=0){
        if(ADJList[key].index==key){
            printf("Vertex[%d]가 이미 있습니다.\n",key);
        }
        if(ADJList[key].index==-1){
        ADJList[key].index=key;
        printf("Vertex[%d] has created.\n",key);
        }
        
    }
    else{
        printf("숫자를 제대로 입력하세요\n");
    }
}
void insertEdge(int from, int to){
    ver* new,*next,*temp;
    new=malloc(sizeof(ver));
    new->next=NULL;
    new->index=to;
    if(ADJList[from].index==-1){
        printf("%d의 Index를 가진 Vertex가 없습니다.\n",from);
        insertVertex(from);
        printf("다시 Edge를 시도하세요");
        free(new);
        return;
    }
    if(ADJList[to].index==-1){
        printf("%d의 Index를 가진 Vertex가 없습니다.\n",to);
        insertVertex(to);
        printf("다시 Edge를 시도하세요");
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
	if(front==rear){			//front==rear 이면
		return 0;			//NULL 리턴
	}
	else{						//큐가 비어있지않다면 front를 한칸 늘려서
		return queue[++front];	//++front를 해주고 queue[front]를 리턴
	}
}

void enQueue(int key)
{
	if  (rear==MAX_QUEUE_SIZE-1){	//rear가 배열의 끝에 있다면
		printf("Queue is FUll\n");	//큐가 가득찼다고 출력
		printf("Queue's size is %d\n",MAX_QUEUE_SIZE);
	}
	else{						//가득차지 않았다면
		queue[++rear]=key;	//++rear를 해주고 queue[rear]자리에 key값 추가
	}
}