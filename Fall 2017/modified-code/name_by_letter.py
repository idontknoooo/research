# Fetch name from Chinavitae alphabetically

import requests
import string
from bs4 import BeautifulSoup
import download_profile


def replace_string(s):
    s1 = s.replace(" ", "%20")
    #s1 = s.replace("|", "%7C")
    #s1 = s.repalce("'", "%27")
    return s1

def b(letter):

    headers = {'User-Agent': "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/22.0.1207.1 Safari/537.1"}
    str_start = str("http://www.chinavitae.com/biography_browse.php?l=")#+str(letter)

    #range 0-26 represent a-z
    for i in (range(0, 1)):    
        # Search Url: http://www.chinavitae.com/biography_browse.php?l={A}
        alpha_url = str_start + letter# + string.ascii_uppercase[i]
        print(alpha_url)
        # Get HTML requests
        start_html = requests.get(alpha_url, headers=headers)
        # Get HTML code from requests. Soup contains all HTML code
        Soup = BeautifulSoup(start_html.text, 'lxml')
        # <td> tags contain name list
        all_td = Soup.find_all('td')
        # Column 1,2,3,4 from name search page
        for page in range(2, 6): # Loop from Col_1 to Col_4
            # All names in one search page
            cur_td = all_td[page]
            # all_a: all names in a single row
            all_a = cur_td.find_all('a')
            # For each name in a row (4 in total)
            for a in all_a: # Loop from Row_1 to Row_n
                # Title: Zakir Shohrat. A name without "_"
                title = a.get_text()
                # A post address: /biography/Zakir_Shohrat
                href = a['href']
                # Fix invalid url: " "==%20 and |==%7C and '==%27
                new_href = replace_string(href)
                # Return full url for someone
                career_href = "http://www.chinavitae.com" + new_href + "/career"
                # extract the table content into excel. i: sheet number
                download_profile.extract(i, career_href, letter)









