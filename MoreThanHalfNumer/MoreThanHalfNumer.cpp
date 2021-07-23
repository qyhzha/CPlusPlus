#include <iostream>
#include <vector>
#include <map>

class Solution
{
    public:
        int MoreThanHalfNumber(std::vector<int> v)
        {
            int ret = -1;
            std::map<int, int> m;

            for (int i = 0; i < v.size(); i++)
            {
                std::map<int, int>::iterator iter = m.find(v[i]);

                if (iter == m.end())
                {
                    m.insert(std::pair<int, int>(v[i], 1));
                }
                else
                {
                    m[v[i]]++;

                    if (m[v[i]] > (v.size() / 2))
                    {
                        ret = v[i];
                    }
                }
            }

            return ret;
        }
};

int main()
{
    Solution solution;

    int result = solution.MoreThanHalfNumber({1,2,3,2,2,2,5,4,2});

    std::cout << "result(" << result << ")." << std::endl;

    return 0;
}