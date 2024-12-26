#include <stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void display(struct ListNode *head){
    struct ListNode *temp = head;
    while (temp != NULL){
        printf("%d\n", temp->val);
        temp = temp ->next;
    }
}

int countElements(struct ListNode *head){
    int count=0;
    while (head != NULL){
        count++;
        head= head->next;
    }
    return count;
}

struct ListNode* createNewNode(int num){
    struct ListNode* newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val=num;
    newNode->next=NULL;
    return newNode;
}

void insertAtEnd(struct ListNode **head, int data){
    struct ListNode* newNode = createNewNode(data);

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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL){  // if the list is empty
        printf("Empty List\n");
        return head;
    }
    struct ListNode *temp = head;
    struct ListNode *old = temp;

    if (temp -> next == NULL){  // if there is only one element in the list
        return head;
    }
    
    for (int i=1; i<=(k%countElements(head)); i++){ // k%countElements(head) is used to reduce the number of iterations
        while (temp -> next != NULL){
            old = temp;
            temp = temp -> next;
        }
        
        old -> next = NULL; // breaking the link between the last and second last node
        temp -> next = head;    // connecting the last node to the first node
        head = temp;    // updating the head
    }
    return temp;
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