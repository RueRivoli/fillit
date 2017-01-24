# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 12:41:58 by cchameyr          #+#    #+#              #
#    Updated: 2017/01/24 13:41:49 by cchameyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			fillit

FILES =			main.c \
				get_next_line.c \
				get_tetriminos.c \
				display_list.c \
				check_tetriminos.c \
				square.c

SRCS =			$(addprefix srcs/, $(FILES))

OBJS =			$(addprefix objs/, $(FILES:.c=.o))

DEBUG = 		-fsanitize=address

FLAGS =			-Wall -Werror -Wextra $(DEBUG)

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
