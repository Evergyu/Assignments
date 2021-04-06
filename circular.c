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
    	printf("=========�� �� ��============2018038083=========\n");
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
	cQ = (QueueType *)malloc(sizeof(QueueType));	//�����Ҵ����� ũ�Ⱑ QueueType�� ť ����
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

int freeQueue(QueueType *cQ)	//����� ť�� �޸𸮸� ������
{
    if(cQ == NULL) return 1;
    free(cQ);
    return 1;
}

element getElement()
{
	element item;
	printf("Input element = ");	//ť�� �߰��� �迭 �ϳ� ���
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
    if(cQ->front==cQ->rear)	//front�� rear�� ������ ť�� ��������Ƿ� 1 ����
    	return 1;
	else
		return 0;
}

/* complete the function */
int isFull(QueueType *cQ)
{
	if(cQ->front==(cQ->rear+1)%MAX_QUEUE_SIZE)	//front�� rear+1�� ������ �������̹Ƿ� 1 ����
		return 1;
	else 
		return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{	
	if(isFull(cQ)==1){
		printf("Circular Queue is full!\n");	//1�� �޾����Ƿ� ť�� ����á�ٴ� ���� ���
	}
	else {
		cQ->rear=(cQ->rear+1)%MAX_QUEUE_SIZE;	//rear�� ��ġ�� ��ĭ �÷��ݴϴ�.
		cQ->queue[cQ->rear]=item;				//ũ�� �ȿ��� �������� �ϹǷ� MAX_QUEUE_SIZE�� ���� �������� rear���� �־��ݴϴ�.
	}
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{	
	if(isEmpty(cQ)==1){
		printf("Circular Queue is empty!\n");
	}
	else {
		cQ->queue[cQ->front]='\0';	//front�� �ִ� �ڸ��� ���ڸ� �����ݴϴ�.
		cQ->front=(cQ->front+1)%MAX_QUEUE_SIZE;//front�� ��ĭ �ű�� 
											   //ũ�� �ȿ��� �������� �ϹǷ� MAX_QUEUE_SIZE�� ���� �������� front���� �־��ݴϴ�.
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

