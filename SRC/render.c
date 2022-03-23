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

#include "../Inlcude/fdf.h"

int draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	double	deltaX;
	double	pixelX;
	double	pixelY;
	double	deltaY;
	int		pixels;

	zoom(fdf, &p1, &p2);
	if (fdf->iso == 1)
	{
		iso(&p1.x, &p1.y, p1.z);
		iso(&p2.x, &p2.y, p2.z);
	}
	shifting(fdf, &p1, &p2);
	deltaX = p2.x - p1.x;
	deltaY = p2.y - p1.y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = p1.x;
	pixelY = p1.y;
	while(pixels)
	{
		img_pixel_put(fdf, pixelX, pixelY, p2.color);
		pixelX +=	deltaX;
		pixelY +=	deltaY;
		--pixels;
	}
	return (1);
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
				plot_point(&p2, p1.x + 1, p1.y, fdf->map_colors[p1.y][p1.x]);
				draw_line(fdf, p1, p2);
			}
			if (p1.y < fdf->line_count - 1)
			{
				plot_point(&p2, p1.x, p1.y + 1, fdf->map_colors[p1.y][p1.x]);
				draw_line(fdf, p1, p2);
			}
			p1.x++;
		}
		p1.y++;
	}
	return (0);
}