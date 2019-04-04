/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:37:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/04 12:47:37 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

# include <stdlib.h>

void	expand_tilde(char **s, char *input, size_t *i);
void	expand_dollar_sign(char **s, char *input, size_t *i);
void	expand_backslash(char **s, char *input, size_t *i, int quotes);
void	expand_regular(char **s, const char *ops, char *input, size_t *i);
void	expand_quotes(char **s, char c, char *input, size_t *i);

#endif
