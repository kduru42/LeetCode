#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return (false);
        int temp;
        unsigned long long control;
        int digits = 0;
        unsigned long long divide1;
        int digits_temp;
        
        divide1 = 1;
        
        temp = x;
        while (temp)
        {
            temp /= 10;
            digits++;
        }
        digits_temp = digits;
        control = 0;
        while (digits_temp != 0)
        {
            temp = x;
            control += ((temp / divide1) % 10) * pow(10, digits_temp - 1);
            digits_temp--;
            divide1 *= 10;
        }
        std::cout << control;
        if (control == x)
            return (true);
        else
            return (false);
    }
};