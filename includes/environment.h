/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:35:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/02 19:57:46 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

char	**g_envs;
int		g_num_envs;

const char	*ft_getenv(const char *env);
int			ft_isenv(const char *env, int *i);
void		add_env(const char *env);
void		replace_env(const char *env, int env_to_replace);
void		delete_env(int env_to_delete);

#endif
