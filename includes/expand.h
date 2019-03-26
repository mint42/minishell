/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:45:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/25 17:27:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

#include <stdlib.h>

void	expand_tilde(char **tilde, char *input, size_t *i);
void	expand_dollar_sign(char **dollar_sign, char *input, size_t *i);
void	expand_regular(char **regular, char *input, size_t *i);
void	expand_regular_with_space(char **space, char *input, size_t *i);
void	expand_single_quotes(char **squote, char **input, size_t *i);
void	expand_double_quotes(char **dquote, char **input, size_t *i);
void	expand_string(char **s, char **input, size_t *i, int check_tilde);
void	expand_single_arg(char ***args, int *argc, char **input, size_t *i);
void	expand_args(char ***args, int *argc, char **input, size_t *i);

#endif
