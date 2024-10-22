#ifndef BLOCKCHAIN_H
# define BLOCKCHAIN_H

typedef int 	hash;
typedef char	*trans;

# include <stdio.h>
# include <search.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

typedef struct block
{
	hash	hash_previous;
	hash	hash_block;
	trans	transaction;
}block_t;

#endif
