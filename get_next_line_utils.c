/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaiba <yaiba@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/25 03:55:15 by melkarmi		  #+#	#+#			 */
/*   Updated: 2021/05/10 18:26:54 by yaiba			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoina(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (strdup(s2));
	lens1 = strlen(s1);
	lens2 = strlen(s2);
	str = (char *)malloc((lens1 + lens2 + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (++i < lens1)
		str[i] = s1[i];
	i = 0;
	while (i < lens2)
	{
		str[i + lens1] = s2[i];
		i++;
	}
	str[i + lens1] = '\0';
	return (str);
}

char	*ft_strchra(char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return (s + i);
		}
		i++;
	}
	if (s[i] == (char)c)
		return (s + i);
	return (0);
}

char	*ft_strcpya(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdupa(char *ssrc)
{
	char	*src;
	char	*i;
	int		j;

	src = (char *)ssrc;
	j = 0;
	while (src[j])
		j++;
	i = malloc(j * sizeof(char) + 1);
	if (i == NULL)
		return (NULL);
	ft_strcpya(i, src);
	return (i);
}

char	*ft_substra(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	if (start > i)
		len = 0;
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
