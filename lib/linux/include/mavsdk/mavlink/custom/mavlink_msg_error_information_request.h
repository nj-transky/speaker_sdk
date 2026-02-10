#pragma once
// MESSAGE ERROR_INFORMATION_REQUEST PACKING

#define MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST 20001


typedef struct __mavlink_error_information_request_t {
 int32_t reserved; /*<  Reserved.*/
 char text[100]; /*<  error status text.*/
} mavlink_error_information_request_t;

#define MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN 104
#define MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN 104
#define MAVLINK_MSG_ID_20001_LEN 104
#define MAVLINK_MSG_ID_20001_MIN_LEN 104

#define MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC 105
#define MAVLINK_MSG_ID_20001_CRC 105

#define MAVLINK_MSG_ERROR_INFORMATION_REQUEST_FIELD_TEXT_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ERROR_INFORMATION_REQUEST { \
    20001, \
    "ERROR_INFORMATION_REQUEST", \
    2, \
    {  { "text", NULL, MAVLINK_TYPE_CHAR, 100, 4, offsetof(mavlink_error_information_request_t, text) }, \
         { "reserved", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_error_information_request_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ERROR_INFORMATION_REQUEST { \
    "ERROR_INFORMATION_REQUEST", \
    2, \
    {  { "text", NULL, MAVLINK_TYPE_CHAR, 100, 4, offsetof(mavlink_error_information_request_t, text) }, \
         { "reserved", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_error_information_request_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a error_information_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param text  error status text.
 * @param reserved  Reserved.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_error_information_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *text, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, text, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
#else
    mavlink_error_information_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.text, text, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
}

/**
 * @brief Pack a error_information_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param text  error status text.
 * @param reserved  Reserved.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_error_information_request_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const char *text, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, text, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
#else
    mavlink_error_information_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.text, text, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a error_information_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param text  error status text.
 * @param reserved  Reserved.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_error_information_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *text,int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, text, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
#else
    mavlink_error_information_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.text, text, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
}

/**
 * @brief Encode a error_information_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param error_information_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_error_information_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_error_information_request_t* error_information_request)
{
    return mavlink_msg_error_information_request_pack(system_id, component_id, msg, error_information_request->text, error_information_request->reserved);
}

/**
 * @brief Encode a error_information_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param error_information_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_error_information_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_error_information_request_t* error_information_request)
{
    return mavlink_msg_error_information_request_pack_chan(system_id, component_id, chan, msg, error_information_request->text, error_information_request->reserved);
}

/**
 * @brief Encode a error_information_request struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param error_information_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_error_information_request_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_error_information_request_t* error_information_request)
{
    return mavlink_msg_error_information_request_pack_status(system_id, component_id, _status, msg,  error_information_request->text, error_information_request->reserved);
}

/**
 * @brief Send a error_information_request message
 * @param chan MAVLink channel to send the message
 *
 * @param text  error status text.
 * @param reserved  Reserved.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_error_information_request_send(mavlink_channel_t chan, const char *text, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, text, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST, buf, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
#else
    mavlink_error_information_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.text, text, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
#endif
}

/**
 * @brief Send a error_information_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_error_information_request_send_struct(mavlink_channel_t chan, const mavlink_error_information_request_t* error_information_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_error_information_request_send(chan, error_information_request->text, error_information_request->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST, (const char *)error_information_request, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_error_information_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *text, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, text, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST, buf, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
#else
    mavlink_error_information_request_t *packet = (mavlink_error_information_request_t *)msgbuf;
    packet->reserved = reserved;
    mav_array_memcpy(packet->text, text, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST, (const char *)packet, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_MIN_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE ERROR_INFORMATION_REQUEST UNPACKING


/**
 * @brief Get field text from error_information_request message
 *
 * @return  error status text.
 */
static inline uint16_t mavlink_msg_error_information_request_get_text(const mavlink_message_t* msg, char *text)
{
    return _MAV_RETURN_char_array(msg, text, 100,  4);
}

/**
 * @brief Get field reserved from error_information_request message
 *
 * @return  Reserved.
 */
static inline int32_t mavlink_msg_error_information_request_get_reserved(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a error_information_request message into a struct
 *
 * @param msg The message to decode
 * @param error_information_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_error_information_request_decode(const mavlink_message_t* msg, mavlink_error_information_request_t* error_information_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    error_information_request->reserved = mavlink_msg_error_information_request_get_reserved(msg);
    mavlink_msg_error_information_request_get_text(msg, error_information_request->text);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN;
        memset(error_information_request, 0, MAVLINK_MSG_ID_ERROR_INFORMATION_REQUEST_LEN);
    memcpy(error_information_request, _MAV_PAYLOAD(msg), len);
#endif
}
