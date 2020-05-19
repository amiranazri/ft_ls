# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anazri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 08:05:30 by anazri            #+#    #+#              #
#    Updated: 2019/06/14 14:55:26 by anazri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h

ERRORS = -Wall -Werror -Wextra

CMP = -c -I $(HEADER)

SRC = ft_putendl_fd.c ft_strncat.c ft_putnbr.c ft_strncmp.c ft_atoi.c\
	  ft_putnbr_fd.c ft_strncpy.c ft_bzero.c ft_putstr.c ft_strndup.c\
	  ft_isalnum.c ft_putstr_fd.c ft_strnequ.c ft_isalpha.c ft_strcat.c\
	  ft_strnew.c ft_isascii.c ft_strchr.c ft_strnstr.c ft_isdigit.c\
	  ft_strclr.c ft_strrchr.c ft_isprint.c ft_strcmp.c ft_strsplit.c ft_itoa.c\
	  ft_strcpy.c ft_strstr.c ft_memalloc.c ft_strdel.c ft_strsub.c ft_memccpy.c\
	  ft_strdup.c ft_strtrim.c ft_memchr.c ft_strequ.c ft_strupcase.c ft_memcmp.c\
	  ft_striter.c ft_token_count.c ft_memcpy.c ft_striteri.c ft_tolower.c\
	  ft_memdel.c ft_strjoin.c ft_toupper.c ft_memmove.c ft_strlcat.c ft_memset.c\
	  ft_strlen.c ft_putchar.c ft_strlowcase.c ft_putchar_fd.c ft_strmap.c\
	  ft_putendl.c ft_strmapi.c ft_is_space.c ft_swap.c

OBC =  $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(ERRORS) $(CMP) $(SRC)
	@ar rcs $(NAME) $(OBC)

clean:
	@rm -f $(OBC)

fclean: clean
	@rm -f $(NAME)

re: fclean all
