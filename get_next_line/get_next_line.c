/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:49:28 by srudman           #+#    #+#             */
/*   Updated: 2023/07/15 17:59:01 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (*s)
// 	{
// 		s++;
// 		len++;
// 	}
// 	return (len);
// }

char	*read_file(int fd)
{
	char	*buf;
	size_t	bytes_read;
	size_t	count;
	size_t	buffer_size;
	
	if (fd == -1)
		return(NULL);
	buf = (char *)malloc(buffer_size + 1);
	if (buf == NULL)
		return (NULL);
	count = 0;
	buffer_size = 1000;
	while(1)
	{
		bytes_read = read(fd, buf, buffer_size);
		buf += bytes_read;
		count += bytes_read;
		if (bytes_read == buffer_size)
			buf = (char *)malloc(10);
		else
		{
			buf[count] = '\0';
			break ;
		}
	}
	*buf = *(buf - count);
	printf("Read line: %s\n\n", buf);
	return (buf);
}

int	main(void)
{
	int	fd;
	fd = open("paragraph_file.txt", O_RDONLY);
	read_file(fd);
	return(0);
}