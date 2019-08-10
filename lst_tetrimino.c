/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 03:35:30 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/09 16:21:24 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node		*ft_newnode(int x, int y)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->x = x;
	node->y = y;
	node->str = ft_strnew(0);
	node->next = NULL;
	return (node);
}

void		ft_dellst(t_node **lst)
{
	t_node	*temp;

	while ((*lst))
	{
		temp = (*lst)->next;
		ft_strdel(&(*lst)->str);
		free(*lst);
		*lst = NULL;
		(*lst) = temp;
	}
	free(temp);
	temp = NULL;
}

void	ft_mapdel(char	**str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_strdel(&str[i++]);
	free (str);
	str = NULL;
}
