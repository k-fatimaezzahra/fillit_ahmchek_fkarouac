/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 03:35:30 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/02 03:57:26 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node  *ft_newnode(int x,int y, char *str)
{
	t_node  *node;

	if (!(node = malloc(sizeof(t_node))))
		return (NULL);
	node->next = NULL;
	if (!(node->str = malloc(sizeof(ft_strlen(str) + 1))))
	return (NULL);
	node->x = x;
	node->y = y;
	node->str = ft_strcpy(node->str, str);
	node->next = NULL;
	return (node);
}

void	ft_addnode(t_node **list, t_node *new)
{

}
