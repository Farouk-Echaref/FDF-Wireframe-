/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:09:11 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/24 04:33:18 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*allocate(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (fdf == NULL)
		return (NULL);
	fdf->img = (t_img *)malloc(sizeof(t_img));
	if (fdf->img == NULL)
		return (NULL);
	return (fdf);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		check;

	if (argc == 2)
	{
		fdf = allocate();
		check = ft_parse(argv[1], fdf);
		if (check < 0)
			return (1);
		init_win(fdf);
		draw(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr,
			fdf->win_ptr, fdf->img->img_ptr, 0, 0);
		mlx_key_hook(fdf->win_ptr, esc_key, fdf);
		mlx_hook(fdf->win_ptr, 17, 0, close_fdf, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		ft_printf("Usage: ./fdf map_name \n");
	return (0);
}
