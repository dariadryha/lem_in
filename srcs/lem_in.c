/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 12:56:05 by ddryha            #+#    #+#             */
/*   Updated: 2018/04/27 12:56:05 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#define S1 "it's unknown command."
#define S2 "no information about the rooms."
#define S3 "no information about start room."
#define S4 "no information about end room."
#define S5 "no enough information about the farm of ants."

int				ft_save_ants(t_lem *data, char *line)
{
	if (!line[0])
	{
		if (data->links)
			return (ft_warning("it's empty line."));
		ft_error("it's empty line.", data->flg[0]);
	}
	if (ft_is_str_digit(line))
	{
		ft_strstr(line, "##") ? ft_error(S1, data->flg[0]) : 0;
		line[0] != '#' ? ft_error("it's not valid data.", data->flg[0]) : 0;
	}
	else
	{
		if (data->ants)
			ft_error("ants already exist.", data->flg[0]);
		data->ants = ft_atoi(line);
		if (data->ants <= 0)
			ft_error("the number of ants must be a positive number.",
				data->flg[0]);
		if (data->ants > MAX_ANTS)
			ft_error("the number of ants should be less than 100000.",
				data->flg[0]);
	}
	return (0);
}

static	int		ft_save_links(t_lem *data, char *line)
{
	char	**res;
	int		i[2];

	!data->ants ? ft_error("no number of ants.", data->flg[0]) : 0;
	!data->list ? ft_error(S2, data->flg[0]) : 0;
	data->point[0] == -1 ? ft_error(S3, data->flg[0]) : 0;
	data->point[1] == -1 ? ft_error(S4, data->flg[0]) : 0;
	if (!data->links && data->size)
		data->links = ft_mem_mas_num(data->size, data->size);
	res = ft_strsplit(line, '-');
	if (ft_arrlen(res) != 2)
		return (ft_warning("it's incorrect link."));
	ft_bzero(i, 2 * sizeof(int));
	if (ft_check_coincidence(data->list, res[0], &i[0]) ||
		ft_check_coincidence(data->list, res[1], &i[1]))
		return (ft_warning("no match found with room name."));
	else
	{
		data->links[i[0]][i[1]] = 1;
		data->links[i[1]][i[0]] = 1;
	}
	ft_del_mas_str(res);
	return (0);
}

static	void	ft_read_data(t_lem *data)
{
	char	*line;
	int		stat;
	int		res;

	stat = -1;
	while (get_next_line(0, &line) > 0)
	{
		res = 0;
		ft_printf("%s\n", line);
		if (!ft_strcmp(line, START))
			stat = 0;
		else if (!ft_strcmp(line, END))
			stat = 1;
		else if (line[0] != '#' && ft_strchr(line, ' '))
			res = ft_save_rooms(data, line, &stat);
		else if (line[0] != '#' && ft_strchr(line, '-') && data->ants)
			res = ft_save_links(data, line);
		else
			res = ft_save_ants(data, line);
		free(line);
		if (res)
			return ;
	}
	if (!data->links || !data->ants || !data->list)
		ft_error(S5, data->flg[0]);
}

static	void	ft_create_arr_room(t_lem *data)
{
	t_list *temp;

	temp = data->list;
	data->room = (t_room *)malloc(sizeof(t_room) * data->size);
	while (temp)
	{
		ft_memcpy(&data->room[((t_room *)temp->content)->index],
			((t_room *)temp->content), sizeof(t_room));
		temp = temp->next;
	}
}

int				main(int argc, char **argv)
{
	t_lem data;

	ft_bzero(&data, sizeof(t_lem));
	data.point[0] = -1;
	data.point[1] = -1;
	argc > 1 ? ft_save_flags(argc, argv, &data) : 0;
	ft_read_data(&data);
	ft_create_arr_room(&data);
	ft_breadth_first_search(&data);
	ft_depth_first_search(&data);
	ft_ant_farm(&data);
	ft_free(&data);
	return (0);
}
