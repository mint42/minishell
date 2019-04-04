/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_double_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:37:08 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/03 23:46:40 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_double_array(char ***double_array)
{
	int		i;

	i = 0;
	if (!*double_array)
		return ;
	while ((*double_array)[i])
	{
		ft_strdel(&((*double_array)[i]));
		++i;
	}
	ft_memdel((void **)double_array);
}
