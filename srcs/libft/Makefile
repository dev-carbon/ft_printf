# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 17:49:24 by humanfou          #+#    #+#              #
#    Updated: 2020/10/01 21:04:47 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_charlen.c \
	ft_nbrlen.c \
	ft_isalpha.c \
	ft_islower.c \
	ft_isupper.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strndup.c \
    ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strrev.c \
	ft_strnew.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_strmapi.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putnbrmax_fd.c \
	ft_putnbrumax_fd.c

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rc $(NAME) $^
	ranlib $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@echo $(NAME) CREATED.

clean:
	@/bin/rm -rf $(OBJ) $(OBJ_BONUS)
	@echo Cleaned libft object files.

fclean: clean
	@/bin/rm -f $(NAME)
	@echo $(NAME) Removed.


re: fclean all

.PHONY = all bonus clean fclean re
	
