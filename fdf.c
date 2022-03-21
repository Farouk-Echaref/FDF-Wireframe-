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
				draw_line(fdf,i + 550,j + 150,i + 550 + 3,j + 150, fdf->map_values[index_j][index_i], fdf->map_values[index_j][index_i + 1], GREEN_PIXEL);
			if (index_j != fdf->line_count - 1 )
				draw_line(fdf,i + 550,j + 150,i + 550,j + 150 + 3, fdf->map_values[index_j][index_i], fdf->map_values[index_j + 1][index_i], GREEN_PIXEL);
			i += 3;
			index_i++;
		}
		i = 0;
		j += 3;
		index_j++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf 	*fdf;
	int	check;

	if (argc == 2)
	{
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
			return (1);
		fdf->img = (t_img *)malloc(sizeof(t_img));
		if (!fdf->img)
			return (1);
		check = ft_parse(argv[1], fdf);
		if (check < 0)
			return (ERROR);
		init_win(fdf);
		draw(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
		mlx_hook(fdf->win_ptr, ON_KEYDOWN, 0, esc_press, &fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_printf("Usage: ./fdf map_name \n");
	return (0);
}
