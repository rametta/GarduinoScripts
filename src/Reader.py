import serial
import requests

url = 'https://garduino.now.sh/api/readings'
gardenId = '5b17c0a9ee23292fc8c4a44f'
potId = '5b17c299f027160de0d333b3'
ser = serial.Serial('COM5', 9600)

while True:
    moisture = ser.readline().strip().decode("utf-8")  
    payload = {'potId': potId, 'soilTemp': 0, 'soilMoisture': moisture, 'light': 0, 'humidity': 0}
    print(payload)

    try:
        r = requests.post(url, json=payload)
        print(r.status_code)

    except TypeError as err:
        print(err)
