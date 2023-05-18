/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idumenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:59:36 by idumenil          #+#    #+#             */
/*   Updated: 2023/05/11 14:05:47 by idumenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		found_newline(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	read_and_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, int readed);
void	extract_line(t_list *stash, char **line);
void	create_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
int		ft_strlen(const char *str);
void	free_stash(t_list *stash);
#endif
