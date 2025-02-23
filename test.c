#include <mlx.h>
#include <stdio.h>

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 400, 400, "fractol");
// 	mlx_loop(mlx);
// }

// typedef struct s_data
// {
// 	void	*img; //  Holds the image object.
// 	char	*addr; // Points to the image memory buffer where pixels are stored.
// 	int		bits_per_pixel; // Number of bits per pixel
// 	int		line_length; //  Number of bytes per row in the image.
// 	int 	endian;   // Defines byte order (Little-endian or Big-endian)
// }	t_data;

// /*
// 	🚀 What is a Pixel?
// 	A pixel (short for "picture element") is the smallest unit of a digital image. 
// 	Each pixel has a color, which is usually represented in RGB format (Red, Green, Blue).
// 	When you create an image in MiniLibX, it's just a blank space in memory.
// 	To actually draw something, you need to modify the pixels in that memory.
// */

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)  // It calculates where the pixel is in memory and assigns it a new color.
// {
// 	char *dst; // Stores the memory address of the pixel.

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *) dst = color; // Writes the color to that memory location.
	
// }

// int main(void)
// {
// 	void *mlx; // The MiniLibX connection.
// 	void *mlx_win; // The window pointer.
// 	t_data img; // struct to hold image data.


// 	mlx = mlx_init(); // initialize 
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "fract-ol"); // Create a Window

// 	img.img = mlx_new_image(mlx, 1920, 1080); // Create an Image  -> Allocates memory for a 1920x1080 image and return pointe to the image
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); // Get Its Address

// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000); // Draws a red pixel at (5,5)
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // Displays the image in the window
// 	mlx_loop(mlx); // Keeps the window open & waits for events
// 	return (0);

// }


/*  Best practice   */

// typedef	struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int 	bits_per_pixel;
// 	int		line_length;
// 	int 	endian;
	
// }	t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void draw_square(t_data	*img, int x_start, int y_start, int size, int color1, int color2)
// {

// 	for (int y = y_start; y < y_start + size; y++)
// 	{
// 		for (int x = x_start; x < x_start + size; x++)
// 		{
// 			if (x < size / 2)
// 				my_mlx_pixel_put(img, x, y, color1);
// 			else
// 				my_mlx_pixel_put(img, x, y, color2);
// 		}
// 	}

// }


// int main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx,800, 800, "Practice in MiniLibX");
// 	img.img = mlx_new_image(mlx, 800, 800);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


// 	draw_square(&img, 0, 0, 300, 0x00FF0000,  0x00FF00);

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);

// 	return (0);
// }


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


int main(void)
{

	printf("%f\n", ft_atof("42.73", 0, 1, 1));

}