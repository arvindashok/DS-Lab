#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *push_queue (int x){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

Node *push_stack (Node **head_ref, int x){
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = x;
    new->next = *head_ref;
    return new;
}

void insert_mid (Node **headref, int x, int p){

    Node *temp = *headref;
    Node *new = (Node *)malloc(sizeof(Node));
    int counter=1;

    if (p==1){
        *headref = push_stack (headref, x);
    }

    while (temp!=NULL){
        temp=temp->next;
        counter++;
    }
    if (p>counter){
        printf ("Exceeds limit!\n");
    }
    temp=*headref; 
    for (int i=1; i<=p; i++){
        if (i==p){
            new->data = x;
            new->next = temp->next;
            temp->next = new;
        }
        temp=temp->next;
    }
}

Node *delete_beginning (Node *temp){
    Node *prev=temp;
    temp = temp->next;
    free (prev);
    return temp;
}

void delete_end (Node *temp){
    Node *prev = NULL;
    while (temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next = NULL;
    free (temp);
}

Node *deletenode (Node **head_ref, int *x){

    Node *temp=*head_ref, *prev=NULL, *head=*head_ref;
    int count=1;

    while (temp!=NULL){

        prev=temp;
        if(temp->data==*x){
            if (count==1){
                temp = temp->next;
                free (prev);
                return temp;    
            }
            else{
                prev->next=temp->next;
                free(temp);
                return head;
            }
        }
        temp=temp->next;
        count++;
    }
    printf ("Element does not exist!\n");
    return head;
}

void insert_end (Node **head_ref, int x){
    Node *temp = *head_ref;

    while (temp->next != NULL){
        temp=temp->next;
    }
    temp->next = push_queue (x);
    
}

void display (Node **headref){
    Node *temp = *headref;
    while (temp!=NULL){
        printf ("%d\t",temp->data);
        temp = temp->next;
    }
}

int main (){

    int k=0, i, choice, pos;

    Node *head = NULL;
    Node *temp = (Node *)malloc(sizeof(Node));

    while (1){
        printf ("\n1:Insert begining\n2:Insert end\n3:Insert at position\n4:Display\n5:Quit\n6:Delete beginning\n7:Delete mid\n8:Delete end\n");
        scanf ("%d", &choice);

    switch (choice){

        case 1:printf ("Enter element to add:\n");
        scanf ("%d",&i);
        head = push_stack (&head, i);
        break;

        /*case 2:
        for (int i=0; i<10; i++){

            if (k==0){
                temp = push_queue(i);
                head = temp;
            }
            else{
                temp->next = push_queue(i);
                temp = temp->next;
            }
            k++;
        }
        break;*/

        case 2:printf ("Enter element to add:\n");
        scanf ("%d",&i);
        insert_end (&head, i);
        break;

        case 3:printf ("Enter element to add:\n");
        scanf ("%d",&i);
        printf ("Enter position:\n");
        scanf ("%d",&pos);
        insert_mid (&head, i, pos);
        break;

        case 4:display (&head);
        break;

        case 5:exit(0);
        break;

        case 6:head = delete_beginning (head);
        break;

        case 7:printf ("Enter element:\n");
        scanf ("%d",&pos);
        head = deletenode (&head, &pos);
        break;

        case 8: delete_end(head);
        break;

        default:printf ("Invalid input!\n");
        break;
    }
    }
    return 0;
}



