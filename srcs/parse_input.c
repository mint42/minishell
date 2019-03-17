/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:04:33 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/15 20:15:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		execute_command(int i, char *input)
{
	static void		(*execute_table[TOTAL_BUILTINS + 1])() = {
		ft_cd,
		ft_echo,
		ft_env,
		ft_exit,
		ft_ls,
		ft_pwd,
		ft_setenv,
		ft_unsetenv,
		execute_other,
	};

	execute_table[i](input);
}

static int		get_index(char *input)
{
	int				i;
	size_t			builtin_len;

	i = 0;
	while (g_builtins[i])
	{
		builtin_len = ft_strlen(g_builtins[i]);
		if ((ft_strncmp(input, g_builtins[i], builtin_len)) == 0)
		{
			if (!ft_strchr(" \t\n\v\f\r", input[builtin_len]))
					i = TOTAL_BUILTINS;
			break;
		}
		++i;
	}
	return (i);
}

void			parse_input(char *input)
{
	char	*cur;
	int		i;

	cur = input;
	while (input && *input)
	{
		if ((cur = ft_strchr(input, ';')))
		{
			*cur = '\0';
			cur = ft_skipspace(cur + 1);
		}
		i = get_index(input);
		execute_command(i, input);
		input = cur;
	}
}
