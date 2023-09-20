int minCount(int* coins, int coinsSize){
    int minSum = 0;
    for (int i = 0;  i < coinsSize; i ++)
    {
        if (coins[i] % 2)
            minSum += coins[i] / 2 + 1;
        else
            minSum += coins[i] / 2;
    }
    return minSum;
}
