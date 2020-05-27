#include "stack.h"
int main() {
    char st[50];
    char stk[50][50];

    char expression[50];
    char convExpression[50];

    int choice = 1;

    do {
        printf("\nMENU\n1. Infix to Postfix\n2. Postfix to Prefix\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an infix expression : ");
                scanf("%s", expression);
                inToPost(expression, convExpression, st);
                printf("The infix expression in postfix form is : %s\n", convExpression);
                break;

          
            case 2:
                printf("Enter an postfix expression : ");
                scanf("%s", expression);
                postToPre(expression, stk);
                popMultiple(stk, convExpression);
                printf("The postfix expression in prefix form is : %s\n", convExpression);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice);
    return 0;
} 
