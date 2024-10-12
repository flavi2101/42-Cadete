/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:52:43 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/12 08:53:30 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isascii(int c)
{
	unsigned char	check_char;

	check_char = (unsigned char)(c);
	if (check_char <= 127)
		return (1);
	return (0);
}
