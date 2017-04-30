"""LOL."""

from selenium import webdriver
from selenium.webdriver.common import action_chains, keys
import time

driver = webdriver.Chrome()
driver.get('https://www.quora.com')
time.sleep(3)
action = action_chains.ActionChains(driver)
action.send_keys("reddy.nithinpg@gmail.com" + keys.Keys.TAB + "ketoillidan97" + keys.Keys.ENTER)
action.perform()
time.sleep(6)
action.reset_actions()
action.send_keys("LOL" + keys.Keys.ENTER)
action.perform()
time.sleep(6)
print(driver.page_source)
