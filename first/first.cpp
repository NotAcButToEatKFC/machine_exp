/*
                        ------- From IsOreo

2XSXXSSSSS220  7        rZZW@BSXXrr;:..,i7XSSS22a2a2SSZ8Zr    ,   X02MS:i:::::X,
r;rX7X7X7XXZr  MM2         iZBXr;;;rirS2XXXS22SSXSXSaa;    .SMM.   22Zi...   .i
77SXXXSXSXS8  2MMMMMa   .,.         .,;XaX7rS2880Z0Zr   :ZMMMMMZ   .Bari;i:,::7,
8Za2S2SSXSa2  @MMMMMMMBi:.                      ,2;   XMMMMM@MM@    Xai7ri,:::7i
8ZZZZZZ2SS8r .MM@@MMM0,                             SMMMM@@@@@MM    ,S;Xr,,,,:7:
8ZZZZZZZ228: XMM@MMMi                              MMMMM@@@@W@MM.    BM@7...,i7:
0Z8ZZZZ2SS0  8MMMMM                        ,.       i8MMMMM@@@MMi    2MW7.:X22ZX
ZZZZa2SSSaZ  @MMMM,                        ,.          SMMMM@MMM7    rM0XX2Z222S
ZaZZa2aaaaZ  MMMX:                         ,.            rMMMMMMX    .M8Z22222aS
0808ZZZ8ZZ8  MS                           .i               ;@MMMX     0ZS222222S
@WWZZ88ZZa0::   :                         :                  rMM2     Za2S2S222X
WB0ZZ0ZZZZWX    i                       ,:   .                 87     ZZS2S2S22S
02aaZZ880Bi     ;                 ....::.                             ZBaS2S222S
Z2aZZ8Z0B:   ,  i.           ..i:ii:..                                 SW8aaS222
0ZZaa2ZB:  .r;Z. :          ,:.ii                                       SMB82Sa2
B8ZZSaB;  :X  ;M:r;            i.           ,:.:                         8@ZaZaa
Z2ZaZ@Z  :MX  BM; 2i,         :,   ..:,:XSi,...                           02ZZa2
Z228@M   0MMBMMMi , ii,:...,:i:i,rr,.7MMMM0aX, ,:                         70Za2S
aX0@MX  X@@W@@WBi i   ,,i:,,.   X;    X@BBWZZ0X .:                         0aS2S
88WMM  :aWWWWWZ0. :           , M8    0W80BBS2B7 ,,                        2Z222
B0WM0  :ZZZZZa82  i          : XMM@Z0M@000B022Z0. ;                        ;822S
i7Z@X  :r2aZ2XZ: i.          ; 2WWW@WW0B0BB8Sa2B: ;.                       ,ZSSS
X.r8;  :7X7XX7, ::           ; 70BWBWBBBWB822riZ, ;                        ,WZaX
WMZ.,   i7rri  i,            :. 8aZBBB00ZZSa7iiX  :                        ,MMW0
X8r :    ,,. .,               ; i8a7S2a222S;i;X  :.                        :MM@0
i;i :      . ,,               .; .2ri;;r;;ir7r  :,                         XMMWZ
Xra ,        .i                 i. .ii;;;;;:   :.                          2MW@B
7r2Sr                            ,:,.       .:,                            00BB0
27SSB:                              ,,:::::,.                   ;,        XB088Z
X7XX2a                                                           ;i       0ZZ888
7i7r7ai                                                           ;:     XaXXXXr
S7XS7SZ                                                            7    r02aS22X
ZX0aSX2X                                                           r   :Ba2S2SaX
X7XS22r2r                                              .:         i:  :ZXXrX77X7
7ir;;;;rar                                             :.       :i,  ia77XS208B2
7r7X7XXXXZX                                            i     .rr.   ;ZX72Za2a80B
XrXXXXXXXXZai                                          ;,     ii  .7S77r7rr;r;ri
XrXXXX7XXXX2ZS.                                         ii.. .:  rSXrr;;;rrrrXX7
XrX7XXXXSSSSSaZ7,                                         ... ,:XXX7X7XXX7S2ZZa2
X7XSXXXX7r;r;7XXSX:                                         ,;7i.,,....:rXr77i:,
rirr;i;:i:;;rrXX7S2X7i, .                               ,,7XSXr;;;;;;;r;ri,
;:;7X2S2SSX7ii,:ir7X2S7X;i,. . . . .               ..:i7rii;irXXSXr;;rrr;r7X7X7;
aXaa2Xrii:ii;7X0M87,. ,:;rXrr;;:,....       ..,,:i;;7;i,.       ,iX7r;, ..,:iiri
7;r7;ii7SZZ0BW@Z:  ..,,,...,:i;Xrr;;i: .;r. .,:ii:,,   . ...       ;27ii:,.,,:ii
X;7;;;2Z08ZZ0BX      .,,:,,..         ;WMMMZ7:.                  ,r2a2aSSr;;77X;
SXXSXa0B88ZZaB,                  :7Z@MMMMMMMMMMM0aSX7Xrrrrr7XS22Z8ZS77r777XSXSS:
r.;i;ii;rrXXX2Z7:..      ..:r7a80BB08SX;rrri;;rr7XSXX2aX777rrrr;i,:,:,:,,..  .:
*/

#pragma GCC optimize(3)
#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define inf 2100000000
#define endl '\n'
#define pii pair<int,int>
#define pll pair<long long,long long>
#define MP make_pair
#define eps 1e-6

const double pi=3.14159265358;
const int maxn=3e5+10;
const int mod=1e4+7;

using namespace std;

struct student {
    int id;
    string name;
    string sex;
    string hometown;
    double height;
    string stamina; //体侧成绩
    vector<double>data; // 课程1-10的成绩
}database[maxn],datatxt[maxn],dataall[maxn];
int databasecnt=0,datatxtcnt=0;
int allcnt=0;

int pw(int x) {
    int ans=1,t=10;
    while(x) {
        if(x&1) ans*=t;
        t*=t;
        x>>=1;
    }
    return ans;
}

//string转int
int stringturn(string s) {
    int ans=0;
    for(int i=s.length();i>=0;i--) {
        ans+=(s[i]-'0')*pw(s.length()-i-1);
    }
    return ans;
}

//读取数据库
void readdatabase() {
    ifstream infile;
    infile.open("数据源1.txt");
    assert(infile.is_open());
    string s;
    string tmp;
    getline(infile,s);
    while(getline(infile,s)) {
        int len=s.length();
        int cnt=0;
        for(int i=0;i<len;i++) {
            if(s[i]=='	') {
                tmp="";
                if(cnt==0) {
                    database[cnt].id=cnt+1;
                }
                else if(cnt==1) {
                    database[cnt].name=tmp;
                }
                else if(cnt==2) {
                    database[cnt].sex=tmp;
                }
                else if(cnt==3) {
                    database[cnt].hometown=tmp;
                }
                else if(cnt==4) {
                    database[cnt].height=stringturn(tmp);
                }
                else if(cnt>=5&&cnt<=16) {
                    database[cnt].data.push_back(stringturn(tmp));
                }
            }
            else if(i==len-1) {
                tmp+=s[i];
                database[cnt++].stamina=tmp;
                break;
            }
            else {
                tmp+=s[i];
            }
        }
    }
    databasecnt=cnt;
    infile.close();
}

//读取txt
void readtxt() {
    ifstream infile;
    infile.open("数据源2.txt");
    assert(infile.is_open());
    string s;
    string tmp;
    getline(infile,s);
    int cnt=0;
    while(getline(infile,s)) {
        cout<<s<<endl;
        int len=s.length();
        for(int i=0;i<len;i++) {
            cout<<s[i];
            if(s[i]==',') {
                tmp="";
                if(cnt==0) {
                    datatxt[cnt].id=cnt+1;
                }
                else if(cnt==1) {
                    datatxt[cnt].name=tmp;
                }
                else if(cnt==2) {
                    datatxt[cnt].sex=tmp;
                }
                else if(cnt==3) {
                    datatxt[cnt].hometown=tmp;
                }
                else if(cnt==4) {
                    datatxt[cnt].height=stringturn(tmp);
                }
                else if(cnt>=5&&cnt<=16) {
                    datatxt[cnt].data.push_back(stringturn(tmp));
                }
            }
            else if(i==len-1) {
                tmp+=s[i];
                datatxt[cnt++].stamina=tmp;
                break;
            }
            else {
                tmp+=s[i];
            }
        }
    }
    datatxtcnt=cnt;
    infile.close();
    return;
}

//合成数据库与txt
void compose() {
    allcnt=0;
    for(int i=0;i<databasecnt;i++) {
        dataall[allcnt++]=database[i];
    }
    for(int i=0;i<datatxtcnt;i++) {
        dataall[allcnt++]=datatxt[i];
    }
}

//输出家乡在北京的学生所有课程平均成绩
void Print1() {
    vector<double>coursesum;
    double numofbeijing=0;
    for(int i=0;i<10;i++) {
        coursesum.push_back(0);
    }
    for(int i=0;i<allcnt;i++) {
        if(dataall[i].hometown=="Beijing") {
            numofbeijing++;
            for(int j=0;j<10;j++) {
                coursesum[i]+=dataall[i].data[j];
            }
        }
    }
    cout<<"The students's average grades(10 courses) who live in Beijing : "<<endl;
    for(int i=0;i<coursesum.size();i++) {
        cout<<coursesum[i]/numofbeijing<<" ";
    }
    cout<<endl;
}

//输出家乡在广州，课程1在80分以上，且课程10在9分以上的男同学数量
void Print2() {
    int ans=0;
    for(int i=0;i<allcnt;i++) {
        if(dataall[i].hometown=="Guangzhou"&&dataall[i].data[0]>=80&&dataall[i].data[9]>=9) {
            ans++;
        }
    }
    cout<<"The numbers of male students who live in Guangzhou and course1's grades greater than 80 and course10's grades greater than 9 is : ";
    cout<<ans<<endl;
}

int turn(string s) {
    if(s=="bad") return 60;
    if(s=="normal") return 70;
    if(s=="great") return 80;
    if(s=="excellent") return 90;
    return 0;
}

//比较广州与上海两地女生的平均体能成绩，这里假设"bad"=60,"normal"=70,"great"=80,"excellent"=90;
//如果广州强返回0，如果上海强返回1
bool cmp1() {
    double GZgrades=0,SHgrades=0;
    double gznum=0,shnum=0;
    for(int i=0;i<allcnt;i++) {
        if(dataall[i].hometown=="Guangzhou"&&dataall[i].sex=="female") {
            gznum++;
            GZgrades+=turn(dataall[i].stamina);
        }
        if(dataall[i].hometown=="Shanghai"&&dataall[i].sex=="female") {
            shnum++;
            SHgrades+=turn(dataall[i].stamina);
        }
    }
    return SHgrades>GZgrades;
}

void Print3() {
    if(cmp1()) {
        cout<<"Shanghai's female student's grades of physical fitness test is greater than Guangzhou";
    }
    else {
        cout<<"Guangzhou's female student's grades of physical fitness test is greater than Shanghai";
    }
    cout<<endl;
}

//求学习成绩和体测成绩的相关性

//待续

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    readdatabase();
    readtxt();
    compose();
    Print1();
    Print2();
    Print3();
    return 0;
}


