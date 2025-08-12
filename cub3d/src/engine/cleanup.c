#include <stdlib.h>
#include <mlx.h>
#include "engine/engine.h"

void eng_cleanup(t_state *st)
{
    int i;
    if(!st)
        return; 
    i=0; 
    while(i<4)
    {
        if(st->mlx.tex[i].img)
        mlx_destroy_image(st->mlx.mlx, st->mlx.tex[i].img); 
        i++;
    } 
    if(st->mlx.frame.img)
        mlx_destroy_image(st->mlx.mlx, st->mlx.frame.img); 
    if(st->mlx.win)mlx_destroy_window(st->mlx.mlx, st->mlx.win);
    #ifdef __linux__
    if(st->mlx.mlx)
    {
        mlx_destroy_display(st->mlx.mlx);
        free(st->mlx.mlx);
    }
    #endif
}