#include<string.h>
#include<stdio.h>
#include<ctype.h>
int top=-1;
int stack[100];
void push(char x){
    if (top>=100){
        printf("Stack is full\n");
    }else{
      stack[++top]=x;
    }
}
char pop(){
    if(top==-1){
        printf("No elements to pop out\n");
    }else{
        return stack[top--];
    }
}
int precedence(char x){
    if(x=='('||x==')'){
        return 0;
    }else if(x=='+'||x=='-'){
        return 1;
    }else if(x=='*'||x=='/'){
        return 2;
    }
    return -1;
}
int main(){
    char exp[128];
    int c,size,i;
    printf("Enter the infix expression\n");
    scanf("%s",exp);
    char d;
    size=strlen(exp);
    while(i<size){
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i]=='(')
            push('(');
        else if(exp[i]==')'){
            while((d=pop())!='('){
                printf("%c ",d);
            }
        }else{
            while(top!=-1&&precedence(stack[top])>=precedence(exp[i])){
                d=pop();
                printf("%c",d);
            }
            push(exp[i]);
        }
        i++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
}