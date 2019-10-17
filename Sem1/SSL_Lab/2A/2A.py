import csv
import re

filename = "Market_Basket_V3.csv"
my_dict = {}
cartItems = []
frequent = []
unique_list = []
generic = lambda specific : re.sub("\s.*","",specific[::-1])   #lamda function

with open(filename, 'r') as csvfile:
    reader = csv.reader(csvfile)
    header = next(reader)
    for row in reader:
        key = row[0]
        value = re.sub("[\]\[]","",str(row[1]))    #storing 'CartItems' as string
        value = list(value.split(":"))   #Convert 'CartItems' to list
        for val in value:
            val = (generic(val))[::-1]
            if val not in unique_list:
                unique_list.append(val)
            cartItems.append(val)
        my_dict[key] =value              #storing in dictionary


# print(my_dict)
cartItems.sort()                        # lexical sorting
size = len(my_dict)
for item in unique_list:
    item_size = cartItems.count(item)
    if float(item_size/size) >= 0.1 :
        frequent.append(item)

print(frequent)


