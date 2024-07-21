//ARRAY IMPLEMENTATION OF QUEUE ADT
#include <stdio.h>
// #include <conio.h> // Remove this line as it's not standard
#include <stdlib.h> // Include this for exit() function
#define n 5

int main()
{
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1, x = n;

    printf("Queue using Array\n");
    printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");

    while (ch)
    {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (rear == n)
                printf("\nQueue is Full");
            else
            {
                printf("\nEnter number %d: ", j++);
                scanf("%d", &queue[rear++]);
            }
            break;

        case 2:
            if (front == rear)
            {
                printf("\nQueue is empty");
            }
            else
            {
                printf("\nDeleted Element is %d", queue[front++]);
                x--; // Decrease the count of elements in the queue
            }
            break;

        case 3:
            printf("\nQueue Elements are:\n");
            if (front == rear)
                printf("Queue is Empty\n");
            else
            {
                for (i = front; i < rear; i++)
                {
                    printf("%d\n", queue[i]);
                }
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Wrong Choice: Please see the options\n");
            break;
        }
    }

    // getch(); // Remove this line
    return 0; // Use return 0; to indicate successful termination
}
