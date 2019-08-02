/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_file_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 00:24:54 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/02 03:05:23 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
int		file_reader (int fd,char **str)
{
	char    line[22];
	char    *tmp;
	int		ret;

     if (fd < 0 || fd > 4864)
		 return (-1);
	 ret = read(fd, line, 21);
	 line[ret] = '\0';
	 if (!ret && line[19] != '\n')
		 return (-1);
	 if (line[20] != '\n' && line[20] != '\0')
		 return (-1);
	 tmp = *str;
	 *str = ft_strdup(line);
	 ft_strdel(&tmp);
	return (ret);
}

int main(int ac, char **av)
{
	ac = 1;
	int fd;
	int ret;
	char *str;

	str = ft_strnew(0);
	fd = open(av[1], O_RDONLY);
	while ((ret = file_reader(fd, &str)) >= 0)
	{
		ft_putstr(str);
	}
	return (0);
}
