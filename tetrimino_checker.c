/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:19:27 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/02 01:30:21 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
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

int		tetrimino_checker(int	fd)
{
	int		i;
	char	*str;

	if (!(str = ft_strnew(0)))
		return (-1);
	while (file_reader(fd, &str))
	{
		if ()
	}
}

int main ()
{
	int		fd;
	int		a;
	char	buf[3];

	a = 0;
	fd = open ("test", O_RDONLY);
	while (read(fd, buf, 2))
		a++;
	if (buf[1] != '\n')
	{
		ft_putnbr(-1);
		return(-1);
	}
	close (fd);
	fd = open ("test", O_RDONLY);
	ft_putnbr(tetrimino_checker(fd));
	close (fd);
	return (0);
}
