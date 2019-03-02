# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 05:04:27 by hmuravch          #+#    #+#              #
#    Updated: 2018/08/20 04:27:44 by hmuravch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NOC = \x1b[0m
OKC = \x1b[32m
ERC = \x1b[31m

HEADER = -I ./includes

FLAGS = -Wall -Werror -Wextra

SRC =	ft_atoi.c ft_isdigit.c ft_strcat.c ft_strdup.c ft_strncpy.c ft_isalnum.c \
		ft_isprint.c ft_strchr.c ft_strlen.c ft_strnstr.c ft_isalpha.c ft_strcmp.c \
		ft_strncat.c ft_strrchr.c ft_isascii.c ft_strcpy.c ft_strncmp.c ft_strstr.c \
		ft_toupper.c ft_tolower.c ft_itoa.c ft_putendl.c ft_putstr.c ft_strequ.c \
		ft_strmap.c ft_strsplit.c ft_putendl_fd.c ft_putstr_fd.c ft_striter.c \
		ft_strmapi.c ft_strsub.c ft_putchar.c ft_putnbr.c ft_strclr.c ft_striteri.c \
		ft_strnequ.c ft_strtrim.c ft_putchar_fd.c ft_putnbr_fd.c ft_strdel.c ft_strjoin.c \
		ft_strnew.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		ft_memalloc.c ft_memdel.c ft_bzero.c ft_memcmp.c ft_strlcat.c ft_lstnew.c \
		ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstdel.c ft_fill_word.c \
		ft_num_of_words.c ft_range.c ft_swap.c ft_sqrt.c ft_realloc.c ft_printf.c \
		ft_itoa_base.c ft_strjoin_free.c ft_strlen_int.c my_caster.c my_putchar_unicode.c \
		my_missing_options.c print_flags_for_i.c print_flags_for_x.c print_flags_for_u.c \
		print_flags_for_o.c print_flags_for_cap_s.c print_s_o.c print_d_c_p.c \
		print_percent_u_x.c get_next_line.c ft_is_whitespace.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo "$(OKC)Lib is ready$(NOC)"

%.o: %.c 
	@gcc $(FLAGS) -c $< -o $@ $(HEADER)

clean:
	@rm -f $(OBJ)
	@echo "$(ERC)Objects were deleted$(NOC)"	
fclean: clean
	@rm -f $(NAME)
	@echo "$(ERC)Lib was deleted$(NOC)"

re: fclean all	
