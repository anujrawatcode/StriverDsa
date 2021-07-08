// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// https://drive.google.com/drive/folders/1YjlZ6f1-3Lct3u5CFjq5yX-wMOISaD49?usp=sharing

bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, comp);
    double profit = 0;

    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W = W - arr[i].weight;
            profit += arr[i].value;
        }
        else
            break;
    }

    if (W == 0 || i == n)
        return profit;

    // taking the fraction
    profit += (arr[i].value / (double)arr[i].weight) * (double)W;
    return profit;
}