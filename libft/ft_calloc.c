/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:59:59 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/07 11:18:21 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*mem;

	len = nmemb * size;
	mem = malloc(len + 1);
	if (!mem)
		return (NULL);
	ft_bzero(mem, len);
	return (mem);
}
