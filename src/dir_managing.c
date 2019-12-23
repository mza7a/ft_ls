/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_managing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:10:36 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/23 17:06:23 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_t					*do_flags(t_t *root, char *name, char *path, int option)
{
	if (option & T)
	{
		if (option & S)
			root = check_time_reverse(root, name, path, option);
		else
			root = check_time(root, name, path, option);
	}
	else
	{
		if (option & S)
			root = check_ascii_reverse(root, name, path, option);
		else
			root = check_ascii(root, name, path, option);
	}
	return (root);
}

void				open_dir(char *dir_name, int option)
{
	DIR				*dir;
	struct dirent	*sd;
	t_t				*root;
	int				*tab;

	root = NULL;
	tab = NULL;
	if (!(dir = opendir(dir_name)))
	{
		print_error(dir_name);
		return ;
	}
	while ((sd = readdir(dir)) != NULL)
		root = do_flags(root, sd->d_name, dir_name, option);
	closedir(dir);
	tab = check_option_l_r(option, root, 1);
	display_tree(root, option, tab);
	check_option_l_r(option, root, 2);
	if (tab)
		free(tab);
	free_tree(&root);
}
