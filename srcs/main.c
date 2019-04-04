/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:29:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/04 12:40:36 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "command.h"
#include "minishell.h"
#include "libft.h"

/*
**	other potential prompt:
**	tim = time(NULL);
**	ft_printf("\e[1;31m\342\224\214");
**	ft_printf("(\e[0;31m%s\e[1;31m)\342\224\200", "rreedy");
**	ft_printf("(\e[0;32m~%s\e[1;31m)\342\224\200", getcwd(NULL, 0) + 18);
**	ft_printf("(\e[0;33m%.5s\e[1;31m)\n\342\224\224", ctime(&tim) + 11);
**	ft_printf("(\e[0;35mπ\e[1;31m)\e[m ");
*/

void		print_prompt(int prompt)
{
	if (prompt == 1)
		ft_printf("\e[0;33msquish-$\e[m ");
	else if (prompt == 2)
		ft_printf("\e[0;33m>\e[m ");
}

void		get_match(char **input, int i, int unmatched)
{
	char	*new_input;

	new_input = 0;
	if (unmatched & 4)
		unmatched = unmatched ^ 4;
	else
		*input = ft_strcata(input, "\n\0");
	print_prompt(2);
	if ((get_next_line(1, &new_input)) != 1)
		return ;
	*input = ft_strcata(input, new_input);
	ft_strdel(&new_input);
	match_quotes(input, i, unmatched);
}

void		match_quotes(char **input, int i, int unmatched)
{
	while ((*input) && (*input)[i])
	{
		if (((unmatched & 2) == 0) && (*input)[i] == '\'')
			unmatched = unmatched ^ 1;
		if ((unmatched & 1) == 0)
		{
			if ((*input)[i] == '\"')
				unmatched = unmatched ^ 2;
			else if ((*input)[i] == '\\')
			{
				if ((*input)[i + 1] == '\0')
					unmatched = unmatched | 4;
				else
					++i;
			}
		}
		++i;
	}
	if (unmatched)
		get_match(input, i, unmatched);
}

int			main(void)
{
	extern char		**environ;
	char			*input;
	int				ret;

	ret = 0;
	input = 0;
	g_envs = ft_dup_double_array(environ);
	g_num_envs = ft_len_double_array(g_envs);
	while (!ret)
	{
		print_prompt(1);
		if ((get_next_line(1, &input)) != 1)
			continue;
		match_quotes(&input, 0, 0);
		ret = parse_and_execute(input);
		ft_strdel(&input);
	}
	ft_delete_double_array(&g_envs);
	return (0);
}
