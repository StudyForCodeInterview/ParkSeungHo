#include <iostream>
#include <string>
#include <vector>

//class Solution2 {
//public:
//    std::string simplifyPath(std::string path) {
//        std::string str;
//        std::vector<std::string> stack;
//        //path += "/";
//        int pathLength = path.length();
//
//        if (pathLength == 1)
//            return path;
//
//        int startIndex = 0;
//        while (path[startIndex] == '/')
//            startIndex++;
//        
//        int i = 1;
//        while (1)
//        {
//            if (i >= pathLength)
//                break;
//            if (path[i] == '/')
//            {
//                if (i != startIndex)
//                    stack.push_back(path.substr(startIndex, i - startIndex));
//                while (i < pathLength && path[i] == '/')
//                    i++;
//                startIndex = i;
//                continue;
//
//            }
//            else if (path[i] == '.')
//            {
//                if (i + 1 < pathLength && path[i + 1] == '.')
//                {
//                    if (i + 2 < pathLength && path[i + 2] != '/')
//                    {
//                        i += 3;
//                        continue;
//                    }
//                    if (!stack.empty())
//                        stack.pop_back();
//                    i += 3;
//                    startIndex = i;
//                    continue;
//                }
//                else if (path[i + 1] == '/')
//                {
//                    i += 2;
//                    startIndex = i;
//                    continue;
//                }
//                else
//                {
//                    
//                }
//            }
//            i++;
//        }
//
//        std::string ret("/");
//        int stackSize = stack.size();
//        for (int i = 0; i < stackSize; i++)
//        {
//            ret += stack[i];
//            if (i != stackSize - 1)
//                ret += "/";
//        }
//        return ret;
//    }
//};

class Solution {
public:
    std::string simplifyPath(std::string path) {
        int pathLength = path.length();
        if (pathLength == 1)
            return path;

        std::vector<std::string> stack;

        int startIndex = 0;
        int endIndex = 0;
        while (1)
        {
            if (endIndex >= pathLength)
                break;
            if (path[endIndex] == '/')
            {
                if (startIndex != endIndex)
                    stack.push_back(path.substr(startIndex + 1, endIndex - startIndex - 1));
                startIndex = endIndex;
                while (path[startIndex] == '/')
                    startIndex++;
                endIndex = startIndex;
                startIndex -= 1;
                continue;
            }
            endIndex++;
        }

        std::vector<std::string> resultStack;
        int stackSize = stack.size();
        for (int i = 0; i < stackSize; i++)
        {
            if (strcmp("..", stack[i]))
            {

            }
        }


        std::string ret("/");
        stackSize = resultStack.size();
        for (int i = 0; i < stackSize; i++)
        {
            ret += stack[i];
            if (i != stackSize - 1)
                ret += "/";
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    std::string str1("/home/");
    std::string str2("/../");
    std::string str3("/home//foo/");
    std::string str4("/a/./b/../../c/");
    std::string str5("/a/../../b/../c//.//");
    std::string str6("/...");

    std::cout << s.simplifyPath(str1) << std::endl;
    std::cout << s.simplifyPath(str2) << std::endl;
    std::cout << s.simplifyPath(str3) << std::endl;
    std::cout << s.simplifyPath(str4) << std::endl;
    std::cout << s.simplifyPath(str5) << std::endl;
    std::cout << s.simplifyPath(str6) << std::endl;

    return 0;
}