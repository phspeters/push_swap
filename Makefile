# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pehenri2 <pehenri2@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 12:13:03 by pehenri2          #+#    #+#              #
#    Updated: 2024/02/08 15:09:31 by pehenri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap
CHECKER				=	checker
STACK				=	stack.a
CC					=	cc
CFLAGS				=	-Wextra -Wall -Werror -Wunreachable-code -g3
HEADERS				= 	-I ./include -I $(LIBFT_PATH)
LIBFT				= 	$(addprefix $(LIBFT_PATH), libft.a)
LIBFT_PATH			= 	./lib/libft/
LIBS_PATH			= 	./lib/
LIBS				= 	$(STACK_LIB) $(LIBFT)
SRCS_PATH			= 	./src/push_swap/
FILES				= 	$(addprefix $(SRCS_PATH), main.c sort.c lis.c lis_operations.c cost.c move.c)
OBJS				= 	$(FILES:%.c=%.o)
STACK_LIB			= 	$(addprefix $(LIBS_PATH),$(STACK))
STACK_PATH			=	./src/stack/
STACK_FILES			= 	$(addprefix $(STACK_PATH), parsing.c push.c reverse_rotate.c rotate.c stack.c swap.c utils.c)
STACK_OBJS			= 	$(STACK_FILES:%.c=%.o)
CHECKER_PATH		= 	./src/checker/
CHECKER_FILES		= 	$(addprefix $(CHECKER_PATH), main.c)
CHECKER_OBJS		= 	$(CHECKER_FILES:%.c=%.o)
EXE					?=	push_swap

.DEFAULT_GOAL = $(NAME)

all: $(STACK) $(NAME) $(CHECKER)

bonus: $(STACK) $(CHECKER)

$(NAME): $(STACK) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -o $(NAME)

$(CHECKER): $(STACK) $(CHECKER_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(HEADERS) $(LIBS) -o $(CHECKER)

$(STACK): libft $(STACK_OBJS)

$(STACK_PATH)%.o: $(STACK_PATH)%.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<\n)"
	@ar rcs $(STACK_LIB) $(LIBFT) $@

libft:
	@make -C $(LIBFT_PATH) --silent

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<\n)"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(CHECKER_OBJS)
	@rm -rf $(STACK_OBJS)
	@make -C $(LIBFT_PATH) clean --silent
	@echo "Deleted object files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(CHECKER)
	@rm -rf $(STACK_LIB)
	@make -C $(LIBFT_PATH) fclean --silent
	@echo "Deleted executable files and static libraries"

re: fclean all

norm:
	@norminette $(SRCS_PATH) $(CHECKER_PATH) $(STACK_PATH) $(LIBFT_PATH) include

val: all
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