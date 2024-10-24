#ifndef LIST_H
# define LIST_H


# define NVOTES 10
# include "blockchain.h"

typedef struct
{
	block_t	info;
}DATA;


typedef struct node
{
	DATA		data;
	struct node* next;
}NODE;

void	init(NODE **head);
void	add_at(NODE *node, DATA data);
NODE*	add(NODE* node, DATA data);
void	ft_print_list(NODE* head);
NODE	*reverse(NODE * node);
void	get_list_transactions(NODE* head,unsigned char *list_trans);

#endif