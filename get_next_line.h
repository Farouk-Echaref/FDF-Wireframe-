/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 23:08:04 by fech-cha          #+#    #+#             */
/*   Updated: 2021/12/20 23:40:53 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 500

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_read_all(char *str, int fd);
char	*ft_free(char *str1, char *str2);
char	*ft_getline(char *str, int *i);
char	*ft_getrest(char *reminder, int *i);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);

#endif 
