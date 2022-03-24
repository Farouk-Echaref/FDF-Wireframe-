/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:10:04 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/22 18:10:11 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_draw	elem;

	zoom(fdf, &p1, &p2);
	if (fdf->iso == 1)
	{
		iso(fdf, &p1.x, &p1.y, p1.z);
		iso(fdf, &p2.x, &p2.y, p2.z);
	}
	shifting(fdf, &p1, &p2);
	elem.deltax = p2.x - p1.x;
	elem.deltay = p2.y - p1.y;
	elem.pixels = sqrt((elem.deltax * elem.deltax)
			+ (elem.deltay * elem.deltay));
	elem.deltax /= elem.pixels;
	elem.deltay /= elem.pixels;
	elem.pixelx = p1.x;
	elem.pixely = p1.y;
	while (elem.pixels)
	{
		img_pixel_put(fdf, elem.pixelx, elem.pixely, p2.color);
		elem.pixelx += elem.deltax;
		elem.pixely += elem.deltay;
		--elem.pixels;
	}
	return (1);
}

void	_plot_point1(t_point *p1, t_point *p2, t_fdf *fdf)
{
	plot_point(p2, p1->x + 1, p1->y,
		fdf->map_colors[(int)p1->y][(int)p1->x]);
}

void	_plot_point2(t_point *p1, t_point *p2, t_fdf *fdf)
{
	plot_point(p2, p1->x, p1->y + 1,
		fdf->map_colors[(int)p1->y][(int)p1->x]);
}

int	draw(t_fdf *fdf)
{
	t_point	p1;
	t_point	p2;

	p1.y = 0;
	while (p1.y < fdf->line_count)
	{
		p1.x = 0;
		while (p1.x < fdf->word_count)
		{
			if (p1.x < fdf->word_count - 1)
			{
				_plot_point1(&p1, &p2, fdf);
				draw_line(fdf, p1, p2);
			}
			if (p1.y < fdf->line_count - 1)
			{
				_plot_point2(&p1, &p2, fdf);
				draw_line(fdf, p1, p2);
			}
			p1.x++;
		}
		p1.y++;
	}
	return (0);
}
