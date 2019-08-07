/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 03:35:30 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/07 17:13:29 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_node		*ft_newnode(int x, int y, char *str)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->x = x;
	node->y = y;
	node->str = ft_strdup(str);
	node->next = NULL;
	return (node);
}

void		ft_addnode(t_node **list, t_node *new)
{
	t_node	*head;

	head = *list;
	if (*list || new)
	{
		while (head->next != NULL)
			head = head->next;
		head->next = new;
	}
	if (head == NULL)
		head = new;
}

void		ft_dellst(t_node **lst)
{
	t_node	*temp;

	while ((*lst))
	{
		temp = (*lst)->next;
		//ft_strdel(&(*lst)->str);
		free(*lst);
		*lst = NULL;
		(*lst) = temp;
	}
	free(temp);
	temp = NULL;
}
