/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:16:47 by rreedy            #+#    #+#             */
/*   Updated: 2019/03/18 16:45:27 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define TOTAL_BUILTINS (8)

static char		*g_builtins[TOTAL_BUILTINS + 1] =
{
	"cd",
	"echo",
	"env",
	"exit",
	"ls",
	"pwd",
	"setenv",
	"unsetenv",
	0,
};

char			**g_envs;
int				g_envs_size;

void			parse_input(char *input);

char			*ft_getenv(char *env);
void			expand_tilde(char **command, char **newe);
void			expand_dollar_sign(char **command, char **env);
char			*expand_and_join(char *command, char *newe);
void			ft_cd(char *command);
void			ft_echo(char *command);
void			ft_env(char *command);
void			ft_exit(char *command);
void			ft_ls(char *command);
void			ft_pwd(char *command);
void			ft_setenv(char *command);
void			ft_unsetenv(char *command);
void			execute_other(char *command);

#endif
