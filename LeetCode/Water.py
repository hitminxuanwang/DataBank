class Solution:
	def maxArea(self,height):
		maxarea=0
		i=0
		j=len(height)-1
		while i<j :
			maxarea=max(maxarea,min(height[j],height[i])*(j-i))
			if height[i]<height[j] :
				i+=1
			else:
				j-=1
		return maxarea

solution=Solution()
height=[]
height.append(1)
height.append(2)
height.append(3)
height.append(4)
height.append(5)
height.append(6)
print(solution.maxArea(height))