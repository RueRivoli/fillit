# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 12:41:58 by cchameyr          #+#    #+#              #
#    Updated: 2017/02/15 13:23:05 by fgallois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fillit

FILES =			main.c \
				get_next_line.c \
				get_tetriminos.c \
				display.c \
				check_tetriminos.c \
				check_valid_char.c \
				square.c \
				match.c \
				recursive.c \
				fill.c

SRCS =			$(addprefix srcs/, $(FILES))

OBJS =			$(addprefix objs/, $(FILES:.c=.o))

DEBUG = 		-fsanitize=address

FLAGS =			-Wall -Werror -Wextra #$(DEBUG)

RM =			rm -rf

CC =			gcc

LIBFT =			libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)
	@make objs_mv

objs_mv:
	@mkdir objs
	@mv $(FILES:.c=.o) ./objs

objs_rm:
	@$(RM) objs
	@$(RM) $(FILES:.c=.o)

$(LIBFT):
	make -C ./libft

clean: objs_rm
	make clean -C ./libft

fclean: clean
	$(RM) $(LIBFT) $(NAME)

re: fclean all

r: objs_rm
	$(RM) $(NAME)
	@make
