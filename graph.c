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
//ADJList, 만들어지지 않은 vertex는 -1을 index로 가짐

/*함수들*/
void initialize();  //큐의 front,rear를 -1로 초기화하고 ADJList의 index들을 모두 -1로 초기화
void freeList(ver* ptr); //edge가 만들어질 때 생성된 동적할당 vertex들을 free
void insertVertex(int key); //vertex의 index들을 -1에서 각 숫자에 맞게 초기화
void insertEdge(int from,int to);   //Vertex들을 이은 것을 표현할 때 사용
int FindMinimumVertex();    //edge를 가진 vertex중 가장작은 index를 가진 Vertex를 찾는함수
void DFS(int v);    //DFS

/* for queue */
#define MAX_QUEUE_SIZE 10
int queue[MAX_QUEUE_SIZE];  //BFS때 쓸 int형 큐
int front = -1;
int rear = -1;
int deQueue();
void enQueue(int key);

void BFS(int v);    //BFS
void printGraph();  //ADJList 출력

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
                key=FindMinimumVertex(); //edge를 가진 vertex중 가장작은 index를 가진 Vertex를 찾는함수   
                DFS(key);
    			break;
    		case 'b': case 'B':
                key=FindMinimumVertex();
                BFS(key);
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
    int i;
    front=rear=-1;  
    for(i=0;i<MAX_VERTEX_SIZE;i++){   //Vertex의 사이즈만큼 반복문을 돌려
        ADJList[i].index=-1;        //각 인덱스들을 -1로 초기화
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
        free(ptr);                      //마지막으로 ptr도 free
    }
}

void insertVertex(int key){
    if (key<=9 && key>=0){  //크기가 10이므로 key는 0~9
        if(ADJList[key].index==key){    //만들었던 Vertex를 또 만드려 할때
            printf("Vertex[%d]가 이미 있습니다.\n",key);
        }
        if(ADJList[key].index==-1){     //아직 만들어지지 않은 Vertex라면
        ADJList[key].index=key;         //index를 -1에서 key로 수정
        printf("Vertex[%d] has created.\n",key);    //만들어졌다는 문구 출력
        }
    }
    else{
        printf("숫자를 제대로 입력하세요\n");   //잘못된 범위의 숫자를 입력받았을 때
    }
}
void insertEdge(int from, int to){
    ver* new,*next_ver,*temp;
    new=malloc(sizeof(ver));    //이어줄 Vertex new생성
    new->next=NULL;
    new->index=to;
    if(ADJList[from].index==-1){    //from의 index를 가진 Vertex가 없을 때
        printf("%d의 Index를 가진 Vertex가 없습니다.\n",from);
        insertVertex(from); //Vertex를 생성하고
        printf("다시 Edge를 시도하세요");   //다시 시도하라는 문구 출력
        free(new);  //쓰지않은 Vertex new를 free
        return;     //종료
    }
    if(ADJList[to].index==-1){  //from의 index를 가진 Vertex가 없을 때
        printf("%d의 Index를 가진 Vertex가 없습니다.\n",to);
        insertVertex(to);   //Vertex를 생성하고
        printf("다시 Edge를 시도하세요");   //다시 시도하라는 문구 출력
        free(new);  //쓰지않은 Vertex new를 free
        return;     //종료
    }
    if(ADJList[from].index!=-1 && ADJList[to].index!=-1){   //두 Vertex 모두 있을때
        if(ADJList[from].next==NULL){   
            ADJList[from].next=new; //ADJList[from].next가 NULL이면 바로 이어줍니다.
        }
        else{                       //ADJList[from].next가 NULL이 아니면
            next_ver=ADJList[from].next;    //포인터 next_ver에 ADJList[from].next를 넣어주고
            while(next_ver->next!=NULL){    //next_ver.next가 NULL일떄까지
                if(next_ver->index > to)    //to보다 큰 index를 가진 노드를 만날때까지
                    break;
                if(next_ver->index==to){
                    printf("이미 연결된 edge입니다.\n");
                    return;
                }
                next_ver=next_ver->next;    //next_ver를 한칸씩 옮겨주고
                temp=next_ver;              //temp에 옮긴 값을 넣어줍니다.
            }
            if(next_ver->next==NULL){       //반복문을 나온 후 next_ver.next가 NULL이면
                next_ver->next=new;         //next_ver에 new를 이어주고
            }
            else{                           //NULL이 아니면
                next_ver=new;               //next_ver->new->next_ver.next 이런모양이 되도록
                new->next=temp->next;       //잇습니다.
            }
        }
    }  
}
int FindMinimumVertex(){                    //edge를 가진 Vertex중 가장작은 Vertex 찾기
    int i;
    for(i=0;i<MAX_VERTEX_SIZE;i++){         //BFS,DFS 사용하기 전이므로
        visited[i]=0;                       //visited배열을 모두 0으로 초기화
    }
    for(i=0;i<MAX_VERTEX_SIZE;i++){         
        if(ADJList[i].next!=NULL){          //ADJList[i].next가 NULL이 아니면
            return i;                       //i를 리턴합니다.
        }
    }
    return -1;  //찾지못하면 -1리턴
}
void DFS(int v){    //시작점의 index를 매개변수로 받습니다.
   if(v==-1){
       printf("Vertex와 Edge를 제대로 만들어주세요\n");
       return;
   }
   ver* w;          //포인터를 하나 설정해주고
   visited[v]=1;    //시작점을 visited배열에 표시해 준 후
   printf(" <%d> ", v);     //프린트
   for(w=&ADJList[v];w;w=w->next){  //그리고 반복문과 재귀함수로 w를 한칸씩 옮기면서
       if(!visited[w->index]){      //visited[w.index]가 0이면
           DFS(w->index);           //다시 w.index로 DFS를 실행합니다.
       }
   }
}
void BFS(int v){    //시작점의 index를 매개변수로 받고
    if(v==-1){
       printf("Vertex와 Edge를 제대로 만들어주세요\n");
       return;
   }
    ver* w;             //포인터를 하나 설정해주고
    printf(" <%d> ",v); //프린트
    enQueue(v);         //그리고 큐에 넣습니다.
    visited[v]=1;       //visited[v]에 1을 넣습니다.
    
    while(front<rear){
        v=deQueue();       //v를 deQueue해주고
        for(w=&ADJList[v];w;w=w->next){ //w를 한칸씩 옮기면서
            if(!visited[w->index]){ //visited[w.index]가 0이면
                printf(" <%d> ",w->index);  //w.index를 출력해주고
                enQueue(w->index);          //큐에 넣고
                visited[w->index]=1;        //visited도 1로 바꿔줍니다.
            }
        }
    }
}
void printGraph(){                      //전역변수로 만든 ADJList를 출력
    int i;                              //Vertex:@ Edge: 엣지로 이어진 Vertex들
    ver* ptr;                           //이런식으로 출력합니다.
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
    queue[++rear]=key;	//++rear를 해주고 queue[rear]자리에 key값 추가
}