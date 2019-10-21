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

CH = checker
PS = push_swap

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g

LIB_DIR = libft
LIB_INC = libft/incs

CH_SRCS=\
	validate_arguments.c\
	apply_instruction.c\
	checker.c\
	instructions.c\
	utilities.c

PS_SRCS=\
	push_swap_qs.c\
	instructions.c\
	validate_arguments.c\
	apply_instruction.c\
	utilities.c\
	checker.c\
	main.c

all: $(PS)

$(CH): $(CH_SRCS)
	$(CC) $(CFLAGS) $(CH_SRCS) -L $(LIB_DIR) -lft -I $(LIB_INC) -o $(CH)

$(PS): $(PS_SRCS)
	$(CC) $(CFLAGS) $(PS_SRCS) -L $(LIB_DIR) -lft -I $(LIB_INC) -o $(PS)
