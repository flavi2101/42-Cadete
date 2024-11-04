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
int	parse(char *in_flags, int len_in_flags, char *check_flag);
int	count_digis(int user_inp);
int	get_width_and_precision(t_strfla *pt_flags_info, const char	*flags, int *num_qnty);
char	*get_flags(t_strfla *flag_info, int len_only_flags, int len_flags_plus_nums, const char * ptr_after_percentage);
t_strfla	*get_flags_width_precision_delimiter(const char * ptr_after_percentage, int * len);
int	error_handle(t_strfla	*flags_info, char *conversion_opt);
int	handle_args(t_strfla *flags_info);
void	free_flags(t_strfla *flags_info);
#endif

