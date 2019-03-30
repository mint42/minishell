/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:35:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/29 13:03:31 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

char	**g_envs;
int		g_num_envs;

char	*ft_getenv(char	*env);
int		ft_isenv(char *env, int *i);
void	add_env(char *env);
void	replace_env(char *env, int env_to_replace);
void	delete_env(int env_to_delete);

#endif
