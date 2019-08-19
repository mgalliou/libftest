/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:58:57 by mgalliou          #+#    #+#             */
/*   Updated: 2019/08/19 12:05:20 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftest.h"
#include "string.h"

void parse_args(int argc, char **argv)
{
	t_test_mng *test_mng;

	test_mng = get_test_mng();
	if (argc > 2)
	{
		if (!strcmp("-l", argv[1]))
		{
			test_mng->log = 1;
		}
	}
}
