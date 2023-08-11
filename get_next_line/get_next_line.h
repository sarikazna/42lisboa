/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:46:13 by srudman           #+#    #+#             */
/*   Updated: 2023/08/11 21:28:52 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// fcntl.h needed for flags in the open() function

char	*get_next_line(int fd);
char	*ft_get_text(int fd, char *text);
char	*ft_extract_line(char *text);
char	*ft_keep_text_remainder(char *text);
char	*ft_strjoin_modified(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif