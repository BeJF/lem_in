/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:22:52 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/03 13:03:01 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_name(char *name, t_list **rooms, int index)
{
	t_list	*new_room;
	t_list	*temp;

	new_room = (t_list*)malloc(sizeof(t_list));
	new_room->room_name = name;
	new_room->room_nb = index;
	new_room->next = NULL;
	if (*rooms == NULL)
	{
		*rooms = new_room;	
		return ;
	}
	temp = *rooms;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_room;
}

int data_4_endstart(int index, int start, int end, t_struct *data)
{
	int     i;
	char    *name;
	char    *line;
	line = NULL;
	get_next_line(0, &line);
	i = 0;
	if (line[0] == '#')
	{
		free (line); //gestion d erreurs
		return (-1);
	}
	while (line[i] != ' ')
		i++;
	name = ft_strsub(line, 0, i);
	if (start == 1)
	{
		data->start_name = name;
		data->start_nb = index;
	}
	else if (end == 1)
	{
		data->end_name = name;
		data->end_nb = index;
	}
	free(line);
	return (0);
}

int parser_roomname(int index, t_struct *data, t_list **rooms, char *line)
{
	char    *name;
	int     i;
	i = 0;
	//while (line[0] == '#' && line[1] != '#') //pour les commentaires
	if (line[0] == '#' && line[1] != '#')
	{
		free(line);
		return (1);
		//get_next_line(0, &line); //peut avoir deux gnl d'affiles
	}
	else if (ft_strcmp(line, "##start") == 0)
	{
		free (line);
		if (data_4_endstart(index, 1, 0, data) == -1)
			return (-1);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		free (line);
		if (data_4_endstart(index, 0, 1, data) == -1)
			return (-1);
	}
	else
	{
		while (line[i] != ' ')
			i++;
		name = ft_strsub(line, 0, i);
		put_name(name, rooms, index);
		data->nb_rooms++;
		free (line);
	}
	return (0);
}
