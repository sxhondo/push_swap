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
INC = push_swap.h

CH_SRCS=\
	apply_instruction.c\
	instructions.c\
	ps_utilities1.c\
	ps_utilities2.c\
	graphical_utilities.c\
	validation.c\
	checker.c\
	validation_utilities.c\
	main_checker.c


PS_SRCS=\
	push_swap.c\
	ps_utilities1.c\
	ps_utilities2.c\
	small_sort.c\
	find_med_value.c\
	instructions.c\
	validation_utilities.c\
	validation.c\
	graphical_utilities.c\
	main_push_swap.c

all: $(PS) $(CH)

$(CH): $(INC) $(CH_SRCS)
	$(CC) $(CFLAGS) $(CH_SRCS) -L $(LIB_DIR) -lft -I $(LIB_INC) -o $(CH)

$(PS): $(INC) $(PS_SRCS)
	$(CC) $(CFLAGS) $(PS_SRCS) -L $(LIB_DIR) -lft -I $(LIB_INC) -o $(PS)
