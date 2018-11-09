/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:00:05 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/16 13:36:53 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_on_queue(t_queue **queue, int room, int origin)
{
	t_queue *add;
	t_queue *temp;

	add = (t_queue*)malloc(sizeof(t_queue));
	add->room = room;
	add->origin = origin;
	add->next = NULL;
	if (*queue == NULL)
	{
		*queue = add;
		return ;
	}
	temp = *queue;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = add;
}

void	delete_whole_queue(t_queue **queue)
{
	t_queue *tmp;

	while (*queue)
	{
		tmp = *queue;
		*queue = (*queue)->next;
		free(tmp);
	}
}

void	delete_from_queue(t_queue **queue)
{
	t_queue *tmp;

	tmp = *queue;
	*queue = (*queue)->next;
	free (tmp);
}

void	find_path(t_struct *data, t_queue **queue)
{
	int line;
	int column;
	int size_matrix;
	int **matrix;

	line = data->start_nb;
	add_on_queue(queue, data->start_nb, line);
	column = 0;
	size_matrix = data->nb_rooms;
	matrix = data->matrix;
	while (line != data->end_nb)
	{
		while (column < size_matrix && matrix[line][0] != 2)
		{
			if (matrix[line][column] == 1)
			{
				matrix[line][column] = (*queue)->origin + 10;
				add_on_queue(queue, column, line);
			}
			column++;
		}
		matrix[line][0] = 2;
		delete_from_queue(queue); //!! free tout le reste de la file
		column = 0;
		line = (*queue)->room;
	}
	matrix[data->end_nb][(*queue)->origin] = (*queue)->origin + 10;
	delete_whole_queue(queue);
}
