/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 07:11:57 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/14 08:40:02 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_child(char *cmdwpath, int *fd)
{
	free(fd);
	free(cmdwpath);
	exit (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	close_all(int *fd)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (fd[i] > 0)
			close (fd[i]);
	}
	return ;
}

void	close_inpipe(int *fd)
{
	if (fd[0] > 0)
		close (fd[0]);
	if (fd[1] > 0)
		close (fd[1]);
}
