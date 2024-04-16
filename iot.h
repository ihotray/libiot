#ifndef __IOT_H__
#define __IOT_H__

#define MQTT_LISTEN_ADDR "mqtt://127.0.0.1:11883"
#define MQTTS_LISTEN_ADDR "mqtts://0.0.0.0:18883"


#define MQTT_QOS 1
#define MQTT_MAX_TOPIC_LEN 128

//http communicate with rpcd
//sub
#define IOT_HTTP_TOPIC  "mg/iot-http/+"
#define IOT_HTTP_TOPIC_PREFIX "iot-http/"
//pub mg/iot-http/{reqID}/iot-rpcd
#define IOT_HTTP_RPCD_TOPIC "mg/iot-http/%lu/iot-rpcd"

//http communicate with mqtt
#define IOT_HTTP_MQTT_TOPIC "mg/iot-http/%lu/$iot-mqtt"

//mqtt communicate with others
#define IOT_MQTT_TOPIC "mg/*/$iot-mqtt"
#define IOT_MQTT_TOPIC_POSTFIX "/$iot-mqtt"

//http communicate with agent for proxy
#define IOT_HTTP_PROXY_REQ_TOPIC "device/%.*s/rpc/request/iot-http/%lu"
#define IOT_HTTP_PROXY_RESP_TOPIC "device/+/rpc/response/iot-http/+"

//agent communicate with rpcd
#define IOT_AGENT_TOPIC "mg/iot-agent/%s/+/+/+"
#define IOT_AGENT_TOPIC_RPEFIX "mg/iot-agent/%s/"
#define IOT_AGENT_RPCD_LOCAL_TOPIC "mg/iot-agent/%s/local/1/1/iot-rpcd"  //agent's req
#define IOT_AGENT_RPCD_CONTROLLER_TOPIC "mg/iot-agent/%s/controller/%.*s/iot-rpcd"
#define IOT_CONTROLLER_TOPIC_TYPE "controller/"

//agent communicate with controller
#define IOT_AGENT_REQ_TOPIC "device/%s/rpc/request/+/+"
#define IOT_AGENT_REQ_TOPIC_PREFIX "device/%s/rpc/request/"
#define IOT_AGENT_RESP_TOPIC "device/%s/rpc/response/%.*s"

//communicate between agents
//pub device/{devid}/rpc/request/{serviceId}/{reqId}
#define IOT_AGENT_PROXY_REQ_TOPIC "device/%s/rpc/request/%s/%lu"
//sub device/+/rpc/response/{agent_id}/+
#define IOT_AGENT_PROXY_RESP_TOPIC "device/+/rpc/response/%s/+" 

//rpcd communicate with others
#define IOT_RPCD_TOPIC "mg/+/iot-rpcd"
#define IOT_RPCD_TOPIC_POSTFIX "/iot-rpcd"

#define MAX_TOKEN_LEN 64
#define MAX_USERNAME_LEN 128
#define MAX_PASSWORD_LEN 128
#define MAX_API_LEN 32
#define MAX_URL_LEN 256

#define DEFALUT_NONCE_TIMEOUT 10 //s
#define MAX_NONCE_TIMEOUT 60 //s

#define DEFAULT_NONCE_TRIES 5
#define MAX_NONCE_TRIES 60

#define DEFAULT_TOKEN_TIMEOUT 300
#define MAX_TOKEN_TIMEOUT 86400 //s

#define IOT_SDK_HOST "Host: iot-web\r\n"

#define MQTT_METHOD_PREFIX "$mqtt/"
#define MQTT_METHOD_CLIENTS "$mqtt/clients"

#define FIELD_METHOD "method"
#define FIELD_PARAM "param"
#define FIELD_CODE "code"
#define FIELD_DATA "data"
#define FIELD_USERNAME "username"
#define FIELD_PASSWORD "password"
#define FIELD_CLIENT "client"
#define FIELD_NONCE "nonce"
#define FIELD_TOKEN "token"
#define FIELD_TIMEOUT "timeout"
#define FIELD_TRIES "tries"
#define FIELD_URL "url"
#define FIELD_FILENAME "filename"
#define FIELD_TO "to"
#define FIELD_PROXY "proxy"
#define FIELD_TOPIC "topic"



#define IOT_METHOD_UPLOAD "upload"
#define IOT_METHOD_DOWNLOAD "download"


#endif