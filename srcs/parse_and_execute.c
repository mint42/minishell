/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:42:48 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/06 22:55:34 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "command.h"
#include "minishell.h"
#include "environment.h"
#include "execute_process.h"
#include "expansions.h"
#include "libft.h"

static int		execute_command(t_command *command)
{
	static int		(*execute_table[TOTAL_BUILTINS + 1])() = {
		ft_cd,
		ft_echo,
		ft_env,
		ft_pwd,
		ft_setenv,
		ft_unsetenv,
		execute_other,
	};

	return (execute_table[command->index](command));
}

static int		get_index(char *command_name)
{
	int				i;
	size_t			builtin_len;

	i = 0;
	while (g_builtins[i])
	{
		builtin_len = ft_strlen(g_builtins[i]);
		if (ft_strequ(command_name, g_builtins[i]))
			break ;
		++i;
	}
	return (i);
}

static char		*get_arg(char *input, size_t *i)
{
	char	*arg;

	arg = 0;
	if (input && input[*i] == '~')
		expand_tilde(&arg, input, i);
	while (input && input[*i] && input[*i] != ';' && !ft_isspace(input[*i]))
	{
		if (input[*i] == '$')
			expand_dollar_sign(&arg, input, i);
		else if (input[*i] == '\\')
			expand_backslash(&arg, input, i, 0);
		else if (input[*i] == '\'')
			expand_quotes(&arg, '\'', input, i);
		else if (input[*i] == '\"')
			expand_quotes(&arg, '\"', input, i);
		else
			expand_regular(&arg, " $\\\'\";\t\n\v\f\r", input, i);
	}
	*i = *i + (ft_skipspace(input + *i) - (input + *i));
	return (arg);
}

void			get_args(t_command **command, char *input, size_t *i)
{
	t_list	*cur;
	char	*arg;

	arg = 0;
	cur = 0;
	while (input && input[*i] && input[*i] != ';')
	{
		arg = get_arg(input, i);
		cur = ft_lstinit(arg);
		ft_lstadd_tail(&(*command)->args, cur);
		++((*command)->argc);
	}
}

int				parse_and_execute(char *input)
{
	t_command	*command;
	size_t		i;

	i = 0;
	while (input && input[i])
	{
		command = init_command_struct();
		i = i + (ft_skipspace(input + i) - (input + i));
		command->name = get_arg(input, &i);
		command->index = get_index(command->name);
		if (ft_strequ(command->name, "exit"))
		{
			ft_printf("%s\n", command->name);
			delete_command_struct(&command);
			return (1);
		}
		get_args(&command, input, &i);
		command->ret = execute_command(command);
		delete_command_struct(&command);
		if (input[i] == ';')
			++i;
	}
	return (0);
}
