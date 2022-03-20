#include "fdf.h"

int hex2int(char *hex) 
{
    int	val;
	int	byte;
	int	len;
	int	index;

	index = 0;
	val = 0;
	len = ft_strlen(hex);
	while(index < len && hex[index] != 'x')
		index++;
	index++;
    while (hex[index])
	{
		byte = hex[index]; 
        if (byte >= '0' && byte <= '9')
			byte = byte - '0';
        else if (byte >= 'a' && byte <='f')
			byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F')
			byte = byte - 'A' + 10;
        val = (val << 4) | (byte);
		index++;
    }
    return (val);
}

void ft_copy_hex(int *ar, char **tmp, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		ar[i] = hex2int(*tmp);
		tmp++;
		i++;
	}
}

void	ft_parse_color(char *path, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;
	char	**tmp;

	i = 0;
	fdf->line_count = count_lines(path, &fdf->word_count);
	fdf->map_values = (int **)malloc(fdf->line_count * sizeof(int *));
	fdf->map_colors = (int **)malloc(fdf->line_count * sizeof(int *));
	fd = open(path,O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	while (line && i < fdf->line_count)
	{
		fdf->map_values[i] = (int *)malloc(fdf->word_count * sizeof(int));
		fdf->map_colors[i] = (int *)malloc(fdf->word_count * sizeof(int));
		tmp = ft_split(line , ' ', '\n');
		ft_copy_hex(fdf->map_colors[i], tmp, fdf->word_count);
		ft_copy_value(fdf->map_values[i], tmp, fdf->word_count);
		ft_free_double(line, tmp, fdf->word_count);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

