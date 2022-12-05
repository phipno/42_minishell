/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnolte <pnolte@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:18:15 by amorvai           #+#    #+#             */
/*   Updated: 2022/12/05 19:27:57 by pnolte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/ft_printf/ft_printf.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

// typedef struct s_minishell
// {
// 	/* data */
// }				t_minishell;

// typedef struct s_simple_command
// {
// 	int	no_avail_args;
// 	int	no_args;
// 	char **arguments;
	
// }				t_simple_command;

// typedef struct s_command
// {
// 	int						no_avail_commands;
// 	int						no_commands;
// 	t_simple_command		**simple_commands;
// 	char					*outfile;
// 	char					*infile;
// 	char					*errfile;
// 	int						background;
// 	static t_simple_command	*current_s_command;
// }				t_command;

void parser(char *line);
void tokenizer(char *input);

char *ft_crr_dir();

#endif