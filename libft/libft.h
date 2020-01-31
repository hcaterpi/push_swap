/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:00:11 by hcaterpi          #+#    #+#             */
/*   Updated: 2020/02/01 00:59:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_catalog
{
	int					fd;
	char				*str;
	struct s_catalog	*next;
}				t_catalog;

int				ft_atoi(const char *str);
t_catalog		*ft_catalog_add(t_catalog **begin_catalog, int fd, char *str);
t_catalog		*ft_catalog_create(int fd, char *str);
int				ft_catalog_delete(t_catalog **begin_catalog, int fd);
t_catalog		*ft_catalog_find(t_catalog *begin_catalog, int fd);
int				ft_isinteger(const char *str);
int				ft_gnl(const int fd, char **line);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
int				ft_strequ(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
