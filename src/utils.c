/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:58:35 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/17 23:56:36 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

int	tab_len(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_whitespace(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ' || (cmd[i] > 8 && cmd[i] < 14))
		i++;
	if (i == (int)ft_strlen(cmd))
		return (1);
	else
		return (-1);
}

void	set_fd(int *fd)
{
	int	i;

	i = -1;
	while (++i < 4)
		fd[i] = 0;
	return ;
}

int	set_dup(int *fd)
{
	if (fd[0] > 0)
	{
		if (dup2(fd[0], STDIN_FILENO) < 0)
			return (close_all(fd), -1);
	}
	if (fd[3] > 0)
	{
		if (dup2(fd[3], STDOUT_FILENO) < 0)
			return (close_all(fd), -1);
	}
	close_all(fd);
	return (0);
}
