/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:29:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/03 13:11:33 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "command.h"
#include "minishell.h"
#include "libft.h"

/*
**	//dont forget to fix directory for root folders
**	time_t	tim;
**
**	tim = time(NULL);
**	ft_printf("\e[1;31m\342\224\214");
**	ft_printf("(\e[0;31m%s\e[1;31m)\342\224\200", "rreedy");
**	ft_printf("(\e[0;32m~%s\e[1;31m)\342\224\200", getcwd(NULL, 0) + 18);
**	ft_printf("(\e[0;33m%.5s\e[1;31m)\n\342\224\224", ctime(&tim) + 11);
**	ft_printf("(\e[0;35mπ\e[1;31m)\e[m ");
*/

void		print_prompt(void)
{
	ft_printf("\e[0;33msquish-$\e[m ");
}

int			main(void)
{
	extern char		**environ;
	char			*input;
	int				ret;

	ret = 0;
	input = 0;
	g_envs = ft_dup_double_array(environ);
	g_num_envs = ft_len_double_array(g_envs);
	while (!ret)
	{
		print_prompt();
		if ((get_next_line(1, &input)) == 1)
		{
			ret = parse_and_execute(&input);
			ft_strdel(&input);
		}
	}
	ft_delete_double_array(&g_envs);
	return (0);
}
