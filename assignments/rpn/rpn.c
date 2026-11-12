#include<stdio.h>
#include<stdbool.h>
#define N		(10)

// \n = 10 , " " = 32
typedef struct {
    char list[N];
    int size;
} Stack;

void init_stack(Stack* stack){
    stack->size = -1;
}

bool is_empty(Stack* stack){
    return stack->size == -1;
}

bool is_full(Stack* stack){
    return stack->size == N - 1;
}

int push(Stack* stack, char value){
    if (is_full(stack)) {
        return 1;
    } else {
        stack->size++;
        stack->list[stack->size] = value;
        return 0;
    }
}

char pop(Stack* stack){
    if (is_empty(stack)){
        return '_';
    } else {
        char value = stack->list[stack->size];
        stack->size--;
        return value;
    }
}

char* pop_n(Stack* stack, int n){
    if (stack->size > n - 1){
        return stack->list;
    }
}

void print_stack(Stack* stack){
    int i;
    printf("(");
    for (i = 0; i <= stack->size; i++){
        printf("%d",stack->list[i]);
        if (i < stack->size) {
            printf(",");
        }
    }
    printf(")\n");
    printf("Size: %d\n",stack->size);
}

bool is_number(char new_char){
    if (new_char >= 48 && new_char <= 57){
        return true;
    } else {
        return false;
    }
}

int is_operation(char new_char){
    switch (new_char)
    {
    case '+':
        return 1;

    case '-':
        return 2;

    case '*':
        return 3;

    case '/':
        return 4;
    
    default:
        return 0;
    }
}


int main(void)
{
    Stack char_stack;
    Stack oper_stack;
    char new_char;
    char old_char;
    bool last_was_number;

    init_stack(&char_stack);
    init_stack(&oper_stack);
    new_char = 0;
    while(1){
        old_char = new_char;
        new_char = getchar();
        if (new_char == 10) {continue;}
        int test = is_operation(new_char);
        if (test) {printf("Hello\n");}
        printf("value of operation: %d\n",test);
        // printf("your input(d): %d\n",new_char);
        // printf("your input(c): %c\n",new_char);
        // printf("%d\n",is_number(new_char));
        if (is_number(new_char)){
            last_was_number = true;
            if (push(&char_stack, new_char) == 1){
                printf("Stack is full!\n");
            } else {
                print_stack(&char_stack);
            }
        } else {
            char top_char = pop(&char_stack);
            if (top_char == '_'){
                printf("Stack is empty!\n");
            } else {
                printf("Top of stack: %c\n",top_char);
            }
        }
        // if (new_char != 32) // Check if next character is NOT space

        //     break;
    }
    

    printf("your input: %d\n",new_char);
	return 0;
}
