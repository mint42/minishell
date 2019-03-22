/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:33:02 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:33:06 by rreedy           ###   ########.fr       */
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
		else if (**input == ''')
			expand_single_quotes(&tmp, input);
		else if (**input == '"')
			expand_double_quotes(&tmp, input);
		else
			expand_regular(&tmp, input);
		ft_strcata(s, tmp);
		ft_strdel(&tmp);
	}
}

void		expand_args(char ***args, int *argc, char *input)
{
	char	*tmp;
	char	**cur;

	tmp = 0;
	*cur = input;
	while(**cur)
	{
		++(*argc);
		*cur = ft_next_word(*cur);
	}
	if (!*argc)
		return ;
	*args = (char **)ft_memalloc(sizeof(char *) * (argc + 1));
	cur = *args;
	while (*input)
	{
		expand_string(&tmp, &input, 1);
		ft_strcata(*cur, tmp);
		ft_strdel(&tmp);
		input = ft_next_word(input);
		++cur;
	}
}
