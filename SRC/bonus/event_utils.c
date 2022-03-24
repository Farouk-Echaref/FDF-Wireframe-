/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:56 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/24 02:53:24 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	close_fdf(t_fdf *fdf)
{
	clear_data(fdf);
	return (0);
}

void	clear_data(t_fdf *fdf)
{
	int	i;

	i = 0;
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	while (i < fdf->line_count)
	{
		free(fdf->map_colors[i]);
		free(fdf->map_values[i]);
		i++;
	}
	free(fdf->map_colors);
	free(fdf->map_values);
	free(fdf->img);
	free(fdf);
	exit(0);
}

void	other_options(int keynum, t_fdf *fdf)
{
	if (keynum == ARROWRIGHT)
		fdf->posx += 20;
	else if (keynum == ARROWLEFT)
		fdf->posx -= 20;
	else if (keynum == ROTATE_RIGHT)
		fdf->theta_x += 0.1;
	else if (keynum == ROTATE_LEFT)
		fdf->theta_x -= 0.1;
	else if (keynum == ROTATE_DOWN)
		fdf->theta_y += 0.1;
	else if (keynum == ROTATE_UP)
		fdf->theta_y -= 0.1;
	else if (keynum == ESC_KEY)
		clear_data(fdf);
}

int	key_option(int keynum, t_fdf *fdf)
{
	if (keynum == ZOOM_IN)
		fdf->zoom += 2;
	else if (keynum == ZOOM_OUT)
		fdf->zoom -= 2;
	else if (keynum == ELEVATE_UP)
		fdf->elevation += 0.3;
	else if (keynum == ELEVATE_DOWN)
		fdf->elevation -= 0.3;
	else if (keynum == 34)
		fdf->iso = 1;
	else if (keynum == 35)
		fdf->iso = 0;
	else if (keynum == ARROWUP)
		fdf->posy -= 20;
	else if (keynum == ARROWDOWN)
		fdf->posy += 20;
	other_options(keynum, fdf);
	redraw(fdf);
	return (0);
}
