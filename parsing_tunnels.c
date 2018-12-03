/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tunnels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:49:19 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/03 13:50:27 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int name_to_nb(char *room_name, t_list *rooms, t_struct *data)
{
	while (rooms)
	{
		if (strcmp(rooms->room_name, room_name) == 0)
			return (rooms->room_nb);
	  	rooms = rooms->next;
	}
	if (strcmp(data->start_name, room_name) == 0)
		return (data->start_nb);
	if (strcmp(data->end_name, room_name) == 0)
		return (data->end_nb);
	return (-1); //qd erreur genre room pas trouvee
}

int	parser_tunnels(t_struct *data, t_list *rooms, char *line)
{
	int room_nb1;
	int room_nb2;
	int i;
	int z;

	i = 0;
	z = 0;
	//while (line[0] == '#' && line[1] != '#')
	if (line[0] == '#' && line[1] != '#')
	{
		free (line);
		return (1);
		//get_next_line(0, &line);
	}
	while (line[i] != '-')
		i++;
	room_nb1 = name_to_nb(ft_strsub(line, 0, i), rooms, data);
	while (line[z] != '\0')
		z++;
	room_nb2 = name_to_nb(ft_strsub(line, i + 1, z), rooms, data);
	data->matrix[room_nb1][room_nb2] = 1;
	data->matrix[room_nb2][room_nb1] = 1;
	free (line);
	return (0);
}
