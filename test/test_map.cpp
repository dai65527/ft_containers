/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:37:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/16 15:19:06 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

#include "../map.hpp"
#include "Hoge.hpp"
#include "test.hpp"

void test_map(int& test_no) {
  std::cout << "=== TEST MAP ===" << std::endl;
  std::pair<int, std::string> persons[10] = {
      std::pair<int, std::string>(7, "dnakano"),
      std::pair<int, std::string>(2, "nop"),
      std::pair<int, std::string>(4, "bunjiro"),
      std::pair<int, std::string>(0, "deedee"),
      std::pair<int, std::string>(9, "sataharu"),
      std::pair<int, std::string>(8, "marvin"),
      std::pair<int, std::string>(5, "hoge"),
      std::pair<int, std::string>(1, "fuga"),
      std::pair<int, std::string>(6, "foobar"),
      std::pair<int, std::string>(3, "norminette")};
  std::map<int, std::string> persons_map(persons, persons + 10);

  std::pair<int, std::string> persons_sorted[10] = {
      std::pair<int, std::string>(0, "dnakano"),
      std::pair<int, std::string>(1, "nop"),
      std::pair<int, std::string>(2, "bunjiro"),
      std::pair<int, std::string>(3, "deedee"),
      std::pair<int, std::string>(4, "sataharu"),
      std::pair<int, std::string>(5, "marvin"),
      std::pair<int, std::string>(6, "hoge"),
      std::pair<int, std::string>(7, "fuga"),
      std::pair<int, std::string>(8, "foobar"),
      std::pair<int, std::string>(9, "norminette")};
  std::map<int, std::string> persons_sorted_map(persons_sorted,
                                                persons_sorted + 10);

  std::pair<int, std::string> persons_revsorted[10] = {
      std::pair<int, std::string>(9, "dnakano"),
      std::pair<int, std::string>(8, "nop"),
      std::pair<int, std::string>(7, "bunjiro"),
      std::pair<int, std::string>(6, "deedee"),
      std::pair<int, std::string>(5, "sataharu"),
      std::pair<int, std::string>(4, "marvin"),
      std::pair<int, std::string>(3, "hoge"),
      std::pair<int, std::string>(2, "fuga"),
      std::pair<int, std::string>(1, "foobar"),
      std::pair<int, std::string>(0, "norminette")};
  std::map<int, std::string> persons_revsorted_map(persons_revsorted,
                                                   persons_revsorted + 10);

  std::pair<Hoge, Hoge> hoges[10] = {
      std::pair<Hoge, Hoge>(Hoge(0, 7), Hoge(0, 0)),
      std::pair<Hoge, Hoge>(Hoge(1, 2), Hoge(1, 1)),
      std::pair<Hoge, Hoge>(Hoge(2, 4), Hoge(2, 2)),
      std::pair<Hoge, Hoge>(Hoge(3, 0), Hoge(3, 3)),
      std::pair<Hoge, Hoge>(Hoge(4, 9), Hoge(4, 4)),
      std::pair<Hoge, Hoge>(Hoge(5, 8), Hoge(5, 5)),
      std::pair<Hoge, Hoge>(Hoge(6, 5), Hoge(6, 6)),
      std::pair<Hoge, Hoge>(Hoge(7, 1), Hoge(7, 7)),
      std::pair<Hoge, Hoge>(Hoge(8, 6), Hoge(8, 8)),
      std::pair<Hoge, Hoge>(Hoge(9, 3), Hoge(9, 9))};
  std::map<Hoge, Hoge> hoges_map(hoges, hoges + 10);

  std::pair<Hoge, Hoge> fugas[10] = {
      std::pair<Hoge, Hoge>(Hoge(0, 0), Hoge(0, 5)),
      std::pair<Hoge, Hoge>(Hoge(1, 1), Hoge(1, 1)),
      std::pair<Hoge, Hoge>(Hoge(2, 2), Hoge(2, 5)),
      std::pair<Hoge, Hoge>(Hoge(3, 3), Hoge(3, 589)),
      std::pair<Hoge, Hoge>(Hoge(4, 4), Hoge(4, 4)),
      std::pair<Hoge, Hoge>(Hoge(5, 5), Hoge(5, 43)),
      std::pair<Hoge, Hoge>(Hoge(6, 6), Hoge(6, 6)),
      std::pair<Hoge, Hoge>(Hoge(7, 7), Hoge(7, 45)),
      std::pair<Hoge, Hoge>(Hoge(8, 8), Hoge(8, 8)),
      std::pair<Hoge, Hoge>(Hoge(9, 9), Hoge(9, 24))};
  std::map<Hoge, Hoge> fugas_map(fugas, fugas + 10);

  putTestInfo(test_no, "map<int, string>: default construction");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons[0]);
    ft_map.insert(persons[0]);
    if (std_map[7] != ft_map[7]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 2 to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons[0]);
    ft_map.insert(persons[0]);
    std_map.insert(persons[1]);
    ft_map.insert(persons[1]);
    if (std_map[7] != ft_map[7]) {
      throw std::runtime_error("value");
    }
    if (std_map[2] != ft_map[2]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons[i]);
      ft_res = ft_map.insert(persons[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 sorted to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons_sorted[i]);
      ft_res = ft_map.insert(persons_sorted[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 reverse_sorted to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons_revsorted[i]);
      ft_res = ft_map.insert(persons_revsorted[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 and sorted to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons[i]);
      ft_res = ft_map.insert(persons[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
      std_res = std_map.insert(persons_sorted[i]);
      ft_res = ft_map.insert(persons_sorted[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert 10 to map(0)");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::pair<std::map<Hoge, Hoge>::iterator, bool> std_res;
    std::pair<ft::map<Hoge, Hoge>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map.insert(hoges[i]);
      ft_map.insert(hoges[i]);
      std_map.insert(fugas[i]);
      ft_map.insert(fugas[i]);
    }
    std_map[Hoge(42, 42)];
    ft_map[Hoge(42, 42)];
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[Hoge(42, 42)] != ft_map[Hoge(42, 42)] ||
        std_map[Hoge(-42, -42)] != ft_map[Hoge(42, 42)]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert 10 and 10 to map(0)");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::pair<std::map<Hoge, Hoge>::iterator, bool> std_res;
    std::pair<ft::map<Hoge, Hoge>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map.insert(hoges[i]);
      ft_map.insert(hoges[i]);
    }
    std_map[Hoge(42, 42)];
    ft_map[Hoge(42, 42)];
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[Hoge(42, 42)] != ft_map[Hoge(42, 42)] ||
        std_map[Hoge(-42, -42)] != ft_map[Hoge(42, 42)]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: operator[0..9] to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map[persons[i].first] = persons[i].second;
      ft_map[persons[i].first] = persons[i].second;
    }
    std_map[42];
    ft_map[42];
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[42] != ft_map[42] || std_map[-42] != ft_map[-42]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: operator[0..9] to map(0) case 2");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map[persons[i].first] = persons[i].second;
      ft_map[persons[i].first] = persons[i].second;
      std_map[persons_sorted[i].first] = persons_sorted[i].second;
      ft_map[persons_sorted[i].first] = persons_sorted[i].second;
    }
    std_map[42];
    ft_map[42];
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[42] != ft_map[42] || std_map[-42] != ft_map[-42]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: operator[0..9] to map(0)");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::pair<std::map<Hoge, Hoge>::iterator, bool> std_res;
    std::pair<ft::map<Hoge, Hoge>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map[hoges[i].first] = hoges[i].second;
      ft_map[hoges[i].first] = hoges[i].second;
      std_map[fugas[i].first] = fugas[i].second;
      ft_map[fugas[i].first] = fugas[i].second;
    }
    std_map[Hoge(42, 42)];
    ft_map[Hoge(42, 42)];
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[Hoge(42, 42)] != ft_map[Hoge(42, 42)] ||
        std_map[Hoge(-42, -42)] != ft_map[Hoge(42, 42)]) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(range)
  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) with array");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons, persons + 10);
    ft_map.insert(persons, persons + 10);
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) twice with array");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons_sorted, persons_sorted + 10);
    ft_map.insert(persons_sorted, persons_sorted + 10);
    std_map.insert(persons, persons + 10);
    ft_map.insert(persons, persons + 10);
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) with map itr");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons_map.begin(), persons_map.end());
    ft_map.insert(persons_map.begin(), persons_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) with map itr");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons_map.begin(), persons_map.end());
    ft_map.insert(persons_map.begin(), persons_map.end());
    std_map.insert(persons_sorted_map.begin(), persons_sorted_map.end());
    ft_map.insert(persons_sorted_map.begin(), persons_sorted_map.end());
    std_map.insert(persons_revsorted_map.begin(), persons_revsorted_map.end());
    ft_map.insert(persons_revsorted_map.begin(), persons_revsorted_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert(0 ~ 10) with array");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;

    std_map.insert(hoges, hoges + 10);
    ft_map.insert(hoges, hoges + 10);
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert(0 ~ 10) with map itr");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;

    std_map.insert(hoges_map.begin(), hoges_map.end());
    ft_map.insert(hoges_map.begin(), hoges_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert(0 ~ 10) with map itr");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;

    std_map.insert(hoges_map.begin(), hoges_map.end());
    ft_map.insert(hoges_map.begin(), hoges_map.end());
    std_map.insert(fugas_map.begin(), fugas_map.end());
    ft_map.insert(fugas_map.begin(), fugas_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // fill constructor
  putTestInfo(test_no, "map<int, string>: map(0 ~ 10) with array");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);

    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: map(0 ~ 10) with itr");
  try {
    std::map<int, std::string> std_map(persons_revsorted_map.begin(),
                                       persons_revsorted_map.end());
    ft::map<int, std::string> ft_map(persons_revsorted_map.begin(),
                                     persons_revsorted_map.end());

    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: range construction with array");
  try {
    std::map<Hoge, Hoge> std_map(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(fugas, fugas + 10);

    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: range construction with mapitr");
  try {
    std::map<Hoge, Hoge> std_map(fugas_map.begin(), fugas_map.end());
    ft::map<Hoge, Hoge> ft_map(fugas_map.begin(), fugas_map.end());

    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(10) = map(10) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas, fugas + 10);

    for (int i = 0; i < 10; i++) {
      // std::cout << "std[" << hoges[i].first << "] = " << std_map[hoges[i].first]
      //           << " ft[" << hoges[i].first << "] = " << ft_map[hoges[i].first]
      //           << std::endl;
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    std_map = std_map2;
    ft_map = ft_map2;
    for (int i = 0; i < 10; i++) {
      // std::cout << "std[" << hoges[i].first << "] = " << std_map[hoges[i].first]
      //           << " ft[" << hoges[i].first << "] = " << ft_map[hoges[i].first]
      //           << std::endl;
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(10) = map(5) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 5);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas, fugas + 5);

    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    std_map = std_map2;
    ft_map = ft_map2;
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5) = map(10) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 5);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 10);
    std::map<Hoge, Hoge> ft_map(hoges, hoges + 5);
    std::map<Hoge, Hoge> ft_map2(fugas, fugas + 10);

    for (int i = 0; i < 5; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    std_map = std_map2;
    ft_map = ft_map2;
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
