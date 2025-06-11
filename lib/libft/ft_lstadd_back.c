/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiqueir <bsiqueir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:29:13 by bsiqueir          #+#    #+#             */
/*   Updated: 2022/07/06 02:11:40 by bsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*save;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	save = ft_lstlast(*lst);
	save->next = new;
}

/*	Adds a new node to the end of an existing linked list.*/