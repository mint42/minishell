/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:33:02 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/28 01:04:26 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "libft.h"

void		expand_string(char **s, char **input, size_t *i, int check_tilde)
{
	char	*tmp;

	tmp = 0;
	if (check_tilde && (*input)[*i] == '~')
		expand_tilde(s, *input, i);
	while (*input && (*input)[*i] && !ft_isspace((*input)[*i]))
	{
		if ((*input)[*i] == '$')
			expand_dollar_sign(&tmp, *input, i);
		else if ((*input)[*i] == '\'')
			expand_single_quotes(&tmp, input, i);
		else if ((*input)[*i] == '\"')
			expand_double_quotes(&tmp, input, i);
		else
			expand_regular(&tmp, " $\'\";\t\n\v\f\r", *input, i);
		*s = ft_strcata(s, tmp);
		ft_strdel(&tmp);
	}
	*i = *i + (ft_skipspace(*input + *i) - (*input + *i));
}

void		expand_single_arg(char ***args, int *argc, char **input, size_t *i)
{
	char	*tmp;

	tmp = 0;
	*argc = 1;
	*args = (char **)ft_memalloc(sizeof(char *) * (*argc + 1));
	if ((*input)[*i] == '~')
		expand_tilde(*(args), *input, i);
	while (*input && (*input)[*i])
	{
		if ((*input)[*i] == '$')
			expand_dollar_sign(&tmp, *input, i);
		else if ((*input)[*i] == '\'')
			expand_single_quotes(&tmp, input, i);
		else if ((*input)[*i] == '\"')
			expand_double_quotes(&tmp, input, i);
		else
			expand_regular(&tmp, "$\'\";", *input, i);
		**(args) = ft_strcata(*(args), tmp);
		ft_strdel(&tmp);
	}
}

void		expand_args(char ***args, int *argc, char **input, size_t *i)
{
	char	*tmp;
	char	**cur;
	char	*input_cur;

	tmp = 0;
	input_cur = *input;
	while(input_cur && *input_cur)
	{
		++(*argc);
		input_cur = ft_next_word(input_cur);
	}
	if (!*argc)
		return ;
	*args = (char **)ft_memalloc(sizeof(char *) * (*argc + 1));
	cur = *args;
	while (*input && (*input)[*i])
	{
		expand_string(&tmp, input, i, 1);
		*cur = ft_strdup(tmp);
		ft_strdel(&tmp);
		++cur;
	}
}
