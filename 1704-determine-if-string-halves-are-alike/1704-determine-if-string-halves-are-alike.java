class Solution {
    public boolean halvesAreAlike(String s) {
        String str = s.toLowerCase();
        // int []arr1 = new int[5];
        // int []arr2 = new int[5];
        int arr1 = 0, arr2 = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('a', 0);
        map.put('e', 1);
        map.put('i', 2);
        map.put('o', 3);
        map.put('u', 4);
        
        int sz = str.length();
        
        for(int i = 0; i < sz/2; i++)
        {
            char c = str.charAt(i);
            //System.out.println(c);
            if(map.containsKey(c))
            {
                
                arr1++;
                 
            }
            
        }
        //System.out.println("Size is : " + sz);
        for(int i = sz / 2; i < sz; i++)
        {            
            char c = str.charAt(i);
            //System.out.println(c);
            if(map.containsKey(c))
            {
                
                arr2++;    
            }
        }
        // for(int i = 0; i < 5; i++)
        // {
        //     //cout<<arr1[i]<<" "<<arr2[i]<<endl;
        //     //System.out.println(arr1[i] + " " + arr2[i]);
        //     if(arr1[i] != arr2[i])return false;
        // }
        
        return arr1 == arr2;
    }
}