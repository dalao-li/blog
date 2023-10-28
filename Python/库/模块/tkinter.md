<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-17 15:23:29
-->

# tkinter

```py
from tkinter import *

class Application(Frame):
    def __init__(self, master = None):
        Frame.__init__(self, master)
        self.config(width = 700, height = 400)
        self.pack()
        self.createWidgets()
    
    def createWidgets(self):
        self.urlLabel = Label(self, text = '链接地址', font = ('Arial', 12))
        self.urlLabel.place(x = 20, y = 20)
        
        self.urlEntry = Entry(self, show = None, font = ('Arial', 14))
        self.urlEntry.place(x = 100, y = 20, width = 500)

        self.downButton = Button(self, text = '下载', font = ('Arial', 12), command = download)
        self.downButton.place(x = 100, y = 80, width = 100, height = 50)

if __name__ == '__main__':
    app = Application()

    app.master.title('')

    app.mainloop()
```
