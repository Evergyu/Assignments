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
//ADJList, ��������� ���� vertex�� -1�� index�� ����

/*�Լ���*/
void initialize();  //ť�� front,rear�� -1�� �ʱ�ȭ�ϰ� ADJList�� index���� ��� -1�� �ʱ�ȭ
void freeList(ver* ptr); //edge�� ������� �� ������ �����Ҵ� vertex���� free
void insertVertex(int key); //vertex�� index���� -1���� �� ���ڿ� �°� �ʱ�ȭ
void insertEdge(int from,int to);   //Vertex���� ���� ���� ǥ���� �� ���
int FindMinimumVertex();    //edge�� ���� vertex�� �������� index�� ���� Vertex�� ã���Լ�
void DFS(int v);    //DFS

/* for queue */
#define MAX_QUEUE_SIZE 10
int queue[MAX_QUEUE_SIZE];  //BFS�� �� int�� ť
int front = -1;
int rear = -1;
int deQueue();
void enQueue(int key);

void BFS(int v);    //BFS
void printGraph();  //ADJList ���

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
                key=FindMinimumVertex(); //edge�� ���� vertex�� �������� index�� ���� Vertex�� ã���Լ�   
                DFS(key);
    			break;
    		case 'b': case 'B':
                key=FindMinimumVertex();
                BFS(key);
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
    int i;
    front=rear=-1;  
    for(i=0;i<MAX_VERTEX_SIZE;i++){   //Vertex�� �����ŭ �ݺ����� ����
        ADJList[i].index=-1;        //�� �ε������� -1�� �ʱ�ȭ
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
        free(ptr);                      //���������� ptr�� free
    }
}

void insertVertex(int key){
    if (key<=9 && key>=0){  //ũ�Ⱑ 10�̹Ƿ� key�� 0~9
        if(ADJList[key].index==key){    //������� Vertex�� �� ����� �Ҷ�
            printf("Vertex[%d]�� �̹� �ֽ��ϴ�.\n",key);
        }
        if(ADJList[key].index==-1){     //���� ��������� ���� Vertex���
        ADJList[key].index=key;         //index�� -1���� key�� ����
        printf("Vertex[%d] has created.\n",key);    //��������ٴ� ���� ���
        }
    }
    else{
        printf("���ڸ� ����� �Է��ϼ���\n");   //�߸��� ������ ���ڸ� �Է¹޾��� ��
    }
}
void insertEdge(int from, int to){
    ver* new,*next_ver,*temp;
    new=malloc(sizeof(ver));    //�̾��� Vertex new����
    new->next=NULL;
    new->index=to;
    if(ADJList[from].index==-1){    //from�� index�� ���� Vertex�� ���� ��
        printf("%d�� Index�� ���� Vertex�� �����ϴ�.\n",from);
        insertVertex(from); //Vertex�� �����ϰ�
        printf("�ٽ� Edge�� �õ��ϼ���");   //�ٽ� �õ��϶�� ���� ���
        free(new);  //�������� Vertex new�� free
        return;     //����
    }
    if(ADJList[to].index==-1){  //from�� index�� ���� Vertex�� ���� ��
        printf("%d�� Index�� ���� Vertex�� �����ϴ�.\n",to);
        insertVertex(to);   //Vertex�� �����ϰ�
        printf("�ٽ� Edge�� �õ��ϼ���");   //�ٽ� �õ��϶�� ���� ���
        free(new);  //�������� Vertex new�� free
        return;     //����
    }
    if(ADJList[from].index!=-1 && ADJList[to].index!=-1){   //�� Vertex ��� ������
        if(ADJList[from].next==NULL){   
            ADJList[from].next=new; //ADJList[from].next�� NULL�̸� �ٷ� �̾��ݴϴ�.
        }
        else{                       //ADJList[from].next�� NULL�� �ƴϸ�
            next_ver=ADJList[from].next;    //������ next_ver�� ADJList[from].next�� �־��ְ�
            while(next_ver->next!=NULL){    //next_ver.next�� NULL�ϋ�����
                if(next_ver->index > to)    //to���� ū index�� ���� ��带 ����������
                    break;
                if(next_ver->index==to){
                    printf("�̹� ����� edge�Դϴ�.\n");
                    return;
                }
                next_ver=next_ver->next;    //next_ver�� ��ĭ�� �Ű��ְ�
                temp=next_ver;              //temp�� �ű� ���� �־��ݴϴ�.
            }
            if(next_ver->next==NULL){       //�ݺ����� ���� �� next_ver.next�� NULL�̸�
                next_ver->next=new;         //next_ver�� new�� �̾��ְ�
            }
            else{                           //NULL�� �ƴϸ�
                next_ver=new;               //next_ver->new->next_ver.next �̷������ �ǵ���
                new->next=temp->next;       //�ս��ϴ�.
            }
        }
    }  
}
int FindMinimumVertex(){                    //edge�� ���� Vertex�� �������� Vertex ã��
    int i;
    for(i=0;i<MAX_VERTEX_SIZE;i++){         //BFS,DFS ����ϱ� ���̹Ƿ�
        visited[i]=0;                       //visited�迭�� ��� 0���� �ʱ�ȭ
    }
    for(i=0;i<MAX_VERTEX_SIZE;i++){         
        if(ADJList[i].next!=NULL){          //ADJList[i].next�� NULL�� �ƴϸ�
            return i;                       //i�� �����մϴ�.
        }
    }
    return -1;  //ã�����ϸ� -1����
}
void DFS(int v){    //�������� index�� �Ű������� �޽��ϴ�.
   if(v==-1){
       printf("Vertex�� Edge�� ����� ������ּ���\n");
       return;
   }
   ver* w;          //�����͸� �ϳ� �������ְ�
   visited[v]=1;    //�������� visited�迭�� ǥ���� �� ��
   printf(" <%d> ", v);     //����Ʈ
   for(w=&ADJList[v];w;w=w->next){  //�׸��� �ݺ����� ����Լ��� w�� ��ĭ�� �ű�鼭
       if(!visited[w->index]){      //visited[w.index]�� 0�̸�
           DFS(w->index);           //�ٽ� w.index�� DFS�� �����մϴ�.
       }
   }
}
void BFS(int v){    //�������� index�� �Ű������� �ް�
    if(v==-1){
       printf("Vertex�� Edge�� ����� ������ּ���\n");
       return;
   }
    ver* w;             //�����͸� �ϳ� �������ְ�
    printf(" <%d> ",v); //����Ʈ
    enQueue(v);         //�׸��� ť�� �ֽ��ϴ�.
    visited[v]=1;       //visited[v]�� 1�� �ֽ��ϴ�.
    
    while(front<rear){
        v=deQueue();       //v�� deQueue���ְ�
        for(w=&ADJList[v];w;w=w->next){ //w�� ��ĭ�� �ű�鼭
            if(!visited[w->index]){ //visited[w.index]�� 0�̸�
                printf(" <%d> ",w->index);  //w.index�� ������ְ�
                enQueue(w->index);          //ť�� �ְ�
                visited[w->index]=1;        //visited�� 1�� �ٲ��ݴϴ�.
            }
        }
    }
}
void printGraph(){                      //���������� ���� ADJList�� ���
    int i;                              //Vertex:@ Edge: ������ �̾��� Vertex��
    ver* ptr;                           //�̷������� ����մϴ�.
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
    queue[++rear]=key;	//++rear�� ���ְ� queue[rear]�ڸ��� key�� �߰�
}