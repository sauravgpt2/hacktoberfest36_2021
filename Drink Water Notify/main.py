import time
from plyer import notification

if __name__=='__main__':
    # while True:
        notification.notify(
            title="**Please Drink Water Now**!!",
            message="The National Academies of Sciences, Engineering, and Medicine determined that an adequate daily fluid intake is: About 15.5 cups (3.7 liters) of fluids for men. About 11.5 cups (2.7 liters) of fluids a day for women.",
            app_icon=r"C:\Users\Dell\Documents\PYTHON PROJECTS\Drink Water Notify\icon.ico",
            timeout=10
        )
        # time.sleep(3600)