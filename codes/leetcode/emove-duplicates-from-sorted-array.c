/*
 * Psudo-Code
 * 1. Start both on initial.
 * 2. Keep on incrementing j until j's value is more than i's.
 * 3. Write it to next to i's.
 * 4. Repeat 2 until end of the range.
 */

int removeDuplicates(int *nums, int numsSize)
{
    int *i = nums;
    int *j = nums;
    int iPos = 0;
    int jPos = 1;
    int currentNum;
    while (1)
    {
        if ((j[jPos]) <= (i[iPos]))
            jPos++;
        else
        {
            iPos++;
            i[iPos] = j[jPos];
        }
        if (jPos >= numsSize)
        {
            return iPos;
        }
    }

}
