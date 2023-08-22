/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:24:20 by hgeffroy          #+#    #+#             */
/*   Updated: 2023/06/19 09:42:25 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/header/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_dprintf(int fd, const char *str, ...);
int		printf_putchar(int c, int fd);
int		printf_putstr(const char *str, int fd);
int		printf_putnbr(int nb, int fd);
int		printf_address(unsigned long long ptr, int fd);
int		printf_puthexanbr(unsigned long long n, int up, int fd);
int		printf_putunbr(unsigned long long n, int fd);
int		lenunbr(unsigned long long nb, int basesize);

#endif