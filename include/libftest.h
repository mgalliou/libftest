/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftest.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 20:56:01 by mgalliou          #+#    #+#             */
/*   Updated: 2020/02/13 06:40:33 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTEST_H
# define LIBFTEST_H

# include <stdlib.h>

typedef struct		s_test_suite
{
	const char		*name;
	void			(*before_test)();
	void			(*after_test)();
	int				failed_test;
}					t_test_suite;

typedef struct		s_test_mng
{
	int				asserted;
	int				failed;
	int				passed;
	t_test_suite	current_suite;
	const char		*current_test;
	int				current_test_ret;
	int				log;
}					t_test_mng;

# define TEST_SUITE(suite_name)          void suite_name(void)
# define RUN_TEST_SUITE(suite_name)      run_test_suite(suite_name, #suite_name)

# define BEFORE_TEST(X)                   get_test_mng()->before_test = X
# define AFTER_TEST(X)                    get_test_mng()->after_test = X

# define TEST(test_name)                 void test_name(void)
# define RUN_TEST(test_name)             run_test(test_name, #test_name)

void			parse_args(int argc, char **argv);
void			run_test_suite(void	(test_suite)(void), const char *suite_name);
void			run_test(void (test)(void), const char *test_name);
void			assert_null(void *ptr);
void			assert_not_null(void *ptr);
void			assert_str_equal(char *expected, char *actually);
void			assert_str_n_eq(char *expected, char *actually, size_t n);
void			assert_int_equal(int expected, int actually);
void			assert_ptr_equal(void *expected, void *actually);
void			assert_true(int actually);
void			assert_false(int actually);
void            print_test_results(void);

//internal functions
t_test_mng		*get_test_mng(void);
void			print_test_failed_in_suite();
void			set_cur_test_ret(int ret);

#endif
