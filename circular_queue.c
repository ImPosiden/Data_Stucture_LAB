#include <stdio.h>
void main() {
    int n, True = 1;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    
    int queue[n], a;
    int rear = -1, front = -1;
    while (True == 1) {
        printf("Enter the operation (enqueue=1, dequeue=2, display=3): ");
        scanf("%d", &a);
        if (a == 1) {  
            if ((rear + 1) % n == front) {  
                printf("Overflow: Queue is full\n");
            } else {
                if (front == -1 && rear == -1) { 
                    front = 0;
                    rear = 0;
                    printf("Enter the value: ");
                    scanf("%d", &queue[rear]);
                } else {
                    rear = (rear + 1) % n;
                    printf("Enter the value: ");
                    scanf("%d", &queue[rear]);
                }
            }
        } else if (a == 2) {  
            if (front == -1) {  
                printf("Underflow: Queue is empty\n");
            } else {
                printf("Deleted element is %d\n", queue[front]);
                if (front == rear) {  
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % n;
                }
            }
        } else if (a == 3) { 
            if (front == -1) {  
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                int i = front;
                while (i != rear) {  
                    printf("%d ", queue[i]);
                    i = (i + 1) % n;
                }
                printf("%d\n", queue[rear]); 
            }
        } else { 
            printf("Incorrect operation! Enter either 1, 2, or 3.\n");
        }
    }
}
