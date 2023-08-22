# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 12:02:28 by hgeffroy          #+#    #+#              #
#    Updated: 2023/06/16 08:41:55 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
AR = ar rcs
CC = cc
RM = rm -f
OBJ_DIR = obj/
SRC_DIR = src/
LIBFT_DIR = libft/
LIBFT = libft.a
HEADER = $(SRC_DIR)ft_printf.h

#Files

SRC_F = ft_printf.c\
		ft_printf_nb.c\
		ft_printf_unb.c\
		ft_printf_char.c\
		
OBJ = $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

#Rules

all : lib 
	make $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(LIBFT_DIR)$(LIBFT) $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@ -I $(SRC_DIR)

$(NAME) : $(OBJ_DIR) $(OBJ)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

lib :
	make -C $(LIBFT_DIR)

clean :
	$(RM) -r $(OBJ_DIR) libft.a
	make fclean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean 
	make all

.PHONY : re fclean clean all