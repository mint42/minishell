/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:13:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 20:17:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "command.h"
#include "minishell.h"
#include "environment.h"
#include "expansions.h"
#include "libft.h"

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
			(spaces && ft_isspace((*input)[*i])))
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
	char	**cur;
	char	*input_cur;
	int		spaces;

	input_cur = *input;
	cur = (*command)->args;
	spaces = (*op == ' ') ? 1 : 0;
	if (!spaces && input_cur && *input_cur)
		++((*command)->argc);
	else
	{
		while (input_cur && *input_cur)
		{
			++((*command)->argc);
			input_cur = ft_next_word(input_cur);
		}
	}
	if (!(*command)->argc)
		return ;
	cur = (char **)ft_memalloc(sizeof(char *) * ((*command)->argc + 1));
	while (*input && (*input)[*i])
	{
		*cur = get_arg(input, i, op, spaces);
		++cur;
	}
}

static t_list	*get_command(char **input, size_t *i)
{
	t_command	*command;

	command = init_command_struct();
	command->name = get_arg(input, i, " $\'\";\t\n\v\f\r", 1);
	command->index = get_index(command->name);
	if (command->index == ECHO_INDEX)
		get_args(&command, "$\'\";", input, i);
	else
		get_args(&command, " $\'\";\t\n\v\f\r", input, i);
	return (ft_lstnew(command));
}

t_list		*get_commands(char **input)
{
	t_list		*commands;
	t_list		*command;
	size_t		i;

	i = 0;
	commands = 0;
	command = 0;
	while (*input && (*input)[i])
	{
		command = get_command(input, &i);
		ft_lstadd_tail(commands, command);
	}
	return (commands);
}
