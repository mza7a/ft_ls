/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_l_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:11:38 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/01 17:28:49 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void					print_time(struct stat buff)
{
	time_t				now;
	char				*curr_time;
	char				*file_time;
	char				*stime;

	stime = ft_strsub(ctime(&buff.st_mtime), 4, 6);
	mini_printf(" %s ", stime);
	free(stime);
	time(&now);
	curr_time = ft_strsub(ctime(&now), 4, 4);
	file_time = ft_strsub(ctime(&buff.st_mtime), 4, 4);
	if (((int)now - buff.st_mtime) >= 15768000)
	{
		free(file_time);
		file_time = ft_strsub(ctime(&buff.st_mtime), 20, 4);
		mini_printf(" %s ", file_time);
	}
	else
	{
		stime = ft_strsub(ctime(&buff.st_mtime), 11, 5);
		mini_printf("%s ", stime);
		free(stime);
	}
	free(curr_time);
	free(file_time);
}

int						*get_widths(t_t *root)
{
	int					*tab;

	tab = (int *)malloc(sizeof(int) * 6);
	tab[0] = biggest_size_int(root, 1);
	tab[1] = biggest_size_usr(root);
	tab[2] = biggest_size_grp(root);
	tab[3] = biggest_size_int(root, 0);
	tab[4] = biggest_major(root);
	tab[5] = biggest_minor(root);
	return (tab);
}

void					do_stuff(t_t *root, int **tab)
{
	*tab = get_widths(root);
}

void					drop_spaces(int i)
{
	while (i-- > 0)
		ft_putstr(" ");
}

void					ft_putnbr_long(long int num)
{
	unsigned long int	nb;

	if (num < 0)
	{
		ft_putchar('-');
		nb = (unsigned long int)(num * -1);
	}
	else
		nb = (unsigned long int)num;
	if (nb >= 10)
		ft_putnbr_long(nb / 10);
	ft_putchar(num % 10 + 48);
}
