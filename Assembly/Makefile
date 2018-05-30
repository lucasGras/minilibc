NAME	=	nasm.so

SRC	=	srcs/strlen.S

OBJ	=	$(SRC:.S=.o)

all:	$(NAME)

%.o: %.S
	nasm -o $@ $< -f elf64

$(NAME): $(OBJ)
	gcc -shared -static-libgcc -nostdlib -fno-builtin -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re