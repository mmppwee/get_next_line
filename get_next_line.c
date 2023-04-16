/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:35:57 by pwareepo          #+#    #+#             */
/*   Updated: 2023/04/16 18:24:42 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
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
	// printf("len: %d\n", len);
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
	char	*keep = NULL;
	static char	*temp = NULL;
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
		// printf("buf: %s\n", buf);
		if (i == 0)
		{
			if (ft_check(buf) == 1)
			{
				line = ft_returnline(buf);
				printf("line: %s\n", line);
				return(free(buf), line);
			}
			return (free(buf), NULL);
		}
		if (keep == NULL)
			keep = ft_strdup(buf);
		else
			{
				// printf("buf: %s", buf);
				char *keepstr;
				keepstr = keep;
				// printf("keepstr:[%s]", keepstr);
				keep = ft_strjoin (keepstr, buf);
				free(keepstr);
				printf("keep: %s\nbuf: %s\n", keep, buf);
				// return (free(keep), free(buf), NULL);
			}
		//printf("*keep: [%s]\n", keep);
		n = ft_check (buf);
		// printf("check: %d", n);
		// printf("address: %p", buf);
		if (n == 0)
			break;
		// printf("wl- keep:%s, buf:%s, temp:%s", keep, buf, temp);
		// else if (n == 1)
		// 	{
		// 		line = ft_returnline(buf);
		// 		return (free(buf), line);
		// 	}
		printf("temp: %s\n", temp);
		// printf("aabba\n");
	}
	temp = ft_strchr (keep, '\n');
	printf("temp: %s\n", temp);
	// printf("keep===: %s", keep);
	// printf("exit--\n");
	line = ft_returnline (keep);
	printf("line: %s\n", line);
	// // printf("*temp:%s, *keep:%s", temp, keep);
	free (buf);
	free (keep);
	// free(temp);
	return (line);
	// return(NULL);
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
int main()//(int ac, char **av)
{
	int fd;
	// char *s;
	// char *a;
	// printf("Hello");
	// fd = open(av[1], O_RDONLY);
	fd = open("41_no_nl", O_RDONLY);
	// s = get_next_line(fd);
	// while (s != NULL)
	// {
	// 	free(s);
	// 	s = get_next_line(fd);
	// }
	// free(s);
	// a = get_next_line(fd);
	// printf("gnl: %s", a);
	printf("gnl:%s", get_next_line(fd));
	// printf("gnl:%s", get_next_line(fd));
	// printf("gnl:%s", get_next_line(fd));
	// printf("gnl:%s", get_next_line(fd));
	// printf("gnl:%s", get_next_line(fd));
	// free (a);

// 	close(fd);
}
