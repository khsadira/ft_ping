# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khsadira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 17:56:43 by khsadira          #+#    #+#              #
#    Updated: 2019/02/16 10:41:41 by khsadira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

CPPFLAGS	= 	-I includes

SRC_PATH	=	./srcs

OBJ_PATH	=	./objs

SRC_FILES	=		ft_memccpy.c\
					ft_putnbr.c\
					ft_strequ.c\
					ft_strnequ.c\
					ft_str_countword.c\
					ft_memchr.c\
					ft_putnbr_fd.c\
					ft_striter.c\
					ft_strnew.c\
					ft_strtrim_char.c\
					ft_atoi.c\
					ft_memcmp.c\
					ft_putstr.c\
					ft_striteri.c\
					ft_strnstr.c\
					ft_bzero.c\
					ft_memcpy.c\
					ft_putstr_fd.c\
					ft_strjoin.c\
					ft_strrchr.c\
					ft_isalnum.c\
					ft_memdel.c\
					ft_strcat.c\
					ft_strlcat.c\
					ft_strsplit.c\
					ft_isalpha.c\
					ft_memmove.c\
					ft_strchr.c\
					ft_strlen.c\
					ft_strstr.c\
					ft_isascii.c\
					ft_memset.c\
					ft_strclr.c\
					ft_strmap.c\
					ft_strsub.c\
					ft_isdigit.c\
					ft_putchar.c\
					ft_strcmp.c\
					ft_strmapi.c\
					ft_strtrim.c\
					ft_isprint.c\
					ft_putchar_fd.c\
					ft_strcpy.c\
					ft_strncat.c\
					ft_tolower.c\
					ft_itoa.c\
					ft_putendl.c\
					ft_strdel.c\
					ft_strncmp.c\
					ft_toupper.c\
					ft_memalloc.c\
					ft_putendl_fd.c\
					ft_strdup.c\
					ft_strncpy.c\
					ft_lstnew.c\
					ft_lstdelone.c\
					ft_lstdel.c\
					ft_lstadd.c\
					ft_lstiter.c\
					ft_lstmap.c\
					ft_abs.c\
					ft_swap.c\
					ft_sort_integer_table.c\
					ft_isspace.c\
					ft_isnum.c\
					ft_isupper.c\
					ft_islower.c\
					ft_strcapitalize.c\
					ft_strupcase.c\
					ft_strlowcase.c\
					ft_isnum.c\
					ft_strrev.c\
					ft_is_prime.c\
					ft_find_next_prime.c

OBJ_FILES	=	$(SRC_FILES:.c=.o)

SRCS		=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJS		=	$(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

RM			= 	rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_PATH) :
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(dir $(OBJS))

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
