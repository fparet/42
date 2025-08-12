#include "engine/engine.h"

void put_pixel(t_img *img,int x,int y,int color)
{
    char*px;
    if(!img || x < 0 || y < 0 || x >= img->w || y >= img->h)
        return;
    px = img->addr + (y * img -> line + x * (img->bpp / 8));
    *(int*)px = color;
}

void draw_column(t_state *st, int x, int start, int end, int color)
{
    int y;
    if(start < 0)
        start = 0;
    if(end >= WIN_H)
        end = WIN_H-1;
    y = 0;
    while(y < start)
        put_pixel(&st->mlx.frame, x, y++, st->g->ceiling_color);
    while(y <= end)
        put_pixel(&st->mlx.frame, x, y++, color);
    while(y < WIN_H)
        put_pixel(&st->mlx.frame, x, y++, st->g->floor_color);
}

static int get_tex_color(t_img *tex, int tx, int ty)
{
    char*p;
    
    if(!tex || tx < 0 || ty < 0 || tx >= tex->w || ty >= tex->h)
        return 0;
    p = tex->addr + ty * tex->line + tx * (tex->bpp / 8);
    return(*(int*)p);
}

static void draw_top(t_state *st, int x, int y_end)
{
    int y;
    if(y_end < 0)
        y_end = 0;
    y = 0;
    while(y < y_end && y < WIN_H)
        put_pixel(&st->mlx.frame, x, y++, st->g->ceiling_color);
}

static void draw_bottom(t_state *st, int x, int y_start)
{
    int y;
    if(y_start < 0)
        y_start = 0;
    y = y_start;
    while(y < WIN_H)
        put_pixel(&st->mlx.frame, x, y++, st->g->floor_color);
}

static void draw_tex_span(t_state *st, int x, t_drawctx*c, int tx)
{
    int y;
    double step;
    double tpos;
    int ty;
    
    if(c->start < 0)
        c->start = 0;
    if(c->end >= WIN_H)
        c->end = WIN_H-1;
    step = (double)c->tex->h / (c->end-c->start + 1);
    tpos = 0.0;
    y = c->start;
    while(y <= c->end)
    {
        ty = (int)tpos;
        if(ty >= c->tex->h)
            ty = c->tex->h-1;
        put_pixel(&st->mlx.frame, x, y, get_tex_color(c->tex, tx, ty));
        tpos += step;
        y++;
    }
}
void draw_textured_column(t_state *st, int x, t_drawctx *c)
{
    int tx;
    if(!c || !c->tex || !c->tex->img)
        return(draw_column(st, x, c ? c->start : 0, c ? c->end:0, 0x777777));
    if(c->start < 0)c->start = 0;
    if(c->end >= WIN_H)
        c->end = WIN_H-1;
    tx=(int)(c->wall_x * c->tex->w);
    if((c->side == 0 && c->dir_x > 0) || (c->side == 1 && c->dir_y < 0))
        tx = c->tex->w - tx - 1;
    draw_top(st, x, c->start);
    draw_tex_span(st, x, c, tx);
    draw_bottom(st, x, c->end + 1);
}