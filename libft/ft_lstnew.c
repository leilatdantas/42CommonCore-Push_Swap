/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebarbos <lebarbos@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:07:44 by lebarbos          #+#    #+#             */
/*   Updated: 2023/05/01 16:45:17 by lebarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DEF: Allocates (with malloc) and returns a new node. The member variable
'content' is initialized with the value of the parameter 'content'. The 
variable 'next' is initializad to NULL. 
RETURN VALUE: The new node. 
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
