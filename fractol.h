/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:44:55 by ajelloul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/12 04:12:30 by ajelloul         ###   ########.fr       */
=======
/*   Updated: 2025/03/11 21:59:16 by ajelloul         ###   ########.fr       */
>>>>>>> 68d07db58b120ec1d5f08b36495d5f6ce4b65464
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/Users/ajelloul/Desktop/mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define HEIGHT 800
# define WIDTH 800

typedef struct s_data
{
	void	*img_ptr;
	char	*pixels_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_math
{
	double	re;
	double	im;
	double	default_re;
	double	default_im;
	double	re_x_re;
	double	im_x_im;
	int		iteration;
}	t_math;

typedef struct s_fractol
{
	t_data	img;
	t_math	math;
	void	*mlx;
	void	*mlx_win;
	double	zoom;
	double	ox;
	double	oy;
	int		max_iteration;
	int		color;
	int		is_julia;
	int     flag_set;
}	t_fractol;

<<<<<<< HEAD
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		eshap_hook(int keycode, void *param);
=======
int	ft_strcmp(char *s1, char *s2);
int	ft_atoi(char *num);
int		key_hook(int keycode, void *param);
>>>>>>> 68d07db58b120ec1d5f08b36495d5f6ce4b65464
int		x_close(t_fractol *fractol);
int		mouse_zoom_hook(int button, int x, int y, void *param);
double	to_complex_plane(int pixel_pos, double min, double max);
double	ft_atof(const char *str, double res, int sign, double div);
void	display_usage(void);
void	ft_draw(t_fractol fractol);
<<<<<<< HEAD
void	free_fractol(t_fractol *fractol);
=======
int 	mouse_hook(int button, int x, int y, void *param);
double	to_complex_plane(int pixel_pos, double min, double max);
void 	free_fractol(t_fractol *fractol);
>>>>>>> 68d07db58b120ec1d5f08b36495d5f6ce4b65464

#endif