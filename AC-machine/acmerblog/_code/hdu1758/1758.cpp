int LIS(int str[],int len)
{
    int max,left,right,i,mid;
    lis[1] = str[0];
    max = 1;
    for(i=1; i<len; i++)
    {
        if(str[i] > lis[max])
        {
            lis[++max] = str[i];
        }
        else
        {
            left = 1;
            right = max;
            while(left <= right)
            {
                mid = (left+right)/2;
                if(str[i] > lis[mid])
                    left = mid + 1;
                else if(str[i] < lis[mid])
                    right = mid - 1;
                else
                    break;
            }
            lis[left] = str[i];
        }
    }
    return max;
}