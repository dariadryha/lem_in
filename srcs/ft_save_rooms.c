/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:25:17 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/03 19:25:34 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#define S "the rooms’ coordinates can not be the same."

static	int		ft_check_room_data(t_lem *data, char **res, char *line)
{
	t_list *temp;

	if (ft_arrlen(res) != 3)
	{
		if (!data->ants)
			ft_save_ants(data, line);
		else
			ft_error("it's not valid data.", data->flg[0]);
	}
	!data->ants ? ft_error("no number of ants.", data->flg[0]) : 0;
	if (ft_is_str_digit(res[1]) || ft_is_str_digit(res[2]))
		ft_error("the rooms’ coordinates must be integers.", data->flg[0]);
	if (res[0][0] == 'L')
		ft_error("a room should not start with the character L.", data->flg[0]);
	temp = data->list;
	while (temp)
	{
		if ((((t_room *)temp->content)->cord[0] == ft_atoi(res[1]) &&
			((t_room *)temp->content)->cord[1] == ft_atoi(res[2])))
			ft_error(S, data->flg[0]);
		if (!ft_strcmp(res[0], ((t_room *)temp->content)->name))
			ft_error("the rooms’ names can not be the same.", data->flg[0]);
		temp = temp->next;
	}
	return (0);
}

static	void	ft_add_room(t_lem *data, t_room room)
{
	t_list *temp;

	if (!data->list)
		data->list = ft_lstnew(&room, sizeof(t_room));
	else
	{
		temp = data->list;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(&room, sizeof(t_room));
	}
}

int				ft_save_rooms(t_lem *data, char *line, int *stat)
{
	t_room		room;
	char		**res;

	if (data->links)
		return (ft_warning("currently reading links."));
	res = ft_strsplit(line, ' ');
	ft_check_room_data(data, res, line);
	ft_create_room(&room, res, data->size++);
	ft_add_room(data, room);
	if (*stat != -1)
	{
		if (data->point[0] != -1 && !*stat)
			ft_error("the start room already exists.", data->flg[0]);
		if (data->point[1] != -1 && *stat == 1)
			ft_error("the end room already exists.", data->flg[0]);
		data->point[*stat] = data->size - 1;
		*stat = -1;
	}
	ft_del_mas_str(res);
	return (0);
}
