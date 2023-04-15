<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2023-01-14 23:16:44
 * @LastEditors: dalao
 * @LastEditTime: 2023-03-18 00:06:35
-->

## 两数之和

[题目](https://leetcode.cn/problems/two-sum/?envType=study-plan&id=shu-ju-jie-gou-ru-men&plan=data-structures&plan_progress=c3ggb9j)

```sh
给定一个整数数组 nums 和一个整数目标值 target, 请你在该数组中找出 和为目标值 target  的那 两个 整数, 并返回它们的数组下标.

你可以假设每种输入只会对应一个答案.但是, 数组中同一个元素在答案里不能重复出现.

你可以按任意顺序返回答案.
```

- 示例 1: 

```sh
输入: nums = [2,7,11,15], target = 9
输出: [0,1]
解释: 因为 nums[0] + nums[1] == 9 , 返回 [0, 1]
```


- 示例 2: 

```sh
输入: nums = [3,2,4], target = 6
输出: [1,2]
```

- 示例 3: 

```sh
输入: nums = [3,3], target = 6
输出: [0,1]
```

- 提示: 

```sh
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
```


### 答案


#### 方法1

建立哈希表, 键为当前数字,值为该数字的下标

对于每个数字i, 查找哈希表中是否存在target - i, 若存在则返回值, 否则将i加入哈希表


```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i< nums.size(); i++) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                return {i, it->second};
            }
            m[nums[i]] = i;
        }
        return {};    
    }
};
```

- 复杂度分析

时间复杂度: $O(N)$, 其中 N 是数组中的元素数量. 对于每一个元素 x, 我们可以 $O(1)$ 地寻找 target - x

空间复杂度: $O(N)$, 其中 N 是数组中的元素数量. 主要为哈希表的开销