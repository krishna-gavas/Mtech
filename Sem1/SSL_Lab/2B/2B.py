import pandas as pd 
import numpy as np
import re

df = pd.read_csv("Rainfall.csv")
subd = []
cols = []
avgList = {}

for row,col in df.iterrows():
    if col[0] not in subd:
        subd.append(col[0])

for col in df.columns:
    cols.append(col)

size = len(cols)

# for state in subd:
#     avgList[state] = {}
#     for i in range(2,size):  
#         colVal = cols[i] 
#         mean = df[colVal][df['SUBDIVISION'] == state].mean(axis = 0)
#          mean = df['DEC'].head(23).mean(axis = 0)
#         avgList[state][colVal] = round(mean, 2)


for val in subd:
    for i in range(2,size):
        attr = cols[i]
        mask = df['SUBDIVISION'] == val
        mean =   df.loc[mask , attr].mean() 
        mean = round(mean, 2)
        df.loc[mask, attr] = df.loc[mask, attr].fillna(mean) 


df.to_csv('file1.csv')
    