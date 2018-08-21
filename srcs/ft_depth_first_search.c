/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_depth_first_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:43:50 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/07 18:43:50 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	int		*ft_find_link(t_lem *data, t_list *way)
{
	t_room	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	while (i < data->size)
	{
		if (data->links[*(int *)way->content][i])
		{
			if ((!ptr || data->room[i].step < ptr->step) &&
				!data->room[i].visited)
				ptr = &data->room[i];
		}
		i++;
	}
	return (ptr ? &ptr->index : NULL);
}

static	int		ft_count_ways(t_lem *data)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < data->size)
	{
		if (data->links[data->point[1]][i])
			count++;
		i++;
	}
	return (count);
}

static	void	ft_search_way(t_lem *data, t_list **way, int *count)
{
	int *ptr;

	if (*(int *)(*way)->content == data->point[0])
		return ;
	data->room[*(int *)(*way)->content].visited = 1;
	if (!(ptr = ft_find_link(data, *way)))
	{
		ft_lstdel(way, &delone);
		return ;
	}
	ft_lstadd(way, ft_lstnew(ptr, sizeof(int)));
	(*count)++;
	ft_search_way(data, way, count);
}

static	void	ft_add_way(t_lem *data, t_list *way, int count)
{
	t_list *temp;

	if (!data->ways)
	{
		data->ways = ft_lstnew(NULL, 0);
		data->ways->content = way;
		data->ways->content_size = count;
	}
	else
	{
		temp = data->ways;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(NULL, 0);
		temp->next->content = way;
		temp->next->content_size = count;
	}
}

void			ft_depth_first_search(t_lem *data)
{
	int		ways;
	int		count;
	t_list	*way;

	if (!(ways = ft_count_ways(data)))
		ft_error("no paths found.", data->flg[0]);
	while (ways--)
	{
		count = 0;
		way = ft_lstnew(&data->point[1], sizeof(int));
		ft_search_way(data, &way, &count);
		if (way)
			ft_add_way(data, way, count);
	}
	!data->ways ? ft_error("no paths found.", data->flg[0]) :
	ft_print_way(data);
}
