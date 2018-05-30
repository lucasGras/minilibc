CC      =       gcc

NASM	=	nasm -f elf64

RM      =       rm -f

NAME	=	asm

all:
	$(NASM) srcs/strlen.S
	gcc -o $(NAME) asm_tester.c srcs/*.o

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY:         clean fclean all re