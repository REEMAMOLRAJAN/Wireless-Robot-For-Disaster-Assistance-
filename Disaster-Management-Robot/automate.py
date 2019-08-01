from selenium import webdriver
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
import time

driver = webdriver.Firefox() 
driver.get('https://rl.se/gprmc')
elem = driver.find_element_by_tag_name('body')
GPS_FIELD = (By.XPATH, "//input[@id='nmea']")
Decode = (By.XPATH,"//button[@id='thebut']")
Zoom = ((By.XPATH,"//a[@class='leaflet-control-zoom-in']"))
f= open('gps.txt','r')
myString = f.read()
f.close()
mySubString=myString[myString.find("$GPGGA"):myString.find("*")+3]

fr=open('Hello.txt','w')
fr.write(mySubString)
fr.close()


WebDriverWait(driver, 20).until(EC.element_to_be_clickable(GPS_FIELD)).send_keys(mySubString)
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Decode)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
WebDriverWait(driver, 20).until(EC.element_to_be_clickable(Zoom)).click()
time.sleep(1)
screenshot = driver.save_screenshot('testlocation.png')
driver.maximize_window()
elem.send_keys(Keys.CONTROL+"w")
