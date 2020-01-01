/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:49:31 by clde-ber          #+#    #+#             */
/*   Updated: 2019/12/22 11:58:58 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	if (!dst || !src)
		return (0);
	i = ft_strlen(src);
	j = ft_strlen(dst);
	if (dstsize > 0)
	{
		dstsize = (dstsize > i) ? i : dstsize - 1;
		dst = (char *)ft_memmove(dst, src, dstsize);
		dst[dstsize] = '\0';
	}
	return (i);
}
