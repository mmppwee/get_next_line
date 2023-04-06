/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:35:57 by pwareepo          #+#    #+#             */
/*   Updated: 2023/04/06 18:15:11 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_returnline(const char *s)
{
	int	len;
	int	i;
	char	*line;

	len = 0;
	while (len != '\n' && len != '\0')
		len++;
	line = malloc (sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	static char	*temp;
	int	i;
	int	n;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (temp != NULL)
		buf = ft_strjoin (temp, buf);
	while (1)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i == 0)
			return (NULL);
		n = ft_check (buf, '\0');
		if (n == 0)
			break;
		n = ft_check (buf, '\n');
		if (n == 0)
			break;
	}
	temp = ft_strchr (buf, '\n');
	line = ft_returnline (buf);
	free (buf);
	return (line);
}

#include <stdio.h>
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
//  int main()
//  {
// 	printf("%d", ft_check("hsahiwikkl", 'o'));
//  }
int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
