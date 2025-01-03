#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define NUMBERS "0123456789"
# define XLOW "0123456789abcdef"
# define XHIGH "0123456789ABCDEF"

typedef struct s_f
{
	int	f_m;
	int	f_z;
	int	f_s;
	int	f_h;
	int	f_p;
	int	f_zp;
	int	dot;
	int	zero;
	int	space;
	int	precision;
	int	width;
	int	i;
	int	nb;
	int	cprint;
}	t_f;

//MY_PRINTF
int		my_printf(const char *format, ...);

//FLAGS
void	check_flags(const char *format, va_list args, t_f *f);

//PRINTERS
void	c_printer(va_list args, t_f *f);
void	s_printer(va_list args, t_f *f);
void	iduxx_printer(char c, va_list args, t_f *f);
void	ptr_printer(va_list args, t_f *f);
void	percent_printer(t_f *f);

//HELP FUNCTIONS FOR IDUXX_PRINTER
int		houses(unsigned int n, int base, t_f *f);
void	my_putnbase(unsigned int n, char *base);
int		houses2(unsigned long int n, int base, t_f *s);
void	my_putnbase2(unsigned long int n, char *base);

//HELP FUNCTIONS
void	my_putchar(char c);
void	my_putstr(char *s);
int		my_strlen(char *s);
int		my_isdigit(int c);
int		my_strncmp(const char *s1, const char *s2, size_t n);

#endif
