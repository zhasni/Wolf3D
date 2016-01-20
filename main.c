/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:25:04 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/05 18:51:05 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "main.h"

t_line	*ft_init_line(t_line *line, int x, int len)
{
	if (!(line = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	if (!(line->line = (int*)malloc(sizeof(int) * (len))))
		return (NULL);
	line->x = x;
	line->len = len;
	line->next = NULL;
	return (line);
}

t_line	*ft_newline(t_line *line, char *newline)
{
	static int	nbline;
	char		**tab;
	int			i;
	t_line		*newt_line;
	size_t		len;

	tab = ft_strsplit(newline, ',');
	len = ft_tablen(tab);
	i = 0;
	newt_line = NULL;
	if (!(newt_line = ft_init_line(newt_line, nbline++, len)))
		return (NULL);
	while (tab[i])
	{
		newt_line->line[i] = ft_atoi(tab[i]);
		i++;
	}
	if (line)
	{
		line->next = newt_line;
		line = line->next;
	}
	else
		line = newt_line;
	return (line);
}

void	ft_list_to_grid(t_line *head, t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (head != NULL)
	{
		j = 0;
		while (j < head->len)
		{
			env->worldmap[i][j] = head->line[j];
			j++;
		}
		i++;
		head = head->next;
	}
}

void	ft_get_map(t_env *env)
{
	char	*line;
	t_line	*out;
	t_line	*head;
	int		fd;

	out = NULL;
	head = NULL;
	line = NULL;
	fd = open("map4", O_RDONLY);
	if (fd < 0)
		return ;
	while (get_next_line(fd, &line) == 1)
	{
		out = ft_newline(out, line);
		if (head == NULL)
			head = out;
	}
	close(fd);
	ft_list_to_grid(head, env);
	ft_wolf(env);
}

int		main(int ac, char **av, char **environ)
{
	t_env	env;

	av = av;
	if (!environ[0])
		return (-1);
	ft_init_env(&env);
	ft_init_sprite(&env);
	if (ac == 1)
		ft_get_map(&env);
	return (0);
}
