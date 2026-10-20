#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

int push(int value) {
    if (top == MAX - 1)
        return 0;

    stack[++top] = value;
    return 1;
}

int pop(int *value) {
    if (top == -1)
        return 0;

    *value = stack[top--];
    return 1;
}

int main() {
    char postfix[MAX];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    if (scanf("%99s", postfix) != 1)
        return 1;

    for (i = 0; postfix[i] != '\0'; i++) {

        char ch = postfix[i];

        if (isdigit((unsigned char)ch)) {
            if (!push(ch - '0')) {
                printf("Stack Overflow\n");
                return 1;
            }
        }
        else {
            if (!pop(&b) || !pop(&a)) {
                printf("Invalid postfix expression\n");
                return 1;
            }

            switch (ch) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0) {
                        printf("Division by zero\n");
                        return 1;
                    }
                    result = a / b;
                    break;

                case '%':
                    if (b == 0) {
                        printf("Division by zero\n");
                        return 1;
                    }
                    result = a % b;
                    break;

                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            if (!push(result)) {
                printf("Stack Overflow\n");
                return 1;
            }
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression\n");
        return 1;
    }

    printf("Result = %d\n", stack[top]);

    return 0;
}
