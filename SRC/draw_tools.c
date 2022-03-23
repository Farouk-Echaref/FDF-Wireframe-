/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:45 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/22 21:38:41 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inlcude/fdf.h"

void	plot_point(t_point *p, int x, int y, int color)
{
	p->x = x;
	p->y = y;
	p->color = color;
}

void img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *pixel;

	if(x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0)
	{
		pixel = fdf->img->addr + ((fdf->img->line_len * y) + x * (fdf->img->bpp / 8));
		*(int *)pixel = color;
	} 
}

void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	zoom(t_fdf *fdf, t_point *p1, t_point *p2)
{
	p1->z = fdf->map_values[p1->y][p1->x];
	p2->z = fdf->map_values[p2->y][p2->x];
	p1->z *= fdf->elevation;
	p1->x *= fdf->zoom;
	p1->y *= fdf->zoom;
	p2->z *= fdf->elevation;
	p2->x *= fdf->zoom;
	p2->y *= fdf->zoom;
}


void	shifting(t_fdf *fdf, t_point *p1 , t_point *p2)
{
	p1->x += fdf->posx;
	p1->y += fdf->posy;
	p2->x += fdf->posx;
	p2->y += fdf->posy;
}
