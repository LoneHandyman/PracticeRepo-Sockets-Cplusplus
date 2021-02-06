#include <iostream>
#include <windows.h>
#include <winsock2.h>

//g++ sockets_1.cpp -o sockets_1.exe -lws2_32

int main() {
  WSADATA wsaData;
  if(WSAStartup(MAKEWORD(2, 2),&wsaData) != 0){
    std::cerr << "Startup failure." << std::endl;
    return EXIT_FAILURE;
  }
  else
    std::cout << "Successfull Initialization" << std::endl;
  return EXIT_SUCCESS;
}