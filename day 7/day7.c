#include <stdlib.h>
#include <stdio.h>

#define CHAINED_LIST_SIZE 100

struct Node
{
    int value;
    struct Node *next;
};

struct ChainedList
{
    struct Node *first_element;
    struct Node *last_element;
    int number_of_elements;
};

void add_node(int value, struct ChainedList *p_chained_list)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = value;

    if (p_chained_list->number_of_elements == 0)
    {
        p_chained_list->first_element = new_node;
    }
    else
    {
        p_chained_list->last_element->next = new_node;
    }

    p_chained_list->last_element = new_node;
    p_chained_list->number_of_elements++;
}

void display_nodes(struct ChainedList *chainedList)
{
    if (!chainedList->number_of_elements)
    {
        printf("No node in this list.\n");
        return;
    }

    struct Node *current_node = chainedList->first_element;

    for (int node_index = 1; node_index <= chainedList->number_of_elements; node_index++)
    {

        if (node_index == chainedList->number_of_elements)
        {
            printf("The last node is number '%d' and has value '%d'.\n", node_index, current_node->value);
            return;
        }

        printf("Node '%d' has value '%d'.\n", node_index, current_node->value);
        current_node = current_node->next;
    }
}

int main()
{
    struct ChainedList chained_list;
    chained_list.number_of_elements = 0;

    add_node(4, &chained_list);
    add_node(6, &chained_list);
    add_node(8, &chained_list);

    printf("Chained list has '%d' elements.\n", chained_list.number_of_elements);
    display_nodes(&chained_list);
}
