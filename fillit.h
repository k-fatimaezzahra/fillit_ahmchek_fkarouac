/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:45:52 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/09 21:13:23 by ahmcherk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>

  typedef struct  s_node
 {
	 int     x;
	 int     y;
	 char    *str;
	 struct s_node   *next;
}               t_node;
t_node	*ft_newnode(int	x, int	y);
int     char_counter(char *line, char   c);
void	ft_dellst(t_node **lst);
int     tetrimino_checker(int fd, t_node **start);
int     char_counter(char *line, char c);
char    **map_creator(t_node **list);
char	**ft_map( int size);
int     ft_tetriminos(t_node **list);
int     ft_mapsize(int n);
void	ft_mapdel(char	**str);
void	ft_set(t_node	**start);
#endif

