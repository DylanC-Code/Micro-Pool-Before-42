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

void delete_first_node(struct ChainedList *p_chainedList)
{
    struct Node *node_to_delete = p_chainedList->first_element;

    if (p_chainedList->number_of_elements > 1)
    {
        p_chainedList->first_element = node_to_delete->next;
    }

    free(node_to_delete);
    p_chainedList->number_of_elements--;
    printf("First node deleted. %d nodes left.\n", p_chainedList->number_of_elements);
}

void delete_last_node(struct ChainedList *p_chainedList)
{
    struct Node *previous_node = p_chainedList->first_element;

    for (int node_number = 2; node_number < p_chainedList->number_of_elements; node_number++)
    {
        previous_node = previous_node->next;
    }

    struct Node *last_node = previous_node->next;

    previous_node->next = NULL;

    p_chainedList->last_element = previous_node;
    p_chainedList->number_of_elements--;

    free(last_node);
    printf("Last node successfully deleted. %d nodes left.\n", p_chainedList->number_of_elements);
}

void delete_middle_node(int node_number_to_delete, struct ChainedList *p_chainedList)
{
    struct Node *previous_node = p_chainedList->first_element;

    for (int node_number = 2; node_number < node_number_to_delete; node_number++)
    {
        previous_node = previous_node->next;
    }

    struct Node *node_to_delete = previous_node->next;
    previous_node->next = node_to_delete->next;
    p_chainedList->number_of_elements--;
    free(node_to_delete);

    printf("The node %d deleted. %d nodes left.\n");
}

void delete_node(int node_number_to_delete, struct ChainedList *p_chainedList)
{
    if (node_number_to_delete < 1 || node_number_to_delete > p_chainedList->number_of_elements)
    {
        printf("The node '%d' doesn't exist, the total number of nodes is %d for this chained list.\n", node_number_to_delete, p_chainedList->number_of_elements);
        return;
    }

    if (node_number_to_delete == 1)
    {
        delete_first_node(p_chainedList);
    }
    else if (node_number_to_delete == p_chainedList->number_of_elements)
    {
        delete_last_node(p_chainedList);
    }
    else
    {
        delete_middle_node(node_number_to_delete, p_chainedList);
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

    delete_node(2, &chained_list);
    display_nodes(&chained_list);
}
