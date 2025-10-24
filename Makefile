NAME = fractol
FLAGS = -Wall -Wextra -Werror
OPTION = -MMD -c -I.
# Paths
LIBFT_PATH = lib/Libft
PRINTF_PATH = lib/ft_printf
MINILIBX_PATH = mlx_linux

INCLUDE = Makefile $(LIBFT_PATH)/libft.h $(PRINTF_PATH)/libftprintf.h src/fractol.h

# Library files
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a
MINILIBX = $(MINILIBX_PATH)/libmlx_Linux.a

# Source and object files
SRC = lib/get_next_line.c \
	src/fractol.c \
	src/hooks.c \
	src/start.c \
	src/mandelbrot.c \
	src/julia.c \
	src/utils.c \

OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)

# Compile the final executable
all: $(NAME)

-include $(DEP)

# Rebuild Libft if any object file changes
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Rebuild Printf if any object file changes
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

# Build the main program
#$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
#	cc $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX)
	$(CC) $(OBJ) $(FLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME)

# Compile object files and generate .d files for dependencies
%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) $(OPTION) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# Include the generated dependency files

# Clean object and dependency files
clean:
	/bin/rm -f $(OBJ) $(DEP)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

# Full clean
fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(MAKE) -C $(MINILIBX_PATH) clean

# Rebuild everything
re: fclean all

.PHONY: all, clean, fclean, re
