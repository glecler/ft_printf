# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glecler <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 16:00:31 by glecler           #+#    #+#              #
#    Updated: 2019/09/02 18:57:02 by glecler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= ft_printf
SRC 	= ./srcs/ft_printf.c ./srcs/flags_finder.c ./srcs/type_ls_treatment.c \
		  ./srcs/flags_treatment_oxx.c ./srcs/flags_treatment_diu.c \
		  ./srcs/utilitaries.c ./srcs/utilitaries_2.c ./srcs/test_ft_printf.c \
		  ./srcs/flags_treatment_s.c

FLAGS 	= -Wall -Wextra -Werror
CC 		= gcc

OBJ = $(SRC:.c=.o)
	CL=\x1b[35m
	GREEN=\033[1;32m
	RED=\033[1;31m
	CL2=\x1b[36m
	NC=\033[0m

all: $(NAME)

%.o: %.c
	@$(CC) -c $< -o $@ $(FLAGS)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)[✓]$(NC)$(CL) executable $(NAME) built$(NC)"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@rm -rf ft_printf
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned$(NC)"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
