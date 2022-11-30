class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        HashSet<Integer>set = new HashSet<>();
        HashSet<Integer>freq ;
        HashMap<Integer, Integer>map = new HashMap<>();
        for(int i : arr)
        {
            // if(map.containsKey(i))
            // {
            //     map.put(i, 1 + map.get(i));
            // }
            // else{
            //     map.put(i, 1);
            // }
            map.put(i, map.getOrDefault(i, 0) + 1);
            set.add(i);
        }
        freq = new HashSet<>(map.values());
        // for(int i : set)
        // {
        //     //System.out.println("freq " + map.get(i));
        //     freq.add(map.get(i));
        // }
        //System.out.println(set.size());
        //System.out.println(freq.size());
        
        return set.size() == freq.size();
        
        
        //System.out.println(arr.length);
        
        //return set.size() == arr.length;
        
        
        
    }
}