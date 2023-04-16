/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hrazanam <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/15 14:53:03 by hrazanam		  #+#	#+#			 */
/*   Updated: 2022/03/15 15:07:02 by hrazanam         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define K_ESC 65307
# define K_RIGHT 65363
# define K_LEFT 65361
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_M 109

# define DP 17
# define DG 5

# define M_PI	3.14159265358979323846
# define M_PI2	1.57079632679
# define M_3PI2 	4.71238898038
# define M_2PI 	6.28318530718

# define WHITE 16777215
# define SILVER 12632256
# define GRAY 8421504
# define BLACK 0
# define RED 16711680
# define MAROON 8388608
# define YELLOW 16776960
# define OLIVE 8421376
# define LIME 65280
# define GREEN 32768
# define AQUA 65535
# define TEAL 32896
# define BLUE 255
# define NAVY 128
# define FUCHSIA 16711935
# define PURPLE 8388736

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"
# include "minilibx/mlx.h"

typedef enum e_err
{
	NO_ERROR,
	EXTENSION,
	FEW,
	TEX,
	DIR,
	RGB,
	COL,
	NO_MAP,
	HEND,
	MORE,
	VEND,
	POS,
	UNCORRECT,
	MCOL,
	MTEX,
	INTEX,
	NOFILE,
	NOPOS,
	BADSPC
}	t_err;

typedef struct s_lststr
{
	char			*str;
	struct s_lststr	*nxt;
}t_lststr;

typedef struct s_texture
{
	void		*mlx;
	void		*img;
	char		*path;
	int			w;
	int			h;
	char		*addr;
	int			bpp;
	int			length;
	int			endian;
}	t_texture;

typedef struct s_inf
{
	t_lststr	*map;
	int			start_pos[3];
	int			ceiling;
	int			floor;
	char		*texture[4];
	int			dim[2];
	t_err		err;
}	t_inf;

typedef struct s_ddainfo {
	int			xf;
	int			yf;
	double		dist_x;
	double		dist_y;
	double		fdist_x;
	double		fdist_y;
	double		step_x;
	double		step_y;
}		t_ddainfo;

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_coord {
	double		x;
	double		y;
	double		th;
}		t_coord;

typedef struct s_colision
{
	t_coord		coord;
	int			side_hit;
}	t_colision;

typedef struct s_perso {
	struct s_coord	coord;
	double			th_dir;
}		t_perso;

typedef struct s_plan {
	double			width;
	double			height;
}		t_plan;

typedef struct s_vars {
	void			*img;
	void			*mlx;
	void			*win;
	char			*addr;
	int				bpp;
	int				length;
	int				endian;
}			t_vars;

typedef struct s_game {
	t_colision	col;
	t_inf		inf;
	t_perso		perso;
	t_perso		next_coli1;
	t_perso		next_coli2;
	t_texture	tex[4];
	t_point		mouse;
	int			moved;
	t_vars		vars;
}	t_game;

//INIT.c
int			init_size(t_plan *image);
void		init_main_screen(t_game *game);

//UTILS_CALCUL
int			last_multiple(double nb);
int			next_multiple(double nb);
double		hypo_add(t_perso src_ray, t_perso next_coli);
int			double_compare(double th1, double th2);

//UTILS CADRAN
int			get_cadran(double th);
double		check_modulo(double ray);
int			in_circle(double ray);
int			is_special_case(double th);
int			is_special_case_simple(double th);

//INIT_DDA
void		reinit_save(t_perso *src_ray_save, t_perso src_ray);
t_ddainfo	init_info(double theta, char hor, char vert, t_perso src_ray);

//DDAA SPECIAL CASE
double		process_dda_nsew(t_perso src_ray, t_game	*game);

//DDA GENERAL
double		ft_dda(t_perso src_ray, t_game	*game);

//DDA_SEARCH HIT
void		search_side_hit(t_coord coli, t_game	*game, char mod);

//rendering.c
void		scan_ray(t_perso src_ray, t_game *game);
void		scan_ray_bonus(t_perso src_ray, t_game *game);

//DRW_MINIMAP
void		draw_minimap(t_game *game, t_perso perso, t_lststr *map);

//MINIMAP RAY.C
void		all_super_ray(t_game *game, double thdir);
void		magic_wand(t_perso src_ray, t_game *game);

//MINIMAP INIT.C
void		init_minimap_calc(t_point *centre, t_point *it);
void		init_map_y(t_lststr **map, int height);

//split.c
char		**ft_split(char const *s, char c);

//strlst.c
t_lststr	*newlststr(char *str);
t_lststr	*lastlststr(t_lststr *lst);
void		addlststr(t_lststr **lst, t_lststr *newstr);
int			addstrlst(t_lststr **lst, char *str);
int			strlstsize(t_lststr *lst);

//parce_utils.c
char		*ft_strdup(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
int			ft_isdigit(char c);
int			len_dstr(char **str);
void		mes_sp(char **linesp, t_inf *inf);

//del.c
void		del_inf(t_inf *inf);
void		ft_delstr(char **str);
void		ft_deldstr(char ***str);
void		strlstclear(t_lststr **lst);

//parcing.c
int			end_cub_file(int fd, t_inf *inf);
int			parce_map_inf(char *path, t_inf *inf, int *fd);
int			get_first_line(t_inf *inf, int ret, int fd);
int			end_verif(t_inf *inf, int fd, int mod);
int			parce_map(char *path, t_inf *inf);

//hook_rotation.c
int			turn_left(t_game *game);
int			turn_right(t_game *game);

//hook_up
int			go_up(t_game *game);

//hook down
int			go_down(t_game *game);

//utils hook up down
void		get_dir_down(t_coord *dir, int cadran);
double		get_updown_th(double th);
void		get_dir_up(t_coord *dir, int cadran);

//hook left
int			go_left(t_game *game);

//hook right
int			go_right(t_game *game);

//utils hook left right
double		get_leftright_th(double th);

//hooks.c
int			exit_window(int keycode, t_game *game);
int			exit_window_bis(t_game *game);
int			key_hooks(int keycode, t_game *game);

//draw.c
void		black_screen(t_game *game);
float		rest(float f, int nb);
void		load_texelx(t_game *game, t_point *tix);
void		load_pixely(int len, t_point *pix, int *end);
void		draw_textured_wall(int len, int x, t_game *game, t_texture *tex);

//collision.c
int			collision_hor(t_game *game, t_coord next_coli);
int			collision_ver(t_game *game, t_coord next_coli);
int			collisionx(t_game *game, t_coord next_coli);
int			collisiony(t_game *game, t_coord next_coli);
int			in_map(t_coord p, t_game *game);
void		side_hited(t_game *game, int side);
void		side_hitx(t_game *game, t_coord next_coli);
void		side_hity(t_game *game, t_coord next_coli);
void		adjust_angle(double th, t_point *c, char mod);
char		extract_map(t_lststr *map, int x, int y);
int			no_map(t_coord p, t_game *game);

//color.c
int			trgb(int t, int r, int g, int b);
void		color_ceiling(t_game *game, int c);
void		color_floor(t_game *game, int c);
void		color_edges(t_game *game, int c_floor, int c_ceiling);

//texture.c
void		load_texture(t_game *game);
void		ft_putstr_fd(int fd, char *str);
void		load_one_texture(t_game *game, int ind);
void		clean_texture(t_game *game);

//modmap.c
int			addones(t_lststr *lst, int len);
t_lststr	*extract_line(t_lststr *map, int l);
int			modify_map(t_inf *inf, t_lststr *map);
char		*str_ones(int nb);

//error.c
void		print_err(t_err err);
void		set_err(t_inf *inf, t_err err);
int			error_file(t_inf *inf);

//mouse_hook.c
int			mouse_move(int x, int y, t_game *game);
int			center_mouse(int button, int x, int y, t_game *game);

//parce_mapinfo.c
int			correctrgbformat(char *format);
int			correct_color(char *dir, char *format, t_inf *inf);
int			load_texture_path(t_inf *inf, char *format, int i);
int			correct_direction(char *dir, char *format, t_inf *inf);
int			correct_texture(char *line, t_inf *inf);

//parce_searchsymb.c
int			pre_symb0(char *str, int ind);
int			pre_symb(char *str, int ind);
int			post_symb0(char *str, int ind);
int			post_symp(char *str, int ind);
int			verif_virg(char *format);

//parce_upsympb.c
void		change_upc(int ind, t_lststr *cur, char *up_c);
int			up_symb(t_lststr *map, int nb_line, int ind);
void		change_upc0(int ind, t_lststr *cur, char *up_c);
int			up_symb0(t_lststr *map, int nb_line, int ind);

// display.c
void		displaylststr(t_lststr *lst);
void		displayinf(t_inf *inf);

//parce_checkline.c
int			check_limit(char *str);
int			uncorrect_symb(char *line);
int			check_map(char *line, t_inf *inf, int dim);

//parce_checkvertical.c
int			wrong_space(char c, t_lststr *map, int i, int j);
int			wrong_zero(char c, t_lststr *map, int i, int j);
int			check_vertical_map(t_lststr *map, t_inf *inf);

//parce_downsymb.c
int			down_symb(t_lststr *map, int nb_line, int ind);
int			down_symb0(t_lststr *map, int nb_line, int ind);

//parce_utils2.c
void		ini_inf(t_inf *inf);
int			custom_atoi(char *str);
int			is_posdir(char c, char cplus);
int			load_startpos(t_inf *inf, int i, int j, char c);
int			extention_cub(char *path, t_inf *inf, int *fd);

//extract_wall.c
char		extract_map(t_lststr *map, int x, int y);
int			is_wall1(t_lststr *map, int x, int y);
int			is_wall2(t_lststr *map, int x, int y);
int			is_wall(t_lststr *map, int x, int y);

//collision_utils.c
int			in_map(t_coord p, t_game *game);
int			no_map(t_coord p, t_game *game);
int			adjust_spangle(double th, t_point *c);
int			adjust_anglex(double th, t_point *c);
int			adjust_angley(double th, t_point *c);

//draw_line.c
int			comp_average(int x, double val);
int			in_cub(t_coord x1, t_coord x2, int x, int y);
void		draw_vertical(t_game *game, t_coord x1, t_coord x2, int c);
void		draw_horizontal(t_game *game, t_coord x1, t_coord x2, int c);
void		draw_real_line(t_coord x1, t_coord x2, t_game *game, int c);

//put_to_buff.c
char		*get_dstv(t_game *game, int x, int y);
char		*get_dst(t_texture *tex, int x, int y);
void		put_tex_to_buf(t_game *game, t_texture *tex,
				t_point tix, t_point pix);
void		put_to_buff(t_game *game, int x, int y, int color);

//modmap_utils.c

char		*ft_strjoino(char const *s1, char const *s2);
char		*ones(int len);
void		modone(char **str);

#endif
