/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:35:57 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/25 18:27:24 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read (fd, buf, BUFFER_SIZE);
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
