
#include <stdio.h>
#include <stdlib.h>

/* Structure for each polynomial term */
struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

typedef struct Node Node;

/* Create a new node */
Node *createNode(int coeff, int exp) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

/* Insert terms in descending order of exponents */
void insertTerm(Node **head, int coeff, int exp) {
    if (coeff == 0)
        return;

    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL && current->exp > exp) {
        previous = current;
        current = current->next;
    }

    /* Combine terms with equal exponents */
    if (current != NULL && current->exp == exp) {
        current->coeff += coeff;

        /* Delete node if coefficient becomes zero */
        if (current->coeff == 0) {
            if (previous == NULL)
                *head = current->next;
            else
                previous->next = current->next;

            free(current);
        }

        return;
    }

    Node *newNode = createNode(coeff, exp);
    newNode->next = current;

    if (previous == NULL)
        *head = newNode;
    else
        previous->next = newNode;
}

/* Read a polynomial from the user */
Node *readPolynomial(int number) {
    Node *head = NULL;
    int terms, coeff, exp;

    printf("\nEnter number of terms in Polynomial %d: ", number);

    if (scanf("%d", &terms) != 1 || terms < 0) {
        printf("Invalid number of terms!\n");
        exit(1);
    }

    for (int i = 0; i < terms; i++) {
        printf("Enter coefficient and exponent: ");

        if (scanf("%d %d", &coeff, &exp) != 2) {
            printf("Invalid input!\n");
            exit(1);
        }

        /* Negative coefficients and exponents are allowed */
        insertTerm(&head, coeff, exp);
    }

    return head;
}

/* Append a node to the result list */
void appendTerm(Node **head, Node **tail,
                int coeff, int exp) {
    if (coeff == 0)
        return;

    Node *newNode = createNode(coeff, exp);

    if (*head == NULL)
        *head = newNode;
    else
        (*tail)->next = newNode;

    *tail = newNode;
}

/* Add two polynomials */
Node *addPolynomial(Node *p, Node *q) {
    Node *result = NULL;
    Node *tail = NULL;

    while (p != NULL && q != NULL) {

        if (p->exp > q->exp) {
            appendTerm(&result, &tail, p->coeff, p->exp);
            p = p->next;
        }

        else if (p->exp < q->exp) {
            appendTerm(&result, &tail, q->coeff, q->exp);
            q = q->next;
        }

        else {
            int sum = p->coeff + q->coeff;

            appendTerm(&result, &tail, sum, p->exp);

            p = p->next;
            q = q->next;
        }
    }

    /* Copy remaining terms of first polynomial */
    while (p != NULL) {
        appendTerm(&result, &tail, p->coeff, p->exp);
        p = p->next;
    }

    /* Copy remaining terms of second polynomial */
    while (q != NULL) {
        appendTerm(&result, &tail, q->coeff, q->exp);
        q = q->next;
    }

    return result;
}

/* Display a polynomial */
void displayPolynomial(Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    int first = 1;

    while (head != NULL) {
        int c = head->coeff;
        long long value = c < 0 ? -(long long)c : c;

        if (first) {
            if (c < 0)
                printf("-");
        } else {
            printf(c < 0 ? " - " : " + ");
        }

        if (head->exp == 0) {
            printf("%lld", value);
        } else {
            if (value != 1)
                printf("%lld", value);

            printf("x");

            if (head->exp != 1)
                printf("^%d", head->exp);
        }

        first = 0;
        head = head->next;
    }

    printf("\n");
}

/* Free allocated memory */
void freePolynomial(Node *head) {
    Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* Main function */
int main() {
    Node *P1 = NULL;
    Node *P2 = NULL;
    Node *result = NULL;

    int choice;
    int resultReady = 0;

    printf("====================================\n");
    printf(" POLYNOMIAL ADDITION USING LINKED LISTS\n");
    printf("====================================\n");

    printf("\nEnter First Polynomial:");
    P1 = readPolynomial(1);

    printf("\nEnter Second Polynomial:");
    P2 = readPolynomial(2);

    do {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Display First Polynomial\n");
        printf("2. Display Second Polynomial\n");
        printf("3. Add Two Polynomials\n");
        printf("4. Display Result\n");
        printf("5. Exit\n");
        printf("===============================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {

            case 1:
                printf("\nFirst Polynomial: ");
                displayPolynomial(P1);
                break;

            case 2:
                printf("\nSecond Polynomial: ");
                displayPolynomial(P2);
                break;

            case 3:
                freePolynomial(result);
                result = addPolynomial(P1, P2);
                resultReady = 1;

                printf("\nAddition completed successfully!\n");
                printf("Result: ");
                displayPolynomial(result);
                break;

            case 4:
                if (!resultReady) {
                    printf("\nPlease add the polynomials first!\n");
                } else {
                    printf("\nResult Polynomial: ");
                    displayPolynomial(result);
                }
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    /* Release all allocated memory */
    freePolynomial(P1);
    freePolynomial(P2);
    freePolynomial(result);

    printf("Memory released successfully.\n");

    return 0;
}
