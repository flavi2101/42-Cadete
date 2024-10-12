/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 08:55:30 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/12 08:56:46 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isprint(int c)
{
	unsigned char	is_printable;

	is_printable = (unsigned char)(c);
	if (is_printable >= 32 && is_printable <= 126)
		return (1);
	return (0);
}
