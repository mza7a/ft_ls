/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:47:36 by hmzah             #+#    #+#             */
/*   Updated: 2019/03/27 14:50:04 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int arg)
{
	if (arg >= 'A' && arg <= 'Z')
		return (arg + 32);
	return (arg);
}
