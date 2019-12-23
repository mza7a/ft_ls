/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 02:30:53 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/23 14:37:06 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_t					*get_new_node(char *name, char *path, int mod_time)
{
	t_t				*root;
	char			*tmp;

	root = (t_t *)malloc(sizeof(t_t));
	root->name = ft_strdup(name);
	if (!(check & Y))
	{
		if (ft_strcmp(path, "/"))
		{
			tmp = ft_strjoin(path, "/");
			root->fullpath = ft_strjoin(tmp, name);
			free(tmp);
		}
		else
			root->fullpath = ft_strjoin(path, name);
	}
	else
		root->fullpath = ft_strdup(name);	
	root->mod_time = mod_time;
	root->left = NULL;
	root->right = NULL;
	return (root);
}

/*t_t					*get_new_node2(char *name, int mod_time)
{
	t_t				*root;

	root = (t_t *)malloc(sizeof(t_t));
	root->name = ft_strdup(name);
	root->fullpath = ft_strdup(name);
	root->mod_time = mod_time;
	root->left = NULL;
	root->right = NULL;
	return (root);
}

t_t					*insert_name2(t_t *root, char *name)
{
	if (root == NULL)
	{
		root = get_new_node2(name, 0);
		return (root);
	}
	if (ft_strcmp(name, root->name) <= 0)
		root->left = insert_name2(root->left, name);
	else
		root->right = insert_name2(root->right, name);
	return (root);
}*/

t_t					*insert_name(t_t *root, char *name, char *path)
{
	if (root == NULL)
	{
		root = get_new_node(name, path, 0);
		return (root);
	}
	if (ft_strcmp(name, root->name) <= 0)
		root->left = insert_name(root->left, name, path);
	else
		root->right = insert_name(root->right, name, path);
	return (root);
}

void				display_tree(t_t *root, int option, int *tab)
{
	int				check;

	if (root != NULL)
	{
		if (root->left != NULL)
			display_tree(root->left, option, tab);
		if (option & L)
		{
			check = display_tree_l(root, tab);
			if (check == 0)
				return ;
		}
		mini_printf("%s", root->name);
		if (option & P && is_directory(root->fullpath))
			ft_putchar('/');
		if (option & L)
			check_link(root->fullpath);
		mini_printf("\n");
		if (root->right != NULL)
			display_tree(root->right, option, tab);
	}
}
