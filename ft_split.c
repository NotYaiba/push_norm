/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkarmi <melkarmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:53:49 by melkarmi          #+#    #+#             */
/*   Updated: 2021/05/29 16:56:36 by melkarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cntw(char const *str, char c)
{
	int	i;
	int	j;
	int	cntw;

	cntw = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
			j = 0;
		else if (j == 0)
		{
			j = 1;
			cntw++;
		}
		i++;
	}
	return (cntw);
}

int	ft_ln_w(char const *str, char w)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != w && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_tabcpy(char const *str, char **t, char w)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] && str[i] == w)
			i++;
		if (str[i])
		{
			t[j] = malloc(sizeof(char *) * ft_ln_w(str, w) + 1);
			if (t[j] == NULL)
				ft_free(t, i);
			while (str[i] != w && str[i])
			{
				t[j][k++] = str[i++];
			}
			t[j++][k] = '\0';
		}
	}
	t[j] = 0;
	return (t);
}

char	**ft_split(char const *str, char c)
{
	char	**res;

	if (str == NULL)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_cntw(str, c) + 1));
	if (res == NULL)
		return (NULL);
	ft_tabcpy(str, res, c);
	return (res);
}
