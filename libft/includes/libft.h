#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "ft_stack.h"

# define MAX_FILE_DESCRIPTOR	RLIMIT_NOFILE
# define BUFFER_SIZE	32

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *str);
long long	ft_atol(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isint(long long int n);
int			ft_isprint(int c);
int			ft_isspace(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
void		ft_lstprint(t_list *lst);
void		ft_lstremove(t_list **lst);
int			ft_lstsize(t_list *lst);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
int			ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_putnbr(int nb);
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr(char *str);
char		**ft_split(char const *s, char c);
int			ft_str_isnumeric(char *str);
char		*ft_strcat(char *dest, char *src);
char		*ft_strchr(const char *s, int c);
size_t		ft_strclen(const char *str, const char c);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
void		ft_strdel(char **str);
char		*ft_strdup(const char *s1);
char		*ft_strjoin_free(char *dest, char *src);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t destsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strncat(char *dest, char *src, unsigned int nb);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strndup(const char *str, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_swap(int *a, int *b);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			get_next_line(int fd, char **line);

#endif
