/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 19:04:33 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 20:25:39 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"
#include "command.h"
#include "expand.h"
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
		command = init_command_struct();
		expand_string(&(command->name), &input, 0);
		i = get_index(command->name);
		if (i == ECHO_INDEX)
			expand_single_arg(&(command->args), &(command->argc), input);
		else
			expand_args(&(command->args), &(command->argc), input);
		execute_command(command, i);
		delete_command_struct(&command);
		input = cur;
	}
}
