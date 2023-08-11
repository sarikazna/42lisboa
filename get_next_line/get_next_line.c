/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:49:28 by srudman           #+#    #+#             */
/*   Updated: 2023/08/11 21:09:13 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	if (!s)
		return (0);
	if (ch == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)); 
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2 && *s2 != '\n')
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
*/

/* study this */
char	*ft_strjoin_modified(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_keep_text_remainder(char *text)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	remainder = (char *)malloc((ft_strlen(text) - i + 1) * sizeof(char));
	if (!remainder)
		return (NULL);
	j = 0;
	while (text[i])
	{
		remainder[j++] = text[++i];
	}
	remainder[j] = '\0';
	free (text);
	return (remainder);
}

char	*ft_extract_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_text(int fd, char *text)
{
	char	*buff;
	int		bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(text, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		text = ft_strjoin_modified(text, buff);
	}
	free(buff);
	return (text);
}

/* In this function I check if fd is okay. 
Then I read from the file and save what was read in variable "text".
I extract line from the text and return it.
But before I return the linke I altert the variable "text" again so 
I only keep the remainer of the text to be used the next time the 
function is called.  */
char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_get_text(fd, text);
	if (!text)
		return (NULL);
	line = ft_extract_line(text);
	text = ft_keep_text_remainder(text);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	char *line;

// 	line = malloc(1);
// 	fd = open("read_error.txt", O_RDONLY);

// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	close(fd);
// 	return (0);
// }
