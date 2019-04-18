/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreedy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:33:01 by rreedy            #+#    #+#             */
/*   Updated: 2019/04/17 19:00:02 by rreedy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "environment.h"
#include "execute_process.h"
#include "ft_mem.h"
#include "ft_str.h"
#include "ft_list.h"
#include "ft_printf.h"
#include "ft_double_array.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

static char		*errorm(int error)
{
	if (error == 1)
		return ("command not found");
	if (error == 2)
		return ("No such file or directory");
	if (error == 3)
		return ("Permission denied");
	if (error == 4)
		return ("is a directory");
	return ("error unknown: consult your local sysadmin");
}

static int		try_paths(char **path, char *name)
{
	char			**paths;
	char			**cur;

	paths = ft_strsplit(ft_getenv("PATH"), ':');
	cur = paths;
	while ((access(*path, F_OK) == -1) && cur && *cur)
	{
		ft_strdel(path);
		ft_sprintf(path, "%s%c%s", *cur, '/', name);
		++cur;
	}
	ft_delete_double_array(&paths);
	if (access(*path, F_OK) == -1)
		return (1);
	if (access(*path, (R_OK | X_OK)) == -1)
		return (3);
	return (0);
}

static int		validate_command(char **path, char *name)
{
	struct stat		stats;

	if (!ft_strchr(name, '/'))
		return (try_paths(path, name));
	*path = ft_strdup(name);
	stat(*path, &stats);
	if (access(*path, F_OK) == -1)
		return (2);
	if (access(*path, (R_OK | X_OK)) == -1)
		return (3);
	if (S_ISDIR(stats.st_mode))
		return (4);
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

int				execute_other(t_command *command)
{
	char	*path;
	char	**argv;
	int		error;
	int		pid;

	if (!command->name)
		return (0);
	path = 0;
	error = validate_command(&path, command->name);
	if (!error)
	{
		argv = get_argv(command);
		pid = fork();
		if (pid == 0)
			execve(path, argv, g_envs);
		else
			waitpid(pid, 0, 0);
		ft_memdel((void **)&argv);
	}
	else
		ft_printf("squish: %s: %s\n", command->name, errorm(error));
	ft_strdel(&path);
	return (0);
}
