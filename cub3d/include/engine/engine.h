/* ************************************************************************** */
#ifndef ENGINE_H
# define ENGINE_H
# include <math.h>
# include "cub3D.h"
# define WIN_W 800
# define WIN_H 600
# define FOV   0.66
typedef struct s_img{void*img;char*addr;int bpp;int line;int endian;int w;int h;} t_img;
typedef struct s_mlx{void*mlx;void*win;t_img frame; t_img tex[4];} t_mlx;
typedef struct s_state{t_game*g;t_mlx mlx;int keys[512];} t_state;
enum e_keys { KEY_LEFT=314, KEY_RIGHT=315, KEY_UP=316, KEY_DOWN=317 };
typedef struct s_drawctx{int start;int end;int side;double wall_x;double dir_x;double dir_y;t_img*tex;} t_drawctx;
int eng_init(t_state *st, t_game *g); int eng_load_textures(t_state *st);
int on_key_press(int key, t_state *st); int on_key_release(int key, t_state *st); int on_close(t_state *st); int game_loop(t_state *st);
int setup_and_run(t_game *g); void eng_cleanup(t_state *st);
void put_pixel(t_img *img, int x, int y, int color);
void draw_column(t_state *st, int x, int start, int end, int color);
void draw_textured_column(t_state *st, int x, t_drawctx *c);
void raycast_frame(t_state *st);
#endif
