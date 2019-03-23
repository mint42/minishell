/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_double_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 21:58:32 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 22:01:18 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_len_double_array(char **double_array)
{
	size_t		len;

	len = 0;
	if (!double_array)
		return (len);
	while (double_array[len])
		++(len);
	return (len);
}
