#pragma once
// MESSAGE SPEAKER_AUDIO_INFO_REQUEST PACKING

#define MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST 20003


typedef struct __mavlink_speaker_audio_info_request_t {
 int32_t reserved; /*<  Reserved.*/
 char audio_name[64]; /*<  The name of audio file.*/
} mavlink_speaker_audio_info_request_t;

#define MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN 68
#define MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN 68
#define MAVLINK_MSG_ID_20003_LEN 68
#define MAVLINK_MSG_ID_20003_MIN_LEN 68

#define MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC 195
#define MAVLINK_MSG_ID_20003_CRC 195

#define MAVLINK_MSG_SPEAKER_AUDIO_INFO_REQUEST_FIELD_AUDIO_NAME_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SPEAKER_AUDIO_INFO_REQUEST { \
    20003, \
    "SPEAKER_AUDIO_INFO_REQUEST", \
    2, \
    {  { "audio_name", NULL, MAVLINK_TYPE_CHAR, 64, 4, offsetof(mavlink_speaker_audio_info_request_t, audio_name) }, \
         { "reserved", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_speaker_audio_info_request_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SPEAKER_AUDIO_INFO_REQUEST { \
    "SPEAKER_AUDIO_INFO_REQUEST", \
    2, \
    {  { "audio_name", NULL, MAVLINK_TYPE_CHAR, 64, 4, offsetof(mavlink_speaker_audio_info_request_t, audio_name) }, \
         { "reserved", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_speaker_audio_info_request_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a speaker_audio_info_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param audio_name  The name of audio file.
 * @param reserved  Reserved.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_speaker_audio_info_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *audio_name, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, audio_name, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
#else
    mavlink_speaker_audio_info_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.audio_name, audio_name, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
}

/**
 * @brief Pack a speaker_audio_info_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param audio_name  The name of audio file.
 * @param reserved  Reserved.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_speaker_audio_info_request_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const char *audio_name, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, audio_name, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
#else
    mavlink_speaker_audio_info_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.audio_name, audio_name, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a speaker_audio_info_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param audio_name  The name of audio file.
 * @param reserved  Reserved.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_speaker_audio_info_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *audio_name,int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, audio_name, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
#else
    mavlink_speaker_audio_info_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.audio_name, audio_name, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
}

/**
 * @brief Encode a speaker_audio_info_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param speaker_audio_info_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_speaker_audio_info_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_speaker_audio_info_request_t* speaker_audio_info_request)
{
    return mavlink_msg_speaker_audio_info_request_pack(system_id, component_id, msg, speaker_audio_info_request->audio_name, speaker_audio_info_request->reserved);
}

/**
 * @brief Encode a speaker_audio_info_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param speaker_audio_info_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_speaker_audio_info_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_speaker_audio_info_request_t* speaker_audio_info_request)
{
    return mavlink_msg_speaker_audio_info_request_pack_chan(system_id, component_id, chan, msg, speaker_audio_info_request->audio_name, speaker_audio_info_request->reserved);
}

/**
 * @brief Encode a speaker_audio_info_request struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param speaker_audio_info_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_speaker_audio_info_request_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_speaker_audio_info_request_t* speaker_audio_info_request)
{
    return mavlink_msg_speaker_audio_info_request_pack_status(system_id, component_id, _status, msg,  speaker_audio_info_request->audio_name, speaker_audio_info_request->reserved);
}

/**
 * @brief Send a speaker_audio_info_request message
 * @param chan MAVLink channel to send the message
 *
 * @param audio_name  The name of audio file.
 * @param reserved  Reserved.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_speaker_audio_info_request_send(mavlink_channel_t chan, const char *audio_name, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN];
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, audio_name, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST, buf, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
#else
    mavlink_speaker_audio_info_request_t packet;
    packet.reserved = reserved;
    mav_array_memcpy(packet.audio_name, audio_name, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
#endif
}

/**
 * @brief Send a speaker_audio_info_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_speaker_audio_info_request_send_struct(mavlink_channel_t chan, const mavlink_speaker_audio_info_request_t* speaker_audio_info_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_speaker_audio_info_request_send(chan, speaker_audio_info_request->audio_name, speaker_audio_info_request->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST, (const char *)speaker_audio_info_request, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_speaker_audio_info_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *audio_name, int32_t reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, reserved);
    _mav_put_char_array(buf, 4, audio_name, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST, buf, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
#else
    mavlink_speaker_audio_info_request_t *packet = (mavlink_speaker_audio_info_request_t *)msgbuf;
    packet->reserved = reserved;
    mav_array_memcpy(packet->audio_name, audio_name, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST, (const char *)packet, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE SPEAKER_AUDIO_INFO_REQUEST UNPACKING


/**
 * @brief Get field audio_name from speaker_audio_info_request message
 *
 * @return  The name of audio file.
 */
static inline uint16_t mavlink_msg_speaker_audio_info_request_get_audio_name(const mavlink_message_t* msg, char *audio_name)
{
    return _MAV_RETURN_char_array(msg, audio_name, 64,  4);
}

/**
 * @brief Get field reserved from speaker_audio_info_request message
 *
 * @return  Reserved.
 */
static inline int32_t mavlink_msg_speaker_audio_info_request_get_reserved(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a speaker_audio_info_request message into a struct
 *
 * @param msg The message to decode
 * @param speaker_audio_info_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_speaker_audio_info_request_decode(const mavlink_message_t* msg, mavlink_speaker_audio_info_request_t* speaker_audio_info_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    speaker_audio_info_request->reserved = mavlink_msg_speaker_audio_info_request_get_reserved(msg);
    mavlink_msg_speaker_audio_info_request_get_audio_name(msg, speaker_audio_info_request->audio_name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN;
        memset(speaker_audio_info_request, 0, MAVLINK_MSG_ID_SPEAKER_AUDIO_INFO_REQUEST_LEN);
    memcpy(speaker_audio_info_request, _MAV_PAYLOAD(msg), len);
#endif
}
