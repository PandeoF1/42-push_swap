# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnard <tnard@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 12:16:46 by tnard             #+#    #+#              #
#    Updated: 2021/11/12 16:16:21 by tnard            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c utils/ft_putchar.c utils/ft_putnbr_base.c utils/ft_putnbr.c utils/ft_putstr.c utils/ft_putmemory.c

#LIBFT = ./libft/libft.a	

INCLUDES = #-Ift_print.h

NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

ECHO = echo "`expr " [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)utils
	$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "\n\033[0;32mlibftprintf.a compiled !\033[0m\n"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
#	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus