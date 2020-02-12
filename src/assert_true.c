/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_true.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:20:37 by mgalliou          #+#    #+#             */
/*   Updated: 2019/10/25 13:24:23 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <stdio.h>

void	assert_true(int actually)
{
	if (!actually)
	{
		printf("test: %s: failed\n", get_test_mng()->current_test);
		printf("expected: \"%s\"\nactually: \"%s\".\n", "true", "false");
		set_cur_test_ret(EXIT_FAILURE);
	}
}
