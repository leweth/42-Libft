/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-yah <mben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:45:32 by mben-yah          #+#    #+#             */
/*   Updated: 2024/01/07 11:56:51 by mben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;

	tmp = malloc(ft_strlen(s1) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, ft_strlen(s1) + 1);
	return (tmp);
}
