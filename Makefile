# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 04:54:56 by mbouzaie          #+#    #+#              #
#    Updated: 2020/05/09 17:54:27 by mbouzaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra -g $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =	-I includes/
LIBFT_H =	-I $(LIB_DIR)

OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIB_DIR =	srcs/libft/

SRC =		ft_printf.c \
			print_va_char.c \
			print_va_nbr.c \
			print_va_str.c \
			print_va_hex.c \
			init_t_flag.c \
			fill_flag_data.c \
			handle_percent.c \
			format_precision_dec.c \
			format_width_dec.c \

CFIND =		$(SRC:%=$(SRC_DIR)%)

OFILE =		$(SRC:%.c=%.o)

OBJ	=		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			@echo Libft objects are here

$(NAME): $(OBJ)
			@make -C $(LIB_DIR)
			@cp $(LIB_DIR)$(LIBFT_A) .
			@mv $(LIBFT_A) $(NAME)
			@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
			@ranlib $(NAME)
			@echo Merged $(NAME) with $(LIBFT_A)
			@echo ft_printf is here

$(OBJ): $(CFIND)
			@$(MAKE) $(OFILE)

$(OFILE):
			@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
			@/bin/rm -rf $(OBJ_DIR)
			@make -C $(LIB_DIR) clean
			@echo object files cleaned

fclean: clean
			@/bin/rm -f $(NAME)
			@make -C $(LIB_DIR) fclean
			@echo cleaned $(NAME) and object files

re: fclean all

.PHONY: all clean fclean re