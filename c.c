#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1)
        return -1;
    return stack[top--];
}

int precedence(char x) {
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int main() {
    char exp[100], x;
    int i = 0;
    
    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    printf("Postfix expression: ");
    
    while(exp[i] != '\0') {
        char ch = exp[i];
        
        if(isalnum(ch)) {
            printf("%c", ch);
        }
        else if(ch == '(') {
            push(ch);
        }
        else if(ch == ')') {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
                printf("%c", pop());
            push(ch);
        }
        i++;
    }
    
    while(top != -1)
        printf("%c", pop());
    
    return 0;
}