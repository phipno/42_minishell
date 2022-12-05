/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:27:55 by amorvai           #+#    #+#             */
/*   Updated: 2022/12/05 18:34:45 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *ft_crr_dir()
{
	char *crr_dire;
	char *path;
	int i;
	int j;

	path = getenv("PWD");
	if (path == NULL)
	{
		ft_printf("ERROR Protection");
	}
	i = ft_strlen(path);
	j = i;
	ft_printf("PATH:%s \n", path);
	while (path[i] != '/')
		i--;
	crr_dire = ft_substr(path, i, j - i + 1);
	// // the 2 in the malloc call could be wrong, it could be just one
	// crr_dire = malloc(sizeof(char) * (j - i + 1));
	// if (crr_dire == NULL)
	// {
	// 	ft_printf("ERROR Protection");
	// }
	// x = 0;
	// while (i <= j)
	// {
	// 	crr_dire[x] = path[i];
	// 	i++;
	// 	x++;
	// }
	// crr_dire[x] = '\0';
	// free(path);
	return (crr_dire);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*crr_dir;

	(void)argc;
	(void)argv;
	(void)envp;
	//do wee need argc, argv, envp????????
	crr_dir = ft_crr_dir();
	while (1)
	{
		ft_printf("%s %s ", getenv("USER"), crr_dir);
		line = readline("🐚: ");
		parser(line);
		// ft_printf("%s\n", line);
		free(line);
	}
}
 