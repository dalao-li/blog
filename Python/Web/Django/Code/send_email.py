'''
Description: 
Version: 1.0
Author: DaLao
Email:  
Date: 2021-09-24 20:37:24
LastEditors: dalao
LastEditTime: 2022-04-18 10:34:22
'''

import datetime
import smtplib
from email.header import Header
from email.mime.text import MIMEText


class CompanyEmail():
    def __init__(self, ):
        """
        docstring
        """
        self.from_addr = 'cloud_and_bubble@163.com'  # 邮件发送账号
        self.code_163_email = 'ZADEQKQHZVBXJBSN'  # 授权码(这个要填自己获取到的)
        smtp_server = 'smtp.163.com'  # 固定写死
        smtp_port = 465  # 固定端口
        # 配置服务器
        self.stmp = smtplib.SMTP_SSL(smtp_server, smtp_port)
        self.stmp.login(self.from_addr, self.code_163_email)

    def send_mail(self, temp_code, to_addrs):

        body = """
        <table style="width: 99.8%; height: 95%;font-size: xx-large;">
        <tbody>
            <tr>
                <td id="QQMAILSTATIONERY" style="background:url(https://rescdn.qqmail.com/bizmail/zh_CN/htmledition/images/xinzhi/bg/a_02.jpg) no-repeat #fffaf6; min-height:550px; padding:100px 55px 200px 100px; ">
                <div style="text-align: center;font-size: xx-large;"><font size="4">亲爱的用户 ！</font>&nbsp;</div>
                <div style="text-align: center;"><font size="4"><br>
                    </font>
                </div>
                <div style="text-align: center;"><font size="4">这是一封注册认证邮件, 请在网页中输入如下验证码:&nbsp;</font></div>
                <div style="text-align: center;"><font size="4"><br>
                    </font>
                </div>
                <div style="text-align: center;"><font size="5" color="#ff0000"><b><u>临时验证码:{}</u></b></font></div>
                <div style="text-align: center;"><font size="4"><br>
                    </font>
                </div>
                <div style="text-align: center;"><font size="4">            
                    我们是浮名科技公司.<br/>
                    上述验证码10分钟内有效.如果激活失效, 请您重新申请验证码.<br/>
                    请勿将信息提供给其他人.<br/>
                    感谢您注册云与浮名科技公司.&nbsp;<br/>
    </font></div>
                <div style="text-align: center;"><font size="4"><br>
                    </font>
                </div>
                <div style="text-align: center;"><font size="4">感谢支持.</font></div>
                </td>
            </tr>
        </tbody>
    </table>
    <div><includetail><!--<![endif]--></includetail></div>
        
        """.format(temp_code)
        message = MIMEText(body, _subtype="html", _charset="utf-8")
        message['From'] = self.from_addr  # 发件人
        message['To'] = to_addrs  # 收件人
        message['Cc'] = self.from_addr
        message['Subject'] = "云与浮名 公司的身份验证"  # 邮件标题

        try:
            self.stmp.sendmail(self.from_addr, [to_addrs], message.as_string())
        except Exception as e:
            print('邮件发送失败--' + str(e))
        else:
            print('邮件发送成功')

    def __del__(self):
        self.stmp.close()


if __name__ == "__main__":
    CompanyEmail().send_mail("6382", "邮箱")
