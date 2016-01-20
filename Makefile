# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/16 14:59:53 by zhasni            #+#    #+#              #
#    Updated: 2015/01/16 14:59:57 by zhasni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 	display1.c \
			 	display2.c \
			 	display3.c \
			 	display4.c \
				draw.c \
				get_next_line.c \
				wolf.c \
				move1.c \
				move2.c \
				init.c \
				block.c \
				misc.c \
				hook.c \
				main.c
NAME		= 	wolf3d
CC			= 	gcc
CFLAGS		= 	-Werror -Wextra -Wall
MLX			=	-L/usr/X11/lib -lmlx -lXext -lX11
AR			= 	ar rc
OBJ			= 	$(SRC:.c=.o)
RM			= 	rm -rf
INCLUDES	=	libft/
OBJ 		=	$(SRC:.c=.o)
LIBFT		=	libft/
HEADERS		=	-I./. -Ilibft/
LIB			=	libft.a

all: $(LIB) $(NAME)
	@echo "\033[0mCrew ready to sail Cap'tain!~~";
$(LIB):
	@echo "\033[0;34mTrying to board libft.a...";
	@make -C $(LIBFT)

$(NAME): $(OBJ)
	@echo "\033[0;31mSte\033[0;32mali\033[0;33mng a \033[0;34mnew\033[0;35m Ship \033[0m...";
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -L libft/ -lft
	@echo "\033[0;32mShip stolen.";

%.o: %.c
	@echo "\033[0;35mLooting $<";
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@ $(MLX) -L libft/ -lft

clean:
	@echo "\033[0;36mCleaning Rhum from Cargo...";
	@make clean -C $(LIBFT)
	@$(RM) $(OBJ)
	@echo "\033[0;36mFound some fine bottles!";
fclean: clean
	@echo "\033[1;33mCleaning Gold Pieces from rich spoiled daddy's girl...";
	@make fclean -C $(LIBFT)
	@$(RM) $(NAME)
	@echo "Swimming in gold...";
re: fclean all

.PHONY: all clean fclean re

