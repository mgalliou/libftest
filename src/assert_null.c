/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:40:14 by mgalliou          #+#    #+#             */
/*   Updated: 2019/05/13 12:42:30 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libftest.h"

int assert_null(void *ptr)
{
	if (!ptr)
	{
		exit(EXIT_SUCCESS);
	}
	printf("test: %s: failed\n", get_test_mng()->current_test);
	printf("expected: %s\nactually: %s\n", "null", "not null");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
