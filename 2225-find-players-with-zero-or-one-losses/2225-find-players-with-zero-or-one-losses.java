class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        List<List<Integer>>ans = new ArrayList<>();
        HashMap<Integer, Integer>mp = new HashMap<>();
        int n = matches.length;
        HashSet<Integer>st = new HashSet();
        for(int i = 0; i < n; i++)
        {
            int winner = matches[i][0], looser = matches[i][1];
            st.add(winner);
            st.add(looser);
            if(mp.containsKey(looser))
            {
                mp.put(looser, mp.get(looser) - 1);
            }
            else{
                mp.put(looser, -1);
            }
        }
        List<Integer>list = new ArrayList<>();
        List<Integer>list1 = new ArrayList<>();
        List<Integer>list2 = new ArrayList<>();
        for(int it : st)            
        {
            list.add(it);
        }
        Collections.sort(list); 
        for(int it : list)
        {
            if(mp.containsKey(it))
                {
                    if(mp.get(it) == -1)list2.add(it);               
                }
                else{
                    list1.add(it);
                }
        }
        
        ans.add(list1);
        ans.add(list2);
        return ans;
        
    }
}