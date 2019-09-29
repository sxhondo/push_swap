# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 20:02:38 by sxhondo           #+#    #+#              #
#    Updated: 2019/09/26 20:02:39 by sxhondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g

LIB_DIR = libft
LIB_INC = libft/incs

SRCS_LIST=\
	validate_arguments.c\
	validate_instructions.c\
	apply_instruction.c\
	utilities.c\
	main.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS_LIST) -L $(LIB_DIR) -lft -I $(LIB_INC)