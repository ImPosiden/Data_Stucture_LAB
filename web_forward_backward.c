#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char site[100];
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(const char *site) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->site, site);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void newPage(Node **current, const char *site) {
    Node *newNode = createNode(site);
    Node *temp = (*current) ? (*current)->next : NULL;
    while (temp) {
        Node *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    if (*current) {
        (*current)->next = newNode;
        newNode->prev = *current;
    }
    *current = newNode;

    printf("Opened new page: %s\n", (*current)->site);
}

void forward(Node **current) {
    if (*current && (*current)->next) {
        *current = (*current)->next;
        printf("Forward to: %s\n", (*current)->site);
    } else {
        printf("No forward link available!\n");
    }
}

void backward(Node **current) {
    if (*current && (*current)->prev) {
        *current = (*current)->prev;
        printf("Backward to: %s\n", (*current)->site);
    } else {
        printf("No backward link available!\n");
    }
}

void display(Node *head, Node *current) {
    printf("\nBrowsing History:\n");
    Node *temp = head;
    while (temp) {
        if (temp == current)
            printf("[%s] <- current\n", temp->site);
        else
            printf("%s\n", temp->site);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    Node *current = NULL;
    int choice;
    char site[100];
    do {
        printf("\n--- Browser Menu ---\n");
        printf("1. New Page\n");
        printf("2. Go Backward\n");
        printf("3. Go Forward\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter site url: ");
                scanf("%s", site);
                if (head == NULL) {  
                    head = createNode(site);
                    current = head;
                    printf("Opened new page: %s\n", current->site);
                } else {
                    newPage(&current, site);
                }
                break;
            case 2:
                backward(&current);
                break;
            case 3:
                forward(&current);
                break;
            case 4:
                display(head, current);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);
    return 0;
}
