#include <stdio.h>

void main(){
    int n,True=1;
    printf("enter the size of queue:");
    scanf("%d",&n);
    int queue[n],a;
    int rear=-1,front=-1;

    while(True==1){
        printf("enter the operation enqueue or dequeue or display (enqueue=1,dequeue=2,display=3)");
        scanf("%d",&a);
        if (front>rear){
            front = -1 ;
            rear=-1;
        }
        if(a==1){
            if(front==-1 && rear==-1){
                rear=0;
                front=0;
                printf("enter the value");
                scanf("%d",&queue[rear]);
            }else if(rear==n-1){
                printf("overflow");
            }else{
                rear++;
                printf("enter the value");
                scanf("%d",&queue[rear]);
            }
        }else if(a==2){
            if(front==-1 && rear==-1){
                printf("underflow");
            }else if(front<=rear){
                printf("deleted element is %d",queue[front]);
                front++;
            }else{
                printf("underflow");
                front=-1;
                rear=-1;}
        }else if(a == 3) {
            if(front == -1 || front > rear) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                for(int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
        }else{
            printf("incorrect operation  enter either one or two:");
        }
    }
}
