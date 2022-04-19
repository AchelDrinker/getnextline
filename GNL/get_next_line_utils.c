/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:22:55 by humartin          #+#    #+#             */
/*   Updated: 2022/04/13 12:46:54 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	tmp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!(tmp))
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		tmp[i + n] = s2[n];
		n++;
	}
	tmp[i + n] = '\0';
	free ((char *)s1);
	return (tmp);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*call;
	size_t	cur;

	call = malloc(count * size);
	if (!call)
		return (0);
	cur = -1;
	while (++cur < size * count)
		call[cur] = 0;
	return (call);
}
