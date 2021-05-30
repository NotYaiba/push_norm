/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: yaiba <yaiba@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/10/23 16:53:00 by melkarmi		  #+#	#+#			 */
/*   Updated: 2021/05/10 18:22:20 by yaiba			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*ft_strchra(char *str, int c);
char	*ft_strjoina(char *s1, char *s2);
void	*ft_calloca(size_t c, size_t size);
char	*ft_substra(char *s, unsigned int start, size_t len);
char	*ft_strcpya(char *dest, char *src);
char	*ft_strdupa(char *ssrc);

#endif
