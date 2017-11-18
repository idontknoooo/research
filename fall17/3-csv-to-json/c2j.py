#!/usr/bin/python -O



'''
	@Author: Qiaodan Zuo
	@Date: 11/18/2017
'''



# Import dependency
import pandas as pd
import csv


''' 
    Read CSV file into python and convert to pd.DataFrame
'''
def csv_to_array(filename):

	arr = []

    # Open file based on filename
	with open('profile-details/cv-'+filename+'.csv', newline='\n') as f:

        # Use csv.reader to read open stream
		reader = csv.reader(f)

        # reader is a csv.reader object, read row from this object and store it in list
		for row in reader:
			arr.append(row)

	return arr 



''' 
    Convert Array of information to JSON format
'''
def array_to_json(arr):

	# Initialize JSON object in an array form
	jobj_arr = []

	# Read from array and convert to JSON
	for row in arr:

		jobj = ''

		for feat, i in zip(row, range(len(row))):

			# Create single JSON object
			if i==0:
				# First feature is "name"
				jobj += '''\n\t{\n\t\t"name":"'''+feat+'",\n\t\t'
			elif i==1:
				# Second feature is "year"
				jobj += '''"year":"'''+feat+'",\n\t\t'
			elif i==2:
				# Third feature is "title"
				jobj += '''"title":"'''+feat+'",\n\t\t'
			else:
				# All other features are named as "place"
				if i != len(row)-1:
					jobj += '''"place'''+str(i-2)+'":"'+feat+'",\n\t\t'
				else:
					jobj += '''"place'''+str(i-2)+'":"'+feat+'"\n\t'

		# Append closing '},'
		jobj += '},'
		# Append each {} object to list
		jobj_arr.append(jobj)

	return jobj_arr



'''
	Write array to file in a JSON format
'''
def write_arr(filename, arr):

	# Change tmp.json to filename
	file = open('json-files/'+filename+'.json', 'w', newline='\n')

	# Convert array to string and clean the end of string
	jstr = ''.join(arr)

	# Get rid of last ','
	jstr = jstr[:-1] 

	# Add open bracket '['	
	jstr = '[' + jstr

	# Add closing bracket '\n]'
	jstr += '\n]'

	file.write(jstr)

	# Close stream
	file.close()



'''
	Main process
'''
def main():

	# Letter string
	letter = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

	# Process workflow for all letters
	for i in range(26):

		# Get filename
		filename = letter[i]

		# Get array from CSV file
		arr = csv_to_array(filename);

		# Convert array to JSON object array
		jobj_arr = array_to_json(arr)

		# Write to file
		write_arr(filename, jobj_arr)



if __name__ == '__main__':

	main()
