#!/usr/bin/env python
from __future__ import print_function
import boto3
import course_status_checker as csc
import time
import datetime
import threading

def send_sms(client, number, msg):
    client.publish(
        PhoneNumber=number,
        Message=msg
    )

def check_thread(client, term, class_num, phone_num):
    change = True
    while True:
        info = csc.check_course(term, class_num)

        name = info["name"]
        status = info["status"]

        if status == "Open" and change == True:
            msg = "{} open!!".format(name)
            send_sms(client, phone_num, msg)
            change = False
        if status == "Closed" and change == False:
            msg = "{} closed!!".format(name)
            send_sms(client, phone_num, msg)
            change = True

        time.sleep(5) # check every 5 seconds


def print_time(client, phone_num, msg):
    send_sms(client, phone_num, msg)
    # Run every hour
    threading.Timer(3600, print_time, args=[client, phone_num, "Testing EC2+SNS..." + datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")]).start()

if __name__ == "__main__":

    client = boto3.client(
        "sns",
        aws_access_key_id="",
        aws_secret_access_key="",
        region_name="us-east-1"
    )

    term = 1178 # Fall2017
    class_nums = [15132, 15114]
    phone_num = ""

    # first msg sending test 
#    send_sms(client, phone_num, "Test from AWS SNS")

    for class_num in class_nums:
        t = threading.Thread(target=check_thread, args=(client, term, class_num, phone_num))
        t.start()


    print_time(client, phone_num, "Testing EC2+SNS..." + datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
