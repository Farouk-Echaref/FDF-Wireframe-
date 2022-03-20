#include "fdf.h"


void	ft_parse_white(char *path, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;
	char	**tmp;

	fdf->line_count = count_lines(path, &fdf->word_count);
	fdf->map_values = (int **)malloc(fdf->line_count * sizeof(int *));
	i = 0;
	fd = open(path,O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line && i < fdf->line_count)
	{
		fdf->map_values[i] = (int *)malloc(fdf->word_count * sizeof(int));
		tmp = ft_split(line, ' ', '\n');
		ft_copy_value(fdf->map_values[i],tmp,fdf->word_count);
		ft_free_double(line, tmp, fdf->word_count);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}