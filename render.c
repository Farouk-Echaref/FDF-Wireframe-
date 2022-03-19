#include "fdf.h"

// int encode_rgb(int b, int g, int r, int a)
// {
// 	//return (b | g >> 8 | r >> 16 | a >> 24);
//     //return (a >> 24) | ((r & 255) >> 16) | ((g & 255) >> 8) | (b & 255);
//     return (a << 24 | r << 16 | g << 8 )
// }

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void img_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char *pixel;

	pixel = fdf->img->addr + ((fdf->img->line_len * y) + x * (fdf->img->bpp / 8));
	*(int *)pixel = color; 
}

int draw_line(t_fdf *fdf, int beginX, int beginY, int endX, int endY,int z1, int z2, int color)
{
	double	deltaX;
	double	deltaY;
	int pixels;

	iso(&beginX, &beginY, z1);
	iso(&endX, &endY, z2);
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
		img_pixel_put(fdf, pixelX, pixelY, color);
		pixelX +=	deltaX;
		pixelY +=	deltaY;
		--pixels;
	}
	return (1);
}