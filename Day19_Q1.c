n = int(input())
arr = list(map(int, input().split()))

arr.sort()

left = 0
right = n - 1

min_sum = float('inf')
result = (0, 0)

while left < right:
    current_sum = arr[left] + arr[right]
    
    if abs(current_sum) < abs(min_sum):
        min_sum = current_sum
        result = (arr[left], arr[right])
    
    if current_sum < 0:
        left += 1
    else:
        right -= 1

print(result[0], result[1])
