#include <stdio.h>
#include <stdlib.h>
#define N 10
    
typedef struct _LinkedList
{
    int val;
    struct _LinkedList *next;
} LinkedList;

// Reverse Linked List
LinkedList *reverseLinkedList( LinkedList *list )
{
    if ( list == NULL )
    {
        return NULL;
    }
    LinkedList *previous = NULL;
    LinkedList *next = list->next;
    LinkedList *current = list;
    while ( next != NULL )
    {
        current->next = previous;
        previous = current;
        current = next;
        next = next->next;
    }
    current->next = previous;
    
    return current;
}

void printLinkedList( LinkedList *list )
{
    while ( list != NULL )
    {
        printf( "%d ", list->val );
        list = list->next;
    }
    printf( "\n" );
}

LinkedList *makeLinkedList( int len )
{
    LinkedList *head = malloc( sizeof( LinkedList ) );
    LinkedList *prev = head;
    
    for ( int i = 0; i < len - 1; i++ )
    {
        LinkedList *elem = calloc( 1, sizeof( LinkedList ) );
        prev->val = i;
        prev->next = elem;
        prev = elem;
    }
    
    prev->val = len - 1;
    prev->next = NULL;
    
    return head;
}

void freeLinkedList( LinkedList *list ) 
{
    LinkedList next;
    while (list != NULL) {
        next = list->next;
        free(list);
        list = next;
    }
}

int main()
{
    LinkedList *list = makeLinkedList( N );
    printLinkedList( list );
    
    list = reverseLinkedList( list );
    printLinkedList( list);
    
    freeLinkedList( list );
    return 0;
}
