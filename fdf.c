#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode)
{
	if(keycode == 53)
		exit(-1);
	return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	main(int ac, char **av)
// {
// 	av = NULL;
// 	if(ac == 1 || ac > 2)
// 	{
// 		printf("please add file args\n");
// 		return 0;
// 	}

// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	t_vars	vars;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "FdF");
// 	img.img = mlx_new_image(mlx, 1920, 1080);

// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	int x = 0,y;
// 	while(x < 115){
// 			y = 0;
// 			while(y < 115){
// 				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// 				y++;
// 			}
// 			x++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_key_hook(mlx_win, key_hook, &vars);
// 	mlx_loop(mlx);
// }
