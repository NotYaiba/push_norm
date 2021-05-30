/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaiba <yaiba@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/23 17:26:04 by melkarmi		  #+#	#+#			 */
/*   Updated: 2021/05/10 18:23:08 by yaiba			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

int	check_error(int fd, char **line)
{
	int		a;
	char	*c;

	c = NULL;
	a = read(fd, c, 0);
	if (a < 0 || fd < 0 || !line || 100 < 0)
	{
		return (-1);
	}
	return (0);
}

int	len_nl(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strchra(*str, '\n') != NULL)
	{
		while ((*str)[i] != '\n')
			i++;
	}
	if (ft_strchra(*str, '\n'))
	{
		tmp = *line;
		*line = ft_substra(*str, 0, i);
		tmp = *str;
		*str = ft_strdupa(*str + i + 1);
		free(tmp);
		return (1);
	}
	*line = ft_strdupa(*str);
	free(*str);
	*str = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[1024];
	char		*buf;
	int			r;
	char		*tmp;

	buf = malloc(sizeof(char) * 100 + 1);
	if (check_error(fd, line) == -1)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strdupa("");
	while (ft_strchra(str[fd], '\n') == NULL)
	{
		r = read(fd, buf, 100);
		buf[r] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoina(str[fd], buf);
		free(tmp);
		tmp = NULL;
		if (r == 0)
			break ;
	}
	free(buf);
	buf = NULL;
	return (len_nl(&str[fd], line));
}
