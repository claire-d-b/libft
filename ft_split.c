/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:16:15 by clde-ber          #+#    #+#             */
/*   Updated: 2020/01/03 17:37:42 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	len_wd(char const *str, int c)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	return (i);
}

static size_t	count_malloc(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (s[i] == '\0' || c == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void		*ft_free(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;

	i = 0;
	j = 0;
	if (!s || !*s)
		return ((char **)ft_calloc(2, sizeof(char *)));
	if (!(res = malloc(sizeof(char *) * (count_malloc(s, c) + 1))))
		return (0);
	while (i < ft_strlen(s))
	{
		while (j < count_malloc(s, c) && s[i] && s[i] != c)
		{
			if (!(res[j] = malloc(sizeof(char) * (len_wd(&s[i], c) + 1))))
				return (ft_free(res, j));
			res[j] = ft_memmove(res[j], &s[i], len_wd(&s[i], c) + 1);
			res[j][len_wd(&s[i], c)] = '\0';
			j++;
			i += len_wd(&s[i], c);
		}
		i++;
	}
	res[count_malloc(s, c)] = 0;
	return (res);
}
