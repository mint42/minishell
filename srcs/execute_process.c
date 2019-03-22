/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:28:50 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:33:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "libft.h"

void		execute_other(t_command *command)
{
	ft_printf("BAD/OTHER %s\n", command->name);
}
