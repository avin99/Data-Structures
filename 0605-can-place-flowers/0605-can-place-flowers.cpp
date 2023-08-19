class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int num = flowerbed.size();
        if(num == 1){
            if(flowerbed[0] == 0 && n > 0)return true;
        }
        for(int i = 0 ; i < num ; i++){
            if(i == 0){
                if(flowerbed[i] == 0 && i+1 < num && flowerbed[i+1] == 0){
                    cnt++;i++;
                }
                continue;
            }
            if(i == num - 1){
                if(flowerbed[i] == 0 && i-1 > 0 && flowerbed[i-1] == 0){
                    cnt++;
                }
                continue;
            }
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){cnt++;i+=1;}
        }
        return cnt >= n;
    }
};