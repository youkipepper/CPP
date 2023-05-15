import mysql.connector
import paho.mqtt.client as mqtt

# MySQL数据库配置
mysql_config = {
    "host": "123.60.191.124",
    "user": "root",
    "password": "Hzk2022@",
    "database": "for_smt"
}

# MQTT服务器配置
mqtt_config = {
    "host": "106.52.220.216",
    "port": 1883,
    "username": "bjsmat",
    "password": "SMat88351020"
}

# 连接MySQL数据库
def connect_to_mysql():
    connection = mysql.connector.connect(**mysql_config)
    return connection

# 连接MQTT服务器
def connect_to_mqtt():
    client = mqtt.Client()
    client.username_pw_set(mqtt_config["username"], mqtt_config["password"])
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(mqtt_config["host"], mqtt_config["port"], 60)
    return client

# MQTT连接回调函数
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe("your_mqtt_topic")

# MQTT接收消息回调函数
def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.payload))
    # 根据接收到的消息处理MySQL数据库

if __name__ == "__main__":
    mysql_conn = connect_to_mysql()
    mqtt_client = connect_to_mqtt()
    mqtt_client.loop_forever()
