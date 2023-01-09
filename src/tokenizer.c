/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:30:18 by pnolte            #+#    #+#             */
/*   Updated: 2023/01/09 13:07:47 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_split(char **split)
{
	int y;
	
	y = 0;
	printf("Split:\n ======================================\n");
	while (split[y] != NULL)
	{
		printf("%s ?EoF\n", split[y]);
		y++;
	}
	printf("======================================\n");
}

int	how_many_splits(char **token)
{
	int i;
	
	i = 0;
	while (token[i] != NULL)
		i++;
	return(i);
}

int	count_tokens(char *raw)
{
	int i;
	int count;
	bool whitespace;
	bool qoutation;
	
	count = 1;
	i = 0;
	printf("hi");
	if (raw[0] == ' ' || raw[0] == '	')
		whitespace = true;
	while (raw[i] != '\0')
	{	
		if (raw[i] != ' ' && raw[i] != '	')
			whitespace = false;
		if (raw[i] == 34)
			qoutation = true; 
		if((raw[i] == ' ' || raw[i] == '	') && whitespace == false && qoutation == false)
		{
			count++;
			raw[i] = 3;
			whitespace = true;
		}
		i++;
		if (raw[i] == 45)
			qoutation = false;
	}
	return(count);
}

void	tokenizer(char *raw)
{
	int i;
	int count;
	int raw_length;
	char **token;
	
	i = 0;
	printf("raw:%s\n", raw);
	count = count_tokens(raw);
	printf("Count: %d\n", count);
	// 3 is ETX (end of text), my new beloved seperator
	token = ft_split(raw, 3);
	print_split(token);
	if (count != how_many_splits(token))
	{
		printf("its not equal");
	}
}