/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:16:22 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/10 12:33:09 by ajelloul         ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
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