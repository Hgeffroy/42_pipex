/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:28:51 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/14 16:21:58 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

int	is_cmdwpath(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (-1);
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (0);
		i++;
	}
	return (-1);
}

char	**is_path(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

int	check_end_path(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (1);
	return (-1);
}

int	is_directory(char *cmd)
{
	int	fd;

	fd = open(cmd, O_DIRECTORY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

char	**get_path(char **env)
{
	int		i;
	char	**new_paths;
	char	**paths;

	paths = is_path(env);
	if (!paths)
		return (NULL);
	new_paths = (char **)malloc(sizeof(char *) * (tab_len(paths) + 1));
	if (!new_paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		if (check_end_path(paths[i]) < 0)
		{
			new_paths[i] = ft_strjoin(paths[i], "/");
			if (!new_paths[i])
				return (ft_dprintf(2, "Malloc failed in parsing\n"), \
					free_tab(paths), free_tab(new_paths), NULL);
		}
		else
			new_paths[i] = ft_strdup(paths[i]);
	}
	new_paths[i] = NULL;
	return (free_tab(paths), new_paths);
}
