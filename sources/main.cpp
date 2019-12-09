#include <iostream>
#include "SharedPtr.h"

using std::cout;
using std::cin;

int main() {
    int x = 2;
    int y = 4;
    int z = 8;

    SharedPtr<int> ptr1(&x);
    SharedPtr<int> ptr2(&y);
    SharedPtr<int> ptr3(ptr2);
    SharedPtr<int> ptr4;
    try {
        cout << "\nPtr1 = " << *ptr1.get() << " cnt = " << *ptr1.use_count();
        cout << "\nPtr2 = " << *ptr2.get() << " cnt = " << *ptr2.use_count();
        cout << "\nPtr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count();

        cout << "\n\nPtr3 was copied from Ptr2. Now we will reset Ptr2 to check"
        << " if Ptr3's сounter points to nowhere...\nRESETTING PTR2...";
        ptr2.reset();
        cout << "\nPtr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count();

        ptr1.swap(ptr3);

        cout << "\n\nPtr1 and Ptr3 swap:";
        cout << "\nPtr1 = " << *ptr1.get();
        cout << "\nPtr3 = " << *ptr3.get();

        cout << "\n\nPtr3 reset for varable Z:\n";
        ptr3.reset(&z);
        cout << "Ptr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count();

        cout << "\n\nDefine of Ptr4 (Ptr4 = Ptr3):";
        ptr4 = ptr3;
        cout << "\nPtr4 = " << *ptr4.get() << " cnt = " << *ptr4.use_count();
        cout << "\nPtr3 = " << *ptr3.get() << " cnt = " << *ptr3.use_count()
        << std::endl;

    }
    catch (const std::exception& e) {
        cout << "\n" << e.what();
    }
}
