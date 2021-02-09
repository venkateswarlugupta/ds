#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    char ch[128];
    int sz,open=0,close=0;
    printf("Enter the Expression \n");
    scanf("%s",ch);
    sz=strlen(ch);
    for(int i=0;i<sz;i++){
        if(ch[i]=='('){
            open++;
        }else if(ch[i]==')'&&open==0){
            printf("Not Matched\n");
            exit(1);
        }else if(ch[i]==')'){
            close++;
        }
    }
    if(open==close){
        printf("Matched\n");
    }else{
        printf("Not Matched\n");
    }
}