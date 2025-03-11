/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:16:22 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/11 22:03:18 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	display_usage(void)
{
	write(1, "====================================\n", 37);
	write(1, "              USAGE                 \n", 37);
	write(1, "====================================\n", 37);
	write(1, "\n", 1);
	write(1, "Usage 1: Mandelbrot Set\n", 25);
	write(1, "  ./fractol Mandelbrot\n", 24);
	write(1, "\n", 1);
	write(1, "Usage 2: Julia Set\n", 20);
	write(1, "  ./fractol julia <x> <y>\n", 27);
	write(1, "\n", 1);
	write(1, "Exit:\n", 6);
	write(1, "  Close the window (x) or press ESC.\n", 37);
	write(1, "====================================\n", 37);
	exit(0);
}

void	free_fractol(t_fractol *fractol)
{
	if (fractol->img.img_ptr)
		mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	if (fractol->mlx_win)
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	if (fractol->mlx)
		free(fractol->mlx);
}


double	ft_atof(const char *str, double res, int sign, double div)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str != '.' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str && *str >= '0' && *str <= '9')
		{
			div *= 10;
			res = res + (*str - '0') / div;
			str++;
		}
	}
	return (res * sign);
}
int	ft_atoi(char *num)
{
	int	nbr;
	int	index;

	index = -1;
	nbr = 0;
	while (num[++index])
		nbr = nbr * 10 + (num[index] - '0');
	return (nbr);
}