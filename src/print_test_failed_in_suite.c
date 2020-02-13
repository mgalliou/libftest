/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test_failed_in_suite.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:55:39 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/12 18:56:28 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftest.h"
#include <stdio.h>

void	print_test_failed_in_suite()
{
	if (!get_test_mng()->current_suite.failed_test)
	{
		dprintf(2, "test(s) failed in suite: %s:\n", get_test_mng()->current_suite.name);
	}
}
