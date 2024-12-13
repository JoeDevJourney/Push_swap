# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrandt <jbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 13:20:35 by jbrandt           #+#    #+#              #
#    Updated: 2024/12/09 12:03:00 by jbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c srcs
vpath %.c operations
vpath %.c libft

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./include
FLAGS = -O3 -g3 -L -lft

LIBFT = ./libft
LIBS = /include

RM = rm -f
FILES = push_swap.c push.c reverse_rotate.c rotate_both.c rotate.c \
sort_stacks.c sort_three.c swap.c error_handling.c init_a_to_b.c \
init_b_to_a.c init_stack.c split.c stack_utils.c

OBJ_DIR = build

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I.$(LIBS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ_DIR)/*.o

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all