# Variables
NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SRCDIR = src
INCDIR = include
SRC = $(SRCDIR)/main.c $(SRCDIR)/simulation.c $(SRCDIR)/utils.c $(SRCDIR)/init.c
OBJ = $(SRC:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(INCDIR) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

