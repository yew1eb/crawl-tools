public class Solution {
	
	public static void main(String[] args) {
		HashSet<String> dict = new HashSet<String>();
		String[] strDict = {"hot","dot","dog","lot","log"};
		for (String s : strDict) {
			dict.add(s);
		}
		String start = "hit";
		String end = "cog";
		Solution solution = new Solution();
		System.out.println(solution.ladderLength(start, end, dict));
	}
	
	public int ladderLength(String start, String end, HashSet<String> dict) {
	
		//create graph
	   HashMap<String, ArrayList<String>> graph = new HashMap<String, ArrayList<String>>();
	   
	   graph.put(start, new ArrayList<String>());
	   graph.put(end, new ArrayList<String>());
	   for(String d : dict) {
		   graph.put(d, new ArrayList<String>());
	   }
	   for(String s : graph.keySet()) {
		   ArrayList<String> list = graph.get(s);
	       for(String t : graph.keySet()) {
	           if(getDiff(s,t) == 1) {
	               list.add(t);
	           }              
	       }
	   }
	   // use BFS to traverse the node in the graph, we begin with "start"
	   int step = 0;
	   HashSet<String> visited = new HashSet<String>();
	   ArrayList<String> firstLevel = new ArrayList<String>(graph.get(start));
	   
	   while (firstLevel.size() != 0) {
		   step++;
		   ArrayList<String> nextLevel = new ArrayList<String>();
		   for (String s : firstLevel) {
			   if (s.equals(end)) return step + 1;
			   visited.add(s);
			   nextLevel.addAll(graph.get(s));
		   }
		   firstLevel.clear();
		   for (String t : nextLevel) {
			   if (!visited.contains(t)) {
				   firstLevel.add(t);
			   }
		   }
		   nextLevel.clear();
	   }
	   return 0;
	}

	public int getDiff(String w1, String w2) {
	   int count = 0;        
	   for(int i = 0; i < w1.length(); i++) {
	       if(w1.charAt(i) != w2.charAt(i)) {
	           count++;
	       }
	   }
	   return count;
	}
}