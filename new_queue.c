#include <stdio.h>  

void displayQueue(int queue[], int front, int rear) {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main() {  
    int n, True = 1;  
    printf("Enter the size of queue: ");  
    scanf("%d", &n);  
    int queue[n], a;  
    int rear = -1, front = -1;  

    while(True == 1) {  
        printf("\nEnter the operation: enqueue=1, dequeue=2, display=3: ");  
        scanf("%d", &a);  

        if (front > rear) {  
            front = -1;  
            rear = -1;  
        }  

        if(a == 1) {  
            if(front == -1 && rear == -1) {  
                rear = 0;  
                front = 0;  
                printf("Enter the value: ");  
                scanf("%d", &queue[rear]);  
            } else if(rear == n - 1) {  
                printf("Overflow\n");  
            } else {  
                rear++;  
                printf("Enter the value: ");  
                scanf("%d", &queue[rear]);  
            }  
            displayQueue(queue, front, rear);  

        } else if(a == 2) {  
            if(front == -1 && rear == -1) {  
                printf("Underflow\n");  
            } else if(front <= rear) {  
                printf("Deleted element is %d\n", queue[front]);  
                front++;  
            } else {  
                printf("Underflow\n");  
                front = -1;  
                rear = -1;  
            }  
            displayQueue(queue, front, rear);  

        } else if(a == 3) {  
            displayQueue(queue, front, rear);  

        } else {  
            printf("Incorrect operation. Enter 1 (enqueue), 2 (dequeue), or 3 (display)\n");  
        }  
    }  
}
