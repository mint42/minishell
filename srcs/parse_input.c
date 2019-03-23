/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:04:33 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 22:09:28 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include "libft.h"

static void		execute_command(t_command *command, int i)
{
	static int		(*execute_table[TOTAL_BUILTINS + 1])() = {
		ft_cd,
		ft_echo,
		ft_env,
		ft_exit,
		ft_pwd,
		ft_setenv,
		ft_unsetenv,
		execute_other,
	};

	command->ret = execute_table[i](command);
}

static int		get_index(char *command_name)
{
	int				i;
	size_t			builtin_len;

	i = 0;
	while (g_builtins[i])
	{
		builtin_len = ft_strlen(g_builtins[i]);
		if (ft_strnequ(command_name, g_builtins[i], builtin_len))
			break;
		++i;
	}
	return (i);
}

void			parse_input(char *input)
{
	t_command	*command;
	char		*cur;
	int			i;

	cur = input;
	while (input && *input)
	{
		if ((cur = ft_strchr(input, ';')))
		{
			*cur = '\0';
			cur = ft_skipspace(cur + 1);
		}
		command = get_command_struct(input);
		i = get_index(command->name);
		execute_command(command, i);
		delete_command_struct(&command);
		input = cur;
	}
}
