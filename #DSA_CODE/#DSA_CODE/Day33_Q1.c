#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    int i=0,j=0;

    scanf("%s",infix);

    while(infix[i]){
        if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(top!=-1 && peek()!='(')
                postfix[j++]=pop();
            pop();
        }
        else{
            while(top!=-1 && precedence(peek())>=precedence(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }

    while(top!=-1)
        postfix[j++]=pop();

    postfix[j]='\0';

    printf("%s",postfix);

    return 0;
}
