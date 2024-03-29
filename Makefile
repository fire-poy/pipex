# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <mpons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 22:10:59 by mpons             #+#    #+#              #
#    Updated: 2022/05/23 12:17:19 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

OBJS		= ${SRC:.c=.o}

RM			= rm -f

LIBFT_DIR	= ./libft

SRC 		= ./src/pipex.c\
			  ./src/cmd.c\
			  ./src/process.c\

INC			= -I./inc -I./libft/libft.h 

LIB			= -L ./libft -lft

all: $(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB)

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
		   	$(RM) $(OBJS)

fclean: 
			$(MAKE) -C $(LIBFT_DIR) fclean
		   	$(RM) $(OBJS)
	   		$(RM) $(NAME)

re:			fclean all

.PHONY : all clean fclean re bonus
