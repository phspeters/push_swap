# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:13:03 by pehenri2          #+#    #+#              #
#    Updated: 2024/02/01 18:21:52 by pehenri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap
BONUS_NAME			= checker
#CFLAGS				= -Wextra -Wall -Werror -Wunreachable-code -fsanitize=address #-Ofast
CFLAGS				= -Wextra -Wall -Werror -Wunreachable-code -g3 #-Ofast
LIBFT				= ./lib/libft
CC					= cc
HEADERS				= -I ./include -I $(LIBFT)
LIBS				= $(LIBFT)/libft.a
SRCS_PATH			= ./src/mandatory/
FILES				= main.c parsing.c utils.c push.c sort.c lis.c cost.c move.c swap.c rotate.c reverse_rotate.c
OBJS				= $(addprefix $(SRCS_PATH),$(FILES:%.c=%.o))
BONUS_PATH			= ./src/bonus/
BONUS_FILES			= main.c parsing.c instructions.c utils.c push.c reverse_rotate.c rotate.c swap.c
BONUS_OBJS			= $(addprefix $(BONUS_PATH),$(BONUS_FILES:%.c=%.o))
EXE					?= 	push_swap

all: $(NAME)

bonus: $(BONUS_NAME)

libft:
	@make -C $(LIBFT) --silent

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"

$(NAME): libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(BONUS_NAME): libft $(BONUS_OBJS)
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

test3: $(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 3))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test5: $(NAME)	
		$(eval ARG = $(shell shuf -i 0-50 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test100: $(NAME)	
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

test500: $(NAME)	
		$(eval ARG = $(shell shuf -i 0-2000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

.PHONY: all, clean, fclean, re, norm, val, test3, test5, test100, test500
