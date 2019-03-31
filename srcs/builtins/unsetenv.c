/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:03:14 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/31 13:15:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "libft.h"

int				ft_unsetenv(t_command *command)
{
	char	*arg;
	int		i;

	i = 0;
	while (command->args)
	{
		arg = command->args->content;
		if (ft_isenv(arg, &i))
			delete_env(i);
		else
		{
			ft_printf("squish: unsetenv: `%s': not a valid identifier\n", arg);
			return (1);
		}
		command->args = (command->args)->next;
	}
	return (0);
}
