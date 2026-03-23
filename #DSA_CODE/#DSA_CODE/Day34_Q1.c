#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    if(top==NULL) return 0;
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main(){
    char exp[100];
    fgets(exp,100,stdin);

    int i=0;
    while(exp[i]){
        if(isdigit(exp[i])){
            int num=0;
            while(isdigit(exp[i])){
                num = num*10 + (exp[i]-'0');
                i++;
            }
            push(num);
        }
        else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            int b = pop();
            int a = pop();
            int res;

            if(exp[i]=='+') res = a+b;
            else if(exp[i]=='-') res = a-b;
            else if(exp[i]=='*') res = a*b;
            else res = a/b;

            push(res);
        }
        i++;
    }

    printf("%d",pop());

    return 0;
}
