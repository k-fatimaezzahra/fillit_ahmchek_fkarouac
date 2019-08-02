/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:19:27 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/07/30 19:38:34 by fkarouac         ###   ########.fr       */
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

int		file_reader (int fd, char *tetrimino)
{
	char	*tmp;
	char	*line;
	int		ret;
    
	if (!(tetrimino = malloc(sizeof( char * 21))))
		return (-1);
	tmp = tetrimino;
	tetrimino = ft_strdup("\0");
	ft_strdel(&tmp);
	while ( ft_strlen(tetrimino) < 21 )
	{	tmp = tetrimino;
		ret = get_next_line(fd, &line);
		tetrimino = ft_strjoin(tetrimino, line);
		ft_strdel(&tmp);
	}
	return (ret);
}

int		tetrimino_checker(int	fd)
{
	char	*line;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0' && ++k)
		{
			if (!(get_next_line(fd, &line)) ||
				line[0] == '\0' || i != 4 || j != 4)
				return (-1);
			j = 0;
			i = 0;
		}
		if ((char_counter(line ,'.') + char_counter(line,'#') != 4)
			|| (ft_strlen(line) != 4))
			return (-1);
		j = j + char_counter(line, '#');
		i++;
		ft_strdel(&line);
	}
	return (++k);
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
