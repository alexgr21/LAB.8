#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* next;};

struct node *first, *last, *current;

void DisplayList();
int GetNth(int index);

int main()
{
    int NbOfElements;
    int i;
    int ind;
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

    printf("\n\nInput the index for the node to be shown: ");
    scanf("%i", &ind);

    printf("\nThe data of the node at given index is: %i", GetNth(ind));
}


int GetNth(int index)
{
    int cnt = 0;
    current = first;
    while(cnt < index)
    {
        current = current->next;
        cnt++;
    }

return current->info;
}

void DisplayList()
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
