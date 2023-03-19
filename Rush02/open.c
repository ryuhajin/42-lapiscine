/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 22:00:34 by dayou             #+#    #+#             */
/*   Updated: 2023/02/26 22:00:57 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	buff[1024];

	fd = open("./numbers.dict", O_RDONLY);
	if (fd > 0)
	{
		read(fd, buff, 1024);
		puts(buff);
		close(fd);
	}
	return (0);
}
