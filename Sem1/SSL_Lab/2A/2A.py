import csv
import re

filename = "Market_Basket_V3.csv"
original_dict = {}
modified_dict = {}
cartItems = []                  # list for repeated values
cartItems2 = []                 # list for repeated values
frequent = []
frequentk = []
unique_list = []
unique_list2 = []

generic = lambda specific : re.sub("\s.*","",specific[::-1])    #lamda function

def aprioriGen(Lk, k):                  #creates Ck+1 from Lk
    retList = []
    unique_list2.clear()
    lenLk = len(Lk)
    for i in range(lenLk):
        for j in range(i+1, lenLk):
            L1 = list(Lk[i])[:k-2]; 
            L2 = list(Lk[j])[:k-2] 
            L1.sort(); 
            L2.sort()
            if L1==L2:                  # union the 2 sets only if their first (k-2) elements are same
                if (Lk[i] | Lk[j]) not in unique_list2:
                    unique_list2.append(Lk[i] | Lk[j]) 
                retList.append(Lk[i] | Lk[j])
    return retList


with open(filename, 'r') as csvfile:
    reader = csv.reader(csvfile)
    header = next(reader)
    for row in reader:
        key = row[0]
        value = re.sub("[\]\[]","",str(row[1]))         #storing 'CartItems' as string
        value = list(value.split(":"))                  #Convert 'CartItems' to list
        temp_list = []
        for val in value:
            val = (generic(val))[::-1]
            if val not in unique_list:
                unique_list.append(val)
            cartItems.append(val)
            temp_list.append(val)
        original_dict[key] =value                       #storing in dictionary
        temp_list.sort()
        modified_dict[key] = temp_list

cartItems.sort()                        # lexical sorting
size = len(original_dict)
for item in unique_list:
    item_size = cartItems.count(item)
    if float(item_size/size) >= 0.1 :
        frequent.append({item})         # Frequent items for k = 1
# print(frequent)
print()
frequent1 = frequent.copy()                    # Storing first frequent list in frequent1

k = 2
while aprioriGen(frequent,k) :              # while aprioriGen returns non-empty list
    Ck = aprioriGen(frequent,2)         

    for lists in modified_dict.values():    # for each transaction(t) check whether  
        for item in Ck:                     # every list of Ck is present in t
            item = list(item)
            flag = 1
            for i in range(0,len(item)):
                if item[i] in lists:
                    flag = 1
                else:
                    flag = 0
                    break
            item = set(item)
            if flag == 1:
                cartItems2.append(item)      
        
    
    frequent.clear()
    for item in unique_list2:
        item_size = cartItems2.count(item)
        if float(item_size/size) >= 0.1 :
            frequent.append(item)
    print(frequent)
    print()
    print()
    if len(frequent) != 0:
        frequentk = frequent.copy()
    k = k + 1

if len(frequentk) == 0:
    output = frequent1.copy()
else:
    output = frequentk.copy()


with open('output.txt', 'w') as f:
    for item in output:
        f.write("%s\n" % item)

