
# Nom de l'exécutable
NAME = fractol

# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Dossiers
MLX_DIR = ./minilibx-linux
INCLUDES = -I$(MLX_DIR)
LIBS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11

# Fichiers sources et objets
SRCS = main.c events.c init.c main.c mandelbrot.c atof.c
OBJS = $(SRCS:.c=.o)

# Commandes
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

