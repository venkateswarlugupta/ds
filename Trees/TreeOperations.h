typedef struct node{
    int data;
    struct node *leftChild,*rightChild;
    
}Tree;
Tree *createNode(int value){
    Tree *newNode;
    newNode=(Tree *)malloc(sizeof(Tree));
    newNode->leftChild=NULL;
    newNode->data=value;
    newNode->rightChild=NULL;
    
    return newNode;
}
void preOrderTraversal(Tree *root){
    if(root!=NULL){
        printf(" %d ",root->data);
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}
void postOrderTraversal(Tree *root){
    if(root!=NULL){
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf(" %d ",root->data);
    }
}
void inOrderTraversal(Tree *root){
    if(root!=NULL){
        inOrderTraversal(root->leftChild);
        printf(" %d ",root->data);
        inOrderTraversal(root->rightChild);
    }
}
int front=-1;
int rear=-1;
#define sz 50
Tree *Q[sz];
void push(Tree *x){
    if(rear==sz-1){
        //Full
    }else if(front==-1 && rear==-1){
        front++;
    }
    Q[++rear]=x;
}
Tree *pop(){
    Tree *x;
    if(front==-1 && rear==-1){
        //Empty 
    }else if(front==rear){
        front=-1;
        rear=-1;
    }else{
        x=Q[front];
        front++;
        return x;
    }
}
void levelOrder(Tree *root) 
{ 
    if (root == NULL) return; 
    Tree *current;  
    push(root);  
    push(NULL); //first iteration : root->data null
    //     1 
    // 2      3

    while(rear-front>0) { 
        current=pop();  
        if (current == NULL) { 
           push(NULL); 
           printf(" \n");
        } else { 
            if(current->leftChild) 
            push(current->leftChild); 
            if(current->rightChild) 
            push(current->rightChild); 
            printf("%d ",current->data); 
        } 
    } 
} 
int isLeaf(Tree *node){
    if(node->leftChild==NULL&&node->rightChild==NULL){
        return 1;
    }
    return 0;
}
int max(int a, int b){
    return (a>b) ? a:b;
}
int height(Tree *node){
    if(node==NULL||isLeaf(node)){
        return 0;
    }
    return max(height(node->leftChild),height(node->rightChild))+1;
}
Tree *CommonAncestor(Tree *root, Tree *p, Tree *q){
    if(root==NULL)          return NULL;    
    if(root==p||root==q)    return root;
    Tree *l=CommonAncestor(root->leftChild,p,q);
    Tree *r=CommonAncestor(root->rightChild,p,q);
    if(l&&r) return root;
    return l?l:r;
}
void deletion(Tree *root, int key){
    if(root==NULL){
        return;
    }else if(root->data==key){
            Tree *t=root;
        if(root->leftChild==NULL&&root->rightChild==NULL){
            root=NULL;
        }else if(root->leftChild==NULL){
            root=root->rightChild;            
        }else{
            root=root->leftChild;
        }
        free(t);
        return;
    }else if(root->leftChild->data==key){
        Tree *t=root->leftChild;
        if(root->leftChild->leftChild==NULL&&root->leftChild->rightChild==NULL){
            root->leftChild=NULL;
        }else if(root->leftChild->leftChild==NULL){
            root->rightChild=root->leftChild->rightChild;
        }else if(root->leftChild->rightChild==NULL){
            root->leftChild=root->rightChild->leftChild;
        }
        free(t);
        return;
    }   
    else if(root->rightChild->data==key){
        Tree *t=root->rightChild;
        if(root->rightChild->leftChild==NULL&&root->rightChild->rightChild==NULL){
            root->rightChild=NULL;
        }else if(root->rightChild->leftChild==NULL){
            root->rightChild=root->rightChild->rightChild;
        }else{
            root->rightChild=root->rightChild->leftChild;
        }
        free(t);
        return;
    }
    if(root->data>key){
        deletion(root->leftChild,key);
    }else{
        deletion(root->rightChild,key);
    }
}