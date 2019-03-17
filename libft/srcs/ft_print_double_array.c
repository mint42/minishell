/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:06:38 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/15 23:39:22 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_double_array(char **double_array)
{
	while (double_array && *double_array)
	{
		ft_printf("%s\n", *double_array);
		++double_array;
	}
}

