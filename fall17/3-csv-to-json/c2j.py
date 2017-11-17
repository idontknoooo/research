import pandas as pd
import csv
# Read CSV file into python and convert to pd.DataFrame
def csv_to_dataframe(filename):

	with open("profile-details/cv-A.csv", newline='\n') as f:
		reader = csv.reader(f)
		for i in range(3):	
			row1 = next(reader)
			print(row1)
	return row1


if __name__ == '__main__':

    df = csv_to_dataframe('d');
    print(df)
