/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:29:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 19:11:59 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "environment.h"
#include "libft.h"

void		print_prompt()
{
	ft_printf("\e[0;33msquish-$\e[m ");
//dont forget to fix directory for root folders
/* 
	time_t	tim;

	tim = time(NULL);
	ft_printf("\e[1;31m\342\224\214");
	ft_printf("(\e[0;31m%s\e[1;31m)\342\224\200", "rreedy");
	ft_printf("(\e[0;32m~%s\e[1;31m)\342\224\200", getcwd(NULL, 0) + 18);
	ft_printf("(\e[0;33m%.5s\e[1;31m)\n\342\224\224", ctime(&tim) + 11);
	ft_printf("(\e[0;35mπ\e[1;31m)\e[m ");
*/
}

int			main()
{
	extern char		**environ;
	char			*input;

	g_envs = ft_dup_double_array(environ);
	g_num_envs = ft_len_double_array(g_envs);
	while (42)
	{
		print_prompt();
		if ((get_next_line(2, &input)) == 1)
		{
			parse_input(input);
			ft_strdel(&input);
		}
	}
	ft_delete_double_array(&g_envs);
	return (0);
}
