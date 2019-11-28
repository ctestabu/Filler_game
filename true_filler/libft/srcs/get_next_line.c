/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:13:03 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/27 20:13:03 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	line_magic(int fd, char *s[], char **line)
{
	int		len;
	char	*helper;

	len = 0;
	if (*s[fd] == '\0')
		return (0);
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (!(*line = ft_strsub(s[fd], 0, len)))
		return (-1);
	if (!(helper = ft_strdup(s[fd] + len + 1)))
		return (-1);
	free(s[fd]);
	s[fd] = ft_strdup(helper);
	free(helper);
	return (1);
}

int	shit_show(char **s, int fd, char *helper)
{
	helper = s[fd];
	if (!(s[fd] = ft_strjoin(helper, "\n")))
	{
		free(helper);
		return (-1);
	}
	free(helper);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD];
	char		line_buf[BUFF_SIZE + 1];
	char		*helper;
	int			ret;

	if (fd == -1 || (read(fd, line_buf, 0) == -1) || fd > MAX_FD)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strnew(1);
	while ((ft_strchr(s[fd], '\n') == NULL) || (ft_strchr(s[fd], '\0') == NULL))
	{
		ret = read(fd, line_buf, BUFF_SIZE);
		if (ret == 0 && *s[fd] != '\0')
			shit_show(s, fd, helper);
		if (ret == 0)
			break ;
		line_buf[ret] = '\0';
		helper = s[fd];
		if (!(s[fd] = ft_strjoin(helper, line_buf)))
			return (-1);
		free(helper);
	}
	return (line_magic(fd, s, line));
}
