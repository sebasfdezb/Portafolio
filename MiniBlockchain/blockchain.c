#include "blockhain.h"

char	*ft_strcat(char *s1, char *s2)
{
	int i;
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

static party_code get_vote()
{
    int r = rand();
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


int main(int argc, char **argv)
{
	srand(time(NULL));
	NODE	*head;
	DATA	genesis_elem;
	trans	genesis_trans;
	trans	t;
	trans	trans_list;
	block_t	genesis_block;
	int		i;
	int		previous_block_hash;
	DATA	*el;
	block_t	*b;

	init(&head);
	genesis_trans = {party_name[get_vote()]};
	genesis_block = {0, string_to_hash(genesis_trans), genesis_trans};
	genesis_elem.info = genesis_block;
	head = add(head, genesis_elem);
	previous_block_hash = genesis_element.info.hash_previous;
	trans_list = (trans)malloc(sizeof(char) * NVOTES * 10);
	i = 0;
	while (i < NVOTES)
	{
		el = malloc(sizeof(DATA));
		b = malloc(sizeof(block_t));
		t = {party_name[get_vote()]};
		ft_strcat(trans_list, t);
		b->hash_previous = previous_block_hash;
		b->hash_block = string_to_hash(trans_list);
		b->transaction = t;
		el->info = *b;
		previous_block_hash = b->hash_block;
		head = add(head, *el);
	}
	ft_printlist(head);
	return (0);
}