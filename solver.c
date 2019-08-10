/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 16:37:50 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/10 03:27:17 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set(t_node	**start)
{
	t_node	*list;
	int		i;
	int		j;
	char	c;

	list = *start;
	c = 0;
	i = 0;
	j = 0;
	while (list)
	{
		j = 0;
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] != '.' && list->str[i] != '\n' && j == 0)
				j = (i % 5) + 1;
			if (j && ((i % 5) + 1) < j && list->str[i] != '\n' && list->str[i] != '.')
				j = (i % 5) + 1;
			i++;
		}
		ft_putnbr(j);
		ft_putchar('\n');
		list = list->next;
	}
}
