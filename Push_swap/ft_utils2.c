/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:28:43 by bgoron            #+#    #+#             */
/*   Updated: 2024/01/05 15:34:46 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	tab = malloc (nmemb * size);
	if (tab == NULL)
		return (NULL);
	ft_bzero (tab, (nmemb * size));
	return (tab);
}

size_t	ft_countwords(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	if (!*s)
		return (0);
	if (*s != c)
		count++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

size_t	ft_countletters(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		i;
	int		wcount;
	int		wsize;

	i = -1;
	wsize = 0;
	if (!s)
		return (NULL);
	wcount = ft_countwords(s, c);
	str = ft_calloc((wcount + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (++i < wcount)
	{
		while (wsize-- > 0 || *s == c)
			s++;
		wsize = ft_countletters(s, c);
		str[i] = ft_calloc((wsize + 1), sizeof(char));
		if (!str[i])
			return (ft_free_tab(str));
		ft_strlcpy(str[i], s, wsize + 1);
	}
	str[i] = 0;
	return (str);
}