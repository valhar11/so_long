/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:57:26 by vlibert           #+#    #+#             */
/*   Updated: 2023/05/30 17:14:27 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	dst_len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	dst_len = ft_strlen((char *) s + start);
	if (len > dst_len)
		len = dst_len;
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
