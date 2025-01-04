#include <vector>
#include <iostream>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int cnt1 = 0, cnt2 = 0;
    int ele1, ele2;

    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 and nums[i] != ele2)
        {
            cnt1 = 1;
            ele1 = nums[i];
        }
        else if (cnt2 == 0 and nums[i] != ele1)
        {
            cnt2 = 1;
            ele2 = nums[i];
        }

        else if (nums[i] == ele1)
            cnt1++;
        else if (nums[i] == ele2)
            cnt2++;

        else
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;

    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ele1)
            cnt1++;
        if (nums[i] == ele2)
            cnt2++;
    }

    int mini = int(nums.size() / 3) + 1;
    if (cnt1 >= mini)
        ans.push_back(ele1);
    if (cnt2 >= mini)
        ans.push_back(ele2);

    return ans;
}

int main(){
    cout<<"hi"<<endl;
}