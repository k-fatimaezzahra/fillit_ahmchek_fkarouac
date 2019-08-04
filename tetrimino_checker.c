/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:19:27 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/04 05:27:30 by ahmcherk         ###   ########.fr       */
/*   Updated: 2019/08/02 01:30:21 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>
int		char_counter(char *line, char	c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == c)
			j++;
		i++;
	}
	return (j);
}

int     file_reader (int fd,char **str)
{
	char    line[22];
	char    *tmp;
	int     ret;

	ret = 0;
	if (fd < 0 || fd > 4864)
		return (-1);
	ret = read(fd, line, 21);
	if (ret == 0 && line[20] == '\n')
		return (-1);
	line[ret] = '\0';
	if (line[20] != '\n' && line[20] != '\0')
		return (-1);
	tmp = *str;
	*str = ft_strdup(line);
	ft_strdel(&tmp);
	return (ret);
}

int		tetrimino_checker(int	fd)
{
	int		i;
	int		j;
	int		ret;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(0)))
		return (-1);
	while ((ret = file_reader(fd, &str)) > 0)
	{
		i = 0;
		while (str[i])
		{
			i = i + 4;
			if (str[i] != '\n' && i <= 19)
				return (-1);
			i++;
		}
		if (char_counter(str, '#') != 4 || char_counter(str, '.') != 12)
			return (-1);
	}
	return (ret);
}

int main ()
{
	int		fd;
	char	*str;
	int		ret;

	str = ft_strnew(0);
	fd = open ("test", O_RDONLY);
	printf("%d\n",tetrimino_checker(fd));
	if (!ret && ret)
	close (fd);
	
	return (0);
}
