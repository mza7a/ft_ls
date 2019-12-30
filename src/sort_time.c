/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:12:00 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/24 18:38:30 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				get_info(char **tmp, char **tmp2, char *name, char *path)
{
	if (ft_strcmp(name, path))
	{
		*tmp2 = ft_strjoin(path, "/");
		*tmp = ft_strjoin(*tmp2, name);
	}
	else
	{
		*tmp2 = ft_strdup(path);
		*tmp = ft_strdup(path);
	}
}

t_t					*check_time(t_t *root, char *name, char *path, int option)
{
	struct stat		buff;
	char			*tmp;
	char			*tmp2;

	get_info(&tmp, &tmp2, name, path);
	if (lstat(tmp, &buff) == 0)
	{
		if (option & A)
			root = insert_time(root, name, buff.st_mtime, path);
		else
		{
			if (!(option & C))
			{
				if (ft_strcmp(name, "..") && ft_strncmp(name, ".", 1))
					root = insert_time(root, name, buff.st_mtime, path);
			}
			else
				root = insert_time(root, name, buff.st_mtime, path);
		}
	}
	free(tmp);
	free(tmp2);
	return (root);
}

t_t					*check_time_reverse(t_t *root, char *name, char *path,
		int option)
{
	struct stat		buff;
	char			*tmp;
	char			*tmp2;

	get_info(&tmp, &tmp2, name, path);
	if (lstat(tmp, &buff) == 0)
	{
		if (option & A)
			root = insert_time_reverse(root, name, buff.st_mtime, path);
		else
		{
			if (!(option & C))
			{
				if (ft_strcmp(name, "..") && ft_strncmp(name, ".", 1))
					root = insert_time_reverse(root, name, buff.st_mtime, path);
			}
			else
				root = insert_time_reverse(root, name, buff.st_mtime, path);
		}
	}
	free(tmp);
	free(tmp2);
	return (root);
}
