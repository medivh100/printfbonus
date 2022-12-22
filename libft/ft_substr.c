/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yst-laur <yst-laur@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:26:56 by yst-laur          #+#    #+#             */
/*   Updated: 2021/09/24 10:27:03 by yst-laur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rs;

	i = 0;
	if (!s)
		return (NULL);
	if (start > (unsigned int) ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	while (i < len && s[i])
		i++;
	rs = malloc((i + 1) * sizeof(char));
	if (rs == NULL)
		return (NULL);
	ft_strlcpy(rs, s + start, len + 1);
	return (rs);
}
