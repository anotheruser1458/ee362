// Maxwell Pauly

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Node {
	int val;
	struct Node * next;
};

void displayList(struct Node *head);
void destroyList(struct Node *head);
struct Node * initList(int n); 
struct Node * weave(struct Node * head);
struct Node * rotate_right(struct Node * head, int k);


void main(void) 
{
struct Node * head;
printf("Weave an even length list\n");
head = initList(10);
displayList(head);
head = weave(head);
displayList(head);
destroyList(head);

printf("Weave an odd length list\n");
head = initList(9);
displayList(head);
head = weave(head);
displayList(head);
destroyList(head);

printf("Rotate to the right by 7 nodes\n");
head = initList(10);
displayList(head);
head = rotate_right(head,7);
displayList(head);
destroyList(head);

}

int numberOfNodes(struct Node * head) {
        int numberOfNodes = 1;
    for(struct Node * currentNode = head; currentNode->next!=NULL; currentNode = currentNode->next) {
        numberOfNodes++;
    }
    return numberOfNodes;
}

struct Node * weave(struct Node * head)
{ 
    int numOfNodes = numberOfNodes(head);
    int midPos = ceil((float)numOfNodes / 2) - 1;
    struct Node *mid = head, *i = head, *temp, *temp2;

    while (midPos-- > 0) {
        mid = mid->next;
    }

    while(mid->next->next!=NULL) {
        temp = i->next;
        temp2 = mid->next->next;
        i->next = mid->next;
        mid->next->next = temp;
        mid->next = temp2;

        i = i->next->next;
    }

    if (numOfNodes%2 != 0) {
        temp = mid->next;
        i->next = mid->next;
        mid->next = NULL;
        temp->next = mid;
    }

    return head;
}

struct Node * rotate_right_once(struct Node *head) {
    struct Node *last = head, *temp;

    while (last->next->next != NULL) {
        last = last->next;
    }

    temp = last->next;
    last->next = NULL;
    temp->next = head;
    return temp;

}

struct Node * rotate_right(struct Node * head, int k)
{
    while(k-- > 0) 
        head = rotate_right_once(head);
return head;

}

struct Node * createNode(int val)
{
struct Node * p = (struct Node *) malloc(sizeof(struct Node));
p->val = val;
p->next = NULL;
return p;
}

void destroyNode(struct Node *p)
{
free(p);
}


struct Node * initList(int n) 
{
if (n<=0) return NULL;
struct Node * head = createNode(0);
struct Node * p = head;
for (int i=1; i<n; i++) {
    p->next = createNode(i);
    p = p->next;
}
return head;
}

void destroyList(struct Node *head)
{
for (struct Node *p = head; p!=NULL;) {
    struct Node * temp = p;
    p = p->next;
    free(temp);
}
}

void displayList(struct Node *head)
{
for (struct Node *p = head; p!=NULL; p=p->next) {
	printf("->%d",p->val); 
}
printf("\n");
}

