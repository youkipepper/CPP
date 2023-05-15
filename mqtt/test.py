import pymysql
import paho.mqtt.client as mqtt

# MQTT连接参数
mqtt_server_address = "<tcp://106.52.220.216:1883>"
mqtt_user_id = "<bjsmatc>"
mqtt_username = "<bjsmat>"
mqtt_password = "<SMat88351020>"
# mqtt_topic = "<SHM/QN>"

# MySQL数据库连接参数
mysql_host = "123.60.191.124"
mysql_user = "root"
mysql_password = "Hzk2022@"
mysql_database = "for_smt"

# 连接MySQL数据库
connection = pymysql.connect(
    host=mysql_host,
    user=mysql_user,
    password=mysql_password,
    database=mysql_database
)

# 连接MQTT服务器
client = mqtt.Client()
client.username_pw_set(mqtt_username, mqtt_password)
client.connect(mqtt_server_address, 1883)

# 定义消息处理函数
def on_message(client, userdata, message):
    # 在此处添加你的消息处理逻辑
    pass

# 订阅主题
client.subscribe(mqtt_topic)
client.on_message = on_message

# 启动循环监听MQTT消息
client.loop_forever()
