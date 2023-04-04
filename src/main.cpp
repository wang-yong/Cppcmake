// Copyright (c) 2023 Tencent Inc. All rights reserved.
// CreateTime   : 2023-04-04 14:29:44
// Author       : yowang
// Desctiption  :
#include <iostream>
int main() {

  std::cout << "input two numbers" << std::endl;
  int number1 = 0, number2 = 0;
  std::cin >> number1 >> number2;
  std::cout << "number1 is " << number1 << "; "
            << "number2 is " << number2 << "\n"
            << "number1+number2=" << number1 + number2 << std::endl;

  system("pause");
  return 0;
}