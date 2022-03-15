#include "fdf.h"

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

int main(int argc, char **argv)
{
	t_fdf 	*fdf;
	int x,y;
	int i, j;

	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
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
		int index_j = 0;
		int index_i ;
		// x = i + 200;
		// y = j + 200;
		i = 0;
		j = 0;
		while (index_j < fdf->map.line_count)
		{
			index_i = 0;
			x = i + 550;
			y = j + 150;
			while (index_i < fdf->map.word_count)
			{
				if (index_i != fdf->map.word_count - 1 )
					draw_line(fdf, x, y, x + 30, y, fdf->map.map_values[index_j][index_i],Red);
				if (index_j != fdf->map.line_count - 1 )
					draw_line(fdf, x, y, x, y + 30, fdf->map.map_values[index_j][index_i],Red);
				x += 30;
				index_i++;
			}
			i = 0;
			j += 30;
			index_j++;
		}
		//mlx_loop_hook(fdf->mlx_ptr, render, &fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_printf("not enough arguments! \n");
	return (0);
}


// for (int i = 0; i < fdf->map.line_count; i++)
// 		{
// 			for (int j = 0; j < fdf->map.word_count ; j++)
// 			{
// 				if (fdf->map.map_values[i][j] < 9)
// 					printf("%d  ",fdf->map.map_values[i][j]);
// 				else
// 					printf("%d ",fdf->map.map_values[i][j]);
// 			}
// 			printf("\n");
// 		}
