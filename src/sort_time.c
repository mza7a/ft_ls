/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:12:00 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/23 02:36:50 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_t					*check_time(t_t *root, char *name, char *path, int option)
{
	struct stat		buff;
	char			*tmp;
	char			*tmp2;

	if (ft_strcmp(name, path))
	{
		tmp2 = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp2, name);
	}
	else
		tmp = ft_strdup(path);
	if (lstat(tmp, &buff) == 0)
	{
		if (option & A)
			root = insert_time(root, name, buff.st_mtime, path);
		else
		{
			if (ft_strcmp(name, "..") && ft_strncmp(name, ".", 1))
				root = insert_time(root, name, buff.st_mtime, path);
		}
		
		//free(tmp2);
		//free(tmp);
		return (root);
	}
	//free(tmp2);
	//free(tmp);
	return (root);
}

t_t					*check_time_reverse(t_t *root, char *name, char *path,
		int option)
{
	struct stat		buff;
	char			*tmp;
	char			*tmp2;

	if (ft_strcmp(name, path))
	{
		tmp2 = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp2, name);
	}
	else
		tmp = ft_strdup(path);
	if (lstat(tmp, &buff) == 0)
	{
		if (option & A)
			root = insert_time_reverse(root, name, buff.st_mtime, path);
		else
		{
			if (ft_strcmp(name, "..") && ft_strncmp(name, ".", 1))
				root = insert_time_reverse(root, name, buff.st_mtime, path);
		}
		//free(tmp2);
		//free(tmp);
		return (root);
	}
	//free(tmp2);
	//free(tmp);
	return (root);
}