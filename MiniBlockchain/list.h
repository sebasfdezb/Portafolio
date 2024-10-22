#ifndef LIST_H
# define LIST_H

# include "blockchain.h"

# define NVOTES 10

typedef struct
{
	block_t	info;
}DATA;


typedef struct node
{
	DATA		data;
	struct node* next;
}NODE;

typedef enum party_code_t {GOOD_PARTY, MEDIOCRE_PARTY, EVIL_PARTY, MAX_PARTIES} party_code;
char *party_name[MAX_PARTIES] = {"GOOD PARTY", "MEDIOCRE_PARTY", "EVIL_PARTY"};

void	init(NODE **head);
void	add_at(NODE *node, DATA data);
NODE*	add(NODE* node, DATA data);
void	print_list(NODE* head);
NODE	*reverse(NODE * node);
void	get_list_transactions(NODE* head,unsigned char *list_trans);

#endif