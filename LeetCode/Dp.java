import java.util.*;
class Solution{
	void printmatirx(boolean [] dp)
	{
		for (int i=0;i<dp.length ;++i ) {
			if(dp[i])
				System.out.print("1 ");
			else
				System.out.print("0 ");
		}
		System.out.println();
	}
public boolean isMatch(String s, String p) {
    boolean[] match = new boolean[s.length()+1];
    Arrays.fill(match, false);
    match[s.length()] = true;
    for(int i=p.length()-1;i>=0;i--){
        if(p.charAt(i)=='*'){
            for(int j=s.length()-1;j>=0;j--)    match[j] = match[j]||match[j+1]&&(p.charAt(i-1)=='.'||s.charAt(j)==p.charAt(i-1));
            i--;
        }
        else{
            for(int j=0;j<s.length();j++)   match[j] = match[j+1]&&(p.charAt(i)=='.'||p.charAt(i)==s.charAt(j));
            match[s.length()] = false;
        }
        printmatirx(match);
    }
    return match[0];
}
}
public class Dp{
	public static void main(String args[]){
		Solution solution = new Solution();
		String s="a";
		String p="a*a*a*";
		boolean result=solution.isMatch(s,p);
		System.out.println(result); 
	}

}