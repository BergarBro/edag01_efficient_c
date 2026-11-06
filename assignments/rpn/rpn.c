#include<stdio.h>
#include<stdbool.h>
#define N		(10)

// \n = 10 , " " = 32
typedef struct {
    int list[N];
    int size;
} Stack;

void init_stack(Stack* stack){
    stack->size = -1;
}

bool isEmpty(Stack* stack){
    return stack->size == -1;
}

bool isFull(Stack* stack){
    return stack->size == N - 1;
}

void push(Stack* stack, int value){
    stack->size++;
    stack->list[stack->size] = value;
}

int pull(Stack* stack){
    int value = stack->list[stack->size];
    stack->size--;
    return value;
}


int main(void)
{
    Stack char_stack;
    Stack oper_stack;
    int new_char;
    int old_char;
    init_stack(&char_stack);
    init_stack(&oper_stack);
    new_char = 0;
    while(1){
        old_char = new_char;
        new_char = getchar();
        if (new_char != 32) // Check if next character is NOT space
            break;
    }
    

    printf("your input: %d\n",new_char);
	return 0;
}
