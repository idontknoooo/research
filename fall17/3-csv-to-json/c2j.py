import pandas as pd
import csv
# Read CSV file into python and convert to pd.DataFrame
def csv_to_array(filename):

	arr = []
	with open("profile-details/cv-A.csv", newline='\n') as f:
		reader = csv.reader(f)
		for row in reader:
			arr.append(row)
	return arr 

def array_to_json(arr):

	jobj_arr = []
	for row in arr:
		jobj = ''
		i = 0
		for feat in row:
			if i==0:
				jobj += '''{"name":"'''+feat+'",'
			elif i==1:
				jobj += '''"year":"'''+feat+'",'
			elif i==2:
				jobj += '''"title":"'''+feat+'",'
			else:
				jobj += '''"place'''+str(i)+'":"'+feat+'",'
			i += 1
		jobj = jobj[:-1]
		jobj += '},'
		jobj_arr.append(jobj)


	return jobj_arr



if __name__ == '__main__':

    df = csv_to_array('d');
    jobj_arr = array_to_json(df)
    # for i in jobj_arr:
    # 	print(i)
    # 	print('')

    file = open('tmp.json', 'w', newline='\n')

    jstr = ''.join(jobj_arr)
    jstr = jstr[:-1]
    jstr = '[' + jstr
    jstr += ']'

    file.write(jstr)