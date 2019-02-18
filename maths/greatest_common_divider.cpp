int greatestCommonDivider(int num1, int num2) 
{
    while (num2) 
    {
        int temp = num2; 
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}
