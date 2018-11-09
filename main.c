/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:43:14 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/16 17:56:03 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	call_algo(t_struct *data)
{
	t_queue	*queue;
	t_path	*path_list;
	t_ants	*lst_ants;

	queue = NULL;
	path_list = NULL;
	lst_ants = NULL;
	
	data->found = 0;
	find_path(data, &queue);
	print_matrix(data);
	read_matrix(data, data->start_nb, 0, &path_list); //data->start_nb
	refresh_matrix(data);
	block_path(data, path_list);	
	find_path(data, &queue);
	read_matrix(data, data->start_nb, 0, &path_list); //data->start_nb

	printf("ocuodufo\n");
	print_ways(lst_ants, data, path_list);	
}


int main()
{
	t_struct	*data;
	t_list		*rooms;
	char		*line;
	int			index;
	
	data = (t_struct*)malloc(sizeof(t_struct));
	data->nb_rooms = 2;
	rooms = NULL;
	line = NULL;
	index = 0;
	
	//stocke nb fourmis	
	get_next_line(0, &line);
	data->nb_ants = ft_atoi(line);
	free (line);
	get_next_line(0, &line);
	printf ("nb ants = %d\n", data->nb_ants);
	
	//stocke les noms des rooms
	while (ft_strchr(line, ' ') != 0 || ft_strchr(line, '#') != 0)
	{
		parser_roomname(index, data, &rooms, line); //gestion d erreur, free line etc
		index++;
		get_next_line(0, &line);
	}
	
	//initialise la matrice selon nbres rooms
	init_matrix(data);
	while (ft_strchr(line, '-') != 0 || ft_strchr(line, '#') != 0)
	{
		parser_tunnels(data, rooms, line);
		get_next_line(0, &line);	
	}

	call_algo(data);
}
