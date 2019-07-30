/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarouac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:43:53 by fkarouac          #+#    #+#             */
/*   Updated: 2019/07/30 18:43:27 by fkarouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_newnode(int x,int y, char *str)
{
	t_node	*node;

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

