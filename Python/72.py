"""
mod P での逆元を高速で計算するクラス
"""
class FactorialMod:
    def __init__(self, max_num, mod):
        """
        Parameters
        ----------
        max_num : int
            作成するリストの最大数
        mod : int
            素数のmod

        inverse : 逆元
        factorial : 階乗
        factorial_inverse : 階乗の逆元
        
        計算コスト : O(n)

        """
        self.max_num = (max_num + 2)
        self.mod = mod
        self.inverse = [0] * self.max_num
        self.factorial = [0] * self.max_num
        self.factorial_inverse = [0] * self.max_num
        self.__calc_inverse()
        self.__calc_factorial_inverse()
    
    def __calc_inverse(self):

        self.inverse[1] = 1
        for i in range(2,self.max_num):
            self.inverse[i] = self.mod - ((self.mod // i) * self.inverse[self.mod % i] % self.mod)
            
    def __calc_factorial_inverse(self):

        self.factorial[0] = self.factorial_inverse[0] = 1
        for i in range(1,self.max_num):
            self.factorial[i] = (self.factorial[i - 1] * i) % self.mod
            self.factorial_inverse[i] = (self.factorial_inverse[i - 1] * self.inverse[i]) % self.mod
            
    def combination_mod(self, n, k):
        if (n < 0 or k < 0 or n > self.max_num or k > self.max_num or k > n):
            return 0
        return (((self.factorial[n] * self.factorial_inverse[k]) % self.mod) * self.factorial_inverse[n - k]) % self.mod
    
    def multi_choose_mod(self, n, k):
        return self.combination_mod(n + k - 1, k)

import math
W, H = map(int,input().split())

a = FactorialMod(10**6, 10**9+7)
if W == H == 1:
    print(1)
else:
    print(a.combination_mod(H+W - 2, W-1))