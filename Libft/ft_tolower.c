/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:37:06 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/12 10:11:26 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	letter;

	letter = (unsigned char)(c);
	if (letter >= 65 && letter <= 90)
		return ((int)(letter + 32));
	return (c);
}
