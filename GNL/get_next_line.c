/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:22:34 by humartin          #+#    #+#             */
/*   Updated: 2022/04/13 12:22:41 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*str;
	int		nbr;

	buf = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	str = NULL;
	nbr = read(fd, buf, (BUFFER_SIZE / BUFFER_SIZE));
	if (nbr > 0)
		str = ft_calloc(((BUFFER_SIZE / BUFFER_SIZE) + 1), sizeof(char));
	while (nbr > 0 && buf[0] != '\n')
	{
		str = ft_strjoin(str, buf);
		nbr = read(fd, buf, (BUFFER_SIZE / BUFFER_SIZE));
	}
	if (buf[0] == '\n')
		str = ft_strjoin(str, "\n");
	free (buf);
	return (str);
}
