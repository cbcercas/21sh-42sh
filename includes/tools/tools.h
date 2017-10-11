/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:00:38 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/11 12:42:15 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# include <ftprintf.h>
# include <btree/ft_btree.h>
# include <string/ft_string.h>

void	ft_strdblfree(char **strdb);
BOOL	is_printstr(char const *line);
BOOL  is_white(int c);
BOOL  is_str_car(const char *buff);
pid_t	sh_fork(void);
int		sh_pipe(int tube[2]);
int		sh_open_exec(t_btree *ast);
int		sh_open(char *file, int flags);
int		sh_ret(int status);
int		sh_test_access(char const *filename);
BOOL  ft_isdigit_str(char *str);
char	*ft_strnew_secu(size_t size, size_t lvl);
char		*ft_strsub_secu(char const *s, unsigned int start, size_t len, size_t lvl);
char		**ft_strsplit_secu(char const *s, char c, size_t lvl);
char	*ft_strdup_secu(char const *src, size_t lvl);
char	*ft_strjoincl_secu(char *s1, char *s2, int free, size_t lvl);
char	*ft_str_insert_secu(char *src1, char *src2, int index, size_t lvl);

t_string	*string_create_secu(size_t lvl);
t_string	*string_growth_cap_secu(t_string *string, size_t cap, size_t lvl);
t_string	*string_growth_secu(t_string *string, size_t lvl);
t_string	*string_init_cap_secu(t_string *string, size_t cap, size_t lvl);
t_string	*string_create_cap_secu(size_t cap, size_t lvl);
t_string	*string_insert_secu(t_string *string, const char *str, size_t pos, size_t lvl);
t_string	*string_insert_front_secu(t_string *string, const char *str, size_t lvl);
t_string	*string_insert_back_secu(t_string *string, const char *str, size_t lvl);
t_string	*string_ndup_secu(const char *str, size_t n, size_t lvl);
t_string	*string_dup_secu(const char *str, size_t lvl);


#endif
