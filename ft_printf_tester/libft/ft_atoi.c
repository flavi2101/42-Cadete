/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:07:05 by flferrei          #+#    #+#             */
/*   Updated: 2024/10/16 15:51:16 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	return_value;
	int	flag;

	return_value = 0;
	flag = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		++nptr;
	if (*nptr == '-')
		flag *= -1;
	if (*nptr == '-' || *nptr == '+')
		++nptr;
	if (!(*nptr >= '0' && *nptr <= '9'))
		return (return_value);
	while (*nptr && (*nptr >= '0' && *nptr <= '9'))
	{
		return_value = return_value * 10 + (*nptr++ - 48);
	}
	return (flag * return_value);
}
