/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 12:49:07 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/11 01:55:05 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstdelone(t_list **link, void (*del)(void *, size_t))
{
	del((*link)->content, (*link)->content_size);
	ft_memdel((void **)link);
}
