#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* createNewNode(int val){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode -> val = val;
    newNode -> next = NULL;
    return newNode;
}

void append(struct ListNode** head, int val){
    if (*head == NULL){
        *head = createNewNode(val);
        return;
    }
    struct ListNode* newNode = createNewNode(val);
    struct ListNode* temp = *head;
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void display(struct ListNode* head){
    while (head != NULL){
        printf("%d\n",head -> val);
        head = head -> next;
    }
}

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* first = NULL;
    struct ListNode* second = head;
    struct ListNode* end = head;
    int count = 0;

    while (end && end -> next){
        count++;
        end = end -> next;
    }

    if (count == 0){
        return head;
    }

    count++;
    for (int i = 0; i < count ; i++){
        if (second -> val >= x){
            if (second == head){
                end -> next = second;
                head = head -> next;
                end = second;
                end -> next = NULL;
                second = head;
            }
            else{
                end -> next = second;
                end = second;
                first -> next = second -> next;
                second = second -> next;
                end -> next = NULL;
            }
        }
        else{
            first = second;
            second = second -> next;
        }
    }
    return head;
}

int main(){
    struct ListNode* head = NULL;
    append(&head,1);
    append(&head,4);
    append(&head,3);
    append(&head,2);
    append(&head,5);
    append(&head,2);
    display(partition(head,3));
    return 0;
}