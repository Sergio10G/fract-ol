# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 17:51:37 by sdiez-ga          #+#    #+#              #
#    Updated: 2022/02/22 19:10:18 by sdiez-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

SRCS			=	src/fractol.c					\
					src/errors.c					\
					src/img_funcs.c					\
					src/input_parse.c				\
					src/color_funcs.c				\
					src/init_structs.c				\
					src/utils.c						\
					src/algorithm.c

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra

MLXFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

MAKEFLAGS		+=	--silent

GREEN		=	\033[1;32m
PINK		=	\033[1;35m
BLUE		=	\033[1;36m
RESET		=	\033[1;0m

%.o				:	%.c
					$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)			:	$(OBJS)
					echo "$(BLUE)Compiling...$(RESET)"
					make -C minilibx/ --silent
					echo "$(PINK)minilibX compiled!$(RESET)"
					$(CC) $(OBJS) $(MLXFLAGS) libft/libft.a -o $(NAME)
					echo "$(GREEN)fract-ol compiled!$(RESET)"

all				:	$(NAME)

clean			:
					rm -f $(OBJS)
					echo "$(BLUE)fract-ol objs cleaned!$(RESET)"

fclean			:	clean
					make -C minilibx/ clean --silent
					echo "$(BLUE)minilibX objs cleaned!$(RESET)"
					rm -f $(NAME)
					echo "$(BLUE)fract-ol removed!$(RESET)"

re				:	fclean all

.PHONY			:	all clean fclean re
