/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:33:02 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 18:14:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "libft.h"

void		expand_string(char **s, char **input, int check_tilde)
{
	char	*tmp;

	tmp = 0;
	if (check_tilde && **input == '~')
		expand_tilde(s, input);
	while (!ft_strchr(" \t\n\v\f\r", **input))
	{
		if (**input == '$')
			expand_dollar_sign(&tmp, input);
		else if (**input == '\'')
			expand_single_quotes(&tmp, input);
		else if (**input == '\"')
			expand_double_quotes(&tmp, input);
		else
			expand_regular(&tmp, input);
		*s = ft_strcata(s, tmp);
		ft_strdel(&tmp);
	}
	*input = ft_skipspace(*input);
}

void		expand_single_arg(char ***args, int *argc, char *input)
{
	char	*tmp;

	tmp = 0;
	*argc = 1;
	*args = (char **)ft_memalloc(sizeof(char *) * (*argc + 1));
	if (*input == '~')
		expand_tilde(*(args), &input);
	while (input && *input)
	{
		if (*input == '$')
			expand_dollar_sign(&tmp, &input);
		else if (*input == '\'')
			expand_single_quotes(&tmp, &input);
		else if (*input == '\"')
			expand_double_quotes(&tmp, &input);
		else
			expand_regular_with_space(&tmp, &input);
		**(args) = ft_strcata(*(args), tmp);
		ft_strdel(&tmp);
	}
}

void		expand_args(char ***args, int *argc, char *input)
{
	char	*tmp;
	char	**cur;
	char	*input_cur;

	tmp = 0;
	input_cur = input;
	while(input_cur && *input_cur)
	{
		++(*argc);
		input_cur = ft_next_word(input_cur);
	}
	if (!*argc)
		return ;
	*args = (char **)ft_memalloc(sizeof(char *) * (*argc + 1));
	cur = *args;
	while (input && *input)
	{
		expand_string(&tmp, &input, 1);
		*cur = ft_strdup(tmp);
		ft_strdel(&tmp);
		++cur;
	}
}
