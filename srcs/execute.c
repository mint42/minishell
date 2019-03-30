/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:18:12 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 18:38:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "execute_process.h"
#include "command.h"
#include "libft.h"

void	execute_commands(t_list *commands)
{
	static int		(*execute_table[TOTAL_BUILTINS + 1])() = {
		ft_cd,
		ft_echo,
		ft_env,
		ft_exit,
		ft_pwd,
		ft_setenv,
		ft_unsetenv,
		execute_other,
	};

	while (commands)
	{
		RET(commands) = execute_table[INDEX(commands)](commands->content);
		commands = commands->next;
	}
}
