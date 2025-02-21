
// Авторы: Тимофеев Марат && Токарев Максим
// Для каждого элемента в массиве найти следующий больший элемент.
// с реализацией команд push, pop, peek
// Распечатать результат
// 1, 2, 3, 4
// 2, 3, 4, -1


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 1024


typedef struct stack_t
{
	int arr[STACK_SIZE];
    size_t top;
} Stack;


void initStack(Stack *stack)
{
  memset(stack->arr, 0, STACK_SIZE);
  stack->top = -1;
}

/**
 * @brief добавляет значение в стэк
 * @param stack — указатель на стэк
 * @param value — значение
 * @note - функция ожидает валидные данные
 */
void push(Stack *stack, int value)
{
  if (++stack->top >= STACK_SIZE)
  {
    printf("ERROR: Stack overflow\n");
	exit(1);
  }
  stack->arr[stack->top] = value;
}

int pop(Stack *stack) 
{
  if (stack->top < 0)
  {
    printf("ERROR: Stack underflow\n");
    exit(1);
  }
  return stack->arr[stack->top--];
}

int peek(Stack *stack) 
{
  if (stack->top < 0)
  {
    printf("ERROR: Stack underflow\n");
    exit(1);
  }
  return stack->arr[stack->top];
}

int stackSize(Stack *stack)
{
  return stack->top + 1;
}

int main()
{
  int array[] = {1, 2, 3, 4, 5};
  int arraySize = sizeof(array) / sizeof(array[0]);
  
  int result[] = {1, 2, 3, 4, 5};
  
  Stack stack;
  initStack(&stack);
  
  push(&stack, 0);
  for (int i = 1; i < arraySize; i++)
  {
    while (stackSize(&stack) > 0 && array[peek(&stack)] < array[i])
    {
      result[pop(&stack)] = array[i];
    }
    push(&stack, i);
  }
  while (stackSize(&stack) > 0)
  {
    result[pop(&stack)] = -1;
  }
  
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}





/*int main()
{
  int N;
  scanf("%d", &N);
  int list[N];
  for (int i = 0; i < N; ++i)
  {
    scanf("%d", &list[i]);
  }
  
  for (int i = 0; i < N - 1; ++i)
  {
    for (int j = i + 1; j < N; ++j)
    {
      if (list[i] < list[j])
      {
        printf("%d, ", list[j]);
        break;
      }
    }
  }
  printf("-1\n");
  
  return 0;
}*/
