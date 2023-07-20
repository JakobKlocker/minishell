/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklocker <jklocker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:30:50 by jklocker          #+#    #+#             */
/*   Updated: 2022/11/08 16:29:43 by jklocker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		min_width;
	int		percision;
	int		length_modifier;
	int		var_length;
	int		hash;

}			t_flags;

int			ft_printf(const char *str, ...);

//Generel
void		check_minus_flag(t_flags *flags, int *counter);
void		print_min_width(t_flags *flags, int *counter);
const char	*ft_manage_arg(const char *str, va_list ap, t_flags *flags,
				int *counter);

//Setting flags
void		init_flags(t_flags *flags, const char *str);
void		null_flags(t_flags *flags);
const char	*set_zero(t_flags *flags, const char *str);
const char	*set_dot(t_flags *flags, const char *str);
const char	*loop_str(t_flags *flags, const char *str);

//Chars
void		char_found(char *str, char var, t_flags *flags, int *counter);
void		char_flags(char *str, t_flags *flags, int *counter);
void		ft_putchar_fd_c(char c, int fd, int *counter);

//Strings
void		str_found(char *str, char *var, t_flags *flags, int *counter);
void		str_flags(char *str, char *var, t_flags *flags, int *counter);
void		ft_putstr_fd_n_c(char *s, int fd, int *counter, int n);
void		ft_putstr_fd_c(char *s, int fd, int *counter);

//Ptr
void		ptr_found(char *str, void *ptr, t_flags *flags, int *counter);
void		ptr_flags(char *str, void *ptr, t_flags *flags, int *counter);
void		ft_putnbr_base_p(void *addr, char *base, int *counter);
void		print_bases(unsigned long nbr, int len, char *base, int *counter);

//Int / d
void		int_found(char *str, int var, t_flags *flags, int *counter);
void		int_flags(char *str, int var, t_flags *flags, int *counter);
void		int_flag_zero(t_flags *flags, int *counter);
void		int_flag_space(int var, t_flags *flags, int *counter);
void		int_flag_plus(int var, t_flags *flags, int *counter);
void		int_flag_percision(t_flags *flags, int *counter, int var);
void		int_print_min_width(t_flags *flags, int *counter, int var);
void		int_check_minus_flag(t_flags *flags, int *counter, int var);
void		ft_putnbr_fd_c(long n, int fd, int *counter);

// Int Unsigned

void		u_int_found(char *str, unsigned int var, t_flags *flags,
				int *counter);
void		u_int_flags(char *str, unsigned int var, t_flags *flags,
				int *counter);
void		ft_putnbr_u_fd_c(unsigned int n, int fd, int *counter);
void		u_int_check_minus_flag(t_flags *flags, int *counter);
void		u_int_print_min_width(t_flags *flags, int *counter);
void		u_int_flag_plus(t_flags *flags, int *counter);
void		u_int_flag_percision(t_flags *flags, int *counter);

//Hex Small

void		hex_found(char *str, unsigned int var, t_flags *flags,
				int *counter);
void		hex_flags(char *str, unsigned int var, t_flags *flags,
				int *counter);
void		ft_putnbr_base_c(unsigned long nbr, char *base, int *counter);
void		hash_flag_small(unsigned int var, t_flags *flags, int *counter);

//Hex Big
void		hex_big_found(char *str, unsigned int var, t_flags *flags,
				int *counter);
void		hash_flag_big(unsigned int var, t_flags *flags, int *counter);
void		pointer_error(int *counter);

//Lengths
int			int_len_u(unsigned int n);
int			int_len(int n);
int			hex_len(unsigned long nb);
int			hex_len_ptr(void *ptr);
size_t		ft_strlen_n(const char *str);
#endif