#include <stdio.h>
#include <stdlib.h> // for exit()

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, i, pos, e;

int main() {
    int ch;
    char g = 'y';
    
    do {
        printf("\n Main Menu");
        printf("\n 1. Create \n 2. Delete \n 3. Search \n 4. Insert \n 5. Display \n 6. Exit \n");
        printf("\n Enter your Choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf(" \n Enter the correct choice:");
        }
        
        printf("\n Do you want to continue (y/n): ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');
    
    return 0;
}

void create() {
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("\n Enter Element %d: ", i+1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);
    
    if(pos >= n || pos < 0) {
        printf("\n Invalid Location!");
        return;
    }
    
    for(i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;
    
    printf("\n The Elements after deletion:");
    display();
}

void search() {
    int found = 0;
    
    printf("\n Enter the Element to be searched: ");
    scanf("%d", &e);
    
    for(i = 0; i < n; i++) {
        if(b[i] == e) {
            printf("\n Value %d is found at position %d.", e, i + 1);
            found = 1;
            break; // Exit the loop once found
        }
    }
    
    if(!found) {
        printf("\n Value %d is not in the list.", e);
    }
}

void insert() {
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);
    
    if(pos > n || pos < 1) {
        printf("\n Invalid Location!");
        return;
    }
    
    printf("\n Enter the element to insert: ");
    scanf("%d", &e);
    
    for(i = n - 1; i >= pos - 1; i--) {
        b[i + 1] = b[i];
    }
    b[pos - 1] = e;
    n++;
    
    printf("\n The list after insertion:");
    display();
}

void display() {
    printf("\n The Elements of The list ADT are:");
    for(i = 0; i < n; i++) {
        printf("\n %d", b[i]);
    }
    printf("\n");
}
