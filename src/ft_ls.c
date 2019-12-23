/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 02:30:46 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/23 02:51:33 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					size_len(unsigned long int i)
{
	int				j;

	j = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= 10;
		j++;
	}
	return (j);
}

void				free_2d_char(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void				argv_managing(char **av, int option)
{
	t_t				*files;
	t_t				*folders;
	t_t				*error;
	int				*tab;

	files = NULL;
	folders = NULL;
	error = NULL;
	while (*(++av) != NULL)
	{
		if (!isfilefolder(*av))
			error = insert_name(error, *av, *av);
		else
			check_argv(av, option, &folders, &files); //go to check_argv
	}
	check = 0;
	tab = check_option_n_print(error, files, option);
	if (files && folders)
		mini_printf("\n");
	display_dir(folders, option, 0,
		size_tree(folders) + size_tree(files) + size_tree(error));
	if (option & L)
		free(tab);
	free_tree(&files);
	free_tree(&folders);
}

int					main(int ac, char **av)
{
	int				option;
	int				start_arg;

	if (ac == 1)
	{
		open_dir(".", 0);
		return (0);
	}
	check_flags(av, &option);
	start_arg = no_file(av);
	if (ac >= 2 && !start_arg)
	{
		open_dir(".", option);
		return (0);
	}
	else if (ac >= 2 && start_arg)
	{
		check += Y;
		argv_managing(av + start_arg - 1, option);
		return (0);
	}
}
