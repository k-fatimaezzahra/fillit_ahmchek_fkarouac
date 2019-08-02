/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmcherk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:45:52 by ahmcherk          #+#    #+#             */
/*   Updated: 2019/08/02 03:34:49 by ahmcherk         ###   ########.fr       */
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
#endif

