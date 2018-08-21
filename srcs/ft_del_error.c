/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:10 by ddryha            #+#    #+#             */
/*   Updated: 2018/05/07 19:16:11 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delone(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

int		ft_warning(char *str)
{
	ft_printf(PURPLE "Warning: %s\n" RESET, str);
	return (1);
}

void	del(void *content, size_t content_size)
{
	free(((t_room *)content)->name);
	ft_bzero(((t_room *)content), sizeof(t_room));
	content_size = 0;
}

void	ft_error(char *str, int n)
{
	n ? ft_printf(RED "\nERROR: " RESET PURPLE "%s\n" RESET, str) :
	ft_printf(RED "\nERROR\n" RESET);
	exit(1);
}
