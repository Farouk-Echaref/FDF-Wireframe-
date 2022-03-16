#include "fdf.h"

int draw(t_fdf *fdf)
{
	int x,y;
	int i, j;
	int index_j = 0;
	int index_i ;
	// x = i + 200;
	// y = j + 200;
	i = 0;
	j = 0;
	while (index_j < fdf->line_count)
	{
		index_i = 0;
		x = i + 550;
		y = j + 150;
		while (index_i < fdf->word_count)
		{
			//if (index_i != fdf->word_count - 1 )
				draw_line(fdf, x, y, x + 30, y, fdf->map_values[index_j][index_i],Red);
			//if (index_j != fdf->line_count - 1 )
				draw_line(fdf, x, y, x, y + 30, fdf->map_values[index_j][index_i],Red);
			x += 30;
			index_i++;
		}
		i = 0;
		j += 30;
		index_j++;
	}
	//mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf 	*fdf;
	

	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			return (1);
		fdf->img = (t_img *)malloc(sizeof(t_img));
		if (!fdf->img)
			return (1);
		ft_parse(argv[1], fdf);
		fdf->mlx_ptr = mlx_init();
		if (!fdf->mlx_ptr)
			return (MLX_ERROR);
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,WINDOW_WIDTH, WINDOW_HEIGHT,"FDF");
		if (fdf->win_ptr == NULL)
		{
			free(fdf);
			return (MLX_ERROR);
		}
		fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
		fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp, &fdf->img->line_len, &fdf->img->endian);
		draw(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
		//mlx_loop_hook(fdf->mlx_ptr, &draw, &fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_printf("not enough arguments! \n");
	return (0);
}


// for (int i = 0; i < fdf->line_count; i++)
// 		{
// 			for (int j = 0; j < fdf->word_count ; j++)
// 			{
// 				if (fdf->map_values[i][j] < 9)
// 					printf("%d  ",fdf->map_values[i][j]);
// 				else
// 					printf("%d ",fdf->map_values[i][j]);
// 			}
// 			printf("\n");
// 		}
