//
//  main.cpp
//  ThreadTest
//
//  Created by Charles Weems on 1/12/16.
//  Copyright © 2016 Charles Weems. All rights reserved.
//

#include <iostream>
#include <thread>

void hello(int n) {
    std::cout << "Hello, World #" << n << "\n";
}

int main(int argc, const char* argv[]) {
    std::thread first(hello, 1);
    std::thread second(hello, 2);
    std::cout << "Goodbye, World!\n";
    first.join();
    second.join();
    return 0;
}
