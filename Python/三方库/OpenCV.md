<!--
 * @Description:  
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-11 21:05:23
-->

## OpenCV


### 安装 OpenCV

```py
pip install opencv-python
```

- 修改 numpy 版本

Windows 只能安装 numpy 1.19.3，若直接使用 pip install 安装的是 1.19.4 版本，因此在安装时需要指定版本

```py
pip uninstall numpy

pip install numpy==1.19.3
```



### 显示图像

```py
import cv2 as cv
import numpy as np

image = cv.imread("图片路径")

# 灰度化处理
gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

cv.namedWindow("input image", cv.WINDOW_AUTOSIZE)
cv.imshow("input image", gray)

cv.waitKey(0)

# 作用是能正常关闭绘图窗口
cv.destroyAllWindows()
```



### 图片人脸识别

```py
import cv2 as cv
import numpy as np

eye_detector_path = "venv\\Lib\\site-packages\\cv2\\data\\haarcascade_eye.xml"

face_detector_path = "venv\\Lib\\site-packages\\cv2\\data\\haarcascade_frontalcatface.xml"

def face_detect_demo():
    # 图片变成灰度图片,因为人脸的特征需要在灰度图像中查找
    gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)
    
    # 通过级联检测器 cv.CascadeClassifier,加载特征数据
    face_detector = cv.CascadeClassifier(face_detector_path)
    
    # 在尺度空间对图片进行人脸检测,
    # 第一个参数是哪个图片,
    # 第二个参数是向上或向下的尺度变化,是原来尺度的1.02倍,
    # 第三个参数是在相邻的几个人脸检测矩形框内出现就认定成人脸,
    # 这里是在相邻的5个人脸检测框内出现,如果图片比较模糊的话建议降低一点
    faces = face_detector.detectMultiScale(gray, 1.02, 5)
    
    # 绘制结果图
    for x, y, w, h in faces:
        # 参数:要绘制的目标图像,矩形的第一个顶点,矩形对角线上的另一个顶点,线条颜色,线条宽度
        cv.rectangle(src, (x, y), (x + w, y + h), (0, 0, 255), 2)
        cv.imshow("result", src)

if __name__ == '__main__':
    src = cv.imread("picture\\a.png")
    cv.namedWindow("input image", cv.WINDOW_AUTOSIZE)
    cv.imshow("input image", src)
    cv.namedWindow("result", cv.WINDOW_AUTOSIZE)
    
    face_detect_demo()
    
    cv.waitKey(0)
    cv.destroyAllWindows()
```


### 视频人脸识别

```py
import cv2 as cv
import numpy as np

eye_detector_path = "venv\\Lib\\site-packages\\cv2\\data\\haarcascade_eye.xml"

face_detector_path = "venv\\Lib\\site-packages\\cv2\\data\\haarcascade_frontalface_default.xml"

if __name__ == '__main__':
    cv.namedWindow("result", cv.WINDOW_AUTOSIZE)
    cap = cv.VideoCapture(1)
    face_detector = cv.CascadeClassifier(face_detector_path)
    face_detector.load(face_detector_path)
    while (True):
        check, frame = cap.read()
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        
        # 在尺度空间对图片进行人脸检测
        # 第一个参数是图片
        # 第二个参数是向上或向下的尺度变化,是原来尺度的1.2倍
        # 第三个参数是在相邻的几个人脸检测矩形框内出现就认定成人脸,这里是在相邻的5个人脸检测框内出现,如果图片比较模糊的话建议降低一点
        faces = face_detector.detectMultiScale(gray, scaleFactor=1.2, minNeighbors=2)
        if len(faces):
            for x, y, w, h in faces:
                # 参数:要绘制的目标图像,矩形的第一个顶点,矩形对角线上的另一个顶点,线条颜色,线条宽度
                cv.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
                print(x, y, x + w, y + h)

        cv.imshow("result", frame)
        if cv.waitKey(1) & 0xFF == ord('q'):  # 按q键退出
            break
    cap.release()
    cv.destroyAllWindows()
```
