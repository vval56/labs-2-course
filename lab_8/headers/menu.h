#ifndef MENU_H
#define MENU_H

#include "queue.h"
#include "algorithm.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cctype>
#include <limits>

template<typename T>
T check_numbers();

void print_menu();

template<typename T>
void enter_queue(Queue<T>& queue);

template<typename T>
void print_queue(Queue<T>& queue);

template<typename T>
void menu();

#endif