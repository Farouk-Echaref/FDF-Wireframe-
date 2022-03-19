#include "fdf.h"

int draw(t_fdf *fdf)
{
	int	i;
	int	j;
	int index_j;
	int index_i;
	
	i = 0;
	j = 0;
	index_j = 0;
	while (index_j < fdf->line_count)
	{
		index_i = 0;
		while (index_i < fdf->word_count)
		{
			if (index_i != fdf->word_count - 1 )
				draw_line(fdf,i + 550,j + 150,i + 550 + 30,j + 150, fdf->map_values[index_j][index_i], fdf->map_values[index_j][index_i + 1], GREEN_PIXEL);
			if (index_j != fdf->line_count - 1 )
				draw_line(fdf,i + 550,j + 150,i + 550,j + 150 + 30, fdf->map_values[index_j][index_i], fdf->map_values[index_j + 1][index_i], GREEN_PIXEL);
			i += 30;
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
		init_win(fdf);
		draw(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
		// work on the line drawing algo , zoom , rotation for one frame , and then change other frames for other maps
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
