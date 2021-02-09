#include<stdio.h>
#include<stdlib.h>
#include"TreeOperations.h"
#define BT Tree

void main(){
    BT *root;
    root=createNode(1);
    root->leftChild=createNode(2);
    root->rightChild=createNode(3);
    root->rightChild->leftChild=createNode(4);
    root->rightChild->rightChild=createNode(5);
    preOrderTraversal(root);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    if(isLeaf(root->leftChild)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    printf("Height of the tree is : %d\n",height(root));
    printf("Common Ancestor of 2 , 3 is %d\n",CommonAncestor(root, root->rightChild->leftChild, root->leftChild)->data);
    printf("Level order\n\n");
    levelOrder(root);
}