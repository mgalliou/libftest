/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_false.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:58:43 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/11 16:59:31 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <stdio.h>

void	assert_false(int actually)
{
	if (actually)
	{
		printf("test: %s: failed\n", get_test_mng()->current_test);
		printf("expected: \"%s\"\nactually: \"%s\".\n", "false", "true");
		set_cur_test_ret(EXIT_FAILURE);
	}
}
