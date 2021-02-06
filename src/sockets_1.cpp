#include <iostream>
#include <windows.h>
#include <winsock.h>

int __cdecl main() {
  WSAVERSION wsaVersion;
  std::cout << wsaVersion.dwVersion << std::endl;
  return EXIT_SUCCESS;
}