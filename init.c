#include "fdf.h"

// int	render (t_fdf *fdf)
// {
// 	mlx_string_put(fdf->mlx_ptr,fdf->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, hex2int("0xFFFFFF"), "Testing this ");
// 	return (0);
// }

// int	init_win(t_fdf *fdf)
// {
// 	fdf->mlx_ptr = mlx_init();
// 	if (!fdf->mlx_ptr)
// 		return (MLX_ERROR);
// 	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,WINDOW_WIDTH, WINDOW_HEIGHT,"FDF");
// 	if (fdf->win_ptr == NULL)
// 	{
// 		free(fdf);
// 		return (MLX_ERROR);
// 	}
// 	mlx_loop_hook(fdf->mlx_ptr, &render, &fdf);
// 		//render(fdf);
// 	mlx_loop(fdf->mlx_ptr);
// 	return (0);
// }