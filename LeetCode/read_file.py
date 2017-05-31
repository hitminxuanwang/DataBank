import sys
fin=open('anno.annotation')
fout=open('annotation.lst','w')
number=0
list=[]
#fin.readline()
string=''
for line in fin:
	if '#' in line:
		fout.write(string)
		fout.write('  ')
		fout.write(str(number))
		#fout.write(str('  '))
		for lst in list:
			chs=lst.split(',')
			fout.write(str('  '))
			for character in chs:
				fout.write(str(int(float(character))))
				fout.write(' ')
		fout.write('\n')
		number=0
		list=[]
		#fout.write(string+' '+ str(number))
		continue
	elif 'object' in line:
		continue
	elif 'bbox' in line: 
		number=number+1
		list.append(line.strip()[6:len(line.strip())])
	elif 'file' in line:
		string=line[6:len(line)-1]
		string.strip()
	else:
		pass
