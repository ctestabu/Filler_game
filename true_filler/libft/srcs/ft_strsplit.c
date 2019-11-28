/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   123.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:38:40 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/19 19:38:40 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(char **dest, int j)
{
	char **copy;

	copy = dest;
	while (j-- != 0)
	{
		free(*dest);
		dest++;
	}
	free(copy);
}

static char		**ft_input(char **dest, const char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0' && c != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') \
			|| (s[i] != c && i == 0))
		{
			if (s[i] == c)
				i++;
			while (s[i] != c && s[i] != '\0')
				dest[j][k++] = s[i++];
			k = 0;
			j++;
		}
		else
			i++;
	}
	return (dest);
}

static char		**ft_sum_sym(char const *s, char **dest, char c, int *symb)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (s[++i] != '\0' && c != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') \
			|| (s[i] != c && i == 0))
		{
			if (s[i] != c && i == 0)
				*symb = *symb + 1;
			while (s[++i] != c && s[i] != '\0')
				*symb = *symb + 1;
			if (!(dest[j++] = (char *)malloc(sizeof(char) * (*symb) + 1)))
			{
				ft_free(dest, j);
				return (NULL);
			}
			dest[j - 1][*symb] = '\0';
			*symb = 0;
			i--;
		}
	}
	return (ft_input(dest, s, c));
}

static int		ft_sum_words(char const *s, char c)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (s[i] != '\0' && c != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') \
			|| (s[i] != c && i == 0))
			sum++;
		i++;
	}
	return (sum);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		sum;
	int		symb;

	symb = 0;
	if (!s || !c)
		return (NULL);
	sum = ft_sum_words(s, c);
	if (sum == 0)
	{
		if (!(dest = (char **)malloc(sizeof(char *) * 1)))
			return (NULL);
		dest[0] = NULL;
		return (dest);
	}
	if (!(dest = (char **)malloc(sizeof(char *) * (sum + 1))))
		return (NULL);
	dest[sum] = NULL;
	dest = ft_sum_sym(s, dest, c, &symb);
	return (dest);
}
