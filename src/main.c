/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:51:25 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/17 23:56:21 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	int		nb_cmd;
	int		nb_fork;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	data->env = env;
	data->args = parsing(argc, argv);
	if (!(data->args))
		return (perror("parsing"), free(data), -1);
	set_fd(data->fd);
	nb_cmd = tab_len(data->args) - 2;
	data->pid = (int *)malloc(sizeof(int) * nb_cmd);
	if (!(data->pid))
		return (perror("pid"), free(data->args), free(data), -1);
	nb_fork = exec_forks(data, nb_cmd);
	close_all(data->fd);
	while (nb_fork--)
		waitpid(-1, 0, 0);
	return (free(data->pid), free_tab(data->args), free(data), 0);
}
