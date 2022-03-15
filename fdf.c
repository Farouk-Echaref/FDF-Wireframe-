#include "fdf.h"

// int encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

int main(int argc, char **argv)
{
	t_fdf 	*fdf;
	int x,y;

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
		x = i + 200;
		y = j + 200;
		while (index_j < fdf->map.line_count)
		{
			index_i = 0;
			while (index_i < fdf->map.word_count)
			{
				if (index_i != fdf->map.word_count - 1 )
					draw_line(fdf, i + 200, j + 200, i + 200 + 30, j + 200, Red);
				if (index_j != fdf->map.line_count - 1 )
					draw_line(fdf, i + 200, j + 200, i + 200, j + 200 + 30, Red);
				i += 30;
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