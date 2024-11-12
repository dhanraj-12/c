#include <stdio.h>
#include <math.h> 

#define MAX 100

struct Term {
    int coeff;
    int exp;
};

struct Polynomial {
    struct Term terms[MAX];
    int numTerms;
};


int evaluatePolynomial(struct Polynomial p, int x) {
    int result = 0;
    for (int i = 0; i < p.numTerms; i++) {
        result += p.terms[i].coeff * pow(x, p.terms[i].exp);
    }
    return result;
}


void displayPolynomial(struct Polynomial p) {
    for (int i = 0; i < p.numTerms; i++) {
        printf("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i != p.numTerms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Polynomial p;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &p.numTerms);
    
    for (int i = 0; i < p.numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &p.terms[i].coeff, &p.terms[i].exp);
    }

    printf("Polynomial: ");
    displayPolynomial(p);

    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = evaluatePolynomial(p, x);
    printf("Result of the polynomial when x = %d is: %d\n", x, result);

    return 0;
}
