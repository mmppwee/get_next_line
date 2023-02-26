/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwareepo <pwareepo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:36:51 by pwareepo          #+#    #+#             */
/*   Updated: 2023/02/26 17:30:10 by pwareepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen (const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
int	*ft_findindex(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
