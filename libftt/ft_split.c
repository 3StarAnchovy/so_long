/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihong <jihong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:30:48 by jihong            #+#    #+#             */
/*   Updated: 2021/12/06 18:01:10 by jihong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if ((s[0] != c && i == 0) || \
			(*(s + i) == c && *(s + i + 1) != c && *(s + i + 1) != '\0'))
		{
			cnt ++;
		}
		i++;
	}
	return (cnt);
}

static char	*ft_strndup(const char *str, int len)
{
	char	*ret;
	int		i;

	i = 0;
	if (len == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		*(ret + i) = *(str + i);
		i ++;
	}
	*(ret + i) = '\0';
	return (ret);
}

static char	**free_str(char **str)
{
	int	i;

	i = 0;
	while (*(str + i) != NULL)
	{
		free(str + i);
		i ++;
	}
	free(str);
	return (NULL);
}

static char	*get_str(const char *str, int *flag, char c)
{
	char	*middle;
	int		i;

	*flag = 1;
	i = 0;
	middle = NULL;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
		{
			middle = ft_strndup(str, i);
			if (middle == NULL)
				return (NULL);
			return (middle);
		}
		else if (i == (int)(ft_strlen(str)) - 1)
		{
			middle = ft_strndup(str, i + 1);
			if (middle == NULL)
				return (NULL);
			return (middle);
		}
		i ++;
	}
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	*middle;
	char	**str;
	int		i;
	int		flag;
	int		str_index;

	str_index = 0;
	i = -1;
	str = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[++i] != '\0')
	{
		flag = 0;
		if ((s[0] != c && i == 0))
			middle = get_str((s + i), &flag, c);
		else if (*(s + i) == c && *(s + i + 1) != c && *(s + i + 1) != '\0')
			middle = get_str((s + i + 1), &flag, c);
		if (middle == NULL && flag == 1)
			return (free_str(str));
		else if (flag == 1)
			str[str_index ++] = middle;
	}
	str[str_index] = 0;
	return (str);
}
