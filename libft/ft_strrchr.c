/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:14:27 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/24 16:37:04 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len + 1 > 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len] + 1);
		len--;
	}
	return (NULL);
}
/*
int main()
{
    const char *s = "Hellols word!";
    
    printf("%s\n", ft_strrchr(s, 'l'));
	return (0);
}*/