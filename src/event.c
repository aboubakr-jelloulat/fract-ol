/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:45:03 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/23 09:47:54 by ajelloul         ###   ########.fr       */
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
