/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 02:31:09 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/24 19:08:33 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_t			*check_ascii(t_t *root, char *name, char *path, int option)
{
	if (option & A)
		root = insert_name(root, name, path);
	else
	{
		if (!(option & C))
		{
			if (ft_strcmp(name, "..") && ft_strncmp(name, ".", 1))
				root = insert_name(root, name, path);
		}
		else
			root = insert_name(root, name, path);
	}
	return (root);
}

t_t			*check_ascii_reverse(t_t *root, char *name, char *path, int option)
{
	if (option & A)
		root = insert_name_reverse(root, name, path);
	else
	{
		if (!(option & C))
		{
			if (ft_strcmp(name, "..") && ft_strncmp(name, ".", 1))
				root = insert_name_reverse(root, name, path);
		}
		else
			root = insert_name_reverse(root, name, path);
	}
	return (root);
}
