/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:10:05 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/27 00:34:54 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					size_tree(t_t *root)
{
	if (root == NULL)
		return (0);
	return (size_tree(root->left) + 1 + size_tree(root->right));
}

void				free_free(t_t **root)
{
	free((*root)->name);
	(*root)->name = NULL;
	free((*root)->fullpath);
	(*root)->fullpath = NULL;
	free(*root);
	*root = NULL;
}

int					free_tree(t_t **node)
{
	t_t				*n;

	if (*node == NULL)
		return (1);
	n = *node;
	free_tree(&(n->left));
	free_tree(&(n->right));
	free_free(&n);
	return (1);
}

void				size_tree_dir(t_t *root, int *sum)
{
	if (root == NULL)
		return ;
	if (is_directory(root->fullpath))
		*sum += 1;
	size_tree_dir(root->left, &(*sum));
	size_tree_dir(root->right, &(*sum));
}

void				display_tree_error(t_t *root)
{
	if (root != NULL)
	{
		if (root->left != NULL)
			display_tree_error(root->left);
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(root->name, 2);
		ft_putendl_fd(": No such file or directory", 2);
		if (root->right != NULL)
			display_tree_error(root->right);
	}
}
