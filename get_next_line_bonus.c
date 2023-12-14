/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:29:56 by oait-bou          #+#    #+#             */
/*   Updated: 2023/12/10 16:30:04 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*chek_rest(char *str)
{
	int		i;
	int		b;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	b = ft_strlen(str) - i;
	str2 = malloc((b + 1) * sizeof(char));
	i++;
	while (j < b)
	{
		str2[j++] = str[i++];
	}
	str2[b] = '\0';
	return (str2);
}

char	*ft_free(char *tr)
{
	free(tr);
	return (NULL);
}

char	*ft_read_line(int fd, char *tr)
{
	char	*str;
	char	*buf;
	ssize_t	p;

	p = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (p > 0 && check_line(tr) != 1)
	{
		p = read(fd, buf, BUFFER_SIZE);
		if (p > 0)
		{
			buf[p] = '\0';
			str = ft_strjoin(tr, buf);
			free(tr);
			tr = str;
		}
	}
	free(buf);
	if (p == -1)
		return (ft_free(tr));
	return (tr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tr[1024];
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd > 1024)
		return (NULL);
	if (tr[fd] == NULL)
	{
		tr[fd] = malloc(1);
		tr[fd][0] = '\0';
	}
	tr[fd] = (ft_read_line(fd, tr[fd]));
	if (tr[fd] == NULL || tr[fd][0] == '\0')
	{
		free(tr[fd]);
		tr[fd] = NULL;
		return (NULL);
	}
	line = ft_line(tr[fd]);
	ptr = chek_rest(tr[fd]);
	free(tr[fd]);
	tr[fd] = ptr;
	return (line);
}

int	main(void)
{
	int	nb;

	nb = open("omar.text", O_CREAT | O_RDWR);
    int a = open("omar1.text", O_CREAT | O_RDWR,0777);
    int c = open("omar2.text", O_CREAT | O_RDWR,0777);
	printf("%d, %d, %d\n", nb,a,c);
	printf("%s", get_next_line(c));
	printf("%s", get_next_line(a));
	printf("%s", get_next_line(nb));
	close(nb);
	return (0);
}
