/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:47:36 by dayou             #+#    #+#             */
/*   Updated: 2023/03/02 12:31:55 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_string.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		count_word(char *str, int *charset_check);
void	copy_words(char **split, char *str, int *charset_check, int size);
char	**ft_split(char *str);

char	*alloc_strcat(char *dst, char *src)
{
	size_t	dstsize;
	size_t	srcsize;
	char	*ptr;
	size_t	idx;

	if (dst == 0)
		dstsize = 0;
	else
		dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	ptr = malloc(sizeof(char) * (dstsize + srcsize + 1));
	if (!ptr)
		return (0);
	idx = -1;
	while (++idx < dstsize)
		ptr[idx] = dst[idx];
	idx = -1;
	while (++idx < dstsize + srcsize && src[idx])
		ptr[dstsize + idx] = src[idx];
	ptr[dstsize + srcsize] = 0;
	if (dst)
		free(dst);
	return (ptr);
}

int	read_fd(int fd, char **file)
{
	ssize_t	readsize;
	char	buffer[101];

	while (1)
	{
		readsize = read(fd, buffer, 100);
		if (readsize == -1)
		{
			free(*file);
			return (0);
		}
		buffer[readsize] = 0;
		if (readsize == 0)
			return (1);
		*file = alloc_strcat(*file, buffer);
	}
}

int	read_file(char *filename, char **file)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (read_fd(fd, file) == 1)
	{
		close(fd);
		return (1);
	}
	return (0);
}
