class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String>st = new HashSet<String>();
        boolean present = false;
        for(int i=0;i<wordList.size();i++){
            if(wordList.get(i).equals(endWord)){
                present = true;
            }
            st.add(wordList.get(i));
        }
        if(!present){
            return 0;
        }
        Queue<String>q = new LinkedList<>();
        q.add(beginWord);
        int depth = 0;
        while(!q.isEmpty()){
            depth++;
            int k = q.size();
            while(k>0){
                String s = q.poll();
                for(int i=0;i<s.length();i++){
                    String ss = s;
                    for(char j='a';j<='z';j++){
                        ss = ss.substring(0, i) + j + ss.substring(i+1);
                        if(ss.equals(s)){
                            continue;
                        }
                        if(ss.equals(endWord)){
                            return depth + 1;
                        }
                        if(st.contains(ss)){
                            q.add(ss);
                            st.remove(ss);
                        }
                    }
                }
                k--;
            }
        }
        return 0;
    }
}
