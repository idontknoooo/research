# HOW TO CONSTRUCT YOUR OWN DATABASE

## Pre-requisite
- Need Python3.x
- Need SQL-Server
## Steps
- Run `python3 main.py` in `home/qz/Documents/research/fall17/6-remodified-part-2` directory of my Linux laptop. This will generate 26 txt files. Each row is separated by '\n', each column is separated by '@'.
- Open terminal in that directory, run `cat *.txt > ALL.txt` to concatenate 26 files into 1 txt file
- Copy this txt file to Windows (for encoding reason, Windows have different encoding system to Linux). Copy all content in txt file, and paste in a excel file.
- In excel, click 'data -- text to columns', then choose '@' to separate data.
- Add row title for data, and ID for each row.
- If total row number is more than 60K, copy the part over 60K to another file.
- We save each file in 97-2003 excel format.
- Open SQL-Server, create a database name `CHINAVITAE`
- Right click CHINAVITAE -- import data. Then import data from 97-2003 excels we saved before.
- Done
