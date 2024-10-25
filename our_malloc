==  o// Написать свой malloc.


#include <stdio.h>

#define MEM_SIZE 1024*1024

char memory[MEM_SIZE];


// {} - занятое пространство, [] - свободное
// [.......................]
// ptr0 = malloc(size)
// {...}[..................]
// ptr1 = malloc(size)
// {...}{...}[.............]
// free(ptr0)
// [...]{...}[.............]
//      ^
// free(ptr1)
// [.......................]

// [0] -> {1} -> [2] -> NULL

typedef LinkedList_t
{
	size_t offset;
    size_t size;
    char is_used;
    LinkedList *next;
    LinkedList *prev;
} LinkedList;

void initList(LinkedList** list)
{
  *(list) = (LinkedList*) malloc(sizeof(LinkedList));
  *list->next = NULL;
  *list->prev = NULL;
  *list->is_used = 0;
  *list->size = MEM_SIZE;
  *list->offset = 0;
}

void insertAfter(LinkedList* dest, LinkedList* new_node)
{
  new_node->next = dest->next;
  if (new_node->next != NULL)
  	new_node->next->prev = new_node;
  dest->next = new_node;
  new_node->prev = dest;
}

void insertBefore(LinkedList* dest, LinkedList* new_node)
{
  new_node->prev = dest->prev;
  if (new_node->prev != NULL)
  	new_node->prev->next = new_node;
  dest->prev = new_node;
  new_node->next = dest;
}

void removeNode(LinkedList* node)
{
  if (node->prev != NULL)
  	node->prev->next = node->next;
  if (node->next != NULL)
  	node->next->prev = node->prev;
  free(node);
}

void merge(LinkedList* node)
{
  if (node->prev != NULL && node->prev->is_used == 0)
  {
    node->offset = node->prev->offset;
    node->size += node->prev->size;
    removeNode(node->prev);
  }
  if (node->next != NULL && node->next->is_used == 0)
  {
    node->size += node->next->size;
    removeNode(node->next);
  }
}

LinkedList* Head;

void *my_malloc(size_t size)
{
  LinkedList* memory_block = Head;
  while (memory_block != NULL)
  {
    if ( !memory_block->is_used && memory_block->size >= size )
        break;
    memory_block = memory_block->next; 
  }
  if( memory_block != NULL )
  {
    if (memory_block->size == size)
    {
      memory_block->is_used = 1;
      return &memory[memory_block->offset]; 
    }
    else if (memory_block->size > size)
    {
      LinkedList* new_node = (LinkedList*) malloc(sizeof(LikedList));
      new_node->size = size; 
      new_node->is_used = 1;
      new_node->offset = memory_block->offset; 
      memory_block->size  -= new_node->size; 
      memory_block->offset += new_node->size; 
      insertBefore(memory_block, new_node);
      if (memory_block == Head)
        Head = new_node; 
      return &memory[new_node->offset]; 
    }
  }
  return 0; 
}

void my_free(void *ptr)
{
  LinkedList* memory_block = Head;
  while (memory_block != NULL)
  {
    if (&memory[memory_block->offset] == ptr)
    {
      memory_block->is_used = 0;
      if (memory_block->prev == Head && Head->is_used)
        Head = memory_block; 
      merge(memory_block); 
      break; 
    }
    memory_block = memory_block->next; 
  }
}

void initMemory()
{
  Head = (LinkedList*) malloc(sizeof(LinkedList)); 
  Head->size = MEM_SIZE; 
  Head->offset = 0; 
  Head->is_used = 0; 
  Head->next = NULL;
  Head->prev = NULL; 
}

int main()
{
	initList(&Head);
	return 0;
}
