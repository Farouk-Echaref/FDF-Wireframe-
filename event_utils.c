#include "fdf.h"

int esc_press(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		//free(fdf->img);
		//free(fdf);
		exit(1);
	}
	return (0);
}