/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant_farm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 15:42:48 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/05 15:42:49 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

#define D(x) data->room[*(int *)data->ant[x].ptr->content].name

static	void	ft_count_length(t_lem *data, t_ant *new)
{
	t_list	*temp;
	t_list	*change;

	temp = data->ways;
	while (temp)
	{
		if (!new->length || temp->content_size < new->length)
		{
			new->length = temp->content_size;
			new->ptr = (t_list *)temp->content;
			change = temp;
		}
		if (!data->flg[2])
			break ;
		temp = temp->next;
	}
	change->content_size++;
}

static	void	ft_run_ant_run(t_lem *data)
{
	int				i;
	unsigned int	length;

	i = 0;
	length = data->ant[0].length;
	ft_printf("\n");
	while (*(int *)data->ant[data->ants - 1].ptr->content != data->point[1])
	{
		i = 0;
		while (i < data->ants && data->ant[i].length <= length)
		{
			if (*(int *)data->ant[i].ptr->content != data->point[1])
			{
				data->ant[i].ptr = data->ant[i].ptr->next;
				data->flg[3] ? ft_printf(data->ant[i].color) : 0;
				data->flg[3] ? ft_printf("L%d-%s" RESET, i + 1, D(i)) :
				ft_printf("L%d-%s", i + 1, D(i));
				if (i + 1 < data->ants && data->ant[i + 1].length <= length)
					ft_printf(" ");
			}
			i++;
		}
		ft_printf("\n");
		length++;
	}
}

void			ft_ant_farm(t_lem *data)
{
	int i;

	i = 0;
	data->ant = (t_ant *)malloc(sizeof(t_ant) * data->ants);
	while (i < data->ants)
	{
		ft_count_length(data, &data->ant[i]);
		i++;
	}
	data->flg[3] ? ft_color_ant(data) : 0;
	ft_run_ant_run(data);
}
