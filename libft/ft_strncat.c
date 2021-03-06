/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:29:15 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/02 15:29:17 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
	{
		len++;
	}
	while (s2[i] != '\0' && i < n)
	{
		s1[len++] = s2[i++];
	}
	s1[len] = '\0';
	return (s1);
}
