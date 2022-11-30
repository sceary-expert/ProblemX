class Solution {
    int k;
    public boolean uniqueOccurrences(int[] arr) {
        k = 1000;
        int freq[] = new int[2 * k + 1];
        for(int a : arr)
        {
            freq[k + a]++;
        }
        Arrays.sort(freq);
        for(int i = 0; i < 2 * k; i++)
        {
            if(freq[i] != 0 && freq[i] == freq[i + 1])return false;
            
        }
        return true;
    }
}