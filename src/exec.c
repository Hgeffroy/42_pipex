/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:22 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/17 23:40:29 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

int	create_pipes(char **args, int *fd, int forknb, int nb_cmd)
{
	fd[0] = fd[2];
	fd[1] = fd[3];
	if (forknb == 0)
	{
		fd[0] = open(args[0], O_RDONLY);
		if (fd[0] < 0)
			perror(args[0]);
	}
	else if (forknb == nb_cmd - 1)
	{
		fd[2] = 0;
		fd[3] = open(args[forknb + 2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd[3] < 0)
			perror(args[forknb + 2]);
	}
	if (forknb != nb_cmd - 1)
	{
		if (pipe(&fd[2]) == -1)
			return (ft_dprintf(2, "Pipe failed"), -2);
	}
	if (fd[0] < 0 || fd[3] < 0)
		return (-1);
	return (0);
}

void	exec_onefork(t_data *data, char *cmdwpath)
{
	char	**argssplitted;
	char	**argstoexec;

	if (set_dup(data->fd) == -1)
		exit_child(cmdwpath, data->fd);
	argssplitted = ft_split(cmdwpath, ' ');
	if (!argssplitted)
		exit_child(cmdwpath, data->fd);
	argstoexec = gen_argsexec(argssplitted[0], argssplitted);
	free_tab(argssplitted);
	if (!argstoexec)
		exit_child(cmdwpath, data->fd);
	free(cmdwpath);
	execve(argstoexec[0], argstoexec, data->env);
	free_tab(argstoexec);
	exit(1);
}

char	*setup_fork(t_data *data, int nb_cmd, int i, int *shouldfork)
{
	char	*cmdwpath;

	*shouldfork = 0;
	if (i == 0)
	{
		*shouldfork += create_pipes(data->args, data->fd, i, nb_cmd);
		cmdwpath = check_cmd(data->env, data->args[i + 1], *shouldfork);
		if (!cmdwpath)
			*shouldfork -= 1;
	}
	else
	{
		cmdwpath = check_cmd(data->env, data->args[i + 1], *shouldfork);
		if (!cmdwpath)
			*shouldfork -= 1;
		else
			*shouldfork += create_pipes(data->args, data->fd, i, nb_cmd);
	}
	return (cmdwpath);
}

int	process_manager(t_data *data, int nb_cmd, int i)
{
	int		shouldfork;
	char	*cmdwpath;

	cmdwpath = setup_fork(data, nb_cmd, i, &shouldfork);
	if (shouldfork > -1)
	{
		data->pid[i] = fork();
		if (data->pid[i] < 0)
			return (close_all(data->fd), free(data->pid), free(cmdwpath), -1);
		if (data->pid[i] == 0)
			exec_onefork(data, cmdwpath);
	}
	free(cmdwpath);
	if (shouldfork > -1)
		return (0);
	else
		return (-2);
}

int	exec_forks(t_data *data, int nb_cmd)
{
	int		i;
	int		nb_fork;

	nb_fork = 0;
	i = -1;
	while (++i < nb_cmd)
	{
		if (process_manager(data, nb_cmd, i) == 0)
			nb_fork++;
		close_inpipe(data->fd);
	}
	return (nb_fork);
}
