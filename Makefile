#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin  <jgeslin@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 12:36:55 by jgeslin           #+#    #+#              #
#    Updated: 2016/05/20 11:49:11 by gvilmont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = sources/ft_drawline.c sources/ft_putintab.c sources/ft_read_txt.c\
	  sources/main.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBS = sources/libft.a

GNL = libft/sources/get_next_line.c

FLAGMLX = -lmlx -framework Opengl -framework AppKit

all: $(NAME)

$(NAME):$(OBJ)
			gcc $(FLAG) -o $(NAME) $(FLAGMLX) $(GNL) $(SRC) $(LIBS) -I.

clean:
			/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re:fclean all	

.PHONY: clean fclean re all
