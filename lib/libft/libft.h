/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:44:01 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/11/14 13:55:46 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // Included for main testing.
# include <fcntl.h>
# include <string.h> // Included for function testing
# include <stdint.h> // Included for SIZE_MAX error treating.
# include <stdarg.h>

# define BUFFER_SIZE 10

//------------------------------------part-one
int		ft_isalpha(int c); //1
int		ft_isdigit(int c); //2
int		ft_isalnum(int c); //3
int		ft_isascii(int c); //4
int		ft_isprint(int c); //5
size_t	ft_strlen(const char *s); //6
void	*ft_memset(void *s, int c, size_t n); //7
void	ft_bzero(void *s, size_t n); //8
void	*ft_memcpy(void *dest, const void *src, size_t n); //9
void	*ft_memmove(void *dest, const void *src, size_t n); //10
size_t	ft_strlcpy(char *dst, const char *src, size_t size); //11
size_t	ft_strlcat(char *dest, const char *src, size_t size); //12
int		ft_toupper(int c); //13
int		ft_tolower(int c); //14
char	*ft_strchr(const char *s, int c); //15
char	*ft_strrchr(const char *s, int c); //16
int		ft_strncmp(const char *s1, const char *s2, size_t n); //17
void	*ft_memchr(const void *s, int c, size_t n); //18
int		ft_memcmp(const void *s1, const void *s2, size_t n); //19
char	*ft_strnstr(const char *s1, const char *s2, size_t n); //20
int		ft_atoi(const char *nptr); //21
void	*ft_calloc(size_t nmemb, size_t size); //22
char	*ft_strdup(const char *s); //23
//------------------------------------part-two
char	*ft_substr(char const *s, unsigned int start, size_t len); //1
char	*ft_strjoin(char const *s1, char const *s2); //2
char	*ft_strtrim(char const *s1, char const *set); //3
char	**ft_split(char const *s, char c); //4
char	*ft_itoa(int n); //5
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); //6
void	ft_striteri(char *s, void (*f)(unsigned int, char*)); //7
void	ft_putchar_fd(char c, int fd); //8
void	ft_putstr_fd(char *s, int fd); //9
void	ft_putendl_fd(char *s, int fd); //10
void	ft_putnbr_fd(int n, int fd); //11
//------------------------------------bonus
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*GNL SUB-Functions*/
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
int		needs_null(char *buff);
/*GNL Main Operation Functions */
char	*next_line(char *buff);
char	*line_thrower(char *buff);
char	*fd_read(int fd, char *buff);
char	*get_next_line(int fd);

/*Printf function */
int		ft_printf(const char *str, ...);
int		convert(va_list arg, char c);
int		ft_putchr(char c);
int		ft_putstr(char *str);
int		ft_putnb(int nb);
int		ft_unsigned(unsigned int nb);
int		ft_puthex(unsigned long nb, char c);
int		ft_putptr(unsigned long nb);

#endif