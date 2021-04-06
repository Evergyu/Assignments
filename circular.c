/*
 * circularQ.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void)
{
	QueueType *cQ = createQueue();
	element data;
	char command;
    	printf("=========이 인 규============2018038083=========\n");
	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ, &data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
   	        freeQueue(cQ);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));	//동적할당으로 크기가 QueueType인 큐 생성
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType *cQ)	//사용한 큐의 메모리를 해제함
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");	//큐에 추가할 배열 하나 얻기
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
    if(cQ->front==cQ->rear)	//front와 rear가 같으면 큐가 비어있으므로 1 리턴
    	return 1;
	else
		return 0;
}

/* complete the function */
int isFull(QueueType *cQ)
{
	if(cQ->front==(cQ->rear+1)%MAX_QUEUE_SIZE)	//front와 rear+1이 같으면 꽉찬것이므로 1 리턴
		return 1;
	else 
		return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{	
	if(isFull(cQ)==1){
		printf("Circular Queue is full!\n");	//1을 받았으므로 큐가 가득찼다는 문구 출력
	}
	else {
		cQ->rear=(cQ->rear+1)%MAX_QUEUE_SIZE;	//rear의 위치를 한칸 올려줍니다.
		cQ->queue[cQ->rear]=item;				//크기 안에서 움직여야 하므로 MAX_QUEUE_SIZE로 나눈 나머지를 rear값에 넣어줍니다.
	}
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{	
	if(isEmpty(cQ)==1){
		printf("Circular Queue is empty!\n");
	}
	else {
		cQ->queue[cQ->front]='\0';	//front가 있던 자리에 문자를 지워줍니다.
		cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE;//front를 한칸 옮기고 
											   //크기 안에서 움직여야 하므로 MAX_QUEUE_SIZE로 나눈 나머지를 front값에 넣어줍니다.
	}
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}

