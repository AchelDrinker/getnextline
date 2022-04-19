/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:43 by mhugueno          #+#    #+#             */
/*   Updated: 2022/04/13 12:52:47 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int		var;
	char	*line;
	char	*tmp;
	char	buf[(BUFFER_SIZE / BUFFER_SIZE) + 1];

	if (BUFFER_SIZE == 0)
		return (NULL);
	var = read(fd, buf, (BUFFER_SIZE / BUFFER_SIZE));
	if ((var < 1) || (fd > 1023) || (fd == -1))
		return (NULL);
	line = ft_calloc(((BUFFER_SIZE) + 1), sizeof(char));
	while (var > 0 && buf[0] != '\n' && buf[0] != '\0')
	{
		tmp = ft_calloc(((BUFFER_SIZE) + 1), sizeof(char));
		tmp[0] = buf[0];
		line = ft_strjoin(line, tmp);
		free (tmp);
		var = read(fd, buf, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buf[0] == '\n')
		line = ft_strjoin(line, "\n");
	if (var == -1)
		return (NULL);
	return (line);
}
