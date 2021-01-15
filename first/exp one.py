
import csv
import math
import os

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

# 去除无用项
def check(x):
    for i in range(len(x)):
        if x[i]== '' and i != len(x)-2: return 0
    return 1
def dele(d) :
    return [x for x in d if check(x)]

# 整合
def unity(d) :
    if(d[0]!=''and len(d[0])<=3) : d[0]=str(int(d[0])+202000)
    if(d[4]!=''and float(d[4])<3) : d[4]=str(int(float(d[4])*100))
    return d

# 去重
def unique(d) :
    d=[unity(x) for x in d]
    d.sort(key=lambda x:int(x[0]))
    cnt=0
    while cnt<len(d) :
        while cnt+1<len(d) and d[cnt+1][0]==d[cnt][0]:
            for i in range(len(d[cnt])):
                if d[cnt][i]==d[cnt+1][i] : continue
                if d[cnt][i]!='' and d[cnt+1][i] != '' :
                    d[cnt][i]=''
                    d[cnt+1][i]=''
                elif d[cnt][i]!='' : d[cnt+1][i] = d[cnt][i]
            d[cnt][0]=''
            cnt+=1
        cnt+=1
    d.sort(key=lambda x:x[0])
    while len(d)>0 and d[0][0] == '':
        d = d[1:]
    return d

data_student = []
city_lsit=['Beijing','Guangzhou','Shenzhen','Shanghai']
constitution_list=['bad','general','good','excellent']
data1=[]
data2=[]
class Student :
    def __init__(self,ID,name,city,gender,height,constitution,data) :
        self.ID = ID
        self.name = name
        self.city = city
        self.gender = gender
        self.height = float(height)if height != '' else 0
        self.constitution = constitution_list.index(constitution)+1 if constitution != '' else 0
        self.data = [float(x) if x != '' else 0 for x in data]
    def getsum(self):
        return sum(self.data)
    def getaver(self):
        return aver(self.data)
    def print(self):
        print(self.ID,self.name,self.city,self.gender)

def main() :
    # 读入
    with open('data1.csv', 'r', encoding='utf-8') as file:
        data1 = list(csv.reader(file))
        data1 = data1[1:]
        data1 = unique(data1)
    with open('data2.txt', 'r', encoding='utf-8') as file:
        data2 = list(csv.reader(file))
        data2 = data2[1:]
        data2 = unique(data2)
    data=dele(unique(data1 + data2))
    data_student=[Student(x[0],x[1],x[2],x[3],x[4],x[-1],x[5:-2]) for x in data]

    # 北京学生的平均成绩
    for i in range(9):
        tmp=[]
        for s in data_student:
            if s.city=='Beijing':
                tmp.append(s.data[i])
        print(i+1,'门课的平均成绩为',aver(tmp))

    # 学生中家乡在广州，课程1在80分以上，且课程9在9分以上的男同学的数量
    cnt=0
    for s in data_student:
        if s.city=='Guangzhou' and s.data[0]>80 and s.data[8]>9 and s.gender=='male': cnt+=1
    print('学生中家乡在广州，课程1在80分以上，且课程9在9分以上的男同学的数量为',cnt)

    # 比较广州和上海两地女生的平均体能测试成绩
    Guangzhou=[]
    Shanghai=[]
    for student in data_student:
        if student.city=='Guangzhou' and student.gender=='female':
            Guangzhou.append(student.constitution)
        if student.city=='Shanghai' and student.gender=='female':
            Shanghai.append(student.constitution)
    print('广州和上海两地女生的平均体能测试成绩: ')
    if aver(Guangzhou)<aver(Shanghai): print('上海强')
    elif aver(Guangzhou)>aver(Shanghai): print('广州强')
    else: print('两者相等')

    # 计算学习成绩和体能测试成绩，两者的相关性
    cons = [student.constitution for student in data_student]
    for i in range(9):
        cour = [student.data[i] for student in data_student]
        print(i+1,'门课的成绩与体测成绩的相关性为:',cor(cour,cons))

    # 保存结果
    with open('ans.txt','w') as f:
        for student in data_student:
            f.write(student.ID+'\t'+student.name+'\t\t'+student.city+'\t\t'+student.gender+'\t'+str(student.height)+',')
            for v in student.data:
                f.write(str(v)+'\t')
            f.write(str(student.constitution)+'\n')

if __name__ == '__main__' :
    main()