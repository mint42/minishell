/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:37:26 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 16:37:54 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSIONS_H
# define EXPANSIONS_H

#include <stdlib.h>

void	expand_tilde(char **tilde, char *input, size_t *i);
void	expand_dollar_sign(char **dollar_sign, char *input, size_t *i);
void	expand_regular(char **regular, char *ops, char *input, size_t *i);
void	expand_single_quotes(char **squote, char **input, size_t *i);
void	expand_double_quotes(char **dquote, char **input, size_t *i);

#endif
