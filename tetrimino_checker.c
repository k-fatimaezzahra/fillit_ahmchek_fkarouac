/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:12:28 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/07 18:17:21 by fkarouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		char_counter(char *line, char c)
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

int		file_reader(int fd, char **str)
{
	char	line[22];
	int		ret;

	ret = 0;
	if (fd < 0)
		return (-1);
	ret = read(fd, line, 21);
	line[ret] = '\0';
	if (ret == 0 && line[20] == '\n')
		return (-1);
	if (line[20] != '\n' && line[20] != '\0' && ret)
		return (-1);
	*str = ft_strdup(line);
	return (ret);
}

int		cnx_checker(char *str)
{
	int		i;
	int		signal;

	i = 0;
	signal = 0;
	while (str[i])
	{
		if (str[i] == '#' && str[i + 5] == '#' && (i + 5) <= (int)ft_strlen(str))
			signal = signal + 2;
		if (str[i] == '#' && str[i + 1] == '#' && (i + 1) <= (int)ft_strlen(str))
			signal = signal + 2;
		i++;
	}
	ft_putstr("signal = ");
	ft_putnbr(signal);
	ft_putchar('\n');
	if (signal == 6 || signal == 8)
		return (1);
	return (0);
}

int		tetrimino_checker(int fd, t_node **start)
{
	int		i;
	int		ret;
	char	*str;

	i = 0;
	while ((ret = file_reader(fd, &str)) > 0)
	{
		i = 0;
		while (str[i])
		{
			i = i + 4;
			if (str[i] != '\n' && i <= 19)
			{
				ft_putendl("A");
				return (-1);
			}
			i++;
		}
		if (char_counter(str, '#') != 4 || char_counter(str, '.') != 12
				|| !cnx_checker(str))
			return (-1);
		if (*start == NULL)
			*start = ft_newnode(0, 0, str);
		else
			ft_addnode(start, ft_newnode(0, 0, str));
	}
	return (ret);
}
