# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 12:02:18 by hgeffroy          #+#    #+#              #
#    Updated: 2023/06/19 09:02:20 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = libft.a
HEADER = header/
FLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
AR = ar rcs
CC = cc
RM = rm -f
OBJ_DIR = ./obj/

#Files

SRC_F = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isstrdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

SRC_B_F = ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \

OBJ_B = $(addprefix $(OBJ_DIR), $(SRC_B_F:.c=.o))

#Rules

all : $(NAME)

$(OBJ_DIR)%.o : %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJ_DIR) $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus : $(OBJ_DIR) $(OBJ) $(OBJ_B)
	$(AR) $(NAME) $(OBJ) $(OBJ_B)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	$(RM) -r $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean 
	make all

.PHONY : re fclean clean all