/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:22:48 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/08 17:22:49 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	void	ft_del_ways(t_list **ways)
{
	t_list *del;
	t_list *temp;

	del = *ways;
	while (del)
	{
		temp = del->next;
		ft_lstdel((t_list **)&del->content, &delone);
		del->next = NULL;
		free(del);
		del = temp;
	}
}

static	void	ft_del_ants(t_ant *ants, int number)
{
	int i;

	i = 0;
	while (i < number)
	{
		ft_bzero(&ants[i], sizeof(t_ant));
		i++;
	}
	free(ants);
}

static	void	ft_del_room(t_room *room, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(room[i].name);
		ft_bzero(&room[i], sizeof(t_room));
		i++;
	}
	free(room);
}

void			ft_free(t_lem *data)
{
	ft_lstdel(&data->list, &delone);
	ft_del_mas_num(data->links, data->size);
	ft_del_ways(&data->ways);
	ft_del_ants(data->ant, data->ants);
	ft_del_room(data->room, data->size);
	ft_bzero(data, sizeof(t_lem));
}
