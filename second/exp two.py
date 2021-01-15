import matplotlib.pyplot as plt
import csv
import math
import functools

# 平均数
def aver(tmp) :
    if tmp==[] : return 0
    return sum(tmp)/len(tmp)
# 协方差
def cove(tmp) :
    if(len(tmp)==0 or len(tmp)==1) : return 0
    return (sum([x*x for x in tmp])-sum(tmp)*sum(tmp)/len(tmp))/(len(tmp))
# 标准差
def stad(tmp) :
    return math.sqrt(cove(tmp))

# 相关性
def solve(tmp) :
    return [(i-aver(tmp))/stad(tmp) for i in tmp]
def cor(x,y) :
    return sum([i*j for i, j in zip(solve(x),solve(y))])

def main() :
    st=[]
    with open('ans.csv') as f:
        file_csv=csv.reader(f)
        st=[list(map(float,v)) for v in file_csv]

    # 散点图
    with open('ans.csv') as f:
        file_csv=csv.reader(f)
        for i in file_csv: plt.scatter(float(i[0]),float(i[-1]))
        plt.show()

    # 直方图
    with open('ans.csv') as f:
        file_csv = csv.reader(f)
        l=[float(i[0]) for i in file_csv]
        plt.hist(l, range=(0, 100), bins=20)
        plt.show()

    correlation_mat=[[cor(st[i],st[j]) for j in range(len(st))] for i in range(len(st))]
    index = [i for i in range(len(correlation_mat))]
    with open('ans2.txt','w') as f:
        for l in correlation_mat:
            index.sort(key=functools.cmp_to_key(lambda x, y: l[y] - l[x]))
            f.write(f'{index[0]}\t{index[1]}\t{index[2]}\n')

if __name__ == "__main__" :
    main()