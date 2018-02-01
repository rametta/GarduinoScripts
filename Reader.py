import serial
import requests

url = 'http://localhost:5000/api/reading'
ser = serial.Serial('/dev/ttyACM1', 9600)
gardenId = 8

while True:
  reading = ser.readline().strip()
  readings = reading.split(',')
  temp = readings[0][5:]
  light = readings[1][6:]
  humidity = readings[2][9:]
  moisture = readings[3][8:]
  payload = {}
  payload['reading'] = { 'gardenId': gardenId, 'temperature': temp, 'light': light, 'humidity': humidity, 'moisture': moisture }
  print payload

  try:
    r = requests.post(url, json=payload)
    print r.status_code

  except:
    print 'could not post data to server'
