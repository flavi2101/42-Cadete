/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:58:02 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/12 10:01:30 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	letter;

	letter = (unsigned char)(c);
	if (letter >= 97 && letter <= 122)
		return ((int)(letter - 32));
	return (c);
}
