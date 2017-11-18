# INTRO

This is a Python3 program which can fetch data from HTTP://chinavitae.com and store file in .csv files with multi-threading mechanism integrated.

# MENU

- codes: Python3 code of this project
- profile-details: First version of .csv files
- Profile-details-new: Second version of .csv files, fixed Chinese dash character and converted it to '-'.
- compile.sh: A shell script convert .py to .pyc

# USAGE

## compile.sh
Covert .py to .pyc can protect your source code  

- run `./compile.sh` to compile .py files in 'codes' to .pyc
- Then go to `codes/__pycache__/` and change each file's name to `original_name.pyc`. (there might be `python35` attached with original name, you need to delete those  

## codes  
- Before run `main.py`, use `pip3 install _package-name_` to install following packages:
  - bs4
  - requests
  - string
  - xlrd
  - xlutils
  - csv  
- run `python3 main.py`
- wait until 26 .csv files in current directory
