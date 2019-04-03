/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 15:47:37 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/02 19:21:34 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncata(char **s1, const char *s2, size_t len)
{
	char	*new;
	size_t	s1len;

	s1len = ft_strlen(*s1);
	new = ft_strnew(len + s1len);
	new = ft_strncpy(new, *s1, s1len);
	new = ft_strncat(new, s2, len);
	ft_strdel(s1);
	return (new);
}
