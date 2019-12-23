/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:10:25 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/01 17:22:06 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int							biggest_size_int(t_t *root, int truue)
{
	unsigned long int		res;
	unsigned long int		lres;
	unsigned long int		rres;
	struct stat				buff;

	if (root == NULL)
		return (0);
	if (!lstat(root->fullpath, &buff))
	{
		if (truue)
			res = size_len(buff.st_nlink);
		else
			res = size_len(buff.st_size);
		lres = biggest_size_int(root->left, truue);
		rres = biggest_size_int(root->right, truue);
		if (lres > res)
			res = lres;
		if (rres > res)
			res = rres;
		return (res);
	}
	return (0);
}

int							biggest_size_usr(t_t *root)
{
	int						res;
	int						lres;
	int						rres;
	struct stat				buff;
	struct passwd			*pwd;

	if (root == NULL)
		return (0);
	if (!lstat(root->fullpath, &buff))
	{
		pwd = getpwuid(buff.st_uid);
		res = ft_strlen(pwd->pw_name);
		lres = biggest_size_usr(root->left);
		rres = biggest_size_usr(root->right);
		if (lres > res)
			res = lres;
		if (rres > res)
			res = rres;
		return (res);
	}
	return (0);
}

int							biggest_size_grp(t_t *root)
{
	int						res;
	int						lres;
	int						rres;
	struct stat				buff;
	struct group			*grp;

	if (root == NULL)
		return (0);
	if (!lstat(root->fullpath, &buff))
	{
		lstat(root->fullpath, &buff);
		grp = getgrgid(buff.st_gid);
		res = ft_strlen(grp->gr_name);
		lres = biggest_size_grp(root->left);
		rres = biggest_size_grp(root->right);
		if (lres > res)
			res = lres;
		if (rres > res)
			res = rres;
		return (res);
	}
	return (0);
}

int							biggest_minor(t_t *root)
{
	int						res;
	int						lres;
	int						rres;
	struct stat				buff;

	if (root == NULL)
		return (0);
	if (!lstat(root->fullpath, &buff))
	{
		res = size_len(minor(buff.st_rdev));
		lres = biggest_minor(root->left);
		rres = biggest_minor(root->right);
		if (S_ISCHR(buff.st_mode) || S_ISBLK(buff.st_mode))
		{
			if (lres > res)
				res = lres;
			if (rres > res)
				res = rres;
			return (res);
		}
	}
	return (0);
}

int							biggest_major(t_t *root)
{
	int						res;
	int						lres;
	int						rres;
	struct stat				buff;

	if (root == NULL)
		return (0);
	if (!lstat(root->fullpath, &buff))
	{
		res = size_len(major(buff.st_rdev));
		lres = biggest_major(root->left);
		rres = biggest_major(root->right);
		if (S_ISCHR(buff.st_mode) || S_ISBLK(buff.st_mode))
		{
			if (lres > res)
				res = lres;
			if (rres > res)
				res = rres;
			return (res);
		}
	}
	return (0);
}
