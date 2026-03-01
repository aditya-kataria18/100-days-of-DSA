#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createCircularList(int n) {
    if (n == 0) return NULL;

    int x;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp->next = head;  
    return head;
}

void traverseCircular(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCircularList(n);

    traverseCircular(head);

    return 0;
}