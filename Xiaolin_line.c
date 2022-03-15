#include "fdf.h"

uint32_t encode_rgb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void swap(double *x, double *y)
{
	double tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

// get fractional part of x
double fpart(double x)
{
	return (x - (int)x);
}

//get the remaining fractional part of x
double rfpart(double x)
{
	return (1 - fpart(x));
}

//draw the line
void Xiaolin(t_fdf *fdf, double x1, double y1, double x2, double y2)
{
	int vertical = 0;
	// uint8_t color;
	int color;

	//vertical = ((fabs(y2 - y1)) > (fabs(x2 - x1)));

	//checking if this a vertical or horizental line type
	if (fabs(y2 - y1) > fabs(x2 - x1))
		vertical = 1;
	//make vertical lines horizental
	if (vertical)
	{
		swap(&x1, &y1);
		swap(&x2, &y2);
	}

	//if x is decreasing swap x1 and x2
	if(x2 < x1)
	{
		swap(&x1, &x2);
		swap(&y1, &y2);
	}

	//line WIDTH and HEIGHT
	int dx = (x2 - x1);
	int dy = (y2 - y1);

	//calculating y from x
	double gradient = ((double)dy) / ((double)dx);

	// handle first endpoint. endpoints will be handle seperately. cuz they are thricky.
   // wu's line algorithm can draw lines with non integer start and end. so we need to
   //have an integer to start with.
   int xend = round(x1);

   //some good y for end point this is also an int
   double yend = y1 + gradient * (xend - x1);

   // xgap is simply pixel around integer
   double xgap = rfpart(x1 + 0.5);

   int xpxl1 = xend; //this will be used in the main loop
   int ypxl1 = floor(yend);

   color = encode_rgb(255*(rfpart(yend) * xgap),255, 0, 0);
   if(vertical)
   {
	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)ypxl1, (double)xpxl1, color);
       color = encode_rgb(255*(fpart(yend) * xgap),255, 0, 0);
	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)(ypxl1 + 1) , (double)xpxl1, color);
   }
   else
   {
	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)xpxl1, (double)ypxl1, color);
       color = encode_rgb(255*(fpart(yend) * xgap),255, 0, 0);
       mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)xpxl1, (double)(ypxl1 + 1), color);
   }
   //putPixel(xpxl1, ypxl1,colorAlpha,alpha);
   double intery = yend + gradient; // first y-intersection for the main loop
   // handle second endpoint
   xend = round(x2);
   yend = y2 + gradient * (xend - x2);
   xgap = fpart(x2 + 0.5);
   int xpxl2 = xend;  // this will be used in the main loop
   int ypxl2 = floor(yend);

   //calculate color of pixel based in its distant from logical line.
   color = encode_rgb(255*(rfpart(yend) * xgap),255, 0, 0);
   //following if, elses are for handling vertical and horizental lines:
   if(vertical)
   {
       //first pixel
	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)ypxl2, (double)xpxl2, color);
       //calculate color of pixel based in its distant from logical line.
       color = encode_rgb(255*(fpart(yend) * xgap),255, 0, 0);
       //second pixel
	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)(ypxl2 + 1), (double)xpxl2, color);
   }
   else//same as if.
   {
	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)xpxl2, (double)ypxl2, color);
       color = encode_rgb(255*(fpart(yend) * xgap),255, 0, 0);
	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (double)xpxl2, (double)(ypxl2 + 1), color);
   }
   // main loop. this is where we draw the rest of the line. like end points
   //we need to draw 2 pixel. and their alpha is calculaed from their distance
   //from logical line.
   for (int i=xpxl1+1;i<=xpxl2-1;i++)
   {
	   color = encode_rgb(255*(rfpart(intery)),255, 0, 0);
       if(vertical)
           {
			   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, floor(intery), i, color);
               color = encode_rgb(255*(fpart(intery)),255, 0, 0);
               mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, floor(intery) + 1, i, color);
           }
           else
           {
               mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, floor(intery) , color);
               color = encode_rgb(255*(fpart(intery)),255, 0, 0);
          	   mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, floor(intery) + 1 , color);
           }
           intery = intery + gradient;
       }
}
