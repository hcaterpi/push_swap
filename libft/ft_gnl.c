/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:43:51 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/01/25 17:02:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_buffer(t_catalog **head, t_catalog *curr, char **line)
{
	char	*trash;
	int		i;

	i = 0;
	while (curr->str[i] != '\n')
	{
		if (!curr->str[i])
			return (0);
		i++;
	}
	curr->str[i] = '\0';
	*line = ft_strdup(curr->str);
	trash = curr->str;
	curr->str = ft_strsub(curr->str, i + 1, ft_strlen(&curr->str[i + 1]));
	free(trash);
	if (ft_strlen(curr->str) == 0)
		ft_catalog_delete(head, curr->fd);
	return (1);
}

static int	ft_read_file(t_catalog **head, t_catalog *curr, char **line)
{
	char	*buffer;
	char	*trash;
	int		byte_read;

	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (-1);
	while ((byte_read = read(curr->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[byte_read] = '\0';
		trash = curr->str;
		curr->str = ft_strjoin(curr->str, buffer);
		free(trash);
		if (ft_check_buffer(head, curr, line))
			break ;
	}
	free(buffer);
	if (byte_read > 0)
		byte_read = 1;
	return (byte_read);
}

int			ft_gnl(const int fd, char **line)
{
	static t_catalog	*descriptors;
	t_catalog			*curr;
	int				sygnal;

	if (fd < 0 || !line)
		return (-1);
	if ((curr = ft_catalog_find(descriptors, fd)) == NULL)
		curr = ft_catalog_add(&descriptors, fd, ft_strnew(0));
	else if (ft_check_buffer(&descriptors, curr, line))
		return (1);
	sygnal = ft_read_file(&descriptors, curr, line);
	if (sygnal != 0 || curr->str[0] == '\0')
		return (sygnal);
	*line = ft_strdup(curr->str);
	ft_catalog_delete(&descriptors, curr->fd);
	return (1);
}
