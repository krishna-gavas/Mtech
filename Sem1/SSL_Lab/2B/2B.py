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

east = subd[0:9]
north = subd[9:16]
west = subd[16:27]
south = subd[27:36]

for col in df.columns:
    cols.append(col)

size = len(cols)

for val in subd:
    for i in range(2,size):
        attr = cols[i]
        mask = df['SUBDIVISION'] == val
        mean =   df.loc[mask , attr].mean() 
        mean = round(mean, 2)
        df.loc[mask, attr] = df.loc[mask, attr].fillna(mean) 

def MapState(state):
    if state in east:
        return "East"
    elif state in north:
        return "North"
    elif state in west:
        return "West"
    else:
        return "South"


df['South_West_Monsoon'] = df['Jun-Sep']
df['North_East_Monsoon'] = df['Oct-Dec']

df['Region_Code'] = df.SUBDIVISION.apply(MapState)

df.to_csv('file1.csv')
    