/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:44:55 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/05 23:24:45 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
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
}	t_fractol;

int		ft_strcmp(char *s1, char *s2);
int		key_hook(int keycode, void *param);
int		x_close(t_fractol *fractol);
double	ft_atof(const char *str, double res, int sign, double div);
void	display_usage(void);
void	ft_draw(t_fractol fractol);
int 	mouse_hook(int button, int x, int y, void *param);
double	to_complex_plane(int pixel_pos, double min, double max);

#endif