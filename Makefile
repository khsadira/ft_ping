NAME		=		ft_ping


CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra


INC			=		-I includes/

LLIBFT		=		libft/libft.a


SRC_PATH	=		./srcs

SRC_FILES	=		main.c\
					ft_ping.c\
					manage_flag.c


OBJ_PATH	=		./objs

OBJ_FILES	=		$(SRC_FILES:.c=.o)


SRCS		=		$(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJS		=		$(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

all: $(OBJS) | $(OBJ_PATH)
	make -C libft
	$(CC) $(INC) -o $(NAME) $(OBJS) $(LLIBFT)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(INC) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $@
	mkdir -p $(dir $(OBJS))

clean:
	make clean -C libft
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean flean re