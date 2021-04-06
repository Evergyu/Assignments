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

/* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum{
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

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
	printf("=========이인규============2018038083=========\n");
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
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
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
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */
    
	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while(*exp != '\0')
	{
		{
			/* *exp의 값이 1 즉 operand일 때 postFixExp에 저장합니다.*/
			if(getPriority(*(exp))==1){
                charCat(exp);
			}
			/* *exp의 값이 젤 처음 여는괄호를 만나면 push해줍니다.
				이다음 *(exp)==9 즉 닫는괄호를 만나면 없어집니다.*/
			  else if(getPriority(*(exp))==0){
				postfixPush(*(exp));
			}
			/* *exp의 값이 ) 우괄호 일 때 스택에서 ( 좌괄호를 만날 때 까지 pop하고
			  postfixExp에 넣어줍니다.*/
			else if(getPriority(*(exp))==9){
				//여는괄호가 나올때까지 토큰들을 pop해서 출력시킴
				while(getPriority(postfixStack[postfixStackTop])!=0){
					x=postfixPop();
                    charCat(&x);
				}
				/*그 후 (는 pop해서 지워줍니다.*/
				postfixPop();
			}
			/*우선순위를 비교해 스택에 있는 것보다 토큰의 우선순위가 더 작으면
			  스택에 있던 것을 pop해주고 토큰을 push해줍니다*/
			else if(getPriority(postfixStack[postfixStackTop])>=getPriority(*(exp))){
				x=postfixPop();
                charCat(&x);
                postfixPush(*(exp));
			}
			/*마지막 남은 경우도 push해서 스택에 넣어줍니다.*/
			else postfixPush(*(exp));
		}
		exp++;//exp의 주소값을 한칸씩 증가시켜 단어를 읽습니다
	}
	/*스택에 남은 것들을 postfixExp에 넣어줍니다*/
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
	char *exp = postfixExp;	//postfixExp의 문자를 하나씩 넣을 포인터
	int op1,op2; //상수를 넣을 int형변수 두개
	/*postfixExp배열이 끝날때까지 계산합니다*/
	while(*exp != '\0'){	
		if (getToken(*exp)==1){	//exp가 operand면
			evalPush(*exp-'0');	//-'0'을 해서 int형으로 바꿔줍니다
		}
		/*연산자를 만나면 스택에서 뒤에숫자가 먼저 나오므로 op2,op1순으로 pop
		  후 연산자에 따라 계산해서 스택에 넣습니다*/
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
		exp++; //postfixExp를 한칸씩 옮깁니다
	}
	evalResult=evalPop(); //마지막으로 결과값을 pop해서 넣어줍니다.
	/* postfixExp, evalStack을 이용한 계산 */
}

