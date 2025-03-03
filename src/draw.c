/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:03:29 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/02 23:32:30 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	to_complex_plane(int pixel_pos, double min, double max)
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
	fractol->math.iteration = 0;
}
static void	apply_fractal_formula(t_fractol *fractol)
{
	while (fractol->math.iteration < fractol->max_iteration)
	{
		
	}
	
}