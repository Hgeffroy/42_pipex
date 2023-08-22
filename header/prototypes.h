/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:20:11 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/07/17 23:04:02 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "pipex.h"
# include "struct.h"

// Parsing
char	**parsing(int argc, char **argv);
char	*check_cmd(char **env, char *cmd, int shouldfork);
char	**get_path(char **env);
char	**gen_argsexec(char *cmdwpath, char **args);
int		is_directory(char *cmd);
int		is_cmdwpath(char *cmd);

// Utils
int		tab_len(char **str);
void	free_tab(char **tab);
void	close_all(int *fd);
int		is_whitespace(char *cmd);
void	set_fd(int *fd);
void	close_inpipe(int *fd);
void	exit_child(char *cmdwpath, int *fd);
int		set_dup(int *fd);

// Exec
// int		exec_forks(char **args, char **env, int *fd, int nb_cmd);
int		exec_forks(t_data *data, int nb_cmd);

// A DELETE
void	print_tab(char **tab);
void	print_tabint(int *tab, int n);

#endif
