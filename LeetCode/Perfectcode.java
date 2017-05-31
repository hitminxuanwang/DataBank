import java.util.*;

class Solution{
	void printmatrix(boolean[] dp){
		for (int i=0; i<dp.length;++i ) {
			if (dp[i]) {
				System.out.print("1 ");
			}
			else
				System.out.print("0 ");
		}
		System.out.println();


	}
	boolean isMatch(String s,String p){
		boolean[] dp=new boolean[s.length()+1];
		Arrays.fill(dp,false);
		dp[s.length()]=true;
		printmatrix(dp);
		for (int i=p.length()-1; i>=0;--i ) {
			if(p.charAt(i)=='*'){
					for(int j=s.length()-1;j>=0;--j){
						if(dp[j])//s[j+1] matches p[i]
							dp[j]=true;
						else if(dp[j+1] && (s.charAt(j)==p.charAt(i-1) || p.charAt(i-1)=='.' ))
							dp[j]=true;
						else
							dp[j]=false;

					}
					--i;
			}
			else{
				for (int j=0;j<s.length(); ++j) {
					if(dp[j+1] && (s.charAt(j)==p.charAt(i)||'.'==p.charAt(i))){
						dp[j]=true;
						//System.out.println("this is a point");
					}
					else{
						dp[j]=false;
					}
				}
				dp[s.length()]=false;
			}
			//printmatrix(dp);
			
		}

		return dp[0];
}
}

public class Perfectcode{
	public static void main(String[] args) {
			Solution solution=new Solution();
			String s="aa";
			String p="aa";
			boolean result=solution.isMatch(s,p);
			System.out.println(result);

	}
}
