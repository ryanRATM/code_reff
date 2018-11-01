# cover basic of arrays and dictionaries

# in python an array is defined as a list

# a list can be created either by
arr = list()
arr = []

# unlike a dictionary you cant reference an index that doesnt exist and set it
# arr[1] = 1 # this will throw an error


# add to list
arr.append(33)
arr.append('apples')
arr.append(2.3)

print('arr: ' + str(arr))

# remove, if not in list then throws an error
arr.remove('apples')
print('arr: ' + str(arr))

# sort
arr.sort()
print('arr: ' + str(arr))

# insert at
arr.insert(1, 'INSERTED @ 1')
print('arr: ' + str(arr))

# make a seperate copy of an array 
arrSafeCopy1 = arr[:]
arrSafeCopy2 = arr.copy()

arrUnsafeCopy1 = arr

arrSafeCopy1[0] = 'a'
arrSafeCopy2[0] = 'b'
arrUnsafeCopy1[0] = 'c'

print('arr: ' + str(arr))
print('arrSafeCopy1: ' + str(arrSafeCopy1))
print('arrSafeCopy2: ' + str(arrSafeCopy2))
print('arrUnsafeCopy1: ' + str(arrUnsafeCopy1))

# can quickly check if an element is in an arr by using the in keyword
print("'c' in arr: " + str('c' in arr))
print("'a' in arr: " + str('a' in arr))
