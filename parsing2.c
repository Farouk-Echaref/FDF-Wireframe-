#include "fdf.h"

void copy_data(int *value, char *line, t_fdf *fdf, int *color)
{
	char	**tmp;
	int	i;
	int	*check;

	i = 0;
	tmp = ft_split(line, ' ');
	while(i < fdf->word_count)
	{
		value[i] = ft_atoi(tmp[i]);
		check = function_check_x(tmp[i], ',');
		if (check == 0)
			color[i] == "White";
		else
			color[i] == hex2int(tmp[i]);
		i++;
	}
	ft_free_double_array(tmp, fdf->word_count);
}

int parse(t_fdf *fdf, char *path)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fdf->line_count = count_lines(path, fdf);
	if (fdf->line_count == -1)
 		return (-1);
	fdf->value = malloc(sizeof(int *) * (fdf->line_count + 1));
	fdf->color = malloc(sizeof(int *) * (fdf->line_count));
	fd = open(path, O_RDONLY);
	while(i < fdf->line_count)
	{
		fdf->value[i] = malloc(sizeof(int) * (fdf->word_count));
		fdf->color[i] = malloc(sizeof(int) * (fdf->word_count));
		line = get_next_line(fd);
		copy_data(fdf->value[i], line, fdf, fdf->color[i]);
		free(line);
		i++;
	}
	fdf->value[i] = NULL;
	close(fd);
	return (0);
}
