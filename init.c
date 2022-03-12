#include "fdf.h"

int render_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	//if the window is closed we don't want to draw
	if (fdf->win_ptr == NULL)
		return (MLX_ERROR);
	// while (i < fdf->map.line_count)
	// {
	// 	j = 0;
	// 	while (j < fdf->map.word_count)
	// 	{
	// 		draw_line(fdf, i, j, i + 1 , j, Red);
	// 		draw_line(fdf, i, j , i , j+1, Red);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 500, 500, Red, "	Test Rendering");
	return (0);
}

int	init_win(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (MLX_ERROR);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,WINDOW_WIDTH, WINDOW_HEIGHT,"FDF");
	if (fdf->win_ptr == NULL)
	{
		free(fdf);
		return (MLX_ERROR);
	}
	mlx_loop_hook(fdf->mlx_ptr, render_map, &fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}