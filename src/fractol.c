/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:44:45 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/27 15:05:09 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fractol_init(t_fractol *fractol, char *title)
{
	fractol->mlx = mlx_init();
	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, title);
	fractol->max_iteration = 100;
	fractol->ox = 0;
	fractol->oy = 0;
	fractol->zoom = 2;
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.pixels_addr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bits_per_pixel, &fractol->img.line_length, &fractol->img.endian);
	fractol->color = 0x00ffd9;
	fractol->is_julia = (ft_strcmp(title, "Julia") == 0);
	fractol->math.default_re = -0.466;
	fractol->math.default_im = 0.622;
}

void	julia_set(char **av)
{
	t_fractol	fractol;

	fractol_init(&fractol, av[1]);
	fractol.math.default_re = ft_atof(av[2], 0, 1, 1);
	fractol.math.default_im = ft_atof(av[3], 0, 1, 1);
	mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
	mlx_hook(fractol.mlx_win, 17, 0, x_close, &fractol);
	mlx_loop(fractol.mlx);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0
			|| ft_strcmp(av[1], "julia") == 0)
		{
			fractol_init(&fractol, av[1]);
			mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
			mlx_hook(fractol.mlx_win, 17, 0, x_close, &fractol);
			mlx_loop(fractol.mlx);
		}
		else
			display_usage();
	}
	else if (ac == 4 && ft_strcmp(av[1], "julia") == 0)
		julia_set(av);
	else
		display_usage();
	return (0);
}
