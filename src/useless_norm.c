/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:12:07 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/23 17:02:01 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				is_arg_directory(char *path)
{
	struct stat	buff;
	char		*tmp;

	if (is_symbolic(path))
		tmp = ft_strjoin(path, "/");
	else
		tmp = ft_strdup(path);
	lstat(tmp, &buff);
	free(tmp);
	if (S_ISDIR(buff.st_mode))
		return (1);
	return (0);
}

void			check_argv(char **av, int option, t_t **folders, t_t **files)
{
	if (is_symbolic(*av) && ((option & R && !(option & L))
		|| ((option & L) && *av[ft_strlen(*av) - 1] == '/')))
		*folders = do_flags(*folders, *av, *av, option);
	else if (option & L && is_symbolic(*av) && *av[ft_strlen(*av) - 1] != '/')
		*files = do_flags(*files, *av, *av, option);
	else if (is_arg_directory(*av))
		*folders = do_flags(*folders, *av, *av, option);
	else
		*files = do_flags(*files, *av, *av, option);
}

int				*check_option_n_print(t_t *error, t_t *files, int option)
{
	int			*tab;

	tab = NULL;
	if (option & L)
		do_stuff(files, &tab);
	display_tree_error(error);
	display_tree(files, option, tab);
	return (tab);
}

int				*check_option_l_r(int option, t_t *root, int which)
{
	int			*tab;
	int			len;
	struct stat	buff;

	tab = NULL;
	if (option & L && which == 1)
	{
		if (root && lstat(root->fullpath, &buff) == 0)
			print_total(root);
		do_stuff(root, &tab);
	}
	else if (option & R && which == 2)
	{
		size_tree_dir(root, &len);
		check_subddir(root, option, 0, len);
	}
	return (tab);
}

void			print_error(char *dir_name)
{
	char		*tmp;

	ft_putstr_fd("ls: ", 2);
	if (!(tmp = ft_strrchr(dir_name, '/')))
		perror(dir_name);
	else
		perror(tmp + 1);
}
