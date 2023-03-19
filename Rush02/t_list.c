/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@nate.com>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:33:50 by dayou             #+#    #+#             */
/*   Updated: 2023/02/27 20:05:39 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"
#include <stdlib.h>

/**
 * @brief 새로운 노드를 생성해서 반환하는 함수.
 * 				새로운 노드는 인자로 주어지는 data를 가진다.
 * 
 * @param data
 * @return 새로운 노드의 주소 또는 NULL. NULL의 경우 malloc의 실패를 뜻함
 */
t_list	*new_t_list(void *data)
{
	t_list*const	new_node = malloc(sizeof(t_list));

	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @brief 주어진 노드를 삭제하는 함수.
 * 
 * @param node 
 * @param del 함수포인터로 인자는 void *하나를 가진다. 
 */
void	delete_t_list(t_list *node, void (*del)())
{
	if (node == NULL)
		return ;
	if (node->data != NULL)
		del(node->data);
	free(node);
}

/**
 * @brief 현재 노드의 다음 위치에 새로운 노드를 추가하는 함수.
 * 				새로운 노드는 인자로 주어지는 data를 가진다.
 * 
 * @param cur_node
 * @param data
 * @return t_list* 
 */
t_list	*append_list(t_list *cur_node, void *data)
{
	t_list*const	new_node = new_t_list(data);

	new_node->next = cur_node->next;
	cur_node->next = new_node;
	return (new_node);
}

/**
 * @brief 주어지는 리스트의 가장 마지막에 새로운 노드를 추가하는 함수.
 * 				새로운 노드는 주어지는 data를 가진다.
 * 
 * @param list 
 * @param data 
 * @return t_list* 마지막 노드를 반환한다.
 */
t_list	*push_list(t_list **list, void *data)
{
	t_list	*cur_node;

	if (*list == NULL)
	{
		*list = new_t_list(data);
		return (*list);
	}
	cur_node = *list;
	while (cur_node->next != NULL)
		cur_node = cur_node->next;
	cur_node->next = new_t_list(data);
	return (cur_node->next);
}

/**
 * @brief 주어지는 list의 모든 원소를 printer를 통해서 출력하는 함수
 * 
 * @param list 
 * @param printer 인자는 1개로 t_list *를 받아서 이를 출력한다.
 */
void	print_all_list(t_list **list, void (*printer)())
{
	t_list *cur_node;

	if (list == NULL)
		return ;
	cur_node = *list;
	while (cur_node != NULL)
	{
		printer(cur_node);
		cur_node = cur_node->next;
	}
}

/*
------여기 아래는 실행을 위한 코드 예시-----
------여기 아래는 실행을 위한 코드 예시-----
------여기 아래는 실행을 위한 코드 예시-----
------여기 아래는 실행을 위한 코드 예시-----
------여기 아래는 실행을 위한 코드 예시-----
*/

#include <string.h>
#include <stdio.h>

typedef struct {
	int age;
	char *name;
} t_human;

t_human *new_t_human(int age, const char *name)
{
	t_human *human = malloc(sizeof(t_human));

	human->age = age;
	human->name = strdup(name);
	return (human);
}

/*
Q. 당신이라면 이렇게 작성하시겠습니까? (예/아니오, 왜?)
A. 
*/
void	delete_t_human(t_human *t_human)
{
	free(t_human->name);
	free(t_human);
}

void printer_data_human(t_list *node)
{
	t_human *data = node->data;
	printf("[t_list node (t_human)] address: %p\n", node);
	printf("\tdata (age): %d\n", data->age);
	printf("\tdata (name): %s\n", data->name);
}

// data부분이 human과는 다른 형식으로 작성되어있는 것을 알 수 있다.
// 이렇게 변수를 두는 것과 두지 않는 것은 다른가? (예/아니오, 왜 그렇게 생각하는가?)
void printer_data_int(t_list *node)
{
	printf("[t_list node (int)] address: %p, data: %d\n", node, *((int *)node->data));
}

void example_human_list()
{
	t_list *human_list = NULL;

	push_list(&human_list, new_t_human(11, "youo"));
	push_list(&human_list, new_t_human(12, "dab"));
	push_list(&human_list, new_t_human(13, "ena"));
	push_list(&human_list, new_t_human(14, "jjangb"));
	print_all_list(&human_list, printer_data_human);
}

int *new_int(int i)
{
	int *new_i = malloc(sizeof(int));
	*new_i = i;
	return (new_i);
}
void example_int_list()
{
	t_list *int_list = NULL;

	push_list(&int_list, new_int(11));
	push_list(&int_list, new_int(22));
	push_list(&int_list, new_int(33));
	push_list(&int_list, new_int(44));
	print_all_list(&int_list, printer_data_int);
}

int main()
{
	example_human_list();
	example_int_list();
	return (0);
}

/*
<TMI>
여기에서 예시들은 하나의 타입(t_human / int)을 리스트에 넣어서 사용했지만,
여러 다른 타입을 섞어서 사용할 수도 있다.

+ 그러기 위해서는 각 노드의 타입을 판별할 수 있도록 해야함
	가장 간단한 방식으로는 인간이 외우는 방식 :
		t_list에 int type을 추가하고, type이 0이면 t_human, 1이면 int라고 하면,
		0) t_human 
			node->type = 0 // t_human
			node->data = new_t_human(...)
		1) int
			node->type = 1 // int
			node->data = new_int(...)
	또는 enum을 활용하는 방식
		enum node_type {
			NODE_T_HUMAN,
			NODE_INT
		}
		0) t_human 
			node->type = NODE_T_HUMAN // t_human
			node->data = new_t_human(...)
		1) int
			node->type = NODE_INT // int
			node->data = new_int(...)
*/