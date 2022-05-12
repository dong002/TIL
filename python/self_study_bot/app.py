from selenium import webdriver
driver = webdriver.Chrome('C:\\Users\\s2102\\Downloads\\chromedriver_win32\\chromedriver.exe')
driver.get('https://dotori-gsm.com/home')

def autoClick():
    cnt = 1

    while cnt <= 50:
        driver.refresh()
        btns= driver.find_element_by_xpath('//*[@class="search_btn"]') #버튼 좌표
        btns.click()

