/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:24:55 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/05 17:26:55 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATCH_QUOTES_H
# define MATCH_QUOTES_H

# define SQUOTE (1)
# define DQUOTE (2)
# define BKSLSH (4)

void	match_quotes(char **input, int i, int unmatched);
void	get_match(char **input, int i, int unmatched);

#endif
