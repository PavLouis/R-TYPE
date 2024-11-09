/*
** EPITECH PROJECT, 2022
** TCP
** File description:
** PacketManage
*/

#define SIZE_BUFFER 4096

#include <cstring>
#include <iostream>

//////////////////////////////////////////////////////////////
///@brief get information from client step by step
///@param charpointer information array
///@param char Index delimiter
//////////////////////////////////////////////////////////////
std::string getInfoStepByStep(char *infoArry, char c) noexcept {
  int i = 0;
  while (infoArry[i] != c) {
    if (infoArry[i] == '\0')
      return "";
    i += 1;
  }
  char info[SIZE_BUFFER];
  i = 0;
  while (infoArry[i] != c) {
    info[i] = infoArry[i];
    i += 1;
  }
  info[i] = '\0';
  int j = 0;
  i += 1;
  while (infoArry[i] != '\0') {
    infoArry[j] = infoArry[i];
    j += 1;
    i += 1;
  }
  infoArry[j] = '\0';
  return info;
}