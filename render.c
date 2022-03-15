#include "fdf.h"

int draw_line(t_fdf *fdf, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX;
	double	deltaY;
	int pixels;


	//	delta = sqrt((endX - beginX)*(endX - beginX) + (endY - beginY)*(endY - beginY));

	//To get the direction of the line in 2D space, you can end - begin:
	deltaX = endX - beginX;
	deltaY = endY - beginY;

	//we can approximate the number of pixels we’ll have to draw along the way
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	//The reason why we used double was so we can divide the total distance of our line by the amount of pixels we’ll have to draw.
	//so we get the coordinates of every pixel;
	deltaX /= pixels;
	deltaY /= pixels;

	double pixelX = beginX;
	double pixelY = beginY;

	while(pixels)
	{
		mlx_pixel_put(fdf->mlx_ptr,fdf->win_ptr, pixelX,pixelY,color);
		pixelX +=	deltaX;
		pixelY +=	deltaY;
		--pixels;
	}
	return (1);
}

//ISO Projection
// static void iso(int *x, int *y, int z)
// {
//     int previous_x;
//     int previous_y;

//     previous_x = *x;
//     previous_y = *y;
//     *x = (previous_x - previous_y) * cos(0.523599);
//     *y = -z + (previous_x + previous_y) * sin(0.523599);
// }

// int render_map(t_fdf *fdf)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	//if the window is closed we don't want to draw
// 	if (fdf->win_ptr == NULL)
// 		return (MLX_ERROR);
// 	// while (i < fdf->map.line_count)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < fdf->map.word_count)
// 	// 	{
// 	// 		draw_line(fdf, i, j, i + 1 , j, Red);
// 	// 		draw_line(fdf, i, j , i , j+1, Red);
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// 	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 500, 500, Red, "	Test Rendering");
// 	return (0);
// }