/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:16:47 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/05 17:38:29 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>

typedef struct s_list		t_list;
typedef struct s_command	t_command;

void	print_prompt(int prompt);
int		parse_and_execute(char *input);
void	get_args(t_command **command, char *input, size_t *i);

#endif
