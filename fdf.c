#include "fdf.h"

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
			return (1);
		init_win(fdf);
		draw(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->img_ptr, 0, 0);
		// mlx_hook(fdf->win_ptr, ON_KEYDOWN, 0, esc_press, &fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_printf("Usage: ./fdf map_name \n");
	return (0);
}
