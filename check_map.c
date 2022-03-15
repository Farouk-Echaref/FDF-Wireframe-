#include "fdf.h"

int	ft_check_map(char *path)
{
	int		fd;
	char	*line;
	char 	*ptr;

	fd = open(path,O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	ptr = get_next_line(fd);
	while(ptr)
	{
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	if (!ft_strchr(line, 'x'))
	{
		free(line);
		return (1);
	}
	return (0);
}