# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glecler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 16:00:31 by glecler           #+#    #+#              #
#    Updated: 2019/09/04 17:31:19 by glecler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
SRC 	= ./srcs/ft_printf.c ./srcs/flags_finder.c ./srcs/type_ls_treatment.c \
		  ./srcs/flags_treatment_oxx.c ./srcs/flags_treatment_diu.c \
		  ./srcs/flags_treatment_s.c \
		  ./srcs/utilitaries.c ./srcs/utilitaries_2.c ./srcs/utilitaries_3.c \
		  ./srcs/error_mgmt.c
FLAGS 	= -Wall -Wextra -Werror
CC 		= gcc

OBJ = $(SRC:.c=.o)
	CL=\x1b[35m
	GREEN=\033[1;32m
	RED=\033[1;31m
	CL2=\x1b[36m
	NC=\033[0m

all: $(NAME)

test: all
	@$(CC) $(NAME) test_ft_printf.c -o ft_printf
	@echo "$(GREEN)[✓]$(NC)$(CL) executable ft_printf built$(NC)"
	@$(clean)

$(NAME): $(OBJ)
	@$(CC) -c $(FLAGS) $(SRC)
	@ar rcs $(NAME) $(OBJ)
	@rm -rf *.o 
	@echo "$(GREEN)[✓]$(NC)$(CL) lib $(NAME) built$(NC)"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@rm -rf libftprintf.a
	@rm -rf ft_printf
	@echo "$(RED)[-]$(NC)$(CL2) ft_printf cleaned$(NC)"
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned$(NC)"

re: fclean all

.PHONY: test, all, $(NAME), clean, fclean, re
