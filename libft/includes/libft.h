/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:28:36 by hmuravch          #+#    #+#             */
/*   Updated: 2018/09/07 09:33:21 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include <wchar.h>

# define MIN_INT	(-9223372036854775807 - 1)

typedef	struct		s_type
{
	void			*p;
	char			*s;
	wchar_t			*cap_s;
	char			c;
	wint_t			cap_c;
	intmax_t		d;
	intmax_t		cap_d;
	intmax_t		x;
	intmax_t		cap_x;
	uintmax_t		o;
	uintmax_t		cap_o;
	uintmax_t		u;
	uintmax_t		cap_u;
}					t_type;

typedef	struct		s_sym
{
	int				i;
	int				sign;
	int				len;
	int				sharp;
	int				minus;
	int				zero;
	int				size;
	int				dot;
	int				check;
	char			*tmp;
	char			*tmp2;
	size_t			bits;
	size_t			crutch;
	size_t			width;
	size_t			save_width;
	size_t			save_precision;
	size_t			save_arg_len;
	size_t			arg_len;
	size_t			precision;
}					t_sym;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_sqrt(int nb);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_is_whitespace(int c);
int					*ft_range(int min, int max);
int					ft_printf(const char *format, ...);
int					ft_num_of_words(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_putnbr(intmax_t n);
void				initializer(t_sym *sym);
void				ft_putstr(char const *s);
void				print_plus_d(t_sym *sym);
void				ft_putnbr_u(uintmax_t n);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_swap(char **a, char **b);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				*ft_realloc(void *ptr, size_t size);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_striter(char *s, void (*f)(char *));
void				ft_lstadd(t_list **alst, t_list *new);
void				*ft_memset(void *dest, int sym, size_t len);
void				*ft_memchr(const void *arr, int c, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				missing_width_and_precision(const char *format, t_sym *sym);
void				missing_flags(const char *format, t_sym *sym);
void				checking_sizes(const char *format, t_sym *sym);
void				print_width_d(intmax_t *d, t_sym *sym);
void				print_space_d(intmax_t *d, t_sym *sym);
void				print_zero_d(intmax_t *d, t_sym *sym);
void				print_precision_d(intmax_t *d, t_sym *sym);
void				print_zero_x(intmax_t *x, t_sym *sym);
void				print_precision_x(intmax_t *x, t_sym *sym);
void				print_width_x(t_sym *sym);
void				print_space_u(t_sym *sym);
void				print_zero_u(t_sym *sym);
void				print_width_u(t_sym *sym);
void				print_precision_u(t_sym *sym);
void				print_zero_o(uintmax_t *o, t_sym *sym);
void				print_width_o(t_sym *sym);
void				print_precision_o(uintmax_t *o, t_sym *sym);
void				print_width_not_minus_cap_s(t_sym *sym);
void				print_width_yes_minus_cap_s(t_sym *sym);
char				*ft_itoa(intmax_t n);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *add);
char				*ft_putchar_unicode(wchar_t c, t_sym *sym);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_fill_word(char const *s, char c, int *i);
char				*ft_strjoin(char const *s1, char const *s2);
char				*take_number(const char *format, t_sym *sym);
char				*ft_precision(const char *format, t_sym *sym);
char				*ft_itoa_base(uintmax_t num, int base, int upper);
char				*ft_strncat(char *dst, const char *add, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin_free(char *s1, char *s2, int first, int second);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
size_t				ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
size_t				print_percent(t_sym *sym);
size_t				ft_strlen_int(intmax_t num);
size_t				ft_strlen_u_int(uintmax_t num);
size_t				print_s(va_list arg, t_sym *sym, char *s);
size_t				print_p(va_list arg, void *p, t_sym *sym);
size_t				print_c(va_list arg, char *c, t_sym *sym);
size_t				print_x(va_list arg, intmax_t *x, t_sym *sym);
size_t				print_u(va_list arg, uintmax_t *u, t_sym *sym);
size_t				print_o(va_list arg, uintmax_t *o, t_sym *sym);
size_t				print_i_or_d(va_list arg, t_sym *sym, intmax_t *d);
size_t				print_cap_c(va_list arg, wint_t *cap_c, t_sym *sym);
size_t				print_cap_s(va_list arg, wchar_t *cap_s, t_sym *sym);
size_t				print_cap_d(va_list arg, intmax_t *cap_d, t_sym *sym);
size_t				print_cap_x(va_list arg, intmax_t *cap_x, t_sym *sym);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				print_cap_o(va_list arg, uintmax_t *cap_o, t_sym *sym);
size_t				print_cap_u(va_list arg, uintmax_t *cap_u, t_sym *sym);
intmax_t			cast_int(va_list arg, t_sym *sym);
intmax_t			cast_uint(va_list arg, t_sym *sym);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
