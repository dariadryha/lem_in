/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:06:07 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/03 19:06:13 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_is_str_digit(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

void	ft_create_room(t_room *new, char **str, int i)
{
	new->name = ft_strdup(str[0]);
	new->cord[0] = ft_atoi(str[1]);
	new->cord[1] = ft_atoi(str[2]);
	new->visited = 0;
	new->step = -1;
	new->index = i;
}

int		ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (*arr++)
		i++;
	return (i);
}

int		ft_check_coincidence(t_list *temp, char *str, int *i)
{
	while (temp)
	{
		if (!ft_strcmp(((t_room *)temp->content)->name, str))
		{
			*i = ((t_room *)temp->content)->index;
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
