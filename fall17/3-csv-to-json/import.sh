#!/bin/zsh

# All files should name as 'Letter.json' for this script to work
LETTER="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

i=0
while [ $i -lt 26 ]
do
	mongoimport --db tdb --collection qz --file json-files/${LETTER:$i:1}.json --jsonArray
	i=`expr $i + 1`
	echo '--------------------------'
done

echo '\nFinished importing JSON Datasets!\n'
