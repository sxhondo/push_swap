# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 20:02:38 by sxhondo           #+#    #+#              #
#    Updated: 2019/11/02 15:38:25 by sxhondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH = checker
PS = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs/
LIB = libft.a
LIB_DIR = libft/
LIB_INC = $(LIB_DIR)/incs
LIB_FT = $(LIB_DIR)$(LIB)

INC_DIR = ./
INC = push_swap.h

CH_SRCS=\
	validation.c\
	read_parse_instructions.c\
	validation_utilities.c\
	apply_instruction.c\
	instructions.c\
	ps_utilities1.c\
	ps_utilities2.c\
	graphical_utilities.c\
	verbose.c\
	main_checker.c

PS_SRCS=\
	push_swap.c\
	validation.c\
	apply_instruction.c\
	read_parse_instructions.c\
	validation_utilities.c\
	small_sort.c\
	find_med_value.c\
	ps_utilities1.c\
	ps_utilities2.c\
	instructions.c\
	graphical_utilities.c\
	verbose.c\
	main_push_swap.c


CH_OBJ = $(CH_SRCS:%.c=%.o)
PS_OBJ = $(PS_SRCS:%.c=%.o)

all: $(LIB) $(CH) $(PS)

$(PS): $(PS_OBJ) $(LIB_FT)
	$(CC) $(CFLAGS) $(PS_OBJ) -L $(LIB_DIR) -lft -o $(PS)

$(CH): $(CH_OBJ) $(LIB_FT)
	$(CC) $(CFLAGS) $(CH_OBJ) -L $(LIB_DIR) -lft -o $(CH)

%.o: $(SRCS_DIR)%.c $(INC)
	$(CC) -c $(CFLAGS) -I $(LIB_INC) -I $(INC_DIR) $<

$(LIB): $(LIB_DIR)
	make -C $(LIB_DIR)

clean:
	@rm -f $(CH_OBJ)
	@rm -f $(PS_OBJ)
	@make clean -C $(LIB_DIR)

fclean: clean
	@rm -f $(CH)
	@rm -f $(PS)
	@make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re
