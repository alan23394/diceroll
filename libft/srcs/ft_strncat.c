/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:39:21 by abarnett          #+#    #+#             */
/*   Updated: 2018/06/02 13:45:59 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*cur;

	cur = s1;
	while (*cur)
		cur++;
	while (n-- && *s2)
		*cur++ = *s2++;
	*cur = '\0';
	return (s1);
}
