#include "fdf.h"

void	check_fd(int fd)
{
	if (fd < 0)
	{
			ft_printf("Error opening the file, %s\n", strerror(errno));
			exit(FILE_ERROR);
	}
}

char	*ft_strchr2(char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (ch == 0)
		return ((char *)s + ft_strlen(s));
	while (1)
	{
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			break ;
		++s;
	}
	return (NULL);
}

void	ft_free_double_array(char **str, int c)
{
	int i;

	i = 0;
	while(i < c)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	word_count(char *s, char c)
{
	int	state;
	int	count;

	count = 0;
	state = OUT;
	while (*s)
	{
		if (*s == c)
			state = OUT;
		else if (state == OUT)
		{
			count++;
			state = IN;
		}
		s++;
	}
	return (count);
}

int count_lines(char *path, int *a)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(path,O_RDONLY);
	check_fd(fd);
	line = get_next_line(fd);
	*a = word_count(line, ' ');
	while(line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}