typedef int 	hash;
typedef char	*trans;

typedef struct block
{
	hash	hash_previous;
	hash	hash_block;
	trans	transaction;
}block_t;

typedef struct
{
	block_t	info;
}DATA;


typedef struct node
{
	DATA		data;
	struct node* next;
}NODE;

NODE*	add(NODE* node, DATA data);
void	print_list(NODE* head);
NODE	*reverse(NODE * node);
void	get_list_transactions(NODE* head,unsigned char *list_trans);