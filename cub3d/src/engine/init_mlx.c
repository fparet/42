/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:00:00 by you               #+#    #+#             */
/*   Updated: 2025/08/12 00:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>
#include "engine/engine.h"
#include "libft.h"

static int	init_frame(t_mlx *m)
{
	m->frame.img = mlx_new_image(m->mlx, WIN_W, WIN_H);
	if (!m->frame.img)
		return (0);
	m->frame.addr = mlx_get_data_addr(m->frame.img, &m->frame.bpp,
			&m->frame.line, &m->frame.endian);
	m->frame.w = WIN_W;
	m->frame.h = WIN_H;
	return (1);
}

int	eng_init(t_state *st, t_game *g)
{
	st->g = g;
	st->mlx.mlx = mlx_init();
	if (!st->mlx.mlx)
		return (0);
	st->mlx.win = mlx_new_window(st->mlx.mlx, WIN_W, WIN_H, "cub3D");
	if (!st->mlx.win)
		return (0);
	if (!init_frame(&st->mlx))
		return (0);
	return (1);
}

static int	load_tex_one(t_img *tex, void *mlx, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->w, &tex->h);
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line, &tex->endian);
	return (1);
}

static int	sanitize_and_check(char **p)
{
	char	*t;
	int		fd;

	if (!p || !*p)
		return (0);
	t = ft_strtrim(*p, " \t\r\n");
	if (!t)
		return (0);
	if (t != *p)
	{
		free(*p);
		*p = t;
	}
	fd = open(*p, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	eng_load_textures(t_state *st)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!sanitize_and_check(&st->g->texture[i])
			|| !load_tex_one(&st->mlx.tex[i], st->mlx.mlx, st->g->texture[i]))
			return (0);
		i++;
	}
	return (1);
}
