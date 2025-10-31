dt = open("/Users/pakpim/Desktop/code/competitive/codewars/dict.txt",'r')
s=[e for e in dt.readlines() if (len(e) - (e[-1]=='\n'))]
