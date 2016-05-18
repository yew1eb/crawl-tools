import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Main {
	//how many of type 1...7, then length of last free. stores min test day
	static Map<Key, Integer> dp;
	static int MAX = 141;
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		int T = Integer.parseInt(reader.readLine());
		for(int t = 0; t < T ; t++){
			dp = new HashMap<Key, Integer>();
			int k = Integer.parseInt(reader.readLine());
			int[] state = new int[8];
			for(int i = 0; i < k; i++){
				state[Integer.parseInt(reader.readLine())]++;
			}
			
			int min = MAX;
			for(int free = 1; free <= 7; free++){
				state[0] = free;
				min = Math.min(min, solve(new Key(state)));
			}
			out.println(min);
		}
		
		out.close();
	}
	
	static int solve(Key key){
		if(dp.get(key) != null){
			return dp.get(key);
		}
		
		int sum = 0;
		List<Integer> nonzero = new ArrayList<Integer>();
	
		int sfree = key.state[0];
		
		for(int i = 1; i <= 7; i++){
			sum += key.state[i];
			if(key.state[i] != 0) nonzero.add(i);
		}
		
		if(sum == 1){
			if(sfree == nonzero.get(0)){
				return sfree;
			}else{
				return MAX;
			}
		}
		
		int min = MAX;
		for(int i = 0; i < nonzero.size(); i++){
			int lastL = nonzero.get(i);
			if(lastL < sfree) continue;
			for(int free = 1; free <= 7; free++){
				if(lastL > sfree + free - 1) continue;
				Key nextKey = new Key(key.state.clone());
				nextKey.state[lastL]--;
				nextKey.state[0] = free;
				int ans = solve(nextKey) + sfree;
				min = Math.min(ans,  min);
			}
		}
		
		dp.put(key, min);
		
		return min;
	}
	
	static class Key{
		public int[] state;
		
		public Key(int[] state){
			this.state = state;
		}
		
		@Override
		public boolean equals(Object other){
			return Arrays.equals(this.state, ((Key)other).state);
		}
		
		@Override
		public int hashCode(){
			return Arrays.hashCode(state);
		}
		
	}
}