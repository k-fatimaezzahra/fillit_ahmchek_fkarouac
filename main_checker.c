/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:11:34 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/06 12:13:47 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_node	*start;
	t_node	*list;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_putnbr(tetrimino_checker(fd, &start));
		ft_putchar('\n');
		list = start;
		while (list)
		{
			ft_putstr(list->str);
			list = list->next;
		}
	//	ft_dellst(&list);
		close (fd);
	}
}
