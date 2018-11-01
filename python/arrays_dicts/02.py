# dictionary, defined as a key value pair, where the key represents the value

# can be created either by:
d = dict()
d = {}

d = {'Name': 'Lucas Ryan'}
print('d: ' + str(d))

# can add items to a dictionary easily
d['Age'] = 22
d['Major'] = 'Computer Science'
d['Interests'] = ['Netflix', 'Programming', 'Music', 'Swimming']
d['Other'] = 'Will be removed'

print('d: ' + str(d))

# can also remove key value pairs from a dictionary
del d['Other']
print('d: ' + str(d))


# check if items 
print("'Age' in d: " + str('Age' in d))
print("'<NOT IN D>' in d: " + str('<NOT IN D>' in d))


# fetch keys
print('d.keys(): ' + str(d.keys()))

# fetch values
print('d.values(): ' + str(d.values()))

# fetch items
print('d.items(): ' + str(d.items()))
