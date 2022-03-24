/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:56 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/24 04:31:03 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	esc_key(int keynum, t_fdf *fdf)
{
	if (keynum == ESC_KEY)
		clear_data(fdf);
	return (0);
}
