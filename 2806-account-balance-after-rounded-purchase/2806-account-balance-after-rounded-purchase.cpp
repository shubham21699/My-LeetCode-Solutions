class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        
        if(purchaseAmount % 10 == 0) return 100 - purchaseAmount;
        
        return 100 - (((purchaseAmount/10) + (purchaseAmount%10 >= 5)) * 10);
    }
};