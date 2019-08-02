/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:45:52 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/02 05:28:36 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H
# include "./libft/libft.h"

  typedef struct  s_node
 {
	 int     x;
	 int     y;
	 char    *str;
	 struct s_node   *next;
}               t_node;
t_node	*ft_newmode(int	x, int	y, char *str);
void	ft_addnode(t_node	**list, t_node	*new);
int     char_counter(char *line, char   c);
#endif

