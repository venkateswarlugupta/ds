#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *leftChild,*rightChild;
}BST;
BST *createNode(int value){
    BST *newNode;
    newNode=(BST *)malloc(sizeof(BST));
    newNode->leftChild=NULL;
    newNode->data=value;
    newNode->rightChild=NULL;
    
    return newNode;
}
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
BST *createBST(BST *root,int n){
    
    int i,data;
    for(i=0;i<n;i++){
        scanf("%d",&data);
        root=insertNode(root, data);
    }
    return root;
}
void monkShouting(BST *root, int key){
    BST *cur=root;
    while(1){
        if(cur->data==key){
            printf("YES\n");
            break;
        }else if(cur->data>key){
            cur=cur->leftChild;
            if(cur==NULL){
                printf("NO\n");
                break;
            }
        }else{
            cur=cur->rightChild;
            if(cur==NULL){
                printf("NO\n");
                break;
            }
        }
    }
}
void main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,enteredStudent;
        BST *root=NULL;
        scanf("%d%d",&n,&m);
        root=createBST(root, n);
        while(m--){
            scanf("%d",&enteredStudent);
            monkShouting(root,enteredStudent);
        }
    }
}

#include<stdio.h>
#include<stdlib.h>
typedef struct skillset{
    int content,presentation,communication,total;
}skill;
typedef struct list{
    skill s;
    int teamnum;
    struct list *next;
}node;
 node* q;
node* createll(node *head,int team){
    node *temp=(node *)malloc(sizeof(node));
    scanf("%d%d%d",&temp->s.content,&temp->s.presentation,&temp->s.communication);
    temp->s.total=temp->s.content+temp->s.presentation+temp->s.communication;
    temp->next=NULL;
    temp->teamnum=team;
    if(head==NULL){
        head=temp;
        q=temp;
    }
    else{
        q->next=temp;
        q=temp;
    }
    return head;
}
void display(node *head){
    if(head==NULL){
        printf("No teams participated\n");
    }
    else{
        node *q=head;
        int i=1;
        while(q!=NULL){
            printf("Team %d scores: %d %d %d Total: %d\n",q->teamnum,q->s.content,q->s.presentation,q->s.communication,q->s.total);
            i++;
            q=q->next;
        }
    }
}
node *gettail(node *q){
   while(q!=NULL&&q->next!=NULL){
       q=q->next;
   } 
   return q;
}
node* partition(node *head,node *end,node **newhead,node **newend){
    node *pivot=end;
    node *prev=NULL, *cur=head,*tail=pivot;
    while(cur!=pivot){
        if(cur->s.total>=pivot->s.total){
            if((*newhead)==NULL){
                (*newhead)=cur;
            }
            prev=cur;
            cur=cur->next;
        }
        else{
            if(prev){
                prev->next=cur->next;}
                node *temp=cur->next;
                cur->next=NULL;
                tail->next=cur;
                tail=cur;
                cur=temp;
            }
        
    }
    if(*newhead==NULL){
        *newhead=pivot;
    }
    *newend=tail;
    return pivot;
}
node *quicksortrecur(node *head,node *end){
    if(!head||head==end)return head;
    node *newhead=NULL,*newend=NULL;
    node *pivot=partition(head,end,&newhead,&newend);
    if(newhead!=pivot){
        node *temp=newhead;
        while(temp->next!=pivot){
            temp=temp->next;
        }
        temp->next=NULL;
        newhead=quicksortrecur(newhead,temp);
        temp=gettail(newhead);
        temp->next=pivot;
    }
    pivot->next=quicksortrecur(pivot->next,newend);
    return newhead;
    
}
node* quicksort(node **head){
    *head=quicksortrecur(*head,gettail(*head));
    return *head;
}
int main(){
    node* head=NULL;
    for(int i=0;i<3;i++){
        printf("Enter the scores of team %d  in 3 respective fields out of 10\n",i+1);
       head= createll(head,i+1);
    }
    display(head);
   head= quicksort(&head);
   printf("List of teams after sorting based of total scores\n");
    display(head);
}