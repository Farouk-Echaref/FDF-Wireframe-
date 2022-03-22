#include "fdf.h"

void img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *pixel;

	if(x < WINDOW_WIDTH && x > 0 && y < WINDOW_HEIGHT && y > 0)
	{
		pixel = fdf->img->addr + ((fdf->img->line_len * y) + x * (fdf->img->bpp / 8));
		*(int *)pixel = color;
	} 
}

int draw_line(t_fdf *fdf, int l_index, int w_index, int beginX, int beginY, int endX, int endY,int z1, int z2, int color)
{
	double	deltaX;
	double	pixelX;
	double	pixelY;
	double	deltaY;
	int		pixels;

	zoom(fdf, &beginX, &beginY, z1, l_index, w_index);
	zoom(fdf, &endX, &endY, z2, l_index, w_index );
	if (fdf->iso == 1)
	{
		iso(&beginX, &beginY, z1);
		iso(&endX, &endY, z2);
	}
	shifting(fdf, &beginX, &beginY);
	shifting(fdf, &endX, &endY);
	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;
	while(pixels)
	{
		img_pixel_put(fdf, pixelX, pixelY, color);
		pixelX +=	deltaX;
		pixelY +=	deltaY;
		--pixels;
	}

	return (1);
}
int draw(t_fdf *fdf)
{
	int index_j;
	int index_i;
	
	index_j = 0;
	while (index_j < fdf->line_count)
	{
		index_i = 0;
		while (index_i < fdf->word_count)
		{
			if (index_i != fdf->word_count - 1 )
				draw_line(fdf,index_j, index_i, index_i ,index_j ,index_i + 1, index_j, fdf->map_values[index_j][index_i], fdf->map_values[index_j][index_i + 1], fdf->map_colors[index_j][index_i]);
			if (index_j != fdf->line_count - 1 )
				draw_line(fdf,index_j, index_i, index_i, index_j, index_i, index_j + 1, fdf->map_values[index_j][index_i], fdf->map_values[index_j + 1][index_i], fdf->map_colors[index_j][index_i]);
			index_i++;
		}
		index_j++;
	}
	return (0);
}