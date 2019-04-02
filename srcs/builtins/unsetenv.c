/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/01 20:48:56 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

static void		print_error(char *s)
{
	ft_printf("squish: unsetenv: `%s': not a valid identifier\n", s);
}

int				ft_unsetenv(t_command *command)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = command->args;
	while (cur)
	{
		if (ft_isenv((cur)->content, &i))
			delete_env(i);
		else
			print_error((cur)->content);
		cur = (cur)->next;
	}
	return (0);
}
