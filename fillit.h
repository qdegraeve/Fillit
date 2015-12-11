/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdegraev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:43:52 by qdegraev          #+#    #+#             */
/*   Updated: 2015/12/11 11:32:30 by qdegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
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
int		ft_lstlen(t_list **alst);
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

#endif
