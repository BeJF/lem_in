/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_on_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:15:02 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/03 13:53:44 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_path(t_path **path_list, int *path, int length)
{
	t_path	*new_path;
	t_path	*temp;

	new_path = (t_path*)malloc(sizeof(t_path));
	new_path->path = path;
	new_path->path_length = length;
	new_path->next = NULL;
	if (*path_list == NULL)
	{
		*path_list = new_path;
		return ;
	}
	temp = *path_list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_path;
}

int		path_length(t_struct *data, int previous, int origin)
{
	int **matrix;
	int temp;
	int length;

	length = 2;
	matrix = data->matrix;
	while(matrix[data->end_nb][origin] <= 1)
		origin++;
	previous = origin;
	origin = matrix[origin][data->end_nb] - 10;
	while (origin != data->start_nb)
	{
		length++;
		temp = origin;
		origin = matrix[origin][previous] - 10;
		previous = temp;
	}
	return (length);
}

//verif a faire si chemin = 1

void	read_matrix(t_struct *data, int previous, int origin, t_path **path_list)
{
	int **matrix;
	int *path;
	int i;
	int temp;
	int length;

	i = 0;
	matrix = data->matrix;
	length = path_length(data, 0, 0);
	printf("path length = %d\n", length);
	path = (int*)malloc(sizeof(int) * length);
	path[i++] = data->end_nb;
	//printf("in tab = %d\n", path[0]);
	while(matrix[data->end_nb][origin] <= 1)
	{
		origin++;
	}
	path[i++] = origin;
	//printf("in tab = %d\n", origin);
	previous = origin;
	origin = matrix[origin][data->end_nb] - 10;
	path[i++] = origin;
	//printf("in tab = %d\n", origin);
	while (1)/*(origin != data->start_nb)*/
	{
		temp = origin;
		origin = matrix[origin][previous] - 10;
		if (origin == data->start_nb)
			break ;
		path[i++] = origin;
		//printf("in tab = %d\n", origin);
		previous = temp;
	}
	put_path(path_list, path, length);
}
