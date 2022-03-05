#include "fdf.h"


static int	count_length(char *s, char c, int i)
{
	int	counter;

	counter = 0;
	while (s[i] && s[i] != c)
	{
		counter++;
		i++;
	}
	return (counter);
}

static char	**free_arr(char **str, int j)
{
	while (j)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

char	*ft_start(int *i, int *j, int *k, const char *s)
{
	*i = 0;
	*j = 0;
	*k = 0;
	if (!s)
		return (0);
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	if (!ft_start(&i, &j, &k, s))
		return (NULL);
	new = (char **)malloc((word_count((char *)s, c) + 1)
			* sizeof(char *));
	if (!new)
		return (NULL);
	while (s[i] && j < word_count((char *)s, c))
	{		
		new[j] = (char *)malloc(count_length((char *)s, c, i) + 1);
		if (!new[j])
			return (free_arr(new, j));
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			new[j][k++] = s[i++];
		new[j++][k] = '\0';
		k = 0;
	}
	new[j] = NULL;
	return (new);
}