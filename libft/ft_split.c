/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:28:43 by rahmoham          #+#    #+#             */
/*   Updated: 2024/11/11 17:10:44 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cw(char *str, char d)
{
	size_t	count;
	int		in;

	count = 0;
	in = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != d && !in)
		{
			count++;
			in = 1;
		}
		else if (*str == d)
		{
			in = 0;
		}
		str++;
	}
	return (count);
}

static void	*ft_clean(char **arr, int allocated)
{
	int	j;

	j = 0;
	while (j < allocated)
		free (arr[j++]);
	free (arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	size_t	wlen;

	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)ft_calloc((ft_cw((char *)s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		wlen = 0;
		while (s[wlen] != c && s[wlen])
			wlen++;
		arr[i++] = ft_substr(s, 0, wlen);
		if (!(arr[i - 1]))
			return (ft_clean(arr, i - 1));
		s += wlen;
	}
	return (arr);
}

// int main()
// {
// 	char s[] = "   hello, ,this,is a test,n0   ,";
// 	char **ret = ft_split(s, ' ');

// 	for (size_t i = 0; ret[i] != NULL; i++)
// 	{
// 		printf("%s\n", ret[i]);
// 	}

// 	free(ret);

// 	return 0;
// }