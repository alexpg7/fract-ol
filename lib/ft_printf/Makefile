NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
OPTION = -c -I
INCLUDE = libftprintf.h
SRC = ft_printf.c ft_printtype.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

# $< significa copiar el primero de los requisitos en el comando (ej. en %.o)
# $? copia TODOS los requisitos
# $@ copia el nombre de la regla

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
%.o: %.c $(INCLUDE)
	cc $(FLAG) -MMD -c $< -o $@
-include $(DEP)
clean:
	/bin/rm -f $(OBJ) $(DEP)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


.PHONY: all, clean, fclean, re
