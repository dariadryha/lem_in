/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddryha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 12:46:16 by ddryha            #+#    #+#             */
/*   Updated: 2018/04/27 12:46:17 by ddryha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define START "##start"
# define END "##end"
# define MAX_ANTS 100000

# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct		s_room
{
	char			*name;
	int				index;
	int				step;
	int				visited;
	int				cord[2];
}					t_room;

typedef	struct		s_ant
{
	unsigned int	length;
	char			*color;
	t_list			*ptr;
}					t_ant;

typedef struct		s_lem
{
	int				ants;
	int				**links;
	int				size;
	int				point[2];
	int				flg[4];
	t_list			*list;
	t_list			*ways;
	struct s_room	*room;
	struct s_ant	*ant;
}					t_lem;

int					ft_save_rooms(t_lem *data, char *line, int *stat);
int					ft_is_str_digit(char *str);
void				ft_error(char *str, int n);
void				ft_breadth_first_search(t_lem *data);
void				ft_create_room(t_room *new, char **str, int i);
int					ft_arrlen(char **arr);
int					ft_warning(char *str);
int					ft_save_ants(t_lem *data, char *line);
void				ft_depth_first_search(t_lem *data);
void				delone(void *content, size_t content_size);
void				ft_ant_farm(t_lem *data);
int					ft_save_flags(int n, char **arr, t_lem *data);
void				ft_usage_lem_in(void);
void				ft_print_way(t_lem *data);
void				ft_color_ant(t_lem *data);
int					ft_check_coincidence(t_list *temp, char *str, int *i);
void				del(void *content, size_t content_size);
void				ft_free(t_lem *data);

#endif
