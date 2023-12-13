# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:13:03 by pehenri2          #+#    #+#              #
#    Updated: 2023/12/13 13:27:23 by pehenri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
BONUS_NAME			= checker
CFLAGS				= -Wextra -Wall -Werror -Wunreachable-code -g3 -fsanitize=address #-Ofast
LIBFT				= ./lib/libft
CC					= cc
HEADERS				= -I ./include -I $(LIBFT)
LIBS				= $(LIBFT)/libft.a
SRCS_PATH			= ./src/mandatory/
FILES				= *.c
OBJS				= $(addprefix $(SRCS_PATH),$(FILES:%.c=%.o))
BONUS_PATH			= ./src/bonus/
BONUS_FILES			= *.c
BONUS_OBJS			= $(addprefix $(BONUS_PATH),$(BONUS_FILES:%.c=%.o))
EXE					?= 	push_swap

all: libft $(NAME)

bonus: libft $(NAME_BONUS)

libft:
	@make -C $(LIBFT) --silent

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) $(HEADERS) -o $(BONUS_NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BONUS_OBJS)
	@make -C $(LIBFT) clean --silent
	@echo "Deleted object files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS_NAME)
	@make -C $(LIBFT) fclean --silent
	@echo "Deleted executable files"

re: fclean all

norm:
	@norminette $(SRCS_PATH) $(BONUS_PATH) $(LIBFT) include

val: all bonus
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind-out.txt \
		 ./$(EXE) $(ARG)

.PHONY: all, clean, fclean, re, norm, val
