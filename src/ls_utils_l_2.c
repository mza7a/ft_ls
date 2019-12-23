/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_l_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:11:29 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/01 17:27:27 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					calc_total(t_t *root, int i)
{
	struct stat		buff;

	if (root != NULL)
	{
		if (root->left != NULL)
			i = calc_total(root->left, i);
		if (lstat(root->fullpath, &buff) == 0)
			i += (int)buff.st_blocks;
		if (root->right != NULL)
			i = calc_total(root->right, i);
	}
	return (i);
}

void				print_total(t_t *root)
{
	int				i;

	i = 0;
	i = calc_total(root, i);
	mini_printf("total %d\n", i);
}

void				print_groups(struct stat buff, int us, int grp)
{
	struct passwd	*pw;
	struct group	*gr;
	int				i;

	pw = getpwuid(buff.st_uid);
	gr = getgrgid(buff.st_gid);
	i = (us - ft_strlen(pw->pw_name)) + 1;
	ft_putstr(" ");
	ft_putstr(pw->pw_name);
	while (i--)
		ft_putstr(" ");
	ft_putstr(" ");
	i = (grp - ft_strlen(gr->gr_name)) + 1;
	ft_putstr(gr->gr_name);
	while (i--)
		ft_putstr(" ");
}

void				print_files_rest(struct stat buf, int max_major,
		int max_minor, int size)
{
	int				i;

	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
	{
		drop_spaces(max_major - size_len(major(buf.st_rdev)) + 2);
		mini_printf("%d, ", major(buf.st_rdev));
		drop_spaces(max_minor - size_len(minor(buf.st_rdev)));
		ft_putnbr(minor(buf.st_rdev));
	}
	else
	{
		if ((max_major + max_minor) > size)
			i = max_major + max_minor + 3;
		else if (max_major && (max_major + max_minor) < size)
			i = 2;
		else
			i = 1;
		while (i-- > 0)
			ft_putchar(' ');
		drop_spaces((size - size_len(buf.st_size)));
		ft_putnbr_long(buf.st_size);
	}
}
