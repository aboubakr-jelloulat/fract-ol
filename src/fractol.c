/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:44:45 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/11 22:02:00 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fractol_init(t_fractol *fractol, char *title)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (free_fractol(fractol));
	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, title);
	if (!fractol->mlx_win)
		return (free_fractol(fractol));
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
		return (free_fractol(fractol));
	fractol->img.pixels_addr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	if (!fractol->img.pixels_addr)
		return (free_fractol(fractol));
	fractol->max_iteration = 100;
	fractol->ox = 0;
	fractol->oy = 0;
	fractol->zoom = 2;
	fractol->color = 0xF5F3F2;
	fractol->is_julia = (fractol->flag_set == 2);
	fractol->math.default_re = 0.0;
	fractol->math.default_im = 0.0;
}

void	julia_set(char **av)
{
	t_fractol	fractol;

	fractol.flag_set = 2;
	fractol_init(&fractol, av[1]);
	fractol.math.default_re = ft_atof(av[2], 0, 1, 1);
	fractol.math.default_im = ft_atof(av[3], 0, 1, 1);
	ft_draw(fractol);
	mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
	mlx_hook(fractol.mlx_win, 17, 0, x_close, &fractol);
	mlx_loop(fractol.mlx);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
		{
			fractol.flag_set = 1;
			fractol_init(&fractol, av[1]);
			ft_draw(fractol);
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
