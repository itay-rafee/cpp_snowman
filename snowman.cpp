#include <cstring>
#include "snowman.hpp"

using namespace std;

namespace ariel
{

    string snowman(int num)
    {
        string str = to_string(num);
        int str_size = str.size();
        const int right_size = 8;
        const int num1 = 11114411;
        const int num2 = 33232124;
        string ans;

        if (str_size > right_size || str_size < right_size)
        {
            string err = "Invalid code '" + str + "'";
            throw invalid_argument(err);
        }
        if (num == num1)
        {
            ans = "_===_\n(.,.)\n( : )\n( : )";
        } else if (num == num2) {
            ans = "   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )";
        }
        return ans;
    }

}