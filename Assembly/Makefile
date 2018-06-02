CC      =       gcc

NASM	=	nasm -f elf64

RM      =       rm -f

NAME	=	asm

all:
	$(NASM) srcs/strlen.S
	$(NASM) srcs/write.S
	$(NASM) srcs/memset.S
	$(NASM) srcs/strnlen.S
	$(NASM) srcs/strcmp.S
	$(NASM) srcs/strncmp.S
	$(NASM) srcs/strchr.S
	$(NASM)	srcs/memcpy.S
	gcc -g3 -o $(NAME) asm_tester.c srcs/*.o

clean:
	$(RM) srcs/*.o

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY:         clean fclean all re
