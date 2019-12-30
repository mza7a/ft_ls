/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:08:29 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/24 19:07:13 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			display_dir(t_t *root, int option, int start, int len)
{
	static int	x;

	if (start == 0)
	{
		x = 1;
		start++;
	}
	if (root != NULL)
	{
		if (root->left != NULL)
			display_dir(root->left, option, x, len);
		if (len != 1)
		{
			if (x != 1)
				mini_printf("\n");
			x++;
			mini_printf("%s:\n", root->name);
		}
		open_dir(root->name, option);
		if (root->right != NULL)
			display_dir(root->right, option, x, len);
	}
}

void			check_subddir(t_t *root, int option, int start, int len)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			check_subddir(root->left, option, start, len);
		if (is_directory(root->fullpath)
			&& ft_strcmp(ft_strrchr(root->fullpath, '/') + 1, ".")
			&& ft_strcmp(ft_strrchr(root->fullpath, '/') + 1, ".."))
		{
			if (start != len)
				mini_printf("\n");
			mini_printf("%s:\n", root->fullpath);
			open_dir(root->fullpath, option);
		}
		if (root->right != NULL)
			check_subddir(root->right, option, start, len);
	}
}

t_t				*insert_name_reverse(t_t *root, char *name, char *path)
{
	if (root == NULL)
	{
		root = get_new_node(name, path, 0);
		return (root);
	}
	if (ft_strcmp(name, root->name) >= 0)
		root->left = insert_name_reverse(root->left, name, path);
	else
		root->right = insert_name_reverse(root->right, name, path);
	return (root);
}

t_t				*insert_time(t_t *root, char *dir_name, int mtime, char *path)
{
	if (root == NULL)
	{
		root = get_new_node(dir_name, path, mtime);
		return (root);
	}
	if (mtime > root->mod_time)
		root->left = insert_time(root->left, dir_name, mtime, path);
	else
	{
		if (mtime == root->mod_time)
		{
			if (ft_strcmp(dir_name, root->name) <= 0)
				root->left = insert_time(root->left, dir_name, mtime, path);
			else
				root->right = insert_time(root->right, dir_name, mtime, path);
		}
		else
			root->right = insert_time(root->right, dir_name, mtime, path);
	}
	return (root);
}

t_t				*insert_time_reverse(t_t *root, char *name, int mtime,
		char *path)
{
	if (root == NULL)
	{
		root = get_new_node(name, path, mtime);
		return (root);
	}
	if (mtime < root->mod_time)
		root->left = insert_time_reverse(root->left, name, mtime, path);
	else
	{
		if (mtime == root->mod_time)
		{
			if (ft_strcmp(name, root->name) > 0)
				root->left = insert_time_reverse(root->left, name,
						mtime, path);
			else
				root->right = insert_time_reverse(root->right, name,
						mtime, path);
		}
		else
			root->right = insert_time_reverse(root->right, name, mtime, path);
	}
	return (root);
}
