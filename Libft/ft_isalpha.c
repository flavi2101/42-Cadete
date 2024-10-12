/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:47:40 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/12 08:51:54 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalpha(int c)
{
	unsigned char	letter;

	letter = (unsigned char)(c);
	if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
		return (1);
	return (0);
}
