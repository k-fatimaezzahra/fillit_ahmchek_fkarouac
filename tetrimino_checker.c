/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:12:28 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/09 15:58:32 by ahmcherk         ###   ########.fr       */
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

void	ft_strdupfree(char **dest, char *src)
{
	char	*temp;

	temp = *dest;
	*dest = ft_strdup(src);
	ft_strdel(&temp);
}

int		file_reader(int fd, char **str)
{
	char		line[22];
	static char	*tmp;
	int			ret;

	ret = 0;
	if (fd < 0)
		return (-1);
	ret = read(fd, line, 21);
	line[ret] = '\0';
	if (line[20] != '\n' && line[20] != '\0' && ret)
		return (-1);
	ft_strdupfree(str, line);
	if (!ret)
	{
		if (tmp[20] == '\n')
		{
			ft_strdel(&tmp);
			return (-1);
		}
		ft_strdel(&tmp);
	}
	else
		ft_strdupfree(&tmp, *str);
	return (ret);
}

int		cnx_checker(char *str)
{
	int			i;
	int			signal;
	static int	count;

	i = 0;
	signal = 0;
	count++;
	if (count > 26)
		return (0);
	while (str[i])
	{
		if (str[i] == '#' && str[i + 5] == '#' && (i + 5) <= (int)ft_strlen(str))
			signal = signal + 2;
		if (str[i] == '#' && str[i + 1] == '#' && (i + 1) <= (int)ft_strlen(str))
			signal = signal + 2;
		i++;
	}
	if (signal == 6 || signal == 8)
		return (1);
	return (0);
}

int		tetrimino_checker(int fd, t_node **start)
{
	int		i;
	int		ret;
	t_node	*list;

	*start = ft_newnode(0, 0);
	list = *start;
	while ((ret = file_reader(fd, &list->str)) > 0)
	{
		i = -1;
		while (list->str[++i])
		{
			i = i + 4;
			if (list->str[i] != '\n' && i <= 19)
				return (-1);
		}
		if (char_counter(list->str, '#') != 4 || char_counter(list->str, '.')
				!= 12 || !cnx_checker(list->str))
			return (-1);
		list->next = ft_newnode(0, 0);
		list = list->next;
	}
	return (ret);
}
