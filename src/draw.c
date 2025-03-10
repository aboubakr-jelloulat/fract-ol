/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:03:29 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/10 11:10:33 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

double	to_complex_plane(int pixel_pos, double min, double max)
{
	double	res;

	res = pixel_pos * ((max - min) / WIDTH) + min;
	return (res);
}

static void	init_complex_coordinates(t_fractol *fractol, int x, int y)
{
	fractol->math.re = to_complex_plane(x, fractol->ox - fractol->zoom, fractol->ox + fractol->zoom);
	fractol->math.im = to_complex_plane(y, fractol->oy - fractol->zoom, fractol->oy + fractol->zoom);
	if (!fractol->is_julia)
	{
		fractol->math.default_re = fractol->math.re;
		fractol->math.default_im = fractol->math.im;
	}
}
static void	apply_fractal_formula(t_fractol *fractol)
{
	while (fractol->math.iteration < fractol->max_iteration)
	{
		fractol->math.im_x_im = 2 * fractol->math.re * fractol->math.im;
		fractol->math.re_x_re = fractol->math.re * fractol->math.re - fractol->math.im * fractol->math.im;
		
		fractol->math.re = fractol->math.re_x_re + fractol->math.default_re;
		fractol->math.im = fractol->math.im_x_im + fractol->math.default_im;
		fractol->math.iteration++;

		if (fractol->math.re * fractol->math.re + fractol->math.im * fractol->math.im > 4)
			break;
	}
}

void	ft_mlx_pixel_put(t_fractol fractol, int x, int y, int color)
{
	char	*pixel;

	pixel = fractol.img.pixels_addr + (y * fractol.img.line_length + x
			* (fractol.img.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	ft_draw(t_fractol fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT) // Loop through rows (height)
	{
		x = 0;
		while (x < WIDTH) // Loop through columns (width)
		{
			init_complex_coordinates(&fractol, x, y);
			fractol.math.iteration = 0;
			apply_fractal_formula(&fractol);
			color = fractol.color * fractol.math.iteration;
			if (fractol.math.iteration == fractol.max_iteration)
				color = 0;
			ft_mlx_pixel_put(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(fractol.mlx, fractol.mlx_win);
	mlx_put_image_to_window(fractol.mlx, fractol.mlx_win, fractol.img.img_ptr,
		0, 0);
}
