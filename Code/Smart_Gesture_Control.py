import serial                                               #Including the library to manipulate the serial data from the Octabrix
import pyautogui                                            #Including the library to control the GUI(PC) with the coming serial inputs

Arduino_Serial = serial.Serial("COM4",115200)               #Creating a variable to get connected with the octabrix and to get the serial data
print ("Connected")
while 1:                                                    #Goes on taking serial inputs till the connection ended
    incoming_data = str (Arduino_Serial.readline())         #Typecasting the collected data into a string
    print (incoming_data)                                   

    if 'Up' in incoming_data:                               #If the serial data we get is Up
        pyautogui.hotkey('up');                             #Presses the UP arrow key
        
    if 'Down' in incoming_data:                             #If the data is Down  
        pyautogui.hotkey('down');                           #Presses the Down arrow key

    if 'Left' in incoming_data:                             #If the data is Left
        pyautogui.hotkey('left');                           #Presses the Left arrow key
         
    if 'Right' in incoming_data:                            #If the data is Right
        pyautogui.hotkey('right');                          #Presses the Right arrow key
        
    if 'mouseleft' in incoming_data:                        #If the data is mouseleft
        pyautogui.click();                                  #Presses the LeftClick mouse key
        
    if 'mouseright' in incoming_data:                       #If the data is mouseright
        pyautogui.click(button='right');                    #Presses the RightClick mouse key
        
    if 'stop' in incoming_data:                            #If the data is pauseHello World
        #pyautogui.hotkey('space')                           #Presses the Space Bar
        #pyautogui.keyUp('space')
        pyautogui.click();
        
    if 'next' in incoming_data:
        pyautogui.hotkey('shift','n');
        
    if 'a' in incoming_data:                                #If the data is a
        pyautogui.typewrite("Hello World")                  #We can also give some text input
        
    if 'delete' in incoming_data:                           #If the data is delete
        pyautogui.hotkey('del');                             #Presses Del key

    if 'enter' in incoming_data:                            #if the data is enter
        pyautogui.hotkey('enter');                           #
        
    if 'lock' in  incoming_data:
        pyautogui.hotkey('alt', 'f4')
        
        
    incoming_data = "";                                     #Here we will make the data empty every time because it holds previous data
    
