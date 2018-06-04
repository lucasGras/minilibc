CC      =       gcc

NASM	=	nasm -f elf64

RM      =       rm -f

NAME	=	asm

all:
	$(NASM) srcs/string/strlen.S
	$(NASM) srcs/stdio/write.S
	$(NASM) srcs/string/memset.S
	$(NASM) srcs/string/strnlen.S
	$(NASM) srcs/string/strcmp.S
	$(NASM) srcs/string/strncmp.S
	$(NASM) srcs/string/strchr.S
	$(NASM) srcs/string/memcpy.S
	$(NASM) srcs/string/memmove.S
	$(NASM) srcs/string/strcasecmp.S
	$(NASM) srcs/string/rindex.S
	$(NASM) srcs/string/strstr.S
	$(NASM) srcs/string/strpbrk.S
	$(NASM) srcs/string/strcspn.S
	$(NASM) srcs/string/memchr.S
	$(NASM) srcs/string/strcat.S
	$(NASM) srcs/stdio/putchar.S
	gcc -g3 -o $(NAME) asm_tester.c srcs/string/*.o srcs/stdio/*.o

clean:
	$(RM) srcs/*.o
	$(RM) srcs/string/*.o
	$(RM) srcs/stdio/*.o

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY:         clean fclean all re
