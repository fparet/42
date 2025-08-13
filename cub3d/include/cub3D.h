/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qboutel <qboutel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:10:27 by qboutel           #+#    #+#             */
/*   Updated: 2025/07/18 18:45:00 by qboutel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;
	double	player_x;
	double	player_y;
	double	player_angle;
	char	*texture[4];/* nord, sud, est, ouest */
	int		floor_color;
	int		ceiling_color;
}			t_game;

/* ### PARSING FOLDER ### */
/* color.c */
int		color_conversion(char *tmp);
int		color_pattern(char *tmp);
int		color_floor(char *line, t_game *g);
int		color_ceiling(char *line, t_game *g);

/* map_is_valid.c */
int		character_is_valid(char **map);
int		player_is_valid(char **map);
int		is_invalid(char **map, int y, int x);
int		map_is_closed(char **map);
int		map_is_valid(t_game g);

/* map.c */
int		is_map(char *line);
int		nbr_line_map(char *file);
int		map_malloc2(int fd, char *line, t_game *g);
int		map_malloc(char *file, t_game *g);
int		map(char *file, t_game *g);

/* parsing.c */
void	init_game(t_game *g);
int		file_is_valide(char *file);
int		parse_process(char *copy, t_game *g);
int		parsing(char *file, t_game *g);

/* player.c */
void	position_player(t_game *g);
void	orientation_player(t_game *g);
void	player(t_game *g);

/* texture.c */
int		texture(int index, char *line, t_game *g);
/* ###################### */

/* ### UTILS FOLDER ### */
/* debug.c */
void	print_game(t_game *g);

/* free.c */
char	*free_game(t_game *g);
char	*free_split(char **split);
char	*free_textures(char *texture[4]);

/* get_next_line.c */
char	*get_next_line(int fd);

/* engine interface */
int	setup_and_run(t_game *g);

/* main.c */
int		main(int argc, char **argv);

#endif