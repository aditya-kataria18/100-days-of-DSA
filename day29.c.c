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

struct Node* append(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int n = getLength(head);
    k = k % n;
    if (k == 0)
        return head;

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;

    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++)
        temp = temp->next;

    struct Node* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, k;
    struct Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = append(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}