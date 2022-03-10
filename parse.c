#include "fdf.h"

void	ft_parse(char *path, t_fdf *fdf)
{
	if (ft_check_map(path))
		  	ft_parse_color(path, fdf);
	else
			ft_parse_white(path, fdf);
}