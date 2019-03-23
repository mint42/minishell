/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:45:30 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 18:33:15 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

char	*expand_tilde(char **input);
char	*expand_dollar_sign(char **input);
char	*expand_regular(char **input);
char	*expand_single_quote(char **input);
char	*expand_double_quote(char **input);
void	get_line_until_quote(char **input, char c);
void	expand_string(char **s, char **input, int check_tilde);
void	expand_args(char ***args, int *argc, char *input);

#endif
