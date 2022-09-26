/*
 * @Description:
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-09-26 23:23:38
 * @LastEditors: daLao
 * @LastEditTime: 2022-09-26 23:45:56
 */

#include <iostream>

class Test
{
public:
    Test();

    static Test *get_instance()
    {
        if (m_p == nullptr)
        {
            m_p = new Test();
        }
        return m_p;
    }

private:
    int value;

    static Test *m_p;
};