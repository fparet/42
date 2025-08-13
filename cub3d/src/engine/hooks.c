#include <stdlib.h>
#include <mlx.h>
#include "engine/engine.h"

static int map_cell_is_wall(t_state *st, int ix, int iy)
{
    int len;
    if(ix<0 || iy < 0 || iy >= st->g->map_height)
        return 1;
    len = (int)ft_strlen(st->g->map[iy]);
    if(ix >= len)
        return 1;
    return(st->g->map[iy][ix] != '0' && st->g->map[iy][ix] != 'N' && st->g->map[iy][ix] != 'S' && st->g->map[iy][ix] != 'E' && st->g->map[iy][ix] != 'W');
}

static void move_try(t_state *st, double nx, double ny)
{
    if(!map_cell_is_wall(st, (int)nx, (int)st->g->player_y))
        st->g->player_x = nx;
    if(!map_cell_is_wall(st, (int)st->g->player_x, (int)ny))
        st->g->player_y = ny;
}

static int normalize_key(int key)
{
    if(key == 65361 || key == 123)
        return KEY_LEFT;
    if(key == 65363 || key == 124)
        return KEY_RIGHT;
    if(key == 65362 || key == 126)
        return KEY_UP;
    if(key == 65364 || key == 125)
        return KEY_DOWN;
    if(key == 65307 || key == 53)
        return 27;
    return key;
}

static int is_down(t_state *st, int code)
{
    return(code >= 0 && code < 512 && st->keys[code]);
}

int on_key_press(int key, t_state *st)
{
    int k = normalize_key(key);
    if(k == 27)
    {
        on_close(st);
        return 0;
    }
    if(k >= 0 && k < 512)
        st->keys[k] = 1;
    return 0;
}

int on_key_release(int key, t_state *st)
{
    int k = normalize_key(key);
    if(k >= 0 && k<512)
        st->keys[k] = 0;
    return 0;
}

#include "cub3D.h"

int on_close(t_state *st)
{
    if (!st)
        exit(0);
    /* Libère côté MLX (images, window, display, etc.) */
    eng_cleanup(st);
    /* Libère la partie “jeu” (map dupliquée, chemins textures, etc.) */
    (void)free_game(st->g);
    /* On termine le programme proprement */
    exit(0);
    return (0);
}


static void do_move_rotate(t_state *st)
{  
    double sp;
    double rt;
    double nx;
    double ny;
    
    sp = 0.02;
    rt = 0.02;
    if(is_down(st,KEY_UP))
    {
        nx=st->g->player_x+cos(st->g->player_angle)*sp;
        ny=st->g->player_y+sin(st->g->player_angle)*sp;
        move_try(st,nx,ny);
    }
    if(is_down(st, KEY_DOWN))
    {
        nx = st->g->player_x - cos(st->g->player_angle) * sp;
        ny=st->g->player_y - sin(st->g->player_angle) * sp;
        move_try(st, nx, ny);
    } 
    if(is_down(st, KEY_LEFT))st->g->player_angle -= rt;
    if(is_down(st, KEY_RIGHT))
        st->g->player_angle += rt;
    if(st->g->player_angle > M_PI)
        st->g->player_angle -= 2.0 * M_PI;
    else if(st->g->player_angle <= -M_PI)
        st->g->player_angle += 2.0 * M_PI;
}

int game_loop(t_state *st)
{
    do_move_rotate(st);
    raycast_frame(st);
    mlx_put_image_to_window(st->mlx.mlx, st->mlx.win, st->mlx.frame.img, 0, 0);
    return 0;
}