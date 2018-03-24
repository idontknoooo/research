# Usage
- Copy 'HASH-AWE-CSV.csv' file, column `Hash_Key`. Each key is unique for a person's chinese Pinyin.
- Open any other `HASH-*.csv` and use ctrl-f to find that hash key.

# Note
- This cannot handle 2 names with same pronounciation. e.g. 习近平 vs 习进平 will have same hash key.
- This cannot handle 2 names with same pinyin (regardless of tone). e.g. 习近平 vs 惜金平 will have same hash key even tone is not same, but pinyin is ame.
- This cannot handle Chinese minority's name. e.g. 阿布杜拉

