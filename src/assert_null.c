/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:40:14 by mgalliou          #+#    #+#             */
/*   Updated: 2019/10/25 13:23:38 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/libftest.h"

void assert_null(void *ptr)
{
	if (ptr)
	{
		printf("test: %s: failed\n", get_test_mng()->current_test);
		printf("expected: %s\nactually: %s\n", "null", "not null");
		set_cur_test_ret(EXIT_FAILURE);
	}
}
