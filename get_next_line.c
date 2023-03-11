/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:35:57 by pwareepo          #+#    #+#             */
/*   Updated: 2023/03/11 18:13:25 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	static char	*temp;
	int	i;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (temp != NULL)
		buf = *ft_strjoin (temp, buf);
	i = read (fd, buf, BUFFER_SIZE);
	if (i = 0)
		return (NULL);
	temp = *ft_strchr (buf, '\n');
	line =
	free (buf);
	return (line);
}

// #include <stdio.h>
// int	test()
// {
// 	static int n = 0;
// 	n++;
// 	return (n);
// }
// int main()
// {
// 	static int x;
// 	static int y;
// 	int z;
// 	printf("%d\n%d\n%d", test(), test(), test());
// }
