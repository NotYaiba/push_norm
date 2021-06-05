/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:45:41 by melkarmi          #+#    #+#             */
/*   Updated: 2021/06/05 20:36:05 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sstrlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *ssrc)
{
	char	*src;
	int		s;
	char	*c;

	src = (char *)ssrc;
	s = ft_sstrlen(src);
	c = (char *)malloc((s + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	ft_strcpy(c, src);
	return (c);
}

t_stack	*new_node2(char *content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}
