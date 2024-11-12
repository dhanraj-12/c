#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the polynomial linked list
void addNode(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = createNode(coeff, pow);
    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print a polynomial
void printPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            addNode(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            addNode(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            addNode(&result, sumCoeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms from poly1 or poly2
    while (poly1 != NULL) {
        addNode(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        addNode(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Creating first polynomial: 5x^3 + 4x^2 + 2x^1
    addNode(&poly1, 5, 3);
    addNode(&poly1, 4, 2);
    addNode(&poly1, 2, 1);

    // Creating second polynomial: 3x^3 + 4x^1 + 2x^0
    addNode(&poly2, 3, 3);
    addNode(&poly2, 4, 1);
    addNode(&poly2, 2, 0);

    printf("First Polynomial: ");
    printPoly(poly1);

    printf("Second Polynomial: ");
    printPoly(poly2);

    struct Node* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial after Addition: ");
    printPoly(result);

    return 0;
}
