#include "fdf.h"


void	ft_parse_white(char *path, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;
	char	**tmp;

	i = 0;
	fdf->map.line_count = count_lines(path, &fdf->map.word_count);
	fdf->map.map_values = (int **)malloc(fdf->map.line_count * sizeof(int *));
	while (i < fdf->map.line_count)
		fdf->map.map_values[i++] = (int *)malloc(fdf->map.word_count * sizeof(int));

	i = 0;
	fd = open(path,O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line && i < fdf->map.line_count)
	{
		tmp = ft_split(line, ' ');
		ft_copy_value(fdf->map.map_values[i++],tmp,fdf->map.word_count);
		ft_free_double(line, tmp, fdf->map.word_count);
		line = get_next_line(fd);
	}
	close(fd);
}