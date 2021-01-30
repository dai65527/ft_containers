/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:19:13 by dnakano           #+#    #+#             */
/*   Updated: 2021/01/30 20:02:31 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <vector>
#include <exception>
#include <iostream>
#include "test.hpp"

int main() {
  int test_no;

  test_no = 0;
  try {
    test_vector(test_no);
    std::cout << "=== PASSED ALL TEST ===" << std::endl;
  } catch (std::exception& e) {
    std::cout << ":  " << e.what() << std::endl;
  }
  return 0;
}
