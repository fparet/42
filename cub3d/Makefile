NAME        = cub3D
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinclude -Ilibft -Iinclude/engine -g3
OS          = $(shell uname -s)

SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = libft

SRC_PARSING = \
	$(SRC_DIR)/parsing/color.c \
	$(SRC_DIR)/parsing/map_is_valid.c \
	$(SRC_DIR)/parsing/map.c \
	$(SRC_DIR)/parsing/parsing.c \
	$(SRC_DIR)/parsing/player.c \
	$(SRC_DIR)/parsing/texture.c

SRC_UTILS   = \
	$(SRC_DIR)/utils/debug.c \
	$(SRC_DIR)/utils/free.c \
	$(SRC_DIR)/utils/get_next_line.c

SRC_ENGINE  = \
	$(SRC_DIR)/engine/init_mlx.c \
	$(SRC_DIR)/engine/hooks.c \
	$(SRC_DIR)/engine/draw.c \
	$(SRC_DIR)/engine/raycast.c \
	$(SRC_DIR)/engine/loop.c \
	$(SRC_DIR)/engine/cleanup.c

SRCS        = $(SRC_DIR)/main.c $(SRC_PARSING) $(SRC_UTILS) $(SRC_ENGINE)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT       = $(LIBFT_DIR)/libft.a

ifeq ($(OS), Linux)
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
else
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/parsing
	mkdir -p $(OBJ_DIR)/utils
	mkdir -p $(OBJ_DIR)/engine

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

