# -*- coding: utf-8 -*-
import sys
sys.path.append('C:/XXX/')
import XXX 

print(XXX.Identity_Matrix(1000))
print(XXX.Plus_Matrix([[1,1,1],[1,1,1],[1,1,1]],[[2,2,2],[2,2,2],[2,2,2]]))
print(XXX.Minus_Matrix([[3,3,3],[3,3,3],[3,3,3]],[[2,2,2],[2,2,2],[2,2,2]]))
print(XXX.Random_Matrix(1000,1,1000))
print(XXX.Random_Symetrical_Matrix(1000,1,1000))
print(XXX.Composition([[1,5,3],[4,1,2],[1,1,1]],[[0,1,1],[1,3,1],[2,1,1]]))
print(XXX.NComposition([[1,1,1],[2,2,2],[3,3,3]],5))
print(XXX.Transpose([[1,1,1],[2,2,2],[3,3,3]]))


