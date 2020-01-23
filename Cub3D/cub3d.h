/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:34:35 by qperrot-          #+#    #+#             */
/*   Updated: 2020/01/23 15:09:52 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"
#include "keys.h"

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	char		*text;
	int			width;
	int			height;
    int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_sprit
{
	double		x;
	double		y;
	double		invDet;
	double		tranfX;
	double		tranfY;
	int			Vmouv;
	int			screenX;
	int			height;
	int			drawStartY;
	int			drawStartX;
	int			drawEndY;
	int			drawEndX;
	int			width;
	int			stripe;
}				t_sprit;

typedef struct    data_s
{
    void		*mlx_ptr;
    void		*mlx_win;
	int			win_width;//Width of the window
	int			win_height;//Height of the window
	int			x;
	char		k[280];//the keyboard key that was push
	double		posX;//Start position on X
	double		posY;//Start position on Y
	double		dirX;//Initial direction vector on X
	double		dirY;//Initial direction vector on Y
	double		PlanX;//Vecteur du plan de projection sur X
	double		PlanY;//Vecteur du plen de projection sur Y;
	double		wallX;
	//int			**buffer;
	int			*Zbuffer;
	int			numSprites;
	t_sprit		sprite;
	t_img		img;
	t_img		text[7];
	// t_img		text2;
	// t_img		text3;
	// t_img		text4;
	// t_img		text5;
	// t_img		text6;
	// t_img		text7;
	int			mapX;       //which box of the map we're in
    int			mapY;
    double		sideDistX; //length of ray from current position to next x or y-side
    double		sideDistY;
    double		deltaDistX; //length of ray from one x or y-side to next x or y-side
    double		deltaDistY;
    double		perpWallDist;
	double		rayDirX;
	double		rayDirY;
	double		floorXWall;//Position X du texel du sol au bas du mur
	double		floorYWall;//Position Y du texel du sol au bas du mur
	double		distWall;//Distance du mur
	double		distPlayer;//Distance de la camera
    int			stepX; //what direction to step in x or y-direction (either +1 or -1)
    int			stepY;
    int			hit;
	int			hitSprite;
    int			side;
    int			lineHeight;   //Calculate height of line to draw on screen
    int			drawStart; //calculate lowest and highest pixel to fill in current stripe
    int			drawEnd;
	int			**bufferSprites;
	// char		*text_north;
	// char		*text_south;
	// char		*text_east;
	// char		*text_west;
	// char		*text_sprite;
	int			color_floor;
	int			color_ceil;
	int			num_of_line;
	int			num_of_el;
	int			player;
	int			**map_n;
	// int			texWidth;
	// int			texHeight;
	// int			texWidth2;
	// int			texHeight2;
	// int			texWidth3;
	// int			texHeight3;
	int			save;
}                 data_t;

typedef struct		pars_s
{
	int			*pars;
	int			n_R;
	int			n_S;
	int			n_F;
	int			n_C;
	int			n_EA;
	int			n_NO;
	int			n_SO;
	int			n_WE;
	int			first_line;
	int			last_line;
}					pars_t;

typedef enum		s_text
{
	NORTH = 0,
	SOUTH,
	EAST,
	WEST,
	SPRITE,
	CEIL,
	FLOOR,
}					t_text;

void	print_map(data_t *data);
int		key_release_hook(int key, data_t *data);
int		key_press_hook(int key, data_t *data);
int		deal_key(data_t *data);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
//void    ft_check_arg(pars_t *pars, data_t *data);
void	ft_check_arg(pars_t *pars, data_t *data, int argc, char *argv[]);
void	ft_fill_tmp_map(data_t *data, int **tmp_map, char *line);
void	ft_fill_map_n(data_t *data, int **tmp_map);
void	ft_malloc_map_n(data_t *data);
void	ft_find_player(data_t *data);
void	ft_put_new_line_tmp_map(data_t *data, int **tmp_map, char *line, int j);
void	ft_put_in_tmp_map(data_t *data, int **tmp_map, char *line);
void	ft_realloc(data_t *data, char *line, pars_t *pars);
void	ft_init_dir_plan(data_t *data, char c);
void	ft_check_other_line(char *line, data_t *data, pars_t *pars);
void	ft_check_first_line(char *line, data_t *data, pars_t *pars);
void	ft_check_last_line(char *line, data_t *data, pars_t *pars);
void	ft_check_line(char *line, data_t *data, pars_t *pars);
void	ft_get_resolution(char *line, data_t *data);
void	ft_check_all_color(char **tmp);
void	ft_check_color_arg(char **tmp);
int		ft_get_color(char *line);
void	ft_init_color_floor(char *line, data_t *data, pars_t *pars);
void	ft_init_color_ceil(char *line, data_t *data, pars_t *pars);
void	ft_ckeck_textsp_path(char **tmp, data_t *data, int fd);
void	ft_ckeck_textwe_path(char **tmp, data_t *data, int fd);
void	ft_ckeck_textns_path(char **tmp, data_t *data, int fd);
void	ft_get_text_path(char *line, data_t *data);
void	ft_init_textsp_path(char *line, data_t *data, pars_t *pars);
void	ft_init_textwe_path(char *line, data_t *data, pars_t *pars);
void	ft_init_textno_path(char *line, data_t *data, pars_t *pars);
void	ft_init_textso_path(char *line, data_t *data, pars_t *pars);
void	ft_init_textea_path(char *line, data_t *data, pars_t *pars);
void	ft_init_resolution(char *line, data_t *data, pars_t *pars);
void	ft_init_img(data_t *data);
void    ft_sidedist(data_t *data);
void    ft_hit_wall(data_t *data);
void	ft_per_wall(data_t *data);
void    ft_draw_start_end(data_t *data);
void    ft_put_wall_text(data_t *data);
void    ft_draw_column(data_t *data, int *texX);
void    ft_floor_ceil_orient(data_t *data);
void    ft_draw_floor_ceil(data_t *data);
void    ft_init_sprite(data_t *data);
void	ft_creat_sprite(data_t *data, int i);
void	ft_draw_sprite(data_t *data, int texX, int y);
void    ft_mouve_up_down(data_t *data, double moveSpeed, double security);
void    ft_mouve_left_right(data_t *data, double moveSpeed, double security);
void    ft_rotation(data_t *data, double speed);
void	ft_take_coord_sprites(data_t *data);
void	ft_clean_buff(data_t *data);
void	print_map(data_t *data);
void	ft_sort_sprites(data_t *data);
void	ft_free_buf(data_t *data);
void	ft_take_coord(data_t *data);
void	ft_dist_sprit_player(data_t *data);
void	ft_free_sprite(data_t *data);
void	ft_error_exit(data_t *data);
char	*ft_creat_buf(char *line, int el);
char	*ft_count_el(char *line);
void	*ft_memset(void *b, int c, size_t len);
void	ft_save(data_t *data);
void	ft_count_sprites(data_t *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_check_xpm(data_t *data);
void	ft_init_struct(pars_t *pars, data_t *data);
void	ft_parsing_arg(data_t *data, pars_t *pars, int fd);
#endif