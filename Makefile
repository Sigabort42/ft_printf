#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/10 17:33:59 by elbenkri          #+#    #+#              #
#    Updated: 2017/12/21 15:29:09 by elbenkri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a

NAME_TMP =	tmplibftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	ft_printf.h

SRCS	=	ft_is_number.c \
			ft_itoa_base.c \
			ft_stock_flags.c \
			ft_type.c \
			ft_printf.c \
			ft_stock_ap.c \
			ft_lltoa.c \
			ft_print_buffer.c \
			ft_flags.c \

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

	ar rc $(NAME_TMP) $(OBJS)
	make -C	libft/
	libtool -static -o $(NAME) $(NAME_TMP) libft/libft.a
	ranlib $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJS)
	rm -rf $(NAME_TMP)

fclean:	clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all