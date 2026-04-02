#pragma once
// MESSAGE CUSTOM_DOG_JOY_DATA PACKING

#define MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA 51850


typedef struct __mavlink_custom_dog_joy_data_t {
 float lx; /*<  Left joystick x-axis value.*/
 float ly; /*<  Left joystick y-axis value.*/
 float rx; /*<  Right joystick x-axis value.*/
 float ry; /*<  Right joystick y-axis value.*/
} mavlink_custom_dog_joy_data_t;

#define MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN 16
#define MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN 16
#define MAVLINK_MSG_ID_51850_LEN 16
#define MAVLINK_MSG_ID_51850_MIN_LEN 16

#define MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC 101
#define MAVLINK_MSG_ID_51850_CRC 101



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_JOY_DATA { \
    51850, \
    "CUSTOM_DOG_JOY_DATA", \
    4, \
    {  { "lx", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_custom_dog_joy_data_t, lx) }, \
         { "ly", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_custom_dog_joy_data_t, ly) }, \
         { "rx", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_custom_dog_joy_data_t, rx) }, \
         { "ry", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_custom_dog_joy_data_t, ry) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_JOY_DATA { \
    "CUSTOM_DOG_JOY_DATA", \
    4, \
    {  { "lx", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_custom_dog_joy_data_t, lx) }, \
         { "ly", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_custom_dog_joy_data_t, ly) }, \
         { "rx", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_custom_dog_joy_data_t, rx) }, \
         { "ry", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_custom_dog_joy_data_t, ry) }, \
         } \
}
#endif

/**
 * @brief Pack a custom_dog_joy_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lx  Left joystick x-axis value.
 * @param ly  Left joystick y-axis value.
 * @param rx  Right joystick x-axis value.
 * @param ry  Right joystick y-axis value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_joy_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float lx, float ly, float rx, float ry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN];
    _mav_put_float(buf, 0, lx);
    _mav_put_float(buf, 4, ly);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
#else
    mavlink_custom_dog_joy_data_t packet;
    packet.lx = lx;
    packet.ly = ly;
    packet.rx = rx;
    packet.ry = ry;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
}

/**
 * @brief Pack a custom_dog_joy_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param lx  Left joystick x-axis value.
 * @param ly  Left joystick y-axis value.
 * @param rx  Right joystick x-axis value.
 * @param ry  Right joystick y-axis value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_joy_data_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float lx, float ly, float rx, float ry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN];
    _mav_put_float(buf, 0, lx);
    _mav_put_float(buf, 4, ly);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
#else
    mavlink_custom_dog_joy_data_t packet;
    packet.lx = lx;
    packet.ly = ly;
    packet.rx = rx;
    packet.ry = ry;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
#endif
}

/**
 * @brief Pack a custom_dog_joy_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lx  Left joystick x-axis value.
 * @param ly  Left joystick y-axis value.
 * @param rx  Right joystick x-axis value.
 * @param ry  Right joystick y-axis value.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_joy_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float lx,float ly,float rx,float ry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN];
    _mav_put_float(buf, 0, lx);
    _mav_put_float(buf, 4, ly);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
#else
    mavlink_custom_dog_joy_data_t packet;
    packet.lx = lx;
    packet.ly = ly;
    packet.rx = rx;
    packet.ry = ry;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
}

/**
 * @brief Encode a custom_dog_joy_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_joy_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_joy_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_custom_dog_joy_data_t* custom_dog_joy_data)
{
    return mavlink_msg_custom_dog_joy_data_pack(system_id, component_id, msg, custom_dog_joy_data->lx, custom_dog_joy_data->ly, custom_dog_joy_data->rx, custom_dog_joy_data->ry);
}

/**
 * @brief Encode a custom_dog_joy_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_joy_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_joy_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_custom_dog_joy_data_t* custom_dog_joy_data)
{
    return mavlink_msg_custom_dog_joy_data_pack_chan(system_id, component_id, chan, msg, custom_dog_joy_data->lx, custom_dog_joy_data->ly, custom_dog_joy_data->rx, custom_dog_joy_data->ry);
}

/**
 * @brief Encode a custom_dog_joy_data struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_joy_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_joy_data_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_custom_dog_joy_data_t* custom_dog_joy_data)
{
    return mavlink_msg_custom_dog_joy_data_pack_status(system_id, component_id, _status, msg,  custom_dog_joy_data->lx, custom_dog_joy_data->ly, custom_dog_joy_data->rx, custom_dog_joy_data->ry);
}

/**
 * @brief Send a custom_dog_joy_data message
 * @param chan MAVLink channel to send the message
 *
 * @param lx  Left joystick x-axis value.
 * @param ly  Left joystick y-axis value.
 * @param rx  Right joystick x-axis value.
 * @param ry  Right joystick y-axis value.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_custom_dog_joy_data_send(mavlink_channel_t chan, float lx, float ly, float rx, float ry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN];
    _mav_put_float(buf, 0, lx);
    _mav_put_float(buf, 4, ly);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA, buf, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
#else
    mavlink_custom_dog_joy_data_t packet;
    packet.lx = lx;
    packet.ly = ly;
    packet.rx = rx;
    packet.ry = ry;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA, (const char *)&packet, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
#endif
}

/**
 * @brief Send a custom_dog_joy_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_custom_dog_joy_data_send_struct(mavlink_channel_t chan, const mavlink_custom_dog_joy_data_t* custom_dog_joy_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_custom_dog_joy_data_send(chan, custom_dog_joy_data->lx, custom_dog_joy_data->ly, custom_dog_joy_data->rx, custom_dog_joy_data->ry);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA, (const char *)custom_dog_joy_data, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_custom_dog_joy_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float lx, float ly, float rx, float ry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, lx);
    _mav_put_float(buf, 4, ly);
    _mav_put_float(buf, 8, rx);
    _mav_put_float(buf, 12, ry);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA, buf, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
#else
    mavlink_custom_dog_joy_data_t *packet = (mavlink_custom_dog_joy_data_t *)msgbuf;
    packet->lx = lx;
    packet->ly = ly;
    packet->rx = rx;
    packet->ry = ry;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA, (const char *)packet, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE CUSTOM_DOG_JOY_DATA UNPACKING


/**
 * @brief Get field lx from custom_dog_joy_data message
 *
 * @return  Left joystick x-axis value.
 */
static inline float mavlink_msg_custom_dog_joy_data_get_lx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field ly from custom_dog_joy_data message
 *
 * @return  Left joystick y-axis value.
 */
static inline float mavlink_msg_custom_dog_joy_data_get_ly(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field rx from custom_dog_joy_data message
 *
 * @return  Right joystick x-axis value.
 */
static inline float mavlink_msg_custom_dog_joy_data_get_rx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field ry from custom_dog_joy_data message
 *
 * @return  Right joystick y-axis value.
 */
static inline float mavlink_msg_custom_dog_joy_data_get_ry(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a custom_dog_joy_data message into a struct
 *
 * @param msg The message to decode
 * @param custom_dog_joy_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_custom_dog_joy_data_decode(const mavlink_message_t* msg, mavlink_custom_dog_joy_data_t* custom_dog_joy_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    custom_dog_joy_data->lx = mavlink_msg_custom_dog_joy_data_get_lx(msg);
    custom_dog_joy_data->ly = mavlink_msg_custom_dog_joy_data_get_ly(msg);
    custom_dog_joy_data->rx = mavlink_msg_custom_dog_joy_data_get_rx(msg);
    custom_dog_joy_data->ry = mavlink_msg_custom_dog_joy_data_get_ry(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN? msg->len : MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN;
        memset(custom_dog_joy_data, 0, MAVLINK_MSG_ID_CUSTOM_DOG_JOY_DATA_LEN);
    memcpy(custom_dog_joy_data, _MAV_PAYLOAD(msg), len);
#endif
}
