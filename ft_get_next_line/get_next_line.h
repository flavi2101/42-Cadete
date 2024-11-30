/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flferrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:00:26 by flferrei          #+#    #+#             */
/*   Updated: 2024/11/30 16:12:15 by flferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_check_term_or_break(char *data);
char	*ft_strjoin(char *dst, char *src, int src_len);
char	*ft_clear_mem(char *mem1, char *data, int *end_file);
int		check_buffer_value(int size_break, char **info_file);
#endif
