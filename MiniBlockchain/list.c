#include "list.h"
#include "blockchain.h"

NODE * reverse(NODE * node)
{
	NODE	*aux;
	NODE	*previous;

	previous = NULL;
	while (node != NULL)
	{
		aux = node->next;
		node->next = previous;
		previous = node;
		node = aux;
	}
	return (previous);
}

void init(NODE **head)
{
	*head = NULL;
}

NODE* add(NODE* node, DATA data)
{
	NODE	*aux;

	aux = (NODE *)malloc(sizeof(NODE));
	if (!aux)
		exit(0);
	aux->data = data;
	aux->next = node;
	node = aux;
	return (node);
}

void ft_print_list(NODE* head)
{
	NODE	*tmp;
	int		i;

	head = reverse(head);
	i = 0;
	printf("Chain\n");
	printf("-------\n");
	tmp = head;
	while (tmp != NULL)
	{
		printf("%*sPrevious hash\t%d\n", i,"", tmp->data.info.hash_previous);
        printf("%*sBlock hash\t%d\n", i,"", tmp->data.info.hash_block);
        printf("%*sTransaction\t%s\n", i,"", tmp->data.info.transaction);
        printf("%*s\n", i, "");
		tmp = tmp->next;
		i = i + 2;
	}
	printf("\n");
}

void add_at(NODE* node, DATA data) {
    NODE	*aux;
	
	aux = (NODE*) malloc(sizeof (NODE));
    if (aux == NULL) {
        exit(EXIT_FAILURE);
    }
    aux->data = data;
    aux->next = node->next;
    node->next = aux;
}

void remove_node(NODE* head)
{
	NODE	*aux;

	aux = (NODE *)malloc(sizeof(NODE));
	if (!aux)
		return ;
	aux = head->next;
	head->next = head->next->next;
	free(aux);
}

NODE *free_list(NODE *head)
{
	NODE	*auxptr;
	NODE	*nextptr;

	auxptr = head;
	while (auxptr != NULL)
	{
		nextptr = auxptr;
		auxptr = auxptr->next;
		free(nextptr);
	}
	return (NULL);
}
