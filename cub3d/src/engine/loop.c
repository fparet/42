#include <mlx.h>
#include "engine/engine.h"

int setup_and_run(t_game *g)
{
    t_state st;
    int i;

    i = 0;
    while(i < 512)
        st.keys[i++] = 0;
    if(!eng_init(&st, g))
        return(ft_putstr_fd("Error\nmlx init\n", 1), 1);
    if(!eng_load_textures(&st))
        return(ft_putstr_fd("Error\ntextures\n", 1), 1);
    mlx_hook(st.mlx.win, 2, 1L << 0, on_key_press, &st);
    mlx_hook(st.mlx.win, 3, 1L << 1, on_key_release, &st);
    mlx_hook(st.mlx.win, 17, 0, on_close, &st);
    mlx_loop_hook(st.mlx.mlx, game_loop, &st);
    mlx_loop(st.mlx.mlx);
    return 0;
}