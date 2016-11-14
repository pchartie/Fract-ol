NAME = fractol

SRC = ./fractal.c \
	./init_struct.c \
	./draw.c \
	./event.c \
	./main.c \

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

INC = -I./libft/

CC = gcc -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	make -C minilibx_macos/
	$(CC) -o $(NAME) $(OBJS) $(LIB)

%.o: %.c
	$(CC) -Wall -Wextra -c $< $(INC)

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all
