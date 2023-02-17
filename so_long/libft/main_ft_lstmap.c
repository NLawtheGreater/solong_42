#include "libft.h"
#include <string.h>
#include <stdio.h>
int				__delNum = 0;

void *		lstmap_f(void *content) {
	(void)content;
	return ("OK !");
}

t_list			*lstnew(void *d) {
	t_list *ret = malloc(sizeof(t_list));

	if (!ret)
		return (NULL);
	ret->next = NULL;
	ret->content = d;
	return (ret);
}

void			lstdel_f(void *lst) {
	(void)lst;
	__delNum++;
}

int	main(void)
{
	t_list	*l = lstnew(strdup(" 1 2 3 "));
			t_list	*ret;

			l->next = lstnew(strdup("ss"));
			l->next->next = lstnew(strdup("-_-"));
			
			ret = ft_lstmap(l, lstmap_f, lstdel_f); // or lstdelone_f
			if (!strcmp(ret->content, "OK !") && !strcmp(ret->next->content, "OK !") && !strcmp(ret->next->next->content, "OK !") && !strcmp(l->content, " 1 2 3 ") && !strcmp(l->next->content, "ss") && !strcmp(l->next->next->content, "-_-"))
				printf("TEST_SUCCESS");
}