#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
typedef struct s_flag_info_plus_conver
{
	char	conversion;
	int	width;	
	char	*flags;
	int	total_len;
	int	precision;
	int	(*fuc)(struct s_flag_info_plus_conver *, va_list);

} t_strfla;
t_strfla	*get_flags_width_precision_delimiter(const char * ptr_after_percentage, int * len);
int	handle_args(t_strfla *flags_info);
void	free_flags(t_strfla *flags_info);
#endif

