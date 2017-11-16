/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_memory.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:56:25 by gpouyat           #+#    #+#             */
/*   Updated: 2017/09/16 15:40:43 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SECURE_MEMORY_H
# define SECURE_MEMORY_H

# include <stdlib.h>
#include <string/ft_string.h>

# define MALLOC_LVL_DEFAULT 0
# define M_LVL_FUNCT 1
# define M_LVL_AST 2
# define M_LVL_EXEC 3
# define M_LVL_EXPA 4
# define M_LVL_HIST 5
# define M_LVL_AUTOC 6
# define M_LVL_PARSER 7

/*
** @file   secure_memory.h
**
** @brief  Function prototypes for the lexer module
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @struct s_secu_malloc
**
** @brief TOOD
*/

struct          s_secu_malloc
{
	void                  *ptr;
	size_t								lvl;
	struct s_secu_malloc        *prev;
	struct s_secu_malloc        *next;
};

typedef struct s_secu_malloc t_secu_malloc;

/*
** @struct s_mem
**
** @brief TODO
*/

typedef struct          s_mem
{
	t_secu_malloc             *first;
	t_secu_malloc             *last;
}                       t_mem;

/*
** @file ft_secu_free.c
**
** @brief Functions used to securely free
*/

void ft_secu_free(void *ptr);
void ft_secu_free_all(void);
void ft_secu_free_lvl(size_t lvl);

/*
** @file ft_str_insert_secu.c
**
** @brief Functions used to insert into a string securely
*/

char	*ft_str_insert_secu(char *src1, char *src2, int index, size_t lvl);

/*
** @file ft_strdblfree.c
**
** @brief Functions used to free a char** securely
*/

void	ft_strdblfree(char **strdb);

/*
** @file ft_strdup_secu.c
**
** @brief Functions used to dup a string securely
*/

char	*ft_strdup_secu(char const *src, size_t lvl);

/*
** @file ft_strjoincl_secu
**
** @brief Functions used to join two strings together (TODO)
*/

char	*ft_strjoincl_secu(char *s1, char *s2, int free, size_t lvl);

/*
** @file ft_strnew_secu.c
**
** @brief Functions to create a new string securely
*/

char	*ft_strnew_secu(size_t size, size_t lvl);

/*
** @file ft_strsplit_secu.c
**
** @brief Functions to split a string into a char** securely
*/

char		**ft_strsplit_secu(char const *s, char c, size_t lvl);

/*
** @file ft_strsub_secu.c
**
** @brief Functions to sub to a string securely
*/

char		*ft_strsub_secu(char const *s, unsigned int start, size_t len, size_t lvl);

/*
** @file ft_secu_malloc.c
**
** @brief Functions to malloc securely
*/

void *secu_malloc(size_t size);
void *ft_secu_malloc_lvl(size_t size, size_t lvl);
t_mem *get_mem(void);

/*
** @file string_growth_secu.c
**
** @brief Functions used to grow a t_string securely
*/

t_string	*string_growth_cap_secu(t_string *string, size_t cap, size_t lvl);
t_string	*string_growth_secu(t_string *string, size_t lvl);

/*
** @file string_secu.c
**
** @brief Functions to manage a t_string securely
*/

t_string	*string_init_cap_secu(t_string *string, size_t cap, size_t lvl);
t_string	*string_create_cap_secu(size_t cap, size_t lvl);
t_string	*string_create_secu(size_t lvl);

/*
** @file string_insert_secu.c
**
** @brief Functions used to insert into a t_string securely
*/

t_string	*string_insert_secu(t_string *string, const char *str, size_t pos, size_t lvl);
t_string	*string_insert_front_secu(t_string *string, const char *str, size_t lvl);
t_string	*string_insert_back_secu(t_string *string, const char *str, size_t lvl);

/*
** @file string_dup_secu.c
**
** @brief Functions used to dup a t_string securely
*/

t_string	*string_ndup_secu(const char *str, size_t n, size_t lvl);
t_string	*string_dup_secu(const char *str, size_t lvl);

//# define MALLOC(x) ft_secure_malloc(x)
//# define FREE(x) ft_secure_free(x)
//# define FREE_LVL(x) ft_secure_free_lvl(x)

#endif
