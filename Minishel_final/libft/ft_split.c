/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igrousso <igrousso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:19:07 by igrousso          #+#    #+#             */
/*   Updated: 2025/03/13 23:15:38 by igrousso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/free_etc.h"
#include "libft.h"

int	count_word(const char *s, char c)
{
	int	i;
	int	j;
	int	ct;

	i = 0;
	j = 0;
	ct = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && j == 0)
		{
			j = 1;
			ct++;
		}
		else if (s[i] == c)
			j = 0;
		i++;
	}
	return (ct);
}

char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((finish - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		ft_free(tab[i++]);
	ft_free(tab);
}

char	**ft_split2(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && index >= 0)
		{
			tab[j] = word_dup(s, index, i);
			if (!tab[j++])
				return (free_tab(tab), NULL);
			index = -1;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (!s || !tab)
		return (NULL);
	tab = ft_split2(tab, s, c);
	return (tab);
}

// int	main(int a, char **v)
// {
// 	int i;
// 	char **tab;

// 	if (a == 3)
// 	{
// 		i = 0;
// 		tab = ft_split(v[1], *v[2]);
// 		while (tab[i])
// 		{
// 			printf("%s\n", tab[i]);
// 			i++;
// 		}
// 		free(tab);
// 	}
// 	return (0);
// }