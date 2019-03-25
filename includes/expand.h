/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:45:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/24 18:09:30 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

void	expand_tilde(char **tilde, char **input);
void	expand_dollar_sign(char **dollar_sign, char **input);
void	expand_regular(char **regular, char **input);
void	expand_regular_with_space(char **space, char **input);
void	expand_single_quotes(char **squote, char **input);
void	expand_double_quotes(char **dquote, char **input);
void	expand_string(char **s, char **input, int check_tilde);
void	expand_single_arg(char ***args, int *argc, char *input);
void	expand_args(char ***args, int *argc, char *input);

#endif
