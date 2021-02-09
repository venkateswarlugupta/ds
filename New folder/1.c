#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int popularity;
    struct node *next;
} node;
node *head = NULL;
node *q = NULL;
node *Insert(int p)
{
    node *t = (node *)malloc(sizeof(node));
    t->popularity = p;
    t->next = NULL;
    if (head == NULL) {   
        head = t;
    } else {
        q->next = t;
    }
    q = t;
    return head;
}
node *ref;
node *delete (node *head)
{
    if (head == NULL)   return head;
    int begg = 0;
    node *r = head;
    int counter = 0;
    node *temp;
    while (r != NULL && r->next != NULL)
    {
        if (r->popularity < r->next->popularity && begg == 0)
        {
            temp = r;
            head = r->next;
            free(temp);
            counter++;
            begg = 1;
            break;
        }
        else if (r->popularity < r->next->popularity)
        {
            temp = r;
            ref->next = r->next;
            free(temp);
            counter++;
            break;
        }
        else
        {
            ref = r;
            r = r->next;
        }
        begg = 1;
    }
    if (counter != 1)
    {
        node *te;
        node *t = head;
        while (t->next->next != NULL)
        {
            t = t->next;
        }
        te = t->next;
        t->next = NULL;
        free(te);
    }
    return head;
}
void display(node *head)
{
    node *m = head;
    while (m != NULL)
    {
        printf("%d ", m->popularity);
        m = m->next;
    }
}
int main()
{
    int t, f, fr, p;
    scanf("%d", &t);
    while (t--)
    {
        head = NULL, q = NULL;
        scanf("%d%d", &f, &fr);
        for (int i = 1; i <= f; i++)
        {
            scanf("%d", &p);
            head = Insert(p);
        }
        printf("\n");
        for (int i = 0; i < fr; i++)
        {
            head = delete (head);
        }
        display(head);
    }
    return 0;
}