#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* root) {
    return (root == NULL);
}

// Function to push an element to the stack
void push(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
    printf("%d pushed to the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to get the top element of the stack
int peek(struct Node* root) {
    if (isEmpty(root)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    return root->data;
}

// Function to display the stack
void display(struct Node* root) {
    if (isEmpty(root)) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = root;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    display(root);

    printf("Top element: %d\n", peek(root));
    printf("Popped element: %d\n", pop(&root));
    display(root);

    return 0;
}