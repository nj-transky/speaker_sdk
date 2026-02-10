#pragma once
// MESSAGE ENTER_DEV_MODE PACKING

#define MAVLINK_MSG_ID_ENTER_DEV_MODE 20022


typedef struct __mavlink_enter_dev_mode_t {
 char password[32]; /*<  password to developer mode.*/
} mavlink_enter_dev_mode_t;

#define MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN 32
#define MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN 32
#define MAVLINK_MSG_ID_20022_LEN 32
#define MAVLINK_MSG_ID_20022_MIN_LEN 32

#define MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC 68
#define MAVLINK_MSG_ID_20022_CRC 68

#define MAVLINK_MSG_ENTER_DEV_MODE_FIELD_PASSWORD_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ENTER_DEV_MODE { \
    20022, \
    "ENTER_DEV_MODE", \
    1, \
    {  { "password", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_enter_dev_mode_t, password) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ENTER_DEV_MODE { \
    "ENTER_DEV_MODE", \
    1, \
    {  { "password", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_enter_dev_mode_t, password) }, \
         } \
}
#endif

/**
 * @brief Pack a enter_dev_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param password  password to developer mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_enter_dev_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN];

    _mav_put_char_array(buf, 0, password, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
#else
    mavlink_enter_dev_mode_t packet;

    mav_array_memcpy(packet.password, password, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENTER_DEV_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
}

/**
 * @brief Pack a enter_dev_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param password  password to developer mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_enter_dev_mode_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN];

    _mav_put_char_array(buf, 0, password, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
#else
    mavlink_enter_dev_mode_t packet;

    mav_array_memcpy(packet.password, password, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENTER_DEV_MODE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
#endif
}

/**
 * @brief Pack a enter_dev_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param password  password to developer mode.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_enter_dev_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN];

    _mav_put_char_array(buf, 0, password, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
#else
    mavlink_enter_dev_mode_t packet;

    mav_array_memcpy(packet.password, password, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENTER_DEV_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
}

/**
 * @brief Encode a enter_dev_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param enter_dev_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_enter_dev_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_enter_dev_mode_t* enter_dev_mode)
{
    return mavlink_msg_enter_dev_mode_pack(system_id, component_id, msg, enter_dev_mode->password);
}

/**
 * @brief Encode a enter_dev_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param enter_dev_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_enter_dev_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_enter_dev_mode_t* enter_dev_mode)
{
    return mavlink_msg_enter_dev_mode_pack_chan(system_id, component_id, chan, msg, enter_dev_mode->password);
}

/**
 * @brief Encode a enter_dev_mode struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param enter_dev_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_enter_dev_mode_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_enter_dev_mode_t* enter_dev_mode)
{
    return mavlink_msg_enter_dev_mode_pack_status(system_id, component_id, _status, msg,  enter_dev_mode->password);
}

/**
 * @brief Send a enter_dev_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param password  password to developer mode.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_enter_dev_mode_send(mavlink_channel_t chan, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN];

    _mav_put_char_array(buf, 0, password, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENTER_DEV_MODE, buf, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
#else
    mavlink_enter_dev_mode_t packet;

    mav_array_memcpy(packet.password, password, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENTER_DEV_MODE, (const char *)&packet, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
#endif
}

/**
 * @brief Send a enter_dev_mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_enter_dev_mode_send_struct(mavlink_channel_t chan, const mavlink_enter_dev_mode_t* enter_dev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_enter_dev_mode_send(chan, enter_dev_mode->password);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENTER_DEV_MODE, (const char *)enter_dev_mode, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_enter_dev_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_char_array(buf, 0, password, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENTER_DEV_MODE, buf, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
#else
    mavlink_enter_dev_mode_t *packet = (mavlink_enter_dev_mode_t *)msgbuf;

    mav_array_memcpy(packet->password, password, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENTER_DEV_MODE, (const char *)packet, MAVLINK_MSG_ID_ENTER_DEV_MODE_MIN_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN, MAVLINK_MSG_ID_ENTER_DEV_MODE_CRC);
#endif
}
#endif

#endif

// MESSAGE ENTER_DEV_MODE UNPACKING


/**
 * @brief Get field password from enter_dev_mode message
 *
 * @return  password to developer mode.
 */
static inline uint16_t mavlink_msg_enter_dev_mode_get_password(const mavlink_message_t* msg, char *password)
{
    return _MAV_RETURN_char_array(msg, password, 32,  0);
}

/**
 * @brief Decode a enter_dev_mode message into a struct
 *
 * @param msg The message to decode
 * @param enter_dev_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_enter_dev_mode_decode(const mavlink_message_t* msg, mavlink_enter_dev_mode_t* enter_dev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_enter_dev_mode_get_password(msg, enter_dev_mode->password);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN? msg->len : MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN;
        memset(enter_dev_mode, 0, MAVLINK_MSG_ID_ENTER_DEV_MODE_LEN);
    memcpy(enter_dev_mode, _MAV_PAYLOAD(msg), len);
#endif
}
