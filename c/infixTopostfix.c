#include<stdio.h>
#include<string.h>
char stack[20];
int top=-1;
int pri(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':return 1;
                 break;
        case '*':
        case '/':return 2;
                 break;
        case '^':return 3;
        default: return 0;
    }
}
void push(char c)
{
    top++;
    stack[top]=c;
}
char pop()
{
    int a=top;
    top--;
    return stack[a];
}

void infixToPostfix(){
	char expr[20];
    int i;
	printf("\n*****Infix to Postfix expresion*****\n");
	printf("Enter Expresion:");
	scanf("%[^\n]s",expr);
    for(i=0;i<strlen(expr);i++)
    {
        if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/')
        {
            if(top==-1)
            push(expr[i]);
            else
            {
                if(pri(stack[top])>=pri(expr[i]))
                {
                    printf("%c",pop());
                    push(expr[i]);
                }
                else
                push(expr[i]);
            }
        }
        else if(expr[i]=='(')
        push(expr[i]);
        else if(expr[i]==')')
        {
            while(stack[top]!='(')
            printf("%c",pop());
            pop();
        }
        else if(expr[i]>='a' && expr[i]<='z')
        printf("%c",expr[i]);
    }
    while(top>=0)
    printf("%c",pop());
}
void main()
{
    int ch;
    while(1){
    	printf("\n***** operation *****");
    	printf("\n1.infix to postfix");
    	printf("\n2.infix to prefix");
    	printf("\n3.prefix to postfix");
    	printf("\n4.postfix to prefix");
    	printf("\n5.exit");
    	scanf("%d",&ch);
    	switch(ch){
    		case 1:
    			infixToPostfix();
    			break;
    		case 5:
    			exit(0);
    		default:
    			printf("\nthis option is on progress...");
		}
	}
    
}
