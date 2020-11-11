class Solution(object):
    def longestOnes(self, A, K):
        m,i = 0,0
        for j in range(len(A)):
            if A[j] == 0:
                K -=1
			#A[i] ... A[j] is the current window
			
            while(K<0):
                if(A[i] == 0):
                    K+=1
                i+=1
			#A[i] ... A[j] is now a "valid" window containing at most k zeros
            m = max(j-i+1,m)
        return m
