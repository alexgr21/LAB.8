#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* next;};

struct node *first, *last, *current;

void DisplayList();
void DeleteList();

int main()
{
    int NbOfElements;
    int i;
    printf("Input number of elements: ");
    scanf("%i", &NbOfElements);
    printf("\n");

    first = NULL;
    for(i = 0; i < NbOfElements; ++i)
    {
        current = (struct node*)malloc(sizeof(struct node));

        printf("Input node number %i: ", i);
        scanf("%i", &current->info);
        current->next = NULL;

        if(first == NULL)
        {
            first = current;
            last = current;
        }
        else{
            last->next = current;
            last = current;
        }
    }

    DisplayList();
    DeleteList();
    DisplayList();

}

void DeleteList()
{
   current = first;
   struct node* nextnode = NULL;

   while (current != NULL)
   {
       nextnode = current->next;
       free(current);
       current = nextnode;
   }
   free(nextnode);
   first = NULL;

   printf("\n\nThe list has been deleted!");
}


void DisplayList()
{
    if(first != NULL)
    {
        printf("\nDisplaying the list: \n");
        current = first;
        while(current->next != NULL)
        {
            printf("%i  ", current->info);
            current = current -> next;
        }
    printf("%i", last->info);
    }
    else
        printf("\n\nThe list is NULL!");
}
