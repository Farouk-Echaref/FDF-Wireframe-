#include "fdf.h"

void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	zoom(t_fdf *fdf, int *x, int *y, int z, int lc, int wc)
{
	z = fdf->map_values[lc][wc];
	z *= fdf->elevation;
	*x *= fdf->zoom;
	*y *= fdf->zoom;
}

void	shifting(t_fdf *fdf, int *x, int *y)
{
	*x += fdf->posx;
	*y += fdf->posy;
}