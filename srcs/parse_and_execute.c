/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:13:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/01 21:21:49 by rreedy           ###   ########.fr       */
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
		if (ft_strnequ(command_name, g_builtins[i], builtin_len))
			break;
		++i;
	}
	return (i);
}

static char		*get_arg(char **input, size_t *i, char *op, int spaces)
{
	char	*arg;

	arg = 0;
	if ((*input)[*i] == '~')
		expand_tilde(&arg, *input, i);
	while (*input && (*input)[*i] && (*input)[*i] != ';' &&
			(!spaces || !ft_isspace((*input)[*i])))
	{
		if ((*input)[*i] == '$')
			expand_dollar_sign(&arg, *input, i);
		else if ((*input)[*i] == '\'')
			expand_single_quotes(&arg, input, i);
		else if ((*input)[*i] == '\"')
			expand_double_quotes(&arg, input, i);
		else
			expand_regular(&arg, op, *input, i);
	}
	*i = *i + (ft_skipspace(*input + *i) - (*input + *i));
	return (arg);
}

void		get_args(t_command **command, char *op, char **input, size_t *i)
{
	t_list	*larg;
	char	*arg;
	int		spaces;

	arg = 0;
	larg = 0;
	spaces = (*op == ' ') ? 1 : 0;
	while (*input && (*input)[*i] && (*input)[*i] != ';')
	{
		arg = get_arg(input, i, op, spaces);
		larg = ft_lstinit(arg);
		ft_lstadd_tail(&(*command)->args, larg);
		++((*command)->argc);
	}
}

int			parse_and_execute(char **input)
{
	t_command	*command;
	size_t		i;

	i = 0;
	while (input && (*input)[i])
	{
		command = init_command_struct();
		i = i + (ft_skipspace(*input + i) - (*input + i));
		command->name = get_arg(input, &i, " $\'\";\t\n\v\f\r", 1);
		command->index = get_index(command->name);
		if (ft_strequ(command->name, "exit"))
		{
			delete_command_struct(&command);
			return (0);
		}
		if (command->index == ECHO_INDEX)
			get_args(&command, "$\\\'\";", input, &i);
		else
			get_args(&command, " $\\\'\";\t\n\v\f\r", input, &i);
		command->ret = execute_command(command);
		delete_command_struct(&command);
		if ((*input)[i] == ';')
			++i;
	}
	return (1);
}
