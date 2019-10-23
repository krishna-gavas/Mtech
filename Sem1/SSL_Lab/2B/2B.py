import pandas as pd 
import numpy as np
import re

df = pd.read_csv("Rainfall.csv")            # Reading csv file into dataframe df
subd = []
cols = []

for row,col in df.iterrows():
    if col[0] not in subd:
        subd.append(col[0])                 # appending State names in subd[]

east = subd[0:9]
north = subd[9:16]
west = subd[16:27]
south = subd[27:36]

for col in df.columns:                      # appending Column names in cols[]
    cols.append(col)

size = len(cols)

for val in subd:                            # Populating missing values by state-wise average rainfall
    for i in range(2,size):
        attr = cols[i]
        mask = df['SUBDIVISION'] == val
        mean =   df.loc[mask , attr].mean() 
        mean = round(mean, 2)
        df.loc[mask, attr] = df.loc[mask, attr].fillna(mean) 

def MapState(state):                        # function to Map the states to each region
    if state in east:
        return "East"
    elif state in north:
        return "North"
    elif state in west:
        return "West"
    else:
        return "South"


df['South_West_Monsoon'] = df['Jun-Sep']            # Grouping Jun-Sep rainfall as South_West_Monsoon
df['North_East_Monsoon'] = df['Oct-Dec']            # Grouping Oct-Dec rainfall as North_East_Monsoon

df['Region_Code'] = df.SUBDIVISION.apply(MapState)

# Creating 3 new columns to store the corresponding previous 3 years rainfall values in the same row.
df['RAINFALL_PREV1'] = df.ANNUAL.shift(1)
df['RAINFALL_PREV2'] = df.ANNUAL.shift(2)
df['RAINFALL_PREV3'] = df.ANNUAL.shift(3)
# print(df)

df.to_csv('file1.csv')

# Creating new Dataframe which contains the aggregated region wise SouthWest Monsoon and NorthEast Monsoon from 1901 to 2015
newdf = df.groupby(['Region_Code','YEAR']).agg({'South_West_Monsoon':'sum','North_East_Monsoon':'sum'}).reset_index()
newdf[['South_West_Monsoon','North_East_Monsoon']] = newdf[['South_West_Monsoon','North_East_Monsoon']].round(2)

# newdf.to_csv('newDf.csv')
