/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 02:30:21 by hmzah             #+#    #+#             */
/*   Updated: 2019/12/26 23:29:09 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>

# define A 1
# define L 2
# define R 4
# define S 8
# define T 16
# define P 32
# define Y 2
# define C 64
# define G 128

int					g_check;

typedef struct		s_tree
{
	char			*name;
	char			*fullpath;
	int				mod_time;
	int				check_mate;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_t;

t_t					*get_new_node(char *name, char *path, int mod_time);
t_t					*insert_name(t_t *root, char *name, char *path);
void				display_tree(t_t *root, int option, int *tab);

void				display_dir(t_t *root, int option, int start, int len);
void				check_subddir(t_t *root, int option, int start, int len);
t_t					*insert_name_reverse(t_t *root, char *name, char *path);
t_t					*insert_time(t_t *root, char *dir_name, int mtime,
		char *path);
t_t					*insert_time_reverse(t_t *root, char *name, int mtime,
		char *path);

int					size_tree(t_t *root);
int					free_tree(t_t **node);
void				size_tree_dir(t_t *root, int *sum);
void				display_tree_error(t_t *root);

int					biggest_size_int(t_t *root, int truue);
int					biggest_size_usr(t_t *root);
int					biggest_size_grp(t_t *root);
int					biggest_minor(t_t *root);
int					biggest_major(t_t *root);

void				open_dir(char *dir_name, int option);

void				flags_exist(char c, int **option);
void				check_flags(char **av, int *option);

int					size_len(unsigned long int i);
void				free_2d_char(char **str);

int					no_file(char **av);
void				check_link(char *path);
int					isfilefolder(char *path);
int					is_directory(char *path);
int					is_symbolic(char *name);

void				print_perm_type(struct stat buf);
void				print_perm(struct stat buf);
void				print_acl(char *path);
void				print_permissions(struct stat buff, t_t *root);
int					display_tree_l(t_t *root, int *tab, int option);

void				print_total(t_t *root);
void				print_groups(struct stat buff, int us, int grp, int option);
void				print_files_rest(struct stat buf, int max_major,
		int max_minor, int size);

void				print_time(struct stat buff);
void				ft_putnbr_long(long int num);
void				drop_spaces(int i);
void				do_stuff(t_t *root, int **tab);

t_t					*check_time(t_t *root, char *name, char *path, int option);
t_t					*check_time_reverse(t_t *root, char *name, char *path,
		int option);

t_t					*check_ascii(t_t *root, char *name, char *path, int option);
t_t					*check_ascii_reverse(t_t *root, char *name, char *path,
		int option);

void				check_argv(char **av, int option, t_t **folders,
		t_t **files);
int					*check_option_n_print(t_t *error, t_t *files, int option);
int					*check_option_l_r(int option, t_t *root, int which);
void				print_error(char *dir_name);
void				check_link(char *path);

t_t					*do_flags(t_t *root, char *name, char *path, int option);

#endif
