/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:30:59 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/17 23:55:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

char	**gen_argsexec(char *cmdwpath, char **args)
{
	char	**argsexec;
	int		i;

	argsexec = (char **)malloc(sizeof(char *) * (tab_len(args) + 1));
	if (!argsexec)
	{
		ft_dprintf(2, "Malloc failed in gen_argsexec\n");
		free(args);
		return (NULL);
	}
	argsexec[0] = ft_strdup(cmdwpath);
	if (!argsexec[0])
		return (free_tab(argsexec), NULL);
	i = 0;
	while (args[++i])
	{
		argsexec[i] = ft_strdup(args[i]);
		if (!argsexec[i])
			return (free_tab(argsexec), NULL);
	}
	argsexec[i] = NULL;
	return (argsexec);
}

char	*check_cmd_nopath(char **paths, char *cmd, int i)
{
	char	*cmd_to_check;
	char	**cmd_splitted;

	if (is_whitespace(cmd) > 0)
		return (NULL);
	cmd_to_check = ft_strjoin(paths[i], cmd);
	if (!cmd_to_check)
	{
		ft_dprintf(2, "Malloc failed in parsing\n");
		return (free_tab(paths), NULL);
	}
	cmd_splitted = ft_split(cmd_to_check, ' ');
	if (!cmd_splitted)
	{
		ft_dprintf(2, "Malloc failed in parsing\n");
		return (free(cmd_to_check), free_tab(paths), NULL);
	}
	else if (access(cmd_splitted[0], X_OK) == 0)
		return (free_tab(paths), free_tab(cmd_splitted), cmd_to_check);
	free(cmd_to_check);
	free_tab(cmd_splitted);
	return (NULL);
}

char	*check_cmd_path(char *cmd)
{
	char	**cmd_splitted;

	cmd_splitted = ft_split(cmd, ' ');
	if (!cmd_splitted)
		return (NULL);
	if (is_cmdwpath(cmd_splitted[0]) < 0)
		return (free_tab(cmd_splitted), NULL);
	if (access(cmd_splitted[0], X_OK) == 0)
		return (free_tab(cmd_splitted), ft_strdup(cmd));
	free_tab(cmd_splitted);
	return (NULL);
}

char	*check_cmd(char **env, char *cmd, int shouldfork)
{
	char	**paths;
	char	*cmd_to_check;
	int		i;

	if (shouldfork < 0)
		return (NULL);
	if (is_directory(cmd) == 0)
		return (ft_dprintf(2, "%s: Is a directory\n", cmd), NULL);
	cmd_to_check = check_cmd_path(cmd);
	if (cmd_to_check)
		return (cmd_to_check);
	paths = get_path(env);
	if (!paths)
		return (ft_dprintf(2, "%s: No such file or directory\n", cmd), NULL);
	i = -1;
	while (paths[++i])
	{
		cmd_to_check = check_cmd_nopath(paths, cmd, i);
		if (cmd_to_check)
			return (cmd_to_check);
	}
	free_tab(paths);
	free(cmd_to_check);
	ft_dprintf(2, "Command not found: %s\n", cmd);
	return (NULL);
}

char	**parsing(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc < 5)
	{
		ft_dprintf(2, "Wrong args\n");
		return (NULL);
	}
	args = (char **)malloc(sizeof(char *) * argc);
	if (!args)
		return (ft_dprintf(2, "Malloc failed in parsing\n"), NULL);
	i = 0;
	while (++i < argc)
		args[i - 1] = ft_strdup(argv[i]);
	args[i - 1] = NULL;
	return (args);
}
