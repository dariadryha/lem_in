/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_breadth_first_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:36:42 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/07 18:36:42 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#define Q data->room[*(int *)(*queue)->content].step

static	void	ft_add_to_queue(t_list **queue, int *index)
{
	t_list *temp;

	temp = *queue;
	while (temp->next)
		temp = temp->next;
	temp->next = ft_lstnew(index, sizeof(int));
}

static	int		ft_check_visited_rooms(t_lem *data, t_list *queue, int i)
{
	if (data->room[i].step != -1)
		return (0);
	while (queue)
	{
		if (*(int *)queue->content == i)
			return (0);
		queue = queue->next;
	}
	return (1);
}

static	void	ft_check_links(t_lem *data, t_list **queue)
{
	int i;

	i = 0;
	while (i < data->size)
	{
		if (data->links[*(int *)(*queue)->content][i])
		{
			if (ft_check_visited_rooms(data, *queue, i))
			{
				data->room[i].step = Q + 1;
				ft_add_to_queue(queue, &data->room[i].index);
			}
		}
		i++;
	}
}

void			ft_breadth_first_search(t_lem *data)
{
	t_list *temp;
	t_list *queue;

	queue = ft_lstnew(&data->point[0], sizeof(int));
	data->room[data->point[0]].step = 0;
	while (queue)
	{
		ft_check_links(data, &queue);
		temp = queue->next;
		ft_lstdelone(&queue, &delone);
		queue = temp;
	}
}
