#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int		line_length;
	int 	endian;
	
}	t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int eshap(int keycode)
{
	if (keycode == 53 || keycode == 12)
		exit(0);
	return (0);
}
int	x_close(void *param)
{
	(void)param;
	exit(0); // Properly exit the program
	return (0);
}

void draw_all_windo(t_data *img, int color)
{
	for (int i = 0; i < 800; i++)
	{
		for (int j = 0; j < 800; j++)
		{
			my_mlx_pixel_put(img, i, j, color);
		}
	}
}

void	draw_line(t_data	*img, int color)
{
	for (int i = 0; i < 800; i++) // diragonal 
	{
		my_mlx_pixel_put(img, i, i, color);
	}

	int	x, y, x_start = 0, x_end = 400;

	for (x = x_start; x <= x_end; x++) // mosta9iim
		my_mlx_pixel_put(img, x, y, color);


}

void draw_square(t_data *img, int color1, int color2)
{
	for (int x = 100; x < 400; x++)
		for (int y = 100; y < 400; y++)
		{
			if (y < 200)
				my_mlx_pixel_put(img, x, y, color1);
			else
				my_mlx_pixel_put(img, x, y, color2);
		}
}

void draw_trinagle(t_data	*img, int color1, int color2)
{
	int half = 400;
	int all = 800;
	
	for (int i = 0; i < all; i++)
	{
		for(int j = 0; j < half; j++)
		{
			my_mlx_pixel_put(img, i, j, color2);
		}
		half--;
	}

	half = 400;
	all = 800;

	for (int i = all; i >= 0; i--)
	{
		for(int j = 0; j < half; j++)
		{
			my_mlx_pixel_put(img, i, j, color2);
		}
		half--;
	}

	half = 400;
	all = 800;

	for (int i = 0; i < all; i++)
	{
		for (int j = 400; j < all; j++)
		{
			my_mlx_pixel_put(img, i, j, color2);
		}
	}

}

void draw_dama(t_data	*img, int color1, int color2)
{
	for (int i = 0; i < 800; i++)
	{
		my_mlx_pixel_put(img, i, i, color2);
	}

	int j = 0;
	for (int i = 800; i > 0; i--)
	{
		my_mlx_pixel_put(img, i, j, color2);
		j++;
	}
}


int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,800, 800, "Practice in MiniLibX");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


	draw_all_windo(&img, 0x00FF0000);
	//draw_line(&img, 0x00FF00);
	//draw_square(&img, 0x00FF0000,  0x00FF00);
	draw_trinagle(&img, 0x000000FF, 0x0000FF00);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, eshap, &img);
	mlx_hook(mlx_win, 17, 0, x_close, NULL);
	mlx_loop(mlx);

	return (0);
}
