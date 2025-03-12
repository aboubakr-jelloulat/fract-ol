/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:45:03 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/12 03:26:39 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	eshap_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

int	x_close(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	exit(0);
}

void	zoom(t_fractol *fractol, int button, int x, int y)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	new_x = to_complex_plane(x, fractol->ox - (fractol->zoom * 0.100),
			fractol->ox + (fractol->zoom * 0.100));
	new_y = to_complex_plane(y, fractol->oy - (fractol->zoom * 0.100),
			fractol->oy + (fractol->zoom * 0.100));
	fractol->ox = new_x;
	fractol->oy = new_y;
	if (button == 4)
		fractol->zoom += fractol->zoom * 0.1;
	else if (button == 5)
		fractol->zoom -= fractol->zoom * 0.1;
}

int	mouse_zoom_hook(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	zoom(fractol, button, x, y);
	ft_draw(*fractol);
	return (0);
}
