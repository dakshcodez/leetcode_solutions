#include <stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int countElements(struct ListNode *head){
    int count=0;
    while (head != NULL){
        count++;
        head= head->next;
    }
    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if (head == NULL){
        printf("Empty List\n");
        return head;
    }
    struct ListNode *temp = head;
    struct ListNode *old = temp;

    if (temp -> next == NULL){
        return head;
    }
    
    for (int i=1; i<=(k%countElements(head)); i++){
        while (temp -> next != NULL){
            old = temp;
            temp = temp -> next;
        }
        
        old -> next = NULL;
        temp -> next = head;
        head = temp;
    }
    return temp;
}

void display(struct ListNode *head){
    struct ListNode *temp = head;
    while (temp != NULL){
        printf("%d\n", temp->val);
        temp = temp ->next;
    }
}

void insertAtEnd(struct ListNode **head, int data){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

}

struct ListNode* createNewNode(int num){
    struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=num;
    newNode->next=NULL;
    return newNode;
}

int main(){
    struct ListNode* head = NULL;
    // insertAtEnd(&head, 0);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2); 
    insertAtEnd(&head, 3);
    // insertAtEnd(&head, 4);
    // insertAtEnd(&head, 5);
    //display(head);
    display(rotateRight(head, 2000000000));
    return 0;
}