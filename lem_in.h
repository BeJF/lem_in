/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:06:38 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/16 13:35:28 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft.h"

typedef struct s_struct
{
	int nb_ants;
	int nb_rooms;
	int	**matrix;

	char	*start_name;
	int		start_nb;

	char	*end_name;
	int		end_nb;
	int		found;

}				t_struct;

typedef	struct	s_list
{
	char	*room_name;
	int		room_nb;
	
	struct s_list *next;
}				t_list;

typedef struct s_path
{
	int *path;
	int path_length;
	struct s_path *next;
}				t_path;

typedef struct s_queue
{
	int room;
	int origin;
	struct s_queue *next;
}				t_queue;

typedef struct s_ants
{
	int name;
	int pos;
	int *path;
	int length;
	struct s_ants *next;
}				t_ants;

int	parser_roomname(int index, t_struct *data, t_list **rooms, char *line);
int	parser_tunnels(t_struct *data, t_list *rooms, char *line);

void	init_matrix(t_struct *data);
void	print_matrix(t_struct *data);
void	refresh_matrix(t_struct *data);
void	block_path(t_struct *data, t_path *path_list);

void	find_path(t_struct *data, t_queue **queue);
void	read_matrix(t_struct *data, int previous, int origin, t_path **path_list);

void	print_ways(t_ants *lst_ants, t_struct *data, t_path *path_list);

#endif
