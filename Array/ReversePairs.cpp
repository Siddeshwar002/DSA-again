#include <bits/stdc++.h>
using namespace std;

int merge(vector<long long> &nums , int low , int mid , int high){
        vector<long long> temp;
        int left = low;
        int right = mid+1;
        int cnt = 0;

        int d_left = left;
        int d_right = right;

        while(d_left<=mid && d_right <= high){
            if(nums[d_left] > 2* nums[d_right]){
                cnt += (mid - d_left + 1);
                d_right++;
            }else
                d_left++;
        }

        while(left <= mid && right <= high){
            if(nums[left] > nums[right]){
                temp.push_back(nums[right]);
                right++;
              
            }else{
                temp.push_back(nums[left]);
                left++;
            }
        }


        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }


        for(int i = low ; i <= high; i++){
            nums[i] = temp[i-low];
        }

        return cnt;
    }

    int mergeSort(vector<long long> & nums , int low, int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + high) >> 1;
        cnt += mergeSort(nums , low , mid);
        cnt += mergeSort(nums , mid + 1 , high);
        cnt += merge(nums , low , mid , high);
        for(auto it : nums){
            cout<<it<<" ";
        }
        return cnt;

    }

    int reversePairs(vector<int>& nums) {

        vector<long long> Nums;

        for(auto it : nums){
            Nums.push_back(it);
        }

        return mergeSort(Nums , 0 , nums.size()-1);
    }