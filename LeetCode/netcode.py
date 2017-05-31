# encoding: utf-8
import string
import re
import copy
import sqlite3

keywords=['广州','北京','美国','达到','我是','你的','秘书','are you','a man','a boy']
strs='.州北京are美国you a an i go,'


delEStr = [string.punctuation, ' ', string.digits , string.ascii_letters,'.']#ASCII 标点符号，空格,数字和字母
#identify = str.maketrans(delEStr,'')
#delCStr = '《》（）&%￥#@！{}【】'#符号
#delCStr = '.&%￥#@！'
trantab = dict((ord(a), b) for a, b in zip(delEStr,''))
trantaa=dict('.','')
translated = strs.translate(trantab)
#strs= strs.translate(delEStr)
print(translated)
#if re.findall('[\x80-\xff].',strs):    #strs为中文 
#strs = strs.translate(delCStr) #去除符号
str_timu=strs
print(str_timu)

#print str_timu

indx=int(len(str_timu)/2)
key=[]
x=0
y=4
for i in range(indx-1):
    if str_timu[x:y] in keywords:
        print(str_timu[x:y])
        key.append(str_timu[x:y])
    x=y-2
    y+=2
print(key)