#include<stdio.h>
#include <stdlib.h>

#define max 5
struct pizza 
{
    int id;
    char order[10];
};
struct pizza p[max];
int front=-1;
int rear=-1;
int frontCQ=0;
int rearCQ=0;

void add()
{
    if(rear==max-1)
    {
        printf("\nOrder is waiting confirmation");
    }
    else
    {
        rear= rear+1;
        printf("\nEnter the order id: ");
        scanf("%d", &p[rear].id);
        printf("\nEnter the order : ");
        scanf("%s", &p[rear].order);
    }
}

void delete()
{
    if(front==rear)
    {
        printf("\nNo orderrs placed");
    }
    else
    {
        front++;
        printf("\nOrder with order id %d has been delivered", p[front].id);
    }
    
}

void display()
{
    int c= front;
    front++;
    while(front<=rear)
    {
        printf("order id: %d\n", p[front].id);
        printf("order name: %s\n", p[front].order);
        front++;
    }
    front=c;
   
}

void addCQ()
{
    if((rearCQ+1)%max==frontCQ)
    {
        printf("Order waiting confirmation");
    }
    else
    {
        
        rearCQ=(rearCQ+1)%max;
        printf("\nEnter the order id: ");
        scanf("%d", &p[rearCQ].id);
        printf("\nEnter the order : ");
        scanf("%s", &p[rearCQ].order);
    }
}

void deleteCQ()
{
    if(frontCQ==rearCQ)
    {
        printf("\nNo orderrs placed");
    }
    else
    {
        frontCQ=(frontCQ+1)%max;
        printf("\nOrder with order id %d has been delivered", p[frontCQ].id);
    }
}

void displayCQ()
{
    int i=frontCQ+1;
    while(i!=rearCQ)
    {
        printf("order id: %d", p[i].id);
        i=(i+1)%max;
    }
    printf("order id: %d", p[rearCQ].id);
}

int main()
{
    int ch, ch1;
    printf("Enter typeof queue: \n1.Linear Queque\n2.Circular Queue");
    scanf("%d", &ch1);
    switch(ch1)
    {
        case 1:
            while(1)
            {
                printf("1.Add Order\n2.Delete\n3.Display\n4.EXIT\n");
                scanf("%d", &ch);
                switch(ch)
                {
                    case 1:
                        add();
                        break;

                    case 2:
                        delete();
                        break;

                    case 3:
                        display();
                        break;
                
                    case 4:
                        printf("Thankyou!");
                        exit(1);

                    default:
                        printf("Enter valid option.");
                        break;
                }
            }
            break;
        
        case 2:
            while(1)
            {
                printf("1.Add Order\n2.Delete\n3.Display\n4.EXIT\n");
                scanf("%d", &ch);
                switch(ch)
                {
                    case 1:
                        addCQ();
                        break;

                    case 2:
                        deleteCQ();
                        break;

                    case 3:
                        displayCQ();
                        break;
                
                    case 4:
                        printf("Thankyou!");
                        exit(1);

                    default:
                        printf("Enter valid option.");
                        break;
                }
            
            }
            break;
        
        case 3:
            printf("TQ");
            exit(1);
        case 4: 
            printf("Enter valid option");
            break;
    }
}


















