/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 19:08:19 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "ft_list.h"
#include "ft_printf.h"

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
		{
			ft_printf("squish: unsetenv: `%s': not a valid identifier\n",
					cur->content);
		}
		cur = (cur)->next;
	}
	return (0);
}
