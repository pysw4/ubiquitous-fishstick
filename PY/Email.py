#!/usr/bin/env python3
# from email.mime.text import MIMEText
# msg = MIMEText('hello, send by Python...', 'plain', 'utf-8')
# # 输入Email地址和口令:
# from_addr = "pingjingqing4@icloud.com"
# password = "qecd-fbjb-khck-bnzg"
# # 输入收件人地址:
# to_addr = "thuckyousir718@163.com"
# # 输入SMTP服务器地址:
# smtp_server = "smtp.mail.me.com"

# import smtplib
# server = smtplib.SMTP(smtp_server, 587) # SMTP协议默认端口是25
# server.set_debuglevel(1)
# server.starttls()
# server.login(from_addr, password)
# server.sendmail(from_addr, [to_addr], msg.as_string())
# server.quit()


from email.mime.text import MIMEText
from email.utils import formataddr, make_msgid, formatdate
import smtplib
to_addrs = input('Email to:')
# 创建邮件
msg = MIMEText('Hello, this is a test email from Python!', 'plain', 'utf-8')
# 正确设置邮件头部
msg['From'] = formataddr(('Ishmael', 'pingjingqing4@icloud.com'))
msg['To'] = formataddr(('Recipient', to_addrs))
msg['Subject'] = 'Test Email from iCloud'
msg['Message-ID'] = make_msgid()  # 修正这里
msg['Date'] = formatdate(localtime=True)

# SMTP 配置
smtp_server = "smtp.mail.me.com"
username = "pingjingqing4@icloud.com"
password = "qecd-fbjb-khck-bnzg"


try:
    print("=" * 50)
    print("邮件详情:")
    print(f"发件人: {msg['From']}")
    print(f"收件人: {msg['To']}")
    print(f"主题: {msg['Subject']}")
    print("=" * 50)
    
    # 连接服务器
    with smtplib.SMTP(smtp_server, 587, timeout=30) as server:
        server.set_debuglevel(1)  # 显示详细日志
        
        # 通信流程
        server.ehlo()
        server.starttls()
        server.ehlo()
        
        # 登录
        server.login(username, password)
        
        # 发送
        server.sendmail(username, [to_addrs], msg.as_string())
        
    print("\n发送成功！")
    
except smtplib.SMTPDataError as e:
    print(f"❌ SMTP错误: {e}")
    print("\n建议：")
    print("1. 检查是否需要在 iCloud.com 中验证邮箱")
    print("2. 尝试先用网页版 iCloud 发送一封邮件")
    
except Exception as e:
    print(f"❌ 错误: {e}")