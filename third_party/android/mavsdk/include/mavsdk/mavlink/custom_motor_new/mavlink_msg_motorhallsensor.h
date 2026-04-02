#pragma once
// MESSAGE MotorHallSensor PACKING

#define MAVLINK_MSG_ID_MotorHallSensor 30086


typedef struct __mavlink_motorhallsensor_t {
 float Hall_A_Adc; /*<  */
 float Hall_A_Adc_Bias; /*<  */
 float Hall_B_Adc; /*<  */
 float Hall_B_Adc_Bias; /*<  */
 float HALL_Angle; /*<  */
 float hall_a_basi; /*<  */
 float hall_b_basi; /*<  */
 float norm_a; /*<  */
 float norm_b; /*<  */
} mavlink_motorhallsensor_t;

#define MAVLINK_MSG_ID_MotorHallSensor_LEN 36
#define MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN 36
#define MAVLINK_MSG_ID_30086_LEN 36
#define MAVLINK_MSG_ID_30086_MIN_LEN 36

#define MAVLINK_MSG_ID_MotorHallSensor_CRC 22
#define MAVLINK_MSG_ID_30086_CRC 22



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MotorHallSensor { \
    30086, \
    "MotorHallSensor", \
    9, \
    {  { "Hall_A_Adc", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_motorhallsensor_t, Hall_A_Adc) }, \
         { "Hall_A_Adc_Bias", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_motorhallsensor_t, Hall_A_Adc_Bias) }, \
         { "Hall_B_Adc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_motorhallsensor_t, Hall_B_Adc) }, \
         { "Hall_B_Adc_Bias", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_motorhallsensor_t, Hall_B_Adc_Bias) }, \
         { "HALL_Angle", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motorhallsensor_t, HALL_Angle) }, \
         { "hall_a_basi", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_motorhallsensor_t, hall_a_basi) }, \
         { "hall_b_basi", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_motorhallsensor_t, hall_b_basi) }, \
         { "norm_a", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_motorhallsensor_t, norm_a) }, \
         { "norm_b", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_motorhallsensor_t, norm_b) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MotorHallSensor { \
    "MotorHallSensor", \
    9, \
    {  { "Hall_A_Adc", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_motorhallsensor_t, Hall_A_Adc) }, \
         { "Hall_A_Adc_Bias", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_motorhallsensor_t, Hall_A_Adc_Bias) }, \
         { "Hall_B_Adc", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_motorhallsensor_t, Hall_B_Adc) }, \
         { "Hall_B_Adc_Bias", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_motorhallsensor_t, Hall_B_Adc_Bias) }, \
         { "HALL_Angle", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_motorhallsensor_t, HALL_Angle) }, \
         { "hall_a_basi", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_motorhallsensor_t, hall_a_basi) }, \
         { "hall_b_basi", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_motorhallsensor_t, hall_b_basi) }, \
         { "norm_a", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_motorhallsensor_t, norm_a) }, \
         { "norm_b", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_motorhallsensor_t, norm_b) }, \
         } \
}
#endif

/**
 * @brief Pack a motorhallsensor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Hall_A_Adc  
 * @param Hall_A_Adc_Bias  
 * @param Hall_B_Adc  
 * @param Hall_B_Adc_Bias  
 * @param HALL_Angle  
 * @param hall_a_basi  
 * @param hall_b_basi  
 * @param norm_a  
 * @param norm_b  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motorhallsensor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float Hall_A_Adc, float Hall_A_Adc_Bias, float Hall_B_Adc, float Hall_B_Adc_Bias, float HALL_Angle, float hall_a_basi, float hall_b_basi, float norm_a, float norm_b)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MotorHallSensor_LEN];
    _mav_put_float(buf, 0, Hall_A_Adc);
    _mav_put_float(buf, 4, Hall_A_Adc_Bias);
    _mav_put_float(buf, 8, Hall_B_Adc);
    _mav_put_float(buf, 12, Hall_B_Adc_Bias);
    _mav_put_float(buf, 16, HALL_Angle);
    _mav_put_float(buf, 20, hall_a_basi);
    _mav_put_float(buf, 24, hall_b_basi);
    _mav_put_float(buf, 28, norm_a);
    _mav_put_float(buf, 32, norm_b);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MotorHallSensor_LEN);
#else
    mavlink_motorhallsensor_t packet;
    packet.Hall_A_Adc = Hall_A_Adc;
    packet.Hall_A_Adc_Bias = Hall_A_Adc_Bias;
    packet.Hall_B_Adc = Hall_B_Adc;
    packet.Hall_B_Adc_Bias = Hall_B_Adc_Bias;
    packet.HALL_Angle = HALL_Angle;
    packet.hall_a_basi = hall_a_basi;
    packet.hall_b_basi = hall_b_basi;
    packet.norm_a = norm_a;
    packet.norm_b = norm_b;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MotorHallSensor_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MotorHallSensor;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
}

/**
 * @brief Pack a motorhallsensor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param Hall_A_Adc  
 * @param Hall_A_Adc_Bias  
 * @param Hall_B_Adc  
 * @param Hall_B_Adc_Bias  
 * @param HALL_Angle  
 * @param hall_a_basi  
 * @param hall_b_basi  
 * @param norm_a  
 * @param norm_b  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motorhallsensor_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float Hall_A_Adc, float Hall_A_Adc_Bias, float Hall_B_Adc, float Hall_B_Adc_Bias, float HALL_Angle, float hall_a_basi, float hall_b_basi, float norm_a, float norm_b)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MotorHallSensor_LEN];
    _mav_put_float(buf, 0, Hall_A_Adc);
    _mav_put_float(buf, 4, Hall_A_Adc_Bias);
    _mav_put_float(buf, 8, Hall_B_Adc);
    _mav_put_float(buf, 12, Hall_B_Adc_Bias);
    _mav_put_float(buf, 16, HALL_Angle);
    _mav_put_float(buf, 20, hall_a_basi);
    _mav_put_float(buf, 24, hall_b_basi);
    _mav_put_float(buf, 28, norm_a);
    _mav_put_float(buf, 32, norm_b);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MotorHallSensor_LEN);
#else
    mavlink_motorhallsensor_t packet;
    packet.Hall_A_Adc = Hall_A_Adc;
    packet.Hall_A_Adc_Bias = Hall_A_Adc_Bias;
    packet.Hall_B_Adc = Hall_B_Adc;
    packet.Hall_B_Adc_Bias = Hall_B_Adc_Bias;
    packet.HALL_Angle = HALL_Angle;
    packet.hall_a_basi = hall_a_basi;
    packet.hall_b_basi = hall_b_basi;
    packet.norm_a = norm_a;
    packet.norm_b = norm_b;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MotorHallSensor_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MotorHallSensor;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN);
#endif
}

/**
 * @brief Pack a motorhallsensor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Hall_A_Adc  
 * @param Hall_A_Adc_Bias  
 * @param Hall_B_Adc  
 * @param Hall_B_Adc_Bias  
 * @param HALL_Angle  
 * @param hall_a_basi  
 * @param hall_b_basi  
 * @param norm_a  
 * @param norm_b  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_motorhallsensor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float Hall_A_Adc,float Hall_A_Adc_Bias,float Hall_B_Adc,float Hall_B_Adc_Bias,float HALL_Angle,float hall_a_basi,float hall_b_basi,float norm_a,float norm_b)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MotorHallSensor_LEN];
    _mav_put_float(buf, 0, Hall_A_Adc);
    _mav_put_float(buf, 4, Hall_A_Adc_Bias);
    _mav_put_float(buf, 8, Hall_B_Adc);
    _mav_put_float(buf, 12, Hall_B_Adc_Bias);
    _mav_put_float(buf, 16, HALL_Angle);
    _mav_put_float(buf, 20, hall_a_basi);
    _mav_put_float(buf, 24, hall_b_basi);
    _mav_put_float(buf, 28, norm_a);
    _mav_put_float(buf, 32, norm_b);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MotorHallSensor_LEN);
#else
    mavlink_motorhallsensor_t packet;
    packet.Hall_A_Adc = Hall_A_Adc;
    packet.Hall_A_Adc_Bias = Hall_A_Adc_Bias;
    packet.Hall_B_Adc = Hall_B_Adc;
    packet.Hall_B_Adc_Bias = Hall_B_Adc_Bias;
    packet.HALL_Angle = HALL_Angle;
    packet.hall_a_basi = hall_a_basi;
    packet.hall_b_basi = hall_b_basi;
    packet.norm_a = norm_a;
    packet.norm_b = norm_b;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MotorHallSensor_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MotorHallSensor;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
}

/**
 * @brief Encode a motorhallsensor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param motorhallsensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motorhallsensor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_motorhallsensor_t* motorhallsensor)
{
    return mavlink_msg_motorhallsensor_pack(system_id, component_id, msg, motorhallsensor->Hall_A_Adc, motorhallsensor->Hall_A_Adc_Bias, motorhallsensor->Hall_B_Adc, motorhallsensor->Hall_B_Adc_Bias, motorhallsensor->HALL_Angle, motorhallsensor->hall_a_basi, motorhallsensor->hall_b_basi, motorhallsensor->norm_a, motorhallsensor->norm_b);
}

/**
 * @brief Encode a motorhallsensor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param motorhallsensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motorhallsensor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_motorhallsensor_t* motorhallsensor)
{
    return mavlink_msg_motorhallsensor_pack_chan(system_id, component_id, chan, msg, motorhallsensor->Hall_A_Adc, motorhallsensor->Hall_A_Adc_Bias, motorhallsensor->Hall_B_Adc, motorhallsensor->Hall_B_Adc_Bias, motorhallsensor->HALL_Angle, motorhallsensor->hall_a_basi, motorhallsensor->hall_b_basi, motorhallsensor->norm_a, motorhallsensor->norm_b);
}

/**
 * @brief Encode a motorhallsensor struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param motorhallsensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_motorhallsensor_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_motorhallsensor_t* motorhallsensor)
{
    return mavlink_msg_motorhallsensor_pack_status(system_id, component_id, _status, msg,  motorhallsensor->Hall_A_Adc, motorhallsensor->Hall_A_Adc_Bias, motorhallsensor->Hall_B_Adc, motorhallsensor->Hall_B_Adc_Bias, motorhallsensor->HALL_Angle, motorhallsensor->hall_a_basi, motorhallsensor->hall_b_basi, motorhallsensor->norm_a, motorhallsensor->norm_b);
}

/**
 * @brief Send a motorhallsensor message
 * @param chan MAVLink channel to send the message
 *
 * @param Hall_A_Adc  
 * @param Hall_A_Adc_Bias  
 * @param Hall_B_Adc  
 * @param Hall_B_Adc_Bias  
 * @param HALL_Angle  
 * @param hall_a_basi  
 * @param hall_b_basi  
 * @param norm_a  
 * @param norm_b  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_motorhallsensor_send(mavlink_channel_t chan, float Hall_A_Adc, float Hall_A_Adc_Bias, float Hall_B_Adc, float Hall_B_Adc_Bias, float HALL_Angle, float hall_a_basi, float hall_b_basi, float norm_a, float norm_b)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MotorHallSensor_LEN];
    _mav_put_float(buf, 0, Hall_A_Adc);
    _mav_put_float(buf, 4, Hall_A_Adc_Bias);
    _mav_put_float(buf, 8, Hall_B_Adc);
    _mav_put_float(buf, 12, Hall_B_Adc_Bias);
    _mav_put_float(buf, 16, HALL_Angle);
    _mav_put_float(buf, 20, hall_a_basi);
    _mav_put_float(buf, 24, hall_b_basi);
    _mav_put_float(buf, 28, norm_a);
    _mav_put_float(buf, 32, norm_b);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorHallSensor, buf, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
#else
    mavlink_motorhallsensor_t packet;
    packet.Hall_A_Adc = Hall_A_Adc;
    packet.Hall_A_Adc_Bias = Hall_A_Adc_Bias;
    packet.Hall_B_Adc = Hall_B_Adc;
    packet.Hall_B_Adc_Bias = Hall_B_Adc_Bias;
    packet.HALL_Angle = HALL_Angle;
    packet.hall_a_basi = hall_a_basi;
    packet.hall_b_basi = hall_b_basi;
    packet.norm_a = norm_a;
    packet.norm_b = norm_b;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorHallSensor, (const char *)&packet, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
#endif
}

/**
 * @brief Send a motorhallsensor message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_motorhallsensor_send_struct(mavlink_channel_t chan, const mavlink_motorhallsensor_t* motorhallsensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_motorhallsensor_send(chan, motorhallsensor->Hall_A_Adc, motorhallsensor->Hall_A_Adc_Bias, motorhallsensor->Hall_B_Adc, motorhallsensor->Hall_B_Adc_Bias, motorhallsensor->HALL_Angle, motorhallsensor->hall_a_basi, motorhallsensor->hall_b_basi, motorhallsensor->norm_a, motorhallsensor->norm_b);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorHallSensor, (const char *)motorhallsensor, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
#endif
}

#if MAVLINK_MSG_ID_MotorHallSensor_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_motorhallsensor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float Hall_A_Adc, float Hall_A_Adc_Bias, float Hall_B_Adc, float Hall_B_Adc_Bias, float HALL_Angle, float hall_a_basi, float hall_b_basi, float norm_a, float norm_b)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, Hall_A_Adc);
    _mav_put_float(buf, 4, Hall_A_Adc_Bias);
    _mav_put_float(buf, 8, Hall_B_Adc);
    _mav_put_float(buf, 12, Hall_B_Adc_Bias);
    _mav_put_float(buf, 16, HALL_Angle);
    _mav_put_float(buf, 20, hall_a_basi);
    _mav_put_float(buf, 24, hall_b_basi);
    _mav_put_float(buf, 28, norm_a);
    _mav_put_float(buf, 32, norm_b);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorHallSensor, buf, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
#else
    mavlink_motorhallsensor_t *packet = (mavlink_motorhallsensor_t *)msgbuf;
    packet->Hall_A_Adc = Hall_A_Adc;
    packet->Hall_A_Adc_Bias = Hall_A_Adc_Bias;
    packet->Hall_B_Adc = Hall_B_Adc;
    packet->Hall_B_Adc_Bias = Hall_B_Adc_Bias;
    packet->HALL_Angle = HALL_Angle;
    packet->hall_a_basi = hall_a_basi;
    packet->hall_b_basi = hall_b_basi;
    packet->norm_a = norm_a;
    packet->norm_b = norm_b;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MotorHallSensor, (const char *)packet, MAVLINK_MSG_ID_MotorHallSensor_MIN_LEN, MAVLINK_MSG_ID_MotorHallSensor_LEN, MAVLINK_MSG_ID_MotorHallSensor_CRC);
#endif
}
#endif

#endif

// MESSAGE MotorHallSensor UNPACKING


/**
 * @brief Get field Hall_A_Adc from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_Hall_A_Adc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field Hall_A_Adc_Bias from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_Hall_A_Adc_Bias(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field Hall_B_Adc from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_Hall_B_Adc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field Hall_B_Adc_Bias from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_Hall_B_Adc_Bias(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field HALL_Angle from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_HALL_Angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field hall_a_basi from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_hall_a_basi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field hall_b_basi from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_hall_b_basi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field norm_a from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_norm_a(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field norm_b from motorhallsensor message
 *
 * @return  
 */
static inline float mavlink_msg_motorhallsensor_get_norm_b(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Decode a motorhallsensor message into a struct
 *
 * @param msg The message to decode
 * @param motorhallsensor C-struct to decode the message contents into
 */
static inline void mavlink_msg_motorhallsensor_decode(const mavlink_message_t* msg, mavlink_motorhallsensor_t* motorhallsensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    motorhallsensor->Hall_A_Adc = mavlink_msg_motorhallsensor_get_Hall_A_Adc(msg);
    motorhallsensor->Hall_A_Adc_Bias = mavlink_msg_motorhallsensor_get_Hall_A_Adc_Bias(msg);
    motorhallsensor->Hall_B_Adc = mavlink_msg_motorhallsensor_get_Hall_B_Adc(msg);
    motorhallsensor->Hall_B_Adc_Bias = mavlink_msg_motorhallsensor_get_Hall_B_Adc_Bias(msg);
    motorhallsensor->HALL_Angle = mavlink_msg_motorhallsensor_get_HALL_Angle(msg);
    motorhallsensor->hall_a_basi = mavlink_msg_motorhallsensor_get_hall_a_basi(msg);
    motorhallsensor->hall_b_basi = mavlink_msg_motorhallsensor_get_hall_b_basi(msg);
    motorhallsensor->norm_a = mavlink_msg_motorhallsensor_get_norm_a(msg);
    motorhallsensor->norm_b = mavlink_msg_motorhallsensor_get_norm_b(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MotorHallSensor_LEN? msg->len : MAVLINK_MSG_ID_MotorHallSensor_LEN;
        memset(motorhallsensor, 0, MAVLINK_MSG_ID_MotorHallSensor_LEN);
    memcpy(motorhallsensor, _MAV_PAYLOAD(msg), len);
#endif
}
