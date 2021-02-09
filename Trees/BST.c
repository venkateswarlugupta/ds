#include<stdio.h>
#include<stdlib.h>
#include"TreeOperations.h"
#define BST Tree
BST *insertNode(BST *root, int data){
    BST *parent;
    BST *current;
    if(root==NULL){
        root=createNode(data);
    }else{
        current=root;
        while(1){
            parent=current;
            if(data<current->data){
                current=current->leftChild;
                if(current==NULL){
                    parent->leftChild=createNode(data);
                    break;
                }
            }else{
                current=current->rightChild;
                if(current==NULL){
                    parent->rightChild=createNode(data);
                    break;
                }
            }
        }
    }
    return root;
}
BST *createBST(BST *root){
    
    int i,n,data;
    printf("No of values in BST : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        root=insertNode(root, data);
    }
    return root;
}
void main(){
    // 3 40 5 25 45 60 80 15 50
    BST *root=NULL;
    root=createBST(root);
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n\n\n\n");
//    levelOrder(root);
    deletion(root, 5);
    inOrderTraversal(root);
}