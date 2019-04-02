/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:58:24 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/01 20:33:07 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "execute_process.h"
#include "libft.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

static char		*errorm(int error)
{
	if (error == 1)
		return ("command not found");
	if (error == 2)
		return ("is a directory");
	if (error == 3)
		return ("is not executable");
	return ("error unknown: consult your local sysadmin");
}

static int		get_path(char **path, char *name)
{
	char			*path_env;
	char			**paths;
	char			**cur;
	struct stat		stats;

	path_env = ft_getenv("PATH");
	paths = ft_strsplit(path_env, ':');
	cur = paths;
	*path = ft_strdup(name);
	while ((stat(*path, &stats) == -1) && cur && *cur)
	{
		ft_strdel(path);
		*path = ft_strjoin(*cur, "/");
		*path = ft_strcata(path, name);
		++cur;
	}
	if ((!cur || !*cur) && !stats.st_mode)
		return (1);
	ft_strdel(&path_env);
	ft_delete_double_array(&paths);
	if (S_ISDIR(stats.st_mode))
		return (2);
	if (((stats.st_mode) & (EXE_BITS)) == 0)
		return (3);
	return (0);
}

static char		**get_argv(t_command *command)
{
	char	**argv;
	char	**curv;
	t_list	*cur;

	cur = command->args;
	argv = (char **)ft_memalloc(sizeof(char *) * (command->argc + 2));
	curv = argv;
	*curv = command->name;
	++curv;
	while (cur)
	{
		*curv = (cur)->content;
		cur = (cur)->next;
		++curv;
	}
	return (argv);
}

static void		execute_process(char *path, char **argv)
{
	int		pid;

	pid = fork();
	if (pid == 0)
		execve(path, argv, g_envs);
	else
		waitpid(pid, 0, 0);
}

int				execute_other(t_command *command)
{
	char	*path;
	char	**argv;
	int		error;

	path = 0;
	error = get_path(&path, command->name);
	if (!error)
	{
		argv = get_argv(command);
		execute_process(path, argv);
		ft_memdel((void **)&argv);
	}
	else
		ft_printf("squish: %s: %s\n", command->name, errorm(error));
	ft_strdel(&path);
	return (0);
}
