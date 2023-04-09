/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:35:57 by pwareepo          #+#    #+#             */
/*   Updated: 2023/04/09 18:08:44 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <stdio.h>

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_returnline(const char *s)
{
	int	len;
	int	i;
	char	*line;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	len = i;
	// printf("len:%d\n", len);
	line = malloc (sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	// printf("line:%s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buf;
	static char	*keep;
	static char	*temp;
	int	i;
	int	n;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	if (temp != NULL)
		keep = ft_strdup(temp);
	while (1)
	{
		i = read (fd, buf, BUFFER_SIZE);
		if (i == 0)
			return (NULL);
		if (keep == NULL)
			keep = ft_strdup(buf);
		else if (keep != NULL)
			keep = ft_strjoin (keep, buf);
		n = ft_check (buf);
		if (n == 0)
			break;
		// else if (n == 1)
		// 	{
		// 		line = ft_strdup(buf);
		// 		return (line);
		// 	}
	}
	temp = ft_strchr (keep, '\n');
	line = ft_returnline (keep);
	free (buf);
	return (line);
}

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
// int main()
// {
// 	int fd;
// 	fd = open("test.txt", O_RDONLY);
// 	printf("gnl:%s", get_next_line(fd));
// 	printf("gnl:%s", get_next_line(fd));
// 	printf("gnl:%s", get_next_line(fd));
// 	printf("gnl:%s", get_next_line(fd));


// 	close(fd);
// }
