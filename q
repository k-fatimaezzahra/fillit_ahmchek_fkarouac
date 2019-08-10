/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:11:34 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/08 18:51:01 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	t_node	*start;
	t_node	*list;
	char	**map;
	int		i;

	i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if ((ret = tetrimino_checker(fd, &start)) >= 0)
		{
			list = start;
			while (list)
			{
				ft_putstr(list->str);
				list = list->next;
			}
		}
			//	ft_dellst(&start);
				//list = start;
				//map = map_creator(&start);
				ft_dellst(&start);
		
	/*	while (map[i])
		{
			//ft_putendl(map[i]);
			i++;
		}
		}*/
	/*	//else if (start)
		//	ft_dellst(&start);
		printf("am i even here\n");
		i = ft_tetriminos(&start);
		printf("tetriminos i = %d \n",i);
		i = ft_mapsize(i * 4);
		printf("map_size i = %d \n",i);
	//	map = ft_map(i);
*/
		close (fd);
}
	return 0;
}
