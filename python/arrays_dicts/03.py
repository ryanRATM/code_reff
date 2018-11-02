# list compression
# returns all even numbers between 0 and 10
arr1 = [i for i in range(10) if i % 2 == 0]
arr2 = [i for i in 'ABCDE']

print('arr1: ' + str(arr1))
print('arr2: ' + str(arr2))

# like normal arrays, you can generate nested arrays this way (n-dimensional array)
arr3 = [[i + str(x) for x in arr1] for i in arr2]
print('arr3: ' + str(arr3))


# dict compression
d1 = {i.lower() : i for i in arr2}
print('d1: ' + str(d1))

# list map, filter
# map: apply same function to every element in array
# filter: generates list of elements from array that meat requirement

a = list(map(lambda x: x**2, arr1))
b = list(filter(lambda x: x % 4 == 0, arr1))

print('a: ' + str(a))
print('b: ' + str(b))

