with open("cv-A.txt") as f:
    contents = f.readlines()

contents = [x.strip() for x in contents]
for content in contents:
    tmp = content.split(' --- ')
    last_name = tmp[0].split(' ')[0]
    first_name = tmp[0].split(' ')[1]
    start_year = ''
    end_year = ''
    if tmp[1]:
        year_tmp = tmp[1].split('-')
        start_year = year_tmp[0]
        if len(year_tmp) > 1 and year_tmp[1].isdigit():
            end_year = year_tmp[1]
    title = tmp[2]
    info = []
    info_id = []
    location = []
    location_id = []
    for pair in tmp[3:]:
        pair_split = pair.split(':')
        if pair_split[0][0] == '9':
            location_id.append(pair_split[0])
            location.append(pair_split[1])
        else:
            info_id.append(pair_split[0])
            info.append(pair_split[1])
    # tmp_final += id
    tmp_final = ''
    tmp_final = "'" + last_name + "','" + first_name + "','" + start_year + "','" + end_year + "','" + title + "','"
    for i, i_id in zip(info, info_id):
        tmp_final += i + "','" + i_id + "','"
    for loc, loc_id in zip(location, location_id):
        tmp_final += loc + "','" + loc_id + "','"
    if tmp_final[-2:] == ",'":
        tmp_final = tmp_final[:-2]
    tmp_final = '''"""''' + tmp_final + '''"""'''
    print(tmp_final)
