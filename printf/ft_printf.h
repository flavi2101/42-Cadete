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

} t_strfla;
#endif

