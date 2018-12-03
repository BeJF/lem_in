/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:43:14 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/03 13:57:58 by jfinet           ###   ########.fr       */
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
	//print_matrix(data);
	read_matrix(data, data->start_nb, 0, &path_list); //data->start_nb
	int i = 0;
	while (path_list->path[i])
	{
		printf("room path = %d\n", path_list->path[i]);
		i++;
	}
	//refresh_matrix(data);
	//block_path(data, path_list);	
	//find_path(data, &queue);
	//read_matrix(data, data->start_nb, 0, &path_list); //data->start_nb
	
	
	//print_ways(lst_ants, data, path_list);	
}


int main()
{
	t_struct	*data;
	t_list		*rooms;
	char		*line;
	int			index;
	
	data = (t_struct*)malloc(sizeof(t_struct));
	data->nb_rooms = 2; //hypothetique
	rooms = NULL;
	line = NULL;
	index = 0;
	
	//stocke nb fourmis
	//first check si pas 0 fourmis, et si premier ligne est bien ca
	//printf("test\n");
	get_next_line(0, &line);
	data->nb_ants = ft_atoi(line);
	free (line);
	get_next_line(0, &line);
	printf ("nb ants = %d\n", data->nb_ants);
	
	//stocke les noms des rooms
	while (ft_strchr(line, ' ') != 0 || ft_strchr(line, '#') != 0)
	{
		//printf("1");
		parser_roomname(index, data, &rooms, line); //gestion d erreur, free line etc
		if (line[0] != '#')
			index++;
		if (get_next_line(0, &line) != 1)
			break ;
	}
	
	//initialise la matrice selon nbres rooms
	init_matrix(data);
	while (ft_strchr(line, '-') != 0 || ft_strchr(line, '#') != 0)
	{
		//printf("2");
		parser_tunnels(data, rooms, line);
		if (get_next_line(0, &line) != 1)
			break ;
	}

	call_algo(data);
}
