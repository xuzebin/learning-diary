#!/usr/bin/env python
from __future__ import print_function
import urllib2
from bs4 import BeautifulSoup
import argparse
import time
from termcolor import colored
import json
import datetime

def check_course(term, class_num):
    url = 'https://m.albert.nyu.edu/app/catalog/classsection/NYUNV/' + str(term) + '/' + str(class_num)
    print (url)

    content = urllib2.urlopen(url).read()
    soup = BeautifulSoup(content, 'html.parser')

    name = soup.find('div', {'class': 'primary-head'}).text.strip()
        
    content = soup.find_all('div', {'class': 'section-content'})
    time = content[-8].find('div', {'class': 'pull-right'}).text.strip()
    instructor = content[-9].find('div', {'class': 'pull-right'}).text.strip()
    status = content[-1].find('div', {'class': 'pull-right'}).text.strip()
    bar = "============================"

    data = {"name": name, "status": status}

    if status == "Open":
        status = colored(status, 'green')
    else:
        status = colored(status, 'red')

    name = colored(name, 'yellow', attrs=['bold'])
    print (bar)
    print (datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
    print ("%s\n%s\n%s\n%s" % (name, instructor, time, status))
    print (bar)

    return data


if __name__ == "__main__":
    """ Check basic information on NYU courses by crawling data from Albert """
    parser = argparse.ArgumentParser(description='Check course status from NYU albert')
    parser.add_argument('--class_num', default='14596', help='class number(s), you can enter multiple class numbers splitted by commas wihtout a space (e.g. 14596,14597)')
    parser.add_argument('--term', default='fall2017', help='the term you are querying, currently only fall 2017.')
    parser.add_argument('--loop', type=int, default='0', help='a flag indicates if the check is performed in an endless loop. 1 indicates true, 0 indciates false')
    args = parser.parse_args()


    term = 1178 # Fall2017
    class_nums = args.class_num.split(',')
    loop = (True if args.loop > 0 else False)

    if loop:
        while True:
            for class_num in class_nums:
                check_course(term, class_num)
            print ("wait 5 seconds...\n")
            time.sleep(5) # check every 5 seconds
    else:
        for class_num in class_nums:
            check_course(term, class_num)
        
