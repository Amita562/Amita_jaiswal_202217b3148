#include<stdio.h>

// Structure definition for polynomial term
struct poly {
    int coeff;
    int expo;
};

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    struct poly p1[10], p2[10], p3[10];
    int t1, t2, t3;

    // Read and display first polynomial
    t1 = readPoly(p1);
    printf("\nFirst polynomial : ");
    displayPoly(p1, t1);

    // Read and display second polynomial
    t2 = readPoly(p2);
    printf("\nSecond polynomial : ");
    displayPoly(p2, t2);

    // Add two polynomials and display resultant polynomial
    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\n\nResultant polynomial after addition : ");
    displayPoly(p3, t3);

    printf("\n");
    return 0;
}

// Function to read polynomial terms
int readPoly(struct poly p[10]) {
    int t, i;
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &t);

    printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for(i = 0; i < t; i++) {
        printf("Enter the Coefficient(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return t; // Return the number of terms read
}

// Function to add two polynomials
int addPoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10]) {
    int i = 0, j = 0, k = 0;

    while(i < t1 && j < t2) {
        if(p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if(p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }

    // Copy remaining terms of polynomial 1
    while(i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }

    // Copy remaining terms of polynomial 2
    while(j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }

    return k; // Return the number of terms in resultant polynomial
}

// Function to display polynomial
void displayPoly(struct poly p[10], int term) {
    int k;
    for(k = 0; k < term - 1; k++) {
        printf("%d(x^%d) + ", p[k].coeff, p[k].expo);
    }
    printf("%d(x^%d)", p[term - 1].coeff, p[term - 1].expo);
}
