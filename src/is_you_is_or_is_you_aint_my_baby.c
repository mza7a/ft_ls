/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_you_is_or_is_you_aint_my_baby.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:11:11 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/27 00:42:38 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				no_file(char **av)
{
	int			i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0'))
			return (i);
		i++;
	}
	return (0);
}

void			check_link(char *path)
{
	char		buf[1024];
	struct stat	buff;

	if (lstat(path, &buff) == 0)
	{
		if (S_ISLNK(buff.st_mode))
		{
			ft_memset(buf, 0, sizeof(buf));
			readlink(path, buf, sizeof(buf) - 1);
			mini_printf(" -> %s", buf);
		}
	}
}

int				isfilefolder(char *path)
{
	struct stat	buff;

	if (lstat(path, &buff) != -1)
		return (1);
	return (0);
}

int				is_directory(char *path)
{
	struct stat	buff;

	lstat(path, &buff);
	if (S_ISDIR(buff.st_mode))
		return (1);
	return (0);
}

int				is_symbolic(char *name)
{
	struct stat	buff;

	lstat(name, &buff);
	if (S_ISLNK(buff.st_mode))
		return (1);
	return (0);
}
