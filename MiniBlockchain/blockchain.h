/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blockchain.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:03:09 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/24 12:05:11 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCKCHAIN_H
# define BLOCKCHAIN_H

# include <stdio.h>
# include <search.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

typedef int		t_hash;
typedef char	*t_trans;

typedef enum party_code_t {SEBAS, EMPRESA, CLIENTE, MAX_PARTIES}	t_partycode;

extern char	*g_party_name[MAX_PARTIES];

typedef struct block
{
	t_hash	hash_previous;
	t_hash	hash_block;
	t_trans	transaction;
}block_t;

#endif
