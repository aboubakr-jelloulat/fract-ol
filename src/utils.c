/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:16:22 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/22 14:42:01 by ajelloul         ###   ########.fr       */
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

void    display_usage(void)
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
    write(1, "  Close the window or press ESC.\n", 33);
    write(1, "====================================\n", 37);
}

