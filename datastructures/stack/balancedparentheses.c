#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct Node
{
    char data;
    struct Node *next;
};

struct Node *stack = NULL;

void push(char value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = value;
    temp->next = stack;
    stack = temp;
}

void pop()
{
    if(stack == NULL) return;
    struct Node *temp = stack;
    stack = temp->next;
    free(temp);
}

bool pair(char top, char value)
{
    if (value == ')' && top == '(') 
        return true;
    if (value == '}' && top == '{') 
        return true;
    if (value == ']' && top == '[') 
        return true;

    return false;
}

bool checkBalancedParentheses(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(str[i]);
        }  
        if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (stack == NULL || !pair(stack->data, str[i])) {
                return false;
            } else {
                pop();
            }
        }
        i++;
    }
    
    return stack == NULL ? true : false;
}

int main()
{
    char *str = "{[(HOLA + MUNDO),()[]]}";
    bool checkStr;
    checkStr = checkBalancedParentheses(str);

    if(checkStr == true) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}