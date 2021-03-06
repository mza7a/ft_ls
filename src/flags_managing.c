/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:10:46 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/27 00:31:48 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			check_char(char c)
{
	return (c == 'a' || c == 'l' || c == 'R' || c == 'r' || c == 't'
			|| c == 'p' || c == 'g');
}

void		flags_exist(char c, int **option)
{
	if (c == 'a' && !(**option & A))
		**option += A;
	else if (c == 'g' && !(**option & G))
		**option += G;
	else if (c == 'l' && !(**option & L))
		**option += L;
	else if (c == 'R' && !(**option & R))
		**option += R;
	else if (c == 'r' && !(**option & S))
		**option += S;
	else if (c == 't' && !(**option & T))
		**option += T;
	else if (c == 'p' && !(**option & P))
		**option += P;
	else if (!check_char(c))
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putendl_fd("\nusage: ./ft_ls [-Ralprt] [file ...]", 2);
		exit(0);
	}
}

void		check_flags(char **av, int *option)
{
	int		i;
	int		j;

	*option = 0;
	i = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][0] == '-')
		{
			while (av[i][++j])
				flags_exist(av[i][j], &option);
		}
		else
			return ;
	}
}
