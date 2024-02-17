/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoron <bgoron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:41:52 by bgoron            #+#    #+#             */
/*   Updated: 2024/02/15 20:06:11 by bgoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int f)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!(s1 && s2))
		return (NULL);
	s3 = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		s3[i] = s1[i];
	while (s2[++j] != '\0')
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	if (f == 1 || f == 3)
		free(s1);
	if (f == 2 || f == 3)
		free(s2);
	return (s3);
}
