/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:56:19 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/16 15:30:17 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	block_path(t_struct *data, t_path *path_list)
{
	int line;
	int *path;
	int	**matrix;
	int path_length;

	while (path_list != NULL)
	{
		path = path_list->path;
		path_length = path_list->path_length;
		matrix = data->matrix;
		while (path_length-- > 0)
		{
			line = path[path_length];
			if (line != data->end_nb && line != data->start_nb)
				matrix[line][0] = 2;
		}
		path_list = path_list->next;
	}
}

void	refresh_matrix(t_struct *data)
{
	int size;
	int i;
	int z;
	int **matrix;

	size = data->nb_rooms;
	i = 0;
	z = 0;
	matrix = data->matrix;
	while (i < size)
	{
		while (z < size)
		{
			if (matrix[i][z] != 0)
				matrix[i][z] = 1;
			z++;
		}
		i++;
		z = 0;
	}	
}

void	print_matrix(t_struct *data)
{
	int size;
	int i;
	int z;

	size = data->nb_rooms;
	i = 0;
	z = 0;
	while (i < size)
	{
		while (z < size)
		{
			printf("|%d|", data->matrix[i][z]);
			z++;
		}
		i++;
		printf("\n");
		z = 0;
	}
}

void	init_matrix(t_struct *data)
{
	int nb_rooms;
	int i;
	int z;

	nb_rooms = data->nb_rooms;
	i = 0;
	z = 0;
	printf("nb rooms = %d\n", nb_rooms);
	data->matrix = (int**)malloc(sizeof(int*) * nb_rooms);
	while (i < nb_rooms)
	{
		data->matrix[i] = (int*)malloc(sizeof(int) * nb_rooms);
		i++;
	}
	i = 0;
	while (i < nb_rooms)
	{
		while (z < nb_rooms)
		{
			data->matrix[i][z] = 0;
			z++;
		}
		i++;
		z = 0;
	}
}
