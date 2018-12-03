/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:19:50 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/03 12:30:55 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

//attention printf, pas ft

int	ants_sender(int num_ant, int i, t_path *path_list)
{
	printf("i = %d\n", i);
	if (i < path_list->path_length)
	{
		printf("L%d-%d", num_ant, path_list->path[i]);
		return (0);
	}
	return (-1);
}

void	test(int i, t_path *path_list, int nb_ants_to_move)
{
	t_path *tmp;
	int num_ant;

	tmp = path_list;
	num_ant = 1;
	if (nb_ants == 0)
		return ;
	while (num_ant <= nb_ants)
	{
		nb_ants += ants_sender(num_ant, i, path_list);
		num_ant++;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			ants_sender(num_ant, i, tmp);
			num_ant++;
		}
		tmp = path_list;
	}
	test(i + 1, path_list, nb_ants + num_ant);
}
