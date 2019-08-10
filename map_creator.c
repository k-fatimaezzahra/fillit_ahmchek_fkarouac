/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 07:34:49 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/09 18:24:24 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_nextsqrt(int  nbr)
{
	while (!ft_sqrt(nbr))
		nbr++;
	return (ft_sqrt(nbr));
}

void	ft_charchanger(char *str, char  c)
{
	int     i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = c;
		i++;
	}
}

char	**map_creator(t_node **list)
{
	char	**str;
	t_node	*temp;
	int		i;
	int		next_sqrt;

	i = 0;
	temp = *list;
	next_sqrt = 'A';
	while (temp)
	{
		ft_charchanger(temp->str, next_sqrt);
		next_sqrt++;
		i++;
		temp = temp->next;
	}
	next_sqrt = ft_nextsqrt(i * 4);
	if (!(str = (char**)malloc(sizeof(char*) * (next_sqrt + 1))))
		return (NULL);
	i = 0;
	while (i < next_sqrt)
	{
		str[i] = ft_strnew(next_sqrt + 1);
		ft_memset((void*)str[i], '.', next_sqrt);
		str[i++][next_sqrt] = '\n';
	}
	str[i] = NULL;
	return (str);
}
