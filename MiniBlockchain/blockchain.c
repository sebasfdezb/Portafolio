#include "blockchain.h"
#include "list.h"

char *party_name[MAX_PARTIES] = {"SEBAS", "EMPRESA", "CLIENTE"};

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
		i++;
	j = -1;
	while (s2[++j])
	{
		s1[i] = s2[j];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static t_partycode	get_vote(void)
{
	int	r;

	r = rand();
	return (r % MAX_PARTIES);
}

int	string_to_hash(void *str)
{
	int				result;
	unsigned char	*aux;

	result = 5381;
	aux = (unsigned char *)str;
	while (*aux)
	{
		result = result * 33 + *aux;
		++aux;
	}
	return (result);
}

void	init_blocks(NODE **head, int *previous_block_hash, t_trans *trans_list)
{
	t_trans	genesis_trans;
	block_t	genesis_block;
	DATA	genesis_elem;

	genesis_trans = party_name[get_vote()];
	genesis_block.hash_previous = 0;
	genesis_block.hash_block = string_to_hash(genesis_trans);
	genesis_block.transaction = genesis_trans;

	genesis_elem.info = genesis_block;
	*head = add(*head, genesis_elem);
	*previous_block_hash = genesis_elem.info.hash_previous;
	*trans_list = (t_trans)malloc(sizeof(char) * NVOTES * 10);
}


int	main(void)
{
	NODE	*head;
	t_trans	trans_list;
	t_trans	t;
	int		i;
	int		previous_block_hash;
	DATA	*el;
	block_t	*b;

	srand(time(NULL));
	init(&head);
	init_blocks(&head, &previous_block_hash, &trans_list);
	i = -1;
	while (++i < NVOTES)
	{
		el = malloc(sizeof(DATA));
		b = malloc(sizeof(block_t));
		t = party_name[get_vote()];
		ft_strcat(trans_list, t);
		b->hash_previous = previous_block_hash;
		b->hash_block = string_to_hash(trans_list);
		b->transaction = t;
		el->info = *b;
		previous_block_hash = b->hash_block;
		head = add(head, *el);
	}
	ft_print_list(head);
}
