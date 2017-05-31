import java.util.HashMap;

class Solution{
	public boolean containsDuplicate(int[] nums){
		 int n=nums.length;
		 //if(n==0) return false;
		 HashMap<Integer,Integer> hashmap=new HashMap<Integer,Integer>();
		 for (int i=0; i<n;++i ){
		 	if(hashmap.containsKey(nums[i])){
		 		return true;
		 	}
		 	else
		 		hashmap.put(nums[i],0);	 	
		 }
		 return false;
	}

}

public class ContainDuplicate{

	public static void main(String[] args) {
		Solution solution=new Solution();
		//int nums[]=new int[]{1,2,3,4,5,6,7,8,9};
		int nums[]=new int[]{};
		boolean result=solution.containsDuplicate(nums);
		System.out.println(result);
	
	}




}
class Solution{
	public boolean containsDuplicate(int[] nums){
    	int count=0;
    	int cycle=0;
    	if(nums.length==0||nums.length==1){
       	 return false;
    	}
    	HashSet<Integer> hs=new HashSet<Integer>();
    	for(int i=0;i<nums.length;i++){
        	if(!hs.contains(nums[i])){
        	    hs.add(nums[i]);
        	}else{
           	 return true;
        	}
    	}
    	return false;
	}
}
