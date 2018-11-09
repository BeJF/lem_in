/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:21:17 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/16 18:42:14 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ants *new_ant(int name, int *path, int length, t_ants *lst_ants)
{
	t_ants *new_ant;
	t_ants *tmp;

	new_ant = (t_ants*)malloc(sizeof(t_ants));
	new_ant->name = name;
	new_ant->pos = 0;
	new_ant->path = path;
	new_ant->length = length;
	new_ant->next = NULL;
	if (lst_ants == NULL)
		return (new_ant);
	tmp = lst_ants;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_ant;
	return (lst_ants);
}

t_ants	*clean_list(t_ants *lst_ants)
{	
	t_ants *tmp;
	t_ants *delete;

	if (lst_ants->length == 0)
	{
		delete = lst_ants;
		if (lst_ants->next != NULL)
			lst_ants = lst_ants->next;
		else
			lst_ants = NULL;
		free (delete);
	}
	tmp = lst_ants;
	while (tmp != NULL && tmp->next)
	{
		if (tmp->next->length == 0)
		{
			delete = tmp->next;
			tmp->next = tmp->next->next;
			free (delete);
		}
		tmp = tmp->next;
	}
	return (lst_ants);
}

t_ants *put_ants_in_list(t_struct *data, t_path *path_list, t_ants *lst_ants)
{
	static int name = 1;
	t_path *tmp;

	tmp = path_list;
	//put an ant for every path
	while (tmp != NULL && data->nb_ants != 0)
	{
		lst_ants = new_ant(name, tmp->path, tmp->path_length, lst_ants);
		name++;
		data->nb_ants--;
		//printf("nb ants = %d\n", data->nb_ants);
		//printf("path length = %d\n", tmp->path_length);
		//if (data->nb_ants < tmp->path_length)
		//	break ;
		tmp = tmp->next;
		//condition nb ants and path a faire
	}
	return (lst_ants);
}

//attention print not ft et trad nom room
void	print_ways(t_ants *lst_ants, t_struct *data, t_path *path_list)
{
	t_ants *tmp;
	int		name;
	int		*path;

	if (data->nb_ants != 0)
		lst_ants = put_ants_in_list(data, path_list, lst_ants);
	lst_ants = clean_list(lst_ants);
	if (lst_ants == NULL)
		return ;
	tmp = lst_ants;
	while (tmp != NULL)
	{
		tmp->length--;
		name = tmp->name;
		path = tmp->path;
		//printf("tmp->lenght = %d\n", tmp->length);
		printf("L%d-%d ", name, path[tmp->length]);
		tmp = tmp->next;
	}
	printf("\n");
	print_ways(lst_ants, data, path_list);
}


