/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_flg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:16:14 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/07 17:16:15 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_color_ant(t_lem *data)
{
	int i;

	i = 0;
	while (i < data->ants)
	{
		data->ant[i].color = RED;
		if (i + 1 < data->ants)
			data->ant[i + 1].color = GREEN;
		if (i + 2 < data->ants)
			data->ant[i + 2].color = YELLOW;
		if (i + 3 < data->ants)
			data->ant[i + 3].color = BLUE;
		if (i + 4 < data->ants)
			data->ant[i + 4].color = PURPLE;
		if (i + 5 < data->ants)
			data->ant[i + 5].color = CYAN;
		i += 6;
	}
}

void	ft_usage_lem_in(void)
{
	ft_printf("Usage: ./lem-in [-e | -w | -s | -c] < map.\n");
	ft_printf("-e  displays more detailed information about errors /lem-in.\n");
	ft_printf("-w  displays the way to get n ants across the farm.\n");
	ft_printf("-s  displays all ways to get n ants across the farm.\n");
	ft_printf("-c  displays each ant in different colors.\n");
	exit(EXIT_FAILURE);
}

void	ft_print_way(t_lem *data)
{
	t_list	*out;
	t_list	*in;
	int		count;

	if (!data->flg[1])
		return ;
	out = data->ways;
	count = 0;
	ft_printf("\n");
	while (out)
	{
		in = (t_list *)out->content;
		while (in)
		{
			ft_printf(CYAN "[%s]" RESET, data->room[*(int *)in->content].name);
			if (in->next)
				ft_printf("-");
			in = in->next;
		}
		ft_printf(PURPLE "\nThe length of a way is: %d\n" RESET,
			out->content_size);
		count++;
		out = out->next;
	}
	ft_printf(RED "The number of found ways is: %d\n" RESET, count);
}

int		ft_save_flags(int n, char **arr, t_lem *data)
{
	int i;

	i = 1;
	while (i < n)
	{
		if (arr[i][0] == '-' && !arr[i][2])
		{
			if (arr[i][1] == 'e')
				data->flg[0] ? ft_usage_lem_in() : data->flg[0]++;
			else if (arr[i][1] == 'w')
				data->flg[1] ? ft_usage_lem_in() : data->flg[1]++;
			else if (arr[i][1] == 'a')
				data->flg[2] ? ft_usage_lem_in() : data->flg[2]++;
			else if (arr[i][1] == 'c')
				data->flg[3] ? ft_usage_lem_in() : data->flg[3]++;
			else
				ft_usage_lem_in();
		}
		else
			ft_usage_lem_in();
		i++;
	}
	return (0);
}
