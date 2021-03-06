/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positionator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:17:45 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/26 17:17:47 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* записываем уменшеную тетрисоиду в строковый формат (2й масив) */
void	pos(tetr **item)
{
	int		i;
	char	*str;
	int		j;
	i = 0;
	(*item)->pos = ft_memalloc(sizeof(char *) * (*item)->height);
	while (i < (*item)->height)
	{
		j = 0;
		str = ft_strnew((*item)->width);
		while (j < (*item)->width)
		{
			if (((*item)->c1.x == j+1 && (*item)->c1.y == i+1) ||
			((*item)->c2.x == j+1 && (*item)->c2.y == i+1) ||
			((*item)->c3.x == j+1 && (*item)->c3.y == i+1) ||
			((*item)->c4.x == j+1 && (*item)->c4.y == i+1))
				str[j] = '#';
			else
				str[j] = '.';
			j++;
		}
		(*item)->pos[i] = str;
		i++;
	}
}

/* очистка поля если нужно взять поле побольше */
void	delete_pole(t_pole *pole)
{
	int i;

	i = 0;
	while (i < pole->size)
	{
		ft_memdel((void **)&(pole->array[i]));
		i++;
	}
	ft_memdel((void **)&(pole->array));
	ft_memdel((void **)&pole);
}

int		sqroot(int nb, tetr **array)
{
	double square;
	double root;

	square = (double)nb;
	root=square/3;
	int i;
	if (square <= 0) return 0;
	i = 0;
	while (i++ < 28)
		root = (root + square / root) / 2;
	i = 0;
	if ((int)(root * 10) % 10 != 0)
		root += 1;
	root = (int)root;
	while (array[i])
	{
		if (array[i]->width > root)
			root = array[i]->width;
		if (array[i]->height > root)
			root = array[i]->height;
		i++;
	}
	return (root);
}