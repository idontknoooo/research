# Python script to download given person's profile from Chinavitae

import xlrd
import requests
import string
from xlutils.copy import copy
from bs4 import BeautifulSoup
import csv
import sys
def extract(i, career_href, letter):
    # Open file
    #rb = xlrd.open_workbook('cv'+letter+'.xls')
    # Add sheet
    #rb = rb.add_sheet(i)
    # ith sheet
    #r_sheet = rb.sheet_by_index(i)
    #r = r_sheet.nrows
    #wb = copy(rb)
    #ws = wb.get_sheet(0)
    '''

    wb = xlwt.workbook()
    ws = wb.add_sheet(i)
    '''
    wb = open('cv-'+str(letter)+'.txt', mode='a', encoding='utf-8', newline="\n")
    headers = {
        'User-Agent': "Mozilla/5.0  (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/22.0.1207.1 Safari/537.1"}

    # Request Personal Profile
    start_html = requests.get(career_href, headers=headers)
    # HTML code
    Soup = BeautifulSoup(start_html.text, 'lxml')
    # all_tr: All information for one person, long <tr>
    # Each <tr> is one experience (table row)
    all_tr = Soup.find_all('tr') 
    # number of all_tr
    num_tr = len(all_tr)
    # name is the last tr content
    cur_name = all_tr[num_tr-1].get_text() # name without url
    cur_name = cur_name.replace('\n','')
    index = 0
    delimiter = '\t'
    try:
        for td in all_tr[0:num_tr-5]:
            # print(td)
            td_text = td.get_text()
    
            all_td = td.find_all('td') # all <td>s in <tr>
            ''' 
                In all_td, first is year, second is title
                in title <td>, all <a> are experience
            '''
            year = all_td[0].get_text().split(',')[0] # Year
            year = year.replace('—', '-')
            #print(all_td)
            title = all_td[1].get_text().split(',')[0] # Title
            # print(all_td[1].get_text() + '\n')
            a_list = all_td[1].find_all('a')

            experience = []
            locations = []
            for a in a_list:
                if a['class'][0] == 'link11b':
                    tmp_location = [a['href'].split('/')[-1], a.text]
                    if tmp_location:
                        locations.append(tmp_location)
                    # location[a['href'].split('/')[-1]] = a.text
                else:
                    tmp_experience = [a['href'].split('/')[-1], a.text]
                    if tmp_experience:
                        experience.append(tmp_experience)
                    # experience[a['href'].split('/')[-1]] = a.text

            result = cur_name + delimiter + year + delimiter + title + delimiter

            prev_key = '$'
            prev_val = ''
            for item in experience:
                if item[0].find(prev_key) >= 0:
                    result += item[0] + ':' + prev_val + '-' + item[1] + delimiter
                else:
                    result += item[0] + ':' + item[1] + delimiter
                prev_key = item[0]
                prev_val = item[1]
                
            prev_loc_key = '$'
            prev_loc_val = ''
            if locations:
                for location in locations:
                    if location[0].find(prev_loc_key) >= 0:
                        result += location[0] + ':' + prev_loc_val + ', ' + location[1] + delimiter
                    else:
                        result += location[0] + ':' + location[1] + delimiter
                    prev_loc_key = location[0]
                    prev_loc_val = location[1]
            
            result = result[:-len(delimiter)]
                # pass
                
            result += '\n'

            wb.write(result)

    except:
        pass

    wb.close()














