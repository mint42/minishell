/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:35:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/22 21:39:43 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

#include <stddef.h>

char	**g_envs;
int		g_num_envs;

char	*ft_getenv(char	*env);
int		ft_isenv(char *env, int *i);
int		validate_env(char *env);
char	**add_env(char *env, int num_envs);
char	**delete_env(int env_to_delete, int num_envs);

#endif
