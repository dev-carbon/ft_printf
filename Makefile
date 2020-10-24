# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/25 15:35:56 by humanfou          #+#    #+#              #
#    Updated: 2020/10/06 14:07:17 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H = 	-I srcs/libft/

OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIB_DIR =	srcs/libft/

CFILE =		ft_printf.c \
                get_flags.c \
                get_length.c \
                get_precision.c \
                get_type.c \
                get_width.c \
                parse.c \
                print.c \
                print_c.c \
                print_s.c \
                print_o.c \
                print_p.c \
                print_d.c \
                print_u.c \
                print_x.c \
                print_percent.c \
                print_undefined.c \
                print_sign.c \
                print_preffix.c \
                print_padding.c \
                print_not_blank.c

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

bonus: all

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
		@echo LIBFT STARTED
		@make -C $(LIB_DIR)
		@echo MERGING: $(NAME) WITH $(LIBFT_A)
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@echo $(NAME) CREATED

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned ft_printf object files.

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re
