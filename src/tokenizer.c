/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:30:18 by pnolte            #+#    #+#             */
/*   Updated: 2022/12/05 19:32:00 by pnolte           ###   ########.fr       */
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
		printf("%s\n", split[y]);
		y++;
	}
	printf("======================================");
}

void	tokenizer(char *raw)
{
	int i;
	int count;
	char **split;
	
	i = 0;
	count = 0;
	while (raw[i] != '\0')
	{
		if (raw[i++] == 34)
		{
			while (raw[i] == 34)
				i++;
		}
		if (raw[i] == ' ' && raw[i - 1] != ' ')
			count++;
		i++;
	}
	split = ft_split(raw, ' ');
	print_split(split);
	printf("Count: %d\n", count);
}