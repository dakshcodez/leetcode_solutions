#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

void display(struct ListNode* head){
    struct ListNode* temp = head;
    while(temp != NULL){
        printf("%d\n",temp -> val);
        temp = temp -> next;
    }
}

struct ListNode* createNewNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode -> val = val;
    newNode -> next = NULL;
    return newNode;
}

void insertAtEnd(struct ListNode** head, int val){
    struct ListNode* newNode = createNewNode(val);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *curr, *old;
    curr = head;
    int currElement;
    while (curr != NULL){      
        if (curr -> next != NULL && curr -> val == curr -> next -> val){    // (curr -> next != NULL) was not put inside while loop condition to traverse last element as well
            currElement = curr -> val;
        }
        if (curr -> val == currElement){
            if (curr == head){  //checking if head has duplicates
                head = curr -> next;
                curr = head;
            }
            else{
                old -> next = curr -> next;
                curr = curr -> next;
            }
        }
        else{
            old = curr;
            curr = curr -> next;
        }
    }
    return head;
}

int main(){
    struct ListNode *head = NULL;
    insertAtEnd(&head,0);
    insertAtEnd(&head,0);
    insertAtEnd(&head,1);
    insertAtEnd(&head,2);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    insertAtEnd(&head,4);
    insertAtEnd(&head,5);
    insertAtEnd(&head,5);
    display(deleteDuplicates(head));
    return 0;
}