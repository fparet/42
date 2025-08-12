#include "engine/engine.h"
typedef struct s_ray
{
    double dir_x;
    double dir_y;
    int map_x;
    int map_y;
    double delta_x;
    double delta_y;
    double side_x;
    double side_y;
    int step_x;
    int step_y;
    int side;
    double dist;} t_ray;

static int is_wall(t_state *st, int mx, int my)
{  
    int len;
    
    if (mx<0 || my<0 || my >= st->g->map_height)
        return 1;
    len=(int)
        ft_strlen(st->g->map[my]);
    if(mx >= len)
        return 1;
    return(st->g->map[my][mx] != '0' && st->g->map[my][mx] != 'N' && st->g->map[my][mx] != 'S' && st->g->map[my][mx] != 'E' && st->g->map[my][mx] != 'W');
}

static void init_ray(t_state *st, t_ray *r, double cam_x)
{
    double ca = cos(st->g->player_angle);
    double sa = sin(st->g->player_angle);
    
    r->dir_x = ca + FOV * cam_x * -sa;
    r->dir_y = sa + FOV * cam_x * ca;
    r->map_x = (int)st->g->player_x;
    r->map_y = (int)st->g->player_y;
    r->delta_x = (r->dir_x == 0) ? 1e30 : fabs(1.0 / r->dir_x);
    r->delta_y=(r->dir_y == 0) ? 1e30 : fabs(1.0 / r->dir_y);
    if(r->dir_x < 0)
    {
        r->step_x = -1;
        r->side_x = (st->g->player_x-r->map_x) * r->delta_x;
    }
    else
    {
        r->step_x = 1;
        r->side_x = (r->map_x + 1.0-st->g->player_x) * r->delta_x;
    }
    if(r->dir_y < 0)
    {
        r->step_y = -1;
        r->side_y = (st->g->player_y-r->map_y) * r->delta_y;
    }
    else
    {
        r->step_y = 1;
        r->side_y = (r->map_y + 1.0-st->g->player_y) * r->delta_y;
    }
}

static void advance_until_hit(t_state *st, t_ray *r)
{
    while(!is_wall(st, r->map_x, r->map_y))
    {
        if(r->side_x < r->side_y)
        {
            r->side_x += r->delta_x;
            r->map_x += r->step_x;
            r->side = 0;
        }
        else
        {
            r->side_y += r->delta_y;
            r->map_y += r->step_y;
            r->side = 1;
        }
    }
    r->dist = (r->side == 0) ? (r->side_x-r->delta_x) : (r->side_y-r->delta_y);
    if(r->dist <= 1e-6)r->dist = 1e-6;
}

static int pick_tex_idx(t_ray *r)
{
    if(r->side == 0)
        return(r->step_x > 0 ? 2 : 3);
    return(r->step_y > 0 ? 1 : 0);
}

static void draw_from_ray(t_state *st, int x, t_ray *r)
{
    int lh;
    t_drawctx c;
    int idx;

    lh =  (int)(WIN_H/r->dist);
    c.start = -lh / 2 + WIN_H / 2;
    c.end = lh / 2 + WIN_H / 2;
    if(r->side == 0)
        c.wall_x = st->g->player_y + r->dist * r->dir_y;
    else 
        c.wall_x = st->g->player_x + r->dist * r->dir_x;
    c.wall_x -= floor(c.wall_x); 
    c.side = r->side;
    c.dir_x = r->dir_x;
    c.dir_y = r->dir_y;
    idx = pick_tex_idx(r);
    if(st->mlx.tex[idx].img)
    {
        c.tex = &st->mlx.tex[idx];
        draw_textured_column(st, x, &c);
    }
    else 
        draw_column(st, x, c.start, c.end, (r->side==0) ? 0xAAAAAA : 0x777777);
}

void raycast_frame(t_state *st)
{
    int x = 0;
    t_ray r;
    double cam_x;
    while(x < WIN_W)
    {
        cam_x = 2.0 * x / (double)WIN_W - 1.0;
        init_ray(st, &r, cam_x);
        advance_until_hit(st, &r);
        draw_from_ray(st, x, &r);
        x++;
    }
}