# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fparet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 02:34:03 by fparet            #+#    #+#              #
#    Updated: 2024/11/29 02:34:14 by fparet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom des exécutables
CLIENT = client
SERVER = server

# Fichiers sources
SRC_CLIENT = client.c
SRC_SERVER = server.c

# Fichiers objets générés automatiquement
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Options du compilateur
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Règle par défaut : compile les deux exécutables
all: $(CLIENT) $(SERVER)

# Règle pour compiler le client
$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)

# Règle pour compiler le serveur
$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)

# Règle générique pour créer les fichiers objets à partir des fichiers sources
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

# Nettoyage complet : fichiers objets + exécutables
fclean: clean
	rm -f $(CLIENT) $(SERVER)

# Recompilation complète
re: fclean all

