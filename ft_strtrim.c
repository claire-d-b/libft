/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:14:11 by clde-ber          #+#    #+#             */
/*   Updated: 2020/01/02 11:58:45 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	is_in_set(char const c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 || !set)
		return (ft_strdup(""));
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	len--;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	if (len + 1 == i)
		return (ft_strdup(""));
	while (len > i && s1[len] && is_in_set(s1[len], set))
		len--;
	return (ft_substr(s1, i, len - i + 1));
}
