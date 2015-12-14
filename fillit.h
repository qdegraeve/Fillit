/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:43:52 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/14 15:52:50 by afillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/libft.h"
// size_t
#include <string.h>
// open
#include <fcntl.h>
//malloc
#include <stdlib.h>
//write
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>


t_list	*ft_recordfile(int fd);
int		check_box(char *s);
int		check_piece(char *piece);
int		check_file(t_list *lst);
void	ft_printlist(t_list *lst);
char	**cut_pieces(char *s);
char	*cut_empty_lin(char *s);
void	set_tab(t_list **lst);
t_list	*list_new(void const *content, size_t content_size, char letter);
void	list_addback(t_list **begin_list, void const *content, size_t content_size, char letter);
char	*str_replace(char *dest, const char *src);
char	*str_replace_col(char *dest, const char *src);
char	*cut_empty_col(char *s);
char	*src_emptycol(char *s);
void	insert_pieces(t_list *lst);
int		ft_lstlen(t_list *lst);
void	ft_fill_board(char **map, t_list *lst, int n);
int		ft_small_square(int i);
char	**ft_taballoc(int n);

#endif
