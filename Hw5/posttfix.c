/*
 * postfix.c
 *
 *  Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack ������ �켱����, lparen = 0 ���� ���� */
typedef enum{
	lparen = 0,  /* ( ���� ��ȣ */
	rparen = 9,  /* ) ������ ��ȣ*/
	times = 7,   /* * ���� */
	divide = 6,  /* / ������ */
	plus = 5,    /* + ���� */
	minus = 4,   /* - ���� */
	operand = 1 /* �ǿ����� */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression�� �����ϴ� �迭 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix�� ����� ���ڿ��� �����ϴ� �迭 */
char postfixStack[MAX_STACK_SIZE];	/* postfix�� ��ȯ�� ���� �ʿ��� ���� */
int evalStack[MAX_STACK_SIZE];		/* ����� ���� �ʿ��� ���� */

int postfixStackTop = -1;  /* postfixStack�� top */
int evalStackTop = -1;	   /* evalStack�� top */

int evalResult = 0;	   /* ��� ����� ���� */

void postfixpush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main()
{
	char command;
	printf("=========���α�============2018038083=========\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
    char x;
    if(postfixStackTop == -1)
        return '\0';
    else {
    	x = postfixStack[postfixStackTop--];
    }
    return x;
}

void evalPush(int x)
{
    evalStack[++evalStackTop] = x;
}

int evalPop()
{
    if(evalStackTop == -1)
        return -1;
    else
        return evalStack[evalStackTop--];
}

/**
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
 */
void getInfix()
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp);
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}
}

precedence getPriority(char x)
{
	return getToken(x);
}

/**
 * �����ϳ��� ���޹޾�, postfixExp�� �߰�
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp�� ���ڸ� �ϳ��� �о�鼭 stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postFixExp�� ����ȴ�.
 */
void toPostfix()
{
	/* infixExp�� ���� �ϳ����� �б����� ������ */
	char *exp = infixExp;
	char x; /* �����ϳ��� �ӽ÷� �����ϱ� ���� ���� */
    
	/* exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ���� */
	while(*exp != '\0')
	{
		{
			/* *exp�� ���� 1 �� operand�� �� postFixExp�� �����մϴ�.*/
			if(getPriority(*(exp))==1){
                charCat(exp);
			}
			/* *exp�� ���� �� ó�� ���°�ȣ�� ������ push���ݴϴ�.
				�̴��� *(exp)==9 �� �ݴ°�ȣ�� ������ �������ϴ�.*/
			  else if(getPriority(*(exp))==0){
				postfixPush(*(exp));
			}
			/* *exp�� ���� ) ���ȣ �� �� ���ÿ��� ( �°�ȣ�� ���� �� ���� pop�ϰ�
			  postfixExp�� �־��ݴϴ�.*/
			else if(getPriority(*(exp))==9){
				//���°�ȣ�� ���ö����� ��ū���� pop�ؼ� ��½�Ŵ
				while(getPriority(postfixStack[postfixStackTop])!=0){
					x=postfixPop();
                    charCat(&x);
				}
				/*�� �� (�� pop�ؼ� �����ݴϴ�.*/
				postfixPop();
			}
			/*�켱������ ���� ���ÿ� �ִ� �ͺ��� ��ū�� �켱������ �� ������
			  ���ÿ� �ִ� ���� pop���ְ� ��ū�� push���ݴϴ�*/
			else if(getPriority(postfixStack[postfixStackTop])>=getPriority(*(exp))){
				x=postfixPop();
                charCat(&x);
                postfixPush(*(exp));
			}
			/*������ ���� ��쵵 push�ؼ� ���ÿ� �־��ݴϴ�.*/
			else postfixPush(*(exp));
		}
		exp++;//exp�� �ּҰ��� ��ĭ�� �������� �ܾ �н��ϴ�
	}
	/*���ÿ� ���� �͵��� postfixExp�� �־��ݴϴ�*/
	while(postfixStackTop!=-1){
        x=postfixPop(postfixStack[postfixStackTop]);
        charCat(&x);
        }
}
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
         
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	char *exp = postfixExp;	//postfixExp�� ���ڸ� �ϳ��� ���� ������
	int op1,op2; //����� ���� int������ �ΰ�
	/*postfixExp�迭�� ���������� ����մϴ�*/
	while(*exp != '\0'){	
		if (getToken(*exp)==1){	//exp�� operand��
			evalPush(*exp-'0');	//-'0'�� �ؼ� int������ �ٲ��ݴϴ�
		}
		/*�����ڸ� ������ ���ÿ��� �ڿ����ڰ� ���� �����Ƿ� op2,op1������ pop
		  �� �����ڿ� ���� ����ؼ� ���ÿ� �ֽ��ϴ�*/
		else {	
			op2=evalPop();
			op1=evalPop();
			switch(getToken(*exp)){
				case 4:	evalPush(op1-op2);	break;
				case 5: evalPush(op1+op2);	break;
				case 6: evalPush(op1/op2);	break;
				case 7: evalPush(op1*op2);	break;
			}
		}
		exp++; //postfixExp�� ��ĭ�� �ű�ϴ�
	}
	evalResult=evalPop(); //���������� ������� pop�ؼ� �־��ݴϴ�.
	/* postfixExp, evalStack�� �̿��� ��� */
}

