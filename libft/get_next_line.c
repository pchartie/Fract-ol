/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgay <cgay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 10:54:35 by cgay              #+#    #+#             */
/*   Updated: 2014/11/27 11:00:01 by cgay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		end_line(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	return (i);
}

static int		init_n_check(t_gnl *env, char **line, int fd)
{
	if (env == NULL)
	{
		env = (t_gnl*)malloc(sizeof(t_gnl));
		env->tmp = NULL;
	}
	if (env->tmp == NULL)
		env->tmp = ft_strnew(1);
	if (line == NULL || fd < 0)
		return (-1);
	return (1);
}

static void		buff_in_tmp(t_gnl *env)
{
	env->buff[env->ret] = '\0';
	env->tmp = ft_strjoin(env->tmp, env->buff);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	env;

	if (init_n_check(&env, line, fd) < 0)
		return (-1);
	while (1)
	{
		if (ft_strchr(env.tmp, '\n'))
		{
			*line = ft_strsub(env.tmp, 0, end_line(env.tmp));
			env.tmp = ft_strdup(env.tmp + end_line(env.tmp) + 1);
			return (1);
		}
		env.ret = read(fd, env.buff, BUFF_SIZE);
		if (env.ret <= 0)
		{
			*line = ft_strdup(env.tmp);
			env.tmp = NULL;
			if (ft_strlen(*line) > 0)
				return (1);
			return (env.ret);
		}
		if (env.ret > 0)
			buff_in_tmp(&env);
	}
}
