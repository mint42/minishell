/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:35:10 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/21 17:37:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

#include <stddef.h>

char	**g_envs;
int		g_num_envs;

char	*ft_getenv(char	*command);
int		ft_isenv(char *command, int *i);
char	*replace_env(char *command, size_t env_len);
char	**add_env(char *command, int num_envs);
char	**delete_env(int env_to_delete, int num_envs);

#endif
