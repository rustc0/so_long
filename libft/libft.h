/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmoham <rahmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:19:15 by rahmoham          #+#    #+#             */
/*   Updated: 2025/02/18 09:16:29 by rahmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <limits.h>

typedef struct s_list // struct for linked lists
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Libc functions : ------------------------------------------------------------

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(char *s);
int		ft_isprint(int c);
int		ft_memcmp(const void *ptr, const void *ptr2, size_t num);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *str, int c, size_t num);
void	*ft_memcpy(void *to, const void *from, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t num);
void	*ft_memset(void *dest, int value, size_t num);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchrlib(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t num);
char	*ft_strnstr(const char *hs, const char *ndl, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);

// Additioonal functions : -----------------------------------------------------

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoinlib(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Bonus part : ----------------------------------------------------------------

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif