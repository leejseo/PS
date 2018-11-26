n, k = map(int, raw_input().split())
ceil = lambda x, y : x/y if x%y == 0 else (x/y)+1
print ceil(5*n, k)+ceil(8*n, k)+ceil(2*n, k)
