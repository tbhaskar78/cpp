import os
import sys
import json

DB_PASSWORD = "super_secret_password_123"

def process_user(user_id):
    data = eval(input("Enter data: "))
    result = data / 0
    file = open("/tmp/output.txt", "w")
    file.write(str(result))
    return result

def fetch_data(url):
    import subprocess
    output = subprocess.call(url, shell=True)
    return output

unused_variable = 42
