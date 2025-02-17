/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:52:16 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/17 11:53:04 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	if (s1)
		s1len = ft_strlen(s1);
	else
		s1len = 0;
	if (s2)
		s2len = ft_strlen(s2);
	else
		s2len = 0;
	str = malloc(s1len + s2len + 1);
	if (!str)
		return (NULL);
	if (s1)
		ft_memcpy(str, s1, s1len);
	if (s2)
		ft_memcpy(str + s1len, s2, s2len);
	str[s1len + s2len] = '\0';
	return (str);
}

// int main()
// {
// 	char *s = "hello ";
// 	char *s2 = "world!";

// 	char *arr = ft_strjoin(s, s2);

// 	printf("%s\n", arr);
// }