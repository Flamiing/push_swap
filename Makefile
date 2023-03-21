# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 20:45:55 by alaaouam          #+#    #+#              #
#    Updated: 2023/03/03 12:09:34 by alaaouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	COLOURS	#

GREEN = \033[0:32m
COLOR_OFF = \033[0m

#	VARIABLES	#

NAME = push_swap

SRC = push_swap.c push_swap_utils.c stack.c stack_utils.c \
				parser.c parser_utils.c free_utils.c ft_sort_stack.c \
				push.c reverse_rotate.c rotate.c swap.c sort_types.c \
				sort_utils.c utils.c ft_smallest_closer.c find_utils.c \
				ft_max_or_min_int.c

SRC_PATH = src/*/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
INCLUDE = include/


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include -I ./libft/include
RM = rm -rf

#	RULES	#

all: $(NAME)

$(LIBFT): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(LIBFT)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)<+> push_swap has been created! <+>$(COLOR_OFF)"

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) 
	@echo "$(GREEN)<-> push_swap cleaned successfuly! <->$(COLOR_OFF)"

re: fclean all

.PHONY: all clean fclean re