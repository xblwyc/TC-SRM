Div1 Easy:
大意是已知一个目前的环状数组A，和要求变成的环状数组B，每个位置上移动X，就要消耗对应的值，问最小的消耗。
原题：
http://usaco.org/index.php?page=viewproblem2&cpid=128
O(n)的解法：
http://usaco.org/current/data/sol_restack.html


Div1 Med:
给定n个数，n <= 1e5，每次可以删去其中两个数，然后将这两个数的GCD和LCM加入到数组中，问数组的和的最大值。
假设一个数x1的表示形式为2^a1 * 3^a2 * 5^a3 * 7^a4 *...
x2的表示形式为2^b1 * 3^b2 * 5^b3 * 7^b4 *...
那么GCD(x1,x2) = 2^max(a1,b1) * 3^max(a2,b2) * ...
LCM(x1,x2) = 2^min(a1,b1) * 3^min(a2,b2) * ...
我们求出n个数的各自表现形式，然后使第一个数的每一个质因子的指数都是最小的，第二个数的每一个质因子的指数都是第二小的，以此类推，很容易想到这样的一个数列一定是最大的。