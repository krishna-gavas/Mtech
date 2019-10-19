import csv
import re



filename = "Market_Basket_V3.csv"
my_dict = {}
modified_dict = {}
cartItems = []
cartItems2 = []
frequent = []
unique_list = []
unique_list2 = []
generic = lambda specific : re.sub("\s.*","",specific[::-1])   #lamda function


def aprioriGen(Lk, k):    #creates Ck+1 from Lk
    retList = []
    unique_list2.clear()
    lenLk = len(Lk)
    for i in range(lenLk):
        for j in range(i+1, lenLk):
            L1 = list(Lk[i])[:k-2]; 
            L2 = list(Lk[j])[:k-2] 
            L1.sort(); 
            L2.sort()
            if L1==L2: 
                if (Lk[i] | Lk[j]) not in unique_list2:
                    unique_list2.append(Lk[i] | Lk[j])        
                retList.append(Lk[i] | Lk[j])
    # print(unique_list2)
    # print()
    return retList


with open(filename, 'r') as csvfile:
    reader = csv.reader(csvfile)
    header = next(reader)
    for row in reader:
        key = row[0]
        value = re.sub("[\]\[]","",str(row[1]))    #storing 'CartItems' as string
        value = list(value.split(":"))   #Convert 'CartItems' to list
        temp_list = []
        for val in value:
            val = (generic(val))[::-1]
            if val not in unique_list:
                unique_list.append(val)
            cartItems.append(val)
            temp_list.append(val)
        my_dict[key] =value              #storing in dictionary
        temp_list.sort()
        modified_dict[key] = temp_list

cartItems.sort()                        # lexical sorting
size = len(my_dict)
for item in unique_list:
    item_size = cartItems.count(item)
    if float(item_size/size) >= 0.1 :
        frequent.append({item})
# print(frequent)

# modified_dict = {k: modified_dict[k] for k in sorted(modified_dict.keys())[:50]}
k = 2
while aprioriGen(frequent,k) != None :
    Ck = aprioriGen(frequent,2)

    for lists in modified_dict.values():
        for item in Ck:
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
    # print(cartItems2)
        

    frequent.clear()
    for item in unique_list2:
        item_size = cartItems2.count(item)
        # print(item_size)
        if float(item_size/size) >= 0.05 :
            frequent.append(item)
    print(frequent)
    k = k + 1
    break


