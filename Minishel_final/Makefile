# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/22 02:10:35 by igrousso          #+#    #+#              #
#    Updated: 2025/03/22 14:06:08 by igrousso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LDFLAGS = -lreadline
INCLUDE_FLAGS = -Iincludes

# Project names

NAME = minishell

# Parsing files

SRC_CMD = $(addprefix commands/, fill_command_utils.c fill_command.c get_path.c here_doc.c init_data.c)

SRC_VAR = $(addprefix variables_env/, var.c var_utils.c)

SRC_TOKEN = $(addprefix token/, token_redir.c token_utils.c token_utils2.c tokenizer1.c concat_token.c)

SRC_CHECK = $(addprefix check_error/, check_utils.c check.c errno.c)

SRC_PARS = $(addprefix parsing/, parsing.c $(SRC_VAR) $(SRC_TOKEN) $(SRC_CHECK) $(SRC_CMD))

# Exec files

SRC_EXEC = $(addprefix exec/, exec.c exec_utils.c)

# Free files

SRC_FREE = $(addprefix free_etc/, next_line.c errno_save.c)

# Builts in

SRC_BUILT = $(addprefix builtins/, ft_verif_bultins.c ft_isbuiltin.c env.c cd.c export.c pwd.c unset.c echo.c export_bis.c ft_exit.c ft_verif_builtins2.c ft_verif_builtins3.c)

# Signaux

SRC_SIG = $(addprefix signaux/, signals.c terminal.c)

# Source files

SRCS = $(addprefix sources/, $(SRC_PARS) $(SRC_EXEC) $(SRC_FREE) $(SRC_BUILT) $(SRC_SIG))
MAIN = $(addprefix sources/, main.c)

# Object files

OBJ =  $(SRCS:.c=.o)
OBJ_MAIN		=	$(MAIN:.c=.o)

ALL_OBJS		=	$(OBJ) $(OBJ_MAIN) 

# Library path

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

# Default target

all: $(NAME)

# Build the main program

$(NAME): $(OBJ) $(OBJ_MAIN) $(LIBFT)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $(NAME)

# Compile library

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# Generic rule for .c to .o

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

# Clean object files

clean:
	rm -rf $(ALL_OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

# Full clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

# Rebuild everything

re: fclean all

# valgrind

valgrind:
		@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children=yes --suppressions=supp.supp ./minishell 

# Phony targets

.PHONY : all clean fclean re 
