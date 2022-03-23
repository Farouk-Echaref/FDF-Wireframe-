/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:56 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/22 18:09:02 by fech-cha         ###   ########.fr       */
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
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->img);
	free(fdf);
	exit(0);
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
	else if(keynum == ARROWUP)
		fdf->posy -= 20;
	else if(keynum == ARROWDOWN)
		fdf->posy += 20;
	else if(keynum == ARROWRIGHT)
		fdf->posx += 20;
	else if(keynum == ARROWLEFT)
		fdf->posx -= 20;
	else if (keynum == ESC_KEY)
		clear_data(fdf);
	redraw(fdf);
	return (0);
}



// int esc_press(int key, t_fdf *fdf)
// {
// 	if (key == ESC_KEY)
// 	{
// 		mlx_destroy_image(fdf->mlx_ptr, fdf->img);
// 		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
// 		ft_free_arr(fdf->fdf_colors, fdf->line_count);
// 		ft_free_arr(fdf->fdf_values, fdf->line_count);
// 		free(fdf->img);
// 		free(fdf);
// 		exit(1);
// 	}
// 	return (0);
// }
