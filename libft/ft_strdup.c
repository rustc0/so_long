/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:44:29 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/11 21:05:38 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	int		i;
	char	*s;

	i = 0;
	len = ft_strlen(str);
	s = (char *)malloc(len + 1 * sizeof(char));
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

// int main(void)
// {
// 	char *s = NULL;
// 	printf("%p\n", ft_strdup(s));
// 	//printf("%p\n", strdup(s));	
// }