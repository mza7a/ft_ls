/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 02:31:02 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/01 17:30:06 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				print_perm_type(struct stat buf)
{
	if (S_ISBLK(buf.st_mode))
		ft_putchar('b');
	else if (S_ISSOCK(buf.st_mode))
		ft_putchar('s');
	else if (S_ISCHR(buf.st_mode))
		ft_putchar('c');
	else if (S_ISLNK(buf.st_mode))
		ft_putchar('l');
	else
		ft_putstr((S_ISDIR(buf.st_mode)) ? "d" : "-");
}

void				print_perm(struct stat buf)
{
	print_perm_type(buf);
	ft_putstr((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWUSR) ? "w" : "-");
	if (buf.st_mode & S_ISUID)
		ft_putstr((buf.st_mode & S_IXUSR) ? "s" : "S");
	else
		ft_putstr((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWGRP) ? "w" : "-");
	if (buf.st_mode & S_ISGID)
		ft_putstr((buf.st_mode & S_IXGRP) ? "s" : "S");
	else
		ft_putstr((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((buf.st_mode & S_IWOTH) ? "w" : "-");
	if (buf.st_mode & S_ISVTX)
		ft_putstr((buf.st_mode & S_IXOTH) ? "t" : "T");
	else
		ft_putstr((buf.st_mode & S_IXOTH) ? "x" : "-");
}

void				print_acl(char *path)
{
	acl_t			acl;
	int				t;
	int				a;

	acl = NULL;
	t = 0;
	a = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	t = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (t > 0)
	{
		ft_putchar('@');
		a++;
	}
	else if (acl != NULL)
	{
		ft_putchar('+');
		a++;
	}
	if (a == 0)
		ft_putchar(' ');
	if (acl)
		acl_free(acl);
}

void				print_permissions(struct stat buff, t_t *root)
{
	print_perm(buff);
	print_acl(root->fullpath);
}

int					display_tree_l(t_t *root, int *tab, int option)
{
	struct stat		buff;

	if (!lstat(root->fullpath, &buff))
	{
		print_permissions(buff, root);
		mini_printf(" %dd", tab[0], buff.st_nlink);
		print_groups(buff, tab[1], tab[2], option);
		print_files_rest(buff, tab[4], tab[5], tab[3]);
		print_time(buff);
		return (1);
	}
	return (0);
}
