/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:09:11 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/24 03:01:59 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	allocate(t_fdf *fdf)
{
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	fdf->img = (t_img *)malloc(sizeof(t_img));
	if (!fdf->img)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		check;

	if (argc == 2)
	{
		allocate(fdf);
		check = ft_parse(argv[1], fdf);
		if (check < 0)
			return (1);
		init_win(fdf);
		menu();
		draw(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr,
			fdf->win_ptr, fdf->img->img_ptr, 0, 0);
		mlx_key_hook(fdf->win_ptr, key_option, fdf);
		mlx_hook(fdf->win_ptr, 17, 0, close_fdf, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_printf("Usage: ./fdf map_name \n");
	return (0);
}
