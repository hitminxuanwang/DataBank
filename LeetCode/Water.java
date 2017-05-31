import java.util.*;
class Solution{
	public int maxArea(int[] height){
		int i=0;
		int j=height.length-1;
		int maxarea=0;
		//int maxarea=Math.min(height[j],height[i])*(j-i);
		while(i<j){
			maxarea=Math.max(maxarea,Math.min(height[j],height[i])*(j-i));
			if (height[j]<height[i]) {
				--j;
			}
			else{
				++i;
			}

		}
	return maxarea;

	}
}
public class Water{
public static void main(String[] args) {
	Solution solution=new Solution();
	int [] height= new int[7];
	height[0]=1;
	height[1]=2;
	height[3]=3;
	height[4]=4;
	height[5]=5;
	height[6]=6;
	int result=solution.maxArea(height);
	System.out.println(result);
}



}