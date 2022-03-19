#include "fdf.h"

int	init_win(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (MLX_ERROR);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!fdf->win_ptr)
	{
		free(fdf);
		return (MLX_ERROR);
	}
	fdf->img->img_ptr = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->img_ptr, &fdf->img->bpp, &fdf->img->line_len, &fdf->img->endian);
	return (0);
}