#include <stdio.h>
struct poly{
        int coeff;
        int expo;
    };

void Input(struct poly poly1[],int a){
    for(int i=0;i<a;i++){
        printf("Enter the Coeff and Exponant at Position %d :",i+1);
        scanf("%d %d",&poly1[i].coeff,&poly1[i].expo);
    }
}
void displayPolynomial(struct poly poly1[], int n) {
    for (int i = 0; i < n; i++) {
        if(i<n-1){
            printf("%dx^%d+", poly1[i].coeff, poly1[i].expo);
        }
        else{
            printf("%dx^%d\n", poly1[i].coeff, poly1[i].expo);
        }
    }  
}
void Add(struct poly poly1[], struct poly poly2[], int i, int j) {
    int k = 0;
    struct poly result[i + j];
    int a= 0, b = 0;

    while (a < i && b < j) {
        if (poly1[a].expo == poly2[b].expo) {
            result[k].coeff = poly1[a].coeff + poly2[b].coeff;
            result[k].expo = poly1[a].expo;
            a++;
            b++;
        } else if (poly1[a].expo > poly2[b].expo) {
            result[k] = poly1[a];
            a++;
        } else {
            result[k] = poly2[b];
            b++;
        }
        k++;
    }

    while (a < i) {
        result[k] = poly1[a];
        a++;
        k++;
    }

    while (b < j) {
        result[k] = poly2[b];
        b++;
        k++;
    }

    printf("The result of addition is: ");
    displayPolynomial(result, k);
}
void main() {
    int i, j;

    printf("Enter the number of terms in first Polynomial: ");
    scanf("%d", &i);
    printf("Enter the number of terms in second Polynomial: ");
    scanf("%d", &j);

    struct poly poly1[i], poly2[j];

    printf("Input terms for the first polynomial:\n");
    Input(poly1, i);
    printf("Input terms for the second polynomial:\n");
    Input(poly2, j);

    printf("First Polynomial: ");
    displayPolynomial(poly1, i);
    printf("Second Polynomial: ");
    displayPolynomial(poly2, j);

    Add(poly1, poly2, i, j);
}
