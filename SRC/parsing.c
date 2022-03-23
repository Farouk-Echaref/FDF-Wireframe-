/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:09:53 by fech-cha          #+#    #+#             */
/*   Updated: 2022/03/22 21:40:43 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inlcude/fdf.h"

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

void copy_data(int *value_arr, int *color_arr, char *line, t_fdf *fdf, int c)
{
	int		i;
	char	*check;
	char	**tmp;

	i = 0;
	tmp = ft_split(line, ' ');
	while(i < fdf->word_count)
	{
		value_arr[i] = ft_atoi(tmp[i]);
		check = ft_strchr2(tmp[i], 'x');
		if (check == NULL)
			color_arr[i] = White;
		else
			color_arr[i] = hex2int(tmp[i]);
		i++;
	}
	ft_free_double_array(tmp, fdf->word_count);
}

int ft_parse(char *path, t_fdf *fdf)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fdf->line_count = count_lines(path, &fdf->word_count);
	if (fdf->line_count == -1)
		return (-1);
	fdf->map_values = (int **)malloc(sizeof(int *) * (fdf->line_count + 1));
	fdf->map_colors = (int **)malloc(sizeof(int *) * (fdf->line_count + 1));
	fd = open(path, O_RDONLY);
	check_fd(fd);
	while(i < fdf->line_count)
	{
		fdf->map_values[i] = (int *)malloc(sizeof(int) * (fdf->word_count));
		fdf->map_colors[i] = (int *)malloc(sizeof(int) * (fdf->word_count));
		line = get_next_line(fd);
		copy_data(fdf->map_values[i],fdf->map_colors[i], line, fdf, fdf->word_count);
		free(line);
		i++;
	}
	fdf->map_values[i] = NULL;
	fdf->map_colors[i] = NULL;
	close(fd);
	return (0);
}
