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
    wb = open('cv-'+str(letter)+'.csv', 'a', newline="\n")
    headers = {
        'User-Agent': "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/22.0.1207.1 Safari/537.1"}

    # Request Personal Profile
    start_html = requests.get(career_href, headers=headers)
    # HTML code
    Soup = BeautifulSoup(start_html.text, 'lxml')
    # all_tr: All information for one person, long <tr>
    all_tr = Soup.find_all('tr') 
    # number of all_tr
    num_tr = len(all_tr)
    # name is the last tr content
    cur_name = all_tr[num_tr-1].get_text() # name without url
    cur_name = cur_name.replace('\n','')
    index = 0
    try:
        for td in all_tr[0:num_tr-5]:
            td_text = td.get_text()
    
            all_td = td.find_all('td') # all <td>s in <tr>
            year = all_td[0].get_text().split(',')[0] # Year
            #print(all_td)
            title = all_td[1].get_text().split(',')[0] # Title
            
            for a in all_td[0:-1]:
                    
                #print("First: " + first_td + "\n")
                more_a = a.find_all('a')
                if more_a:
                    info = title
                    for content in more_a:
                        info = info + ',' + content.get_text()
                    info = info.replace('\n','')
                    
                    #print(cur_name)
                    #print(year)
                    #print(info)
                    #print(index)
                    result = cur_name + ',' + year + ',' + info + '\n'
                    # wb.write(r+index, 0, cur_name)
                    # ws.write(r+index, 1, year)
                    # ws.write(r+index, 2, info)
                    #doc = csv.writer(wb)
                    #doc.writerow(result)
                    wb.write(result)
                    index += 1
    except:
        pass
                
        #print("-----------")
                #ws.write(r+all_tr.index(a), 0, cur_name)
                #print("Info: " + info + "\n")
#Zebazou 
#Student
#Minzu University of China,Political Department,Beijing Municipality
    # all_tr[i]: One row information on website for this person, including 1 <tr> and multiple <td> <a>
    # all_td = all_tr[i].find_all('td'): all <td>s in <tr>
    # all_td[i].get_text().split(',')[0]: first <td> string
    # all_td[i].find_all('a')[j].get_text(): all other strings in <td> (they are all <a>s)
    #num_tr = len(all_tr)
    # name is the last tr content
    #cur_name = all_tr[num_tr-1].get_text()
    #print(cur_name)
    #for a in all_tr[0:num_tr-5]:
        # print(a)
        # combine career url
     #   title = a.get_text()
        # period is the first element in title
      #  period = title[0]
        #print(period)
       # experience = title[1:]
        #print(experience)
        #print(all_tr.index(a))
        #ws.write(r+all_tr.index(a), 0, cur_name)
        #ws.write(r+all_tr.index(a), 1, period)
        #ws.write(r+all_tr.index(a), 1, experience)
        # print(cur_name,r)

    wb.close()














