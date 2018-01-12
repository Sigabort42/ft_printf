#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elbenkri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/10 17:33:59 by elbenkri          #+#    #+#              #
#    Updated: 2018/01/11 18:27:20 by elbenkri         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a

NAME_TMP =	tmplibftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

HEADER	=	ft_printf.h

SRCS	=	ft_is_number.c \
			ft_itoa_base.c \
			ft_itoa_base_maj.c \
			ft_ltoa_base.c \
			ft_ltoa_base_maj.c \
			ft_lltoa_base.c \
			ft_lltoa_base_maj.c \
			ft_i_maxtoa_base.c \
			ft_i_maxtoa_base_maj.c \
			ft_ui_maxtoa_base.c \
			ft_ui_maxtoa_base_maj.c \
			ft_stock_flags.c \
			ft_type.c \
			ft_printf.c \
			ft_ltoa.c \
			ft_lltoa.c \
			ft_i_maxtoa.c \
			ft_ui_maxtoa.c \
			ft_print_buffer.c \
			ft_flags.c \
			ft_print_flags_buffer.c \
			ft_flags_stock.c \
			ft_wchar.c \
			ft_wstrlen.c \
			ft_conv_envoi_maj.c \
			ft_conv_envoi.c \
			ft_flags_largeur.c \
			ft_stock_buf_base.c \
			ft_stock_moins.c \
			ft_stock_plus.c \
			ft_flags_stock2.c \
			ft_verif_buf.c \

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME_TMP) $(OBJS)
	@make -C	libft/
	@libtool -static -o $(NAME) $(NAME_TMP) libft/libft.a
	@ranlib $(NAME)
	@rm -rf $(NAME_TMP)
	@echo "\033[H\033[2J\033[32;5m[OK...]"

clean:
	@make -C libft/ clean
	rm -rf $(OBJS)
	rm -rf $(NAME_TMP)
	@echo "\033[H\033[2J\033[32;5m[OK...]"

fclean:	clean
	@make -C libft/ fclean
	rm -rf $(NAME)
	@echo "\033[H\033[2J\033[32;5m[OK...]"

re: fclean all