/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:45:03 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/10 12:43:20 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (0);
}

int	x_close(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	exit(0);
}

void mouse_zoom(t_fractol *fractol, int button, int x, int y)
{
	double new_x = 0;
	double new_y = 0;

	new_x = to_complex_plane(x, fractol->ox - (fractol->zoom * 0.128), fractol->ox + (fractol->zoom * 0.128));
	new_x = to_complex_plane(y, fractol->oy - (fractol->zoom * 0.128), fractol->oy + (fractol->zoom * 0.128));
	fractol->ox = new_x;
	fractol->oy = new_y;
	if (button == 1)
		fractol->zoom += fractol->zoom * 0.1;
	else if (button == 2)
		fractol->zoom -= fractol->zoom * 0.1;
}


int mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	// if (button != 1 && button != 2)
	// {
		mouse_zoom(fractol, button, x, y);
		ft_draw(*fractol);
	//}
	
	return (0);
}
