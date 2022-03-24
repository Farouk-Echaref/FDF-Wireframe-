/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 03:54:52 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/24 03:56:11 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	clear_image(t_fdf *fdf)
{
	int		i;
	int		j;
	char	*pixel;

	j = 0;
	while (j < WINDOW_HEIGHT)
	{
		i = 0;
		while (i < WINDOW_WIDTH)
		{
				pixel = fdf->img->addr + ((fdf->img->line_len * j)
					+ i * (fdf->img->bpp / 8));
				*(int *)pixel = Black;
				i++;
		}
		j++;
	}
}

int	redraw(t_fdf *fdf)
{
	clear_image(fdf);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->img->img_ptr, 0, 0);
	return (0);
}
