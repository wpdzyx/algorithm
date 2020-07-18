class Solution(object):
    def isPalindrome(self, x:int)->bool:
        """
        :type x: int
        :rtype: bool
        """
        if(x<0):
            return False

        for i in range(0,int(len(str(x))/2),1):
            if(str(x)[i] == str(x)[-i-1]):
                continue
            else:
                return False

        return True

    def int2list(self,x):
        return [int(x) for x in str(x)]        

a = Solution()
print(a.int2list(123))
print(a.isPalindrome(123321))



