/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:35:47 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 19:41:07 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_tail(t_list *head, t_list *link)
{
	t_list	*cur;

	cur = head;
	if (!cur)
	{
		cur = link;
		cur->next = 0;
	}
	else
	{
		while (cur)
			cur = cur->next;
		cur = link;
		cur->next = 0;
	}
}
