/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:52:16 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/09 14:46:09 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin2(char *buff, char *tmp)
{
	char	*str;
	size_t	buff_len;
	size_t	tmp_len;

	if (tmp == NULL)
		return (NULL);
	if (!buff)
	{
		buff = (char *)malloc(1);
		if (!buff)
			return (NULL);
		buff[0] = '\0';
	}
	buff_len = ft_strlen(buff);
	tmp_len = ft_strlen(tmp);
	str = malloc(buff_len + tmp_len + 1);
	if (str == NULL)
	{
		free(buff);
		return (NULL);
	}
	ft_strcpy(str, buff);
	ft_strcpy(str + buff_len, tmp);
	return (str);
}

// int main()
// {
// 	char *s = "hello ";
// 	char *s2 = "world!";

// 	char *arr = ft_strjoin(s, s2);

// 	printf("%s\n", arr);
// }