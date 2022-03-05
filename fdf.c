#include "fdf.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
	int		check;
	int		**values;
	t_map 	*map;
	
	if (argc == 2)
	{
		fd = open(argv[1],O_RDONLY);
		if (fd < 0)
		{
			printf("Error opening the file, %s\n", strerror(errno));
			exit(FILE_ERROR);
		}
		// check = ft_check_map(fd);
		// if (check)
		// 	parse_color();
		// else
			//values = ft_parse_values(fd, argv[1]);
		
		// draw();
		map = (t_map *)malloc(sizeof(t_map));
		ft_parse_color(fd, argv[1],map);
		close(fd);
	}
	else
		printf("not enough arguments! \n");
	return (0);
}



// for (int i = 0; i < 11; i++)
		// {
		// 	for (int j = 0; j < 19; j++)
		// 	{
		// 		if (test[i][j] < 9)
		// 			printf("%d  ",test[i][j]);
		// 		else
		// 			printf("%d ",test[i][j]);
		// 	}
		// 	printf("\n");
		// }