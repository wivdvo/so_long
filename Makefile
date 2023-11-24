# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 16:52:48 by wvan-der          #+#    #+#              #
#    Updated: 2023/11/13 17:46:41 by wvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		so_long

SRCS =		srcs/check_border.c \
			srcs/check_map.c \
			srcs/check_path.c \
			srcs/ft_split.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/handle_input.c \
			srcs/init_img.c \
			srcs/init_obj.c \
			srcs/render.c \
			srcs/render_map.c \
			srcs/render_map_obj.c \
			srcs/so_long.c \
			srcs/so_long_utils.c

OBJS = 		$(SRCS:.c=.o)

CC =		cc
CFLAGS = 	-Wall -Werror -Wextra
LIBFLAGS =	-lmlx -lXext -lX11
PRINTF =	ft_printf/libftprintf.a

all:		$(NAME)

$(PRINTF):
				make -C ft_printf

$(NAME):	$(OBJS) $(PRINTF)
				$(CC) $(OBJS) $(CFLAGS) $(LIBFLAGS) $(PRINTF) -o so_long

clean:
				make clean -C ft_printf
				$(RM) $(OBJS)

fclean:		clean
				make fclean -C ft_printf
				$(RM) $(NAME)

re:			fclean all
				