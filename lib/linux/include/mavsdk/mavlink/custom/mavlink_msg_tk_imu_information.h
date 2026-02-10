#pragma once
// MESSAGE TK_IMU_INFORMATION PACKING

#define MAVLINK_MSG_ID_TK_IMU_INFORMATION 51002


typedef struct __mavlink_tk_imu_information_t {
 float temperature; /*<  Temperature of the gimbal imu, unit: 1°C/LSB.*/
 float gyro_offset[3]; /*<  Angular velocity error.*/
 float accel_offset[3]; /*<  acceleration error.*/
 float acc_matrix[9]; /*<  .*/
 uint8_t flag; /*<  Calibration completion flag.*/
} mavlink_tk_imu_information_t;

#define MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN 65
#define MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN 65
#define MAVLINK_MSG_ID_51002_LEN 65
#define MAVLINK_MSG_ID_51002_MIN_LEN 65

#define MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC 211
#define MAVLINK_MSG_ID_51002_CRC 211

#define MAVLINK_MSG_TK_IMU_INFORMATION_FIELD_GYRO_OFFSET_LEN 3
#define MAVLINK_MSG_TK_IMU_INFORMATION_FIELD_ACCEL_OFFSET_LEN 3
#define MAVLINK_MSG_TK_IMU_INFORMATION_FIELD_ACC_MATRIX_LEN 9

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TK_IMU_INFORMATION { \
    51002, \
    "TK_IMU_INFORMATION", \
    5, \
    {  { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tk_imu_information_t, temperature) }, \
         { "gyro_offset", NULL, MAVLINK_TYPE_FLOAT, 3, 4, offsetof(mavlink_tk_imu_information_t, gyro_offset) }, \
         { "accel_offset", NULL, MAVLINK_TYPE_FLOAT, 3, 16, offsetof(mavlink_tk_imu_information_t, accel_offset) }, \
         { "acc_matrix", NULL, MAVLINK_TYPE_FLOAT, 9, 28, offsetof(mavlink_tk_imu_information_t, acc_matrix) }, \
         { "flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_tk_imu_information_t, flag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TK_IMU_INFORMATION { \
    "TK_IMU_INFORMATION", \
    5, \
    {  { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_tk_imu_information_t, temperature) }, \
         { "gyro_offset", NULL, MAVLINK_TYPE_FLOAT, 3, 4, offsetof(mavlink_tk_imu_information_t, gyro_offset) }, \
         { "accel_offset", NULL, MAVLINK_TYPE_FLOAT, 3, 16, offsetof(mavlink_tk_imu_information_t, accel_offset) }, \
         { "acc_matrix", NULL, MAVLINK_TYPE_FLOAT, 9, 28, offsetof(mavlink_tk_imu_information_t, acc_matrix) }, \
         { "flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_tk_imu_information_t, flag) }, \
         } \
}
#endif

/**
 * @brief Pack a tk_imu_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param temperature  Temperature of the gimbal imu, unit: 1°C/LSB.
 * @param gyro_offset  Angular velocity error.
 * @param accel_offset  acceleration error.
 * @param acc_matrix  .
 * @param flag  Calibration completion flag.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tk_imu_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float temperature, const float *gyro_offset, const float *accel_offset, const float *acc_matrix, uint8_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN];
    _mav_put_float(buf, 0, temperature);
    _mav_put_uint8_t(buf, 64, flag);
    _mav_put_float_array(buf, 4, gyro_offset, 3);
    _mav_put_float_array(buf, 16, accel_offset, 3);
    _mav_put_float_array(buf, 28, acc_matrix, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
#else
    mavlink_tk_imu_information_t packet;
    packet.temperature = temperature;
    packet.flag = flag;
    mav_array_memcpy(packet.gyro_offset, gyro_offset, sizeof(float)*3);
    mav_array_memcpy(packet.accel_offset, accel_offset, sizeof(float)*3);
    mav_array_memcpy(packet.acc_matrix, acc_matrix, sizeof(float)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TK_IMU_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
}

/**
 * @brief Pack a tk_imu_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param temperature  Temperature of the gimbal imu, unit: 1°C/LSB.
 * @param gyro_offset  Angular velocity error.
 * @param accel_offset  acceleration error.
 * @param acc_matrix  .
 * @param flag  Calibration completion flag.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tk_imu_information_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float temperature, const float *gyro_offset, const float *accel_offset, const float *acc_matrix, uint8_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN];
    _mav_put_float(buf, 0, temperature);
    _mav_put_uint8_t(buf, 64, flag);
    _mav_put_float_array(buf, 4, gyro_offset, 3);
    _mav_put_float_array(buf, 16, accel_offset, 3);
    _mav_put_float_array(buf, 28, acc_matrix, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
#else
    mavlink_tk_imu_information_t packet;
    packet.temperature = temperature;
    packet.flag = flag;
    mav_array_memcpy(packet.gyro_offset, gyro_offset, sizeof(float)*3);
    mav_array_memcpy(packet.accel_offset, accel_offset, sizeof(float)*3);
    mav_array_memcpy(packet.acc_matrix, acc_matrix, sizeof(float)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TK_IMU_INFORMATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
#endif
}

/**
 * @brief Pack a tk_imu_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param temperature  Temperature of the gimbal imu, unit: 1°C/LSB.
 * @param gyro_offset  Angular velocity error.
 * @param accel_offset  acceleration error.
 * @param acc_matrix  .
 * @param flag  Calibration completion flag.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_tk_imu_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float temperature,const float *gyro_offset,const float *accel_offset,const float *acc_matrix,uint8_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN];
    _mav_put_float(buf, 0, temperature);
    _mav_put_uint8_t(buf, 64, flag);
    _mav_put_float_array(buf, 4, gyro_offset, 3);
    _mav_put_float_array(buf, 16, accel_offset, 3);
    _mav_put_float_array(buf, 28, acc_matrix, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
#else
    mavlink_tk_imu_information_t packet;
    packet.temperature = temperature;
    packet.flag = flag;
    mav_array_memcpy(packet.gyro_offset, gyro_offset, sizeof(float)*3);
    mav_array_memcpy(packet.accel_offset, accel_offset, sizeof(float)*3);
    mav_array_memcpy(packet.acc_matrix, acc_matrix, sizeof(float)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TK_IMU_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
}

/**
 * @brief Encode a tk_imu_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param tk_imu_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tk_imu_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_tk_imu_information_t* tk_imu_information)
{
    return mavlink_msg_tk_imu_information_pack(system_id, component_id, msg, tk_imu_information->temperature, tk_imu_information->gyro_offset, tk_imu_information->accel_offset, tk_imu_information->acc_matrix, tk_imu_information->flag);
}

/**
 * @brief Encode a tk_imu_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param tk_imu_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tk_imu_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_tk_imu_information_t* tk_imu_information)
{
    return mavlink_msg_tk_imu_information_pack_chan(system_id, component_id, chan, msg, tk_imu_information->temperature, tk_imu_information->gyro_offset, tk_imu_information->accel_offset, tk_imu_information->acc_matrix, tk_imu_information->flag);
}

/**
 * @brief Encode a tk_imu_information struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param tk_imu_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_tk_imu_information_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_tk_imu_information_t* tk_imu_information)
{
    return mavlink_msg_tk_imu_information_pack_status(system_id, component_id, _status, msg,  tk_imu_information->temperature, tk_imu_information->gyro_offset, tk_imu_information->accel_offset, tk_imu_information->acc_matrix, tk_imu_information->flag);
}

/**
 * @brief Send a tk_imu_information message
 * @param chan MAVLink channel to send the message
 *
 * @param temperature  Temperature of the gimbal imu, unit: 1°C/LSB.
 * @param gyro_offset  Angular velocity error.
 * @param accel_offset  acceleration error.
 * @param acc_matrix  .
 * @param flag  Calibration completion flag.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_tk_imu_information_send(mavlink_channel_t chan, float temperature, const float *gyro_offset, const float *accel_offset, const float *acc_matrix, uint8_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN];
    _mav_put_float(buf, 0, temperature);
    _mav_put_uint8_t(buf, 64, flag);
    _mav_put_float_array(buf, 4, gyro_offset, 3);
    _mav_put_float_array(buf, 16, accel_offset, 3);
    _mav_put_float_array(buf, 28, acc_matrix, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TK_IMU_INFORMATION, buf, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
#else
    mavlink_tk_imu_information_t packet;
    packet.temperature = temperature;
    packet.flag = flag;
    mav_array_memcpy(packet.gyro_offset, gyro_offset, sizeof(float)*3);
    mav_array_memcpy(packet.accel_offset, accel_offset, sizeof(float)*3);
    mav_array_memcpy(packet.acc_matrix, acc_matrix, sizeof(float)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TK_IMU_INFORMATION, (const char *)&packet, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
#endif
}

/**
 * @brief Send a tk_imu_information message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_tk_imu_information_send_struct(mavlink_channel_t chan, const mavlink_tk_imu_information_t* tk_imu_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_tk_imu_information_send(chan, tk_imu_information->temperature, tk_imu_information->gyro_offset, tk_imu_information->accel_offset, tk_imu_information->acc_matrix, tk_imu_information->flag);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TK_IMU_INFORMATION, (const char *)tk_imu_information, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_tk_imu_information_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float temperature, const float *gyro_offset, const float *accel_offset, const float *acc_matrix, uint8_t flag)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, temperature);
    _mav_put_uint8_t(buf, 64, flag);
    _mav_put_float_array(buf, 4, gyro_offset, 3);
    _mav_put_float_array(buf, 16, accel_offset, 3);
    _mav_put_float_array(buf, 28, acc_matrix, 9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TK_IMU_INFORMATION, buf, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
#else
    mavlink_tk_imu_information_t *packet = (mavlink_tk_imu_information_t *)msgbuf;
    packet->temperature = temperature;
    packet->flag = flag;
    mav_array_memcpy(packet->gyro_offset, gyro_offset, sizeof(float)*3);
    mav_array_memcpy(packet->accel_offset, accel_offset, sizeof(float)*3);
    mav_array_memcpy(packet->acc_matrix, acc_matrix, sizeof(float)*9);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TK_IMU_INFORMATION, (const char *)packet, MAVLINK_MSG_ID_TK_IMU_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN, MAVLINK_MSG_ID_TK_IMU_INFORMATION_CRC);
#endif
}
#endif

#endif

// MESSAGE TK_IMU_INFORMATION UNPACKING


/**
 * @brief Get field temperature from tk_imu_information message
 *
 * @return  Temperature of the gimbal imu, unit: 1°C/LSB.
 */
static inline float mavlink_msg_tk_imu_information_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field gyro_offset from tk_imu_information message
 *
 * @return  Angular velocity error.
 */
static inline uint16_t mavlink_msg_tk_imu_information_get_gyro_offset(const mavlink_message_t* msg, float *gyro_offset)
{
    return _MAV_RETURN_float_array(msg, gyro_offset, 3,  4);
}

/**
 * @brief Get field accel_offset from tk_imu_information message
 *
 * @return  acceleration error.
 */
static inline uint16_t mavlink_msg_tk_imu_information_get_accel_offset(const mavlink_message_t* msg, float *accel_offset)
{
    return _MAV_RETURN_float_array(msg, accel_offset, 3,  16);
}

/**
 * @brief Get field acc_matrix from tk_imu_information message
 *
 * @return  .
 */
static inline uint16_t mavlink_msg_tk_imu_information_get_acc_matrix(const mavlink_message_t* msg, float *acc_matrix)
{
    return _MAV_RETURN_float_array(msg, acc_matrix, 9,  28);
}

/**
 * @brief Get field flag from tk_imu_information message
 *
 * @return  Calibration completion flag.
 */
static inline uint8_t mavlink_msg_tk_imu_information_get_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  64);
}

/**
 * @brief Decode a tk_imu_information message into a struct
 *
 * @param msg The message to decode
 * @param tk_imu_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_tk_imu_information_decode(const mavlink_message_t* msg, mavlink_tk_imu_information_t* tk_imu_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    tk_imu_information->temperature = mavlink_msg_tk_imu_information_get_temperature(msg);
    mavlink_msg_tk_imu_information_get_gyro_offset(msg, tk_imu_information->gyro_offset);
    mavlink_msg_tk_imu_information_get_accel_offset(msg, tk_imu_information->accel_offset);
    mavlink_msg_tk_imu_information_get_acc_matrix(msg, tk_imu_information->acc_matrix);
    tk_imu_information->flag = mavlink_msg_tk_imu_information_get_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN? msg->len : MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN;
        memset(tk_imu_information, 0, MAVLINK_MSG_ID_TK_IMU_INFORMATION_LEN);
    memcpy(tk_imu_information, _MAV_PAYLOAD(msg), len);
#endif
}
