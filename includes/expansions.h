/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:37:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/03 16:47:22 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

# include <stdlib.h>

void	expand_tilde(char **s, char *input, size_t *i);
void	expand_dollar_sign(char **s, char *input, size_t *i);
void	expand_backslash(char **s, char *input, size_t *i);
void	expand_regular(char **s, const char *ops, char *input, size_t *i);
void	expand_single_quotes(char **s, char **input, size_t *i);
void	expand_double_quotes(char **s, char **input, size_t *i);

#endif
