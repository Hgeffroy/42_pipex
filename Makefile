# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 12:02:28 by hgeffroy          #+#    #+#              #
#    Updated: 2023/07/15 09:12:00 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = pipex
FLAGS = -Wall -Wextra -Werror -I header -MMD -MP
CC = cc
RM = rm -f
OBJ_DIR = obj/
SRC_DIR = src/
LIBFT_DIR = libprintf/
LIBFT = $(LIBFT_DIR)libftprintf.a
HEADER = header/pipex.h
DEBUG = no
DFLAGS = -g3 -fsanitize=address

ifeq ($(DEBUG), yes)
	FLAGS += $(DFLAGS)
endif

#Files

SRC_F = exec.c \
		utils.c \
		free.c \
		parsing.c \
		parsing_utils.c \
		main.c \
		
OBJ = $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

DEPS = $(OBJ:.o=.d)

#Rules

all :	lib 
		make $(NAME)

-include $(DEPS)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(LIBFT) $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I .

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@

lib :
	make -C $(LIBFT_DIR)

debug :
	make re DEBUG=yes

clean :
	$(RM) -r $(OBJ_DIR) libft.a
	make fclean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)

re :	fclean 
		make all

.PHONY : re lib debug fclean clean all