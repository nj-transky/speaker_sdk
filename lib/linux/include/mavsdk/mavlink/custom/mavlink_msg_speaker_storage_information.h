#pragma once
// MESSAGE SPEAKER_STORAGE_INFORMATION PACKING

#define MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION 20002


typedef struct __mavlink_speaker_storage_information_t {
 float total_storage; /*< [MiB] Total storage (in MiB).*/
 float used_storage; /*< [MiB] Used storage (in MiB).*/
 float available_storage; /*< [MiB] Available storage (in MiB).*/
 uint8_t storage_status; /*<  Status of storage.*/
 uint8_t storage_type; /*<  Storage type.*/
} mavlink_speaker_storage_information_t;

#define MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN 14
#define MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN 14
#define MAVLINK_MSG_ID_20002_LEN 14
#define MAVLINK_MSG_ID_20002_MIN_LEN 14

#define MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC 119
#define MAVLINK_MSG_ID_20002_CRC 119



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SPEAKER_STORAGE_INFORMATION { \
    20002, \
    "SPEAKER_STORAGE_INFORMATION", \
    5, \
    {  { "storage_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_speaker_storage_information_t, storage_status) }, \
         { "storage_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_speaker_storage_information_t, storage_type) }, \
         { "total_storage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_speaker_storage_information_t, total_storage) }, \
         { "used_storage", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_speaker_storage_information_t, used_storage) }, \
         { "available_storage", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_speaker_storage_information_t, available_storage) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SPEAKER_STORAGE_INFORMATION { \
    "SPEAKER_STORAGE_INFORMATION", \
    5, \
    {  { "storage_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_speaker_storage_information_t, storage_status) }, \
         { "storage_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_speaker_storage_information_t, storage_type) }, \
         { "total_storage", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_speaker_storage_information_t, total_storage) }, \
         { "used_storage", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_speaker_storage_information_t, used_storage) }, \
         { "available_storage", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_speaker_storage_information_t, available_storage) }, \
         } \
}
#endif

/**
 * @brief Pack a speaker_storage_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param storage_status  Status of storage.
 * @param storage_type  Storage type.
 * @param total_storage [MiB] Total storage (in MiB).
 * @param used_storage [MiB] Used storage (in MiB).
 * @param available_storage [MiB] Available storage (in MiB).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_speaker_storage_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t storage_status, uint8_t storage_type, float total_storage, float used_storage, float available_storage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN];
    _mav_put_float(buf, 0, total_storage);
    _mav_put_float(buf, 4, used_storage);
    _mav_put_float(buf, 8, available_storage);
    _mav_put_uint8_t(buf, 12, storage_status);
    _mav_put_uint8_t(buf, 13, storage_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
#else
    mavlink_speaker_storage_information_t packet;
    packet.total_storage = total_storage;
    packet.used_storage = used_storage;
    packet.available_storage = available_storage;
    packet.storage_status = storage_status;
    packet.storage_type = storage_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
}

/**
 * @brief Pack a speaker_storage_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param storage_status  Status of storage.
 * @param storage_type  Storage type.
 * @param total_storage [MiB] Total storage (in MiB).
 * @param used_storage [MiB] Used storage (in MiB).
 * @param available_storage [MiB] Available storage (in MiB).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_speaker_storage_information_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t storage_status, uint8_t storage_type, float total_storage, float used_storage, float available_storage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN];
    _mav_put_float(buf, 0, total_storage);
    _mav_put_float(buf, 4, used_storage);
    _mav_put_float(buf, 8, available_storage);
    _mav_put_uint8_t(buf, 12, storage_status);
    _mav_put_uint8_t(buf, 13, storage_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
#else
    mavlink_speaker_storage_information_t packet;
    packet.total_storage = total_storage;
    packet.used_storage = used_storage;
    packet.available_storage = available_storage;
    packet.storage_status = storage_status;
    packet.storage_type = storage_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
#endif
}

/**
 * @brief Pack a speaker_storage_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param storage_status  Status of storage.
 * @param storage_type  Storage type.
 * @param total_storage [MiB] Total storage (in MiB).
 * @param used_storage [MiB] Used storage (in MiB).
 * @param available_storage [MiB] Available storage (in MiB).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_speaker_storage_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t storage_status,uint8_t storage_type,float total_storage,float used_storage,float available_storage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN];
    _mav_put_float(buf, 0, total_storage);
    _mav_put_float(buf, 4, used_storage);
    _mav_put_float(buf, 8, available_storage);
    _mav_put_uint8_t(buf, 12, storage_status);
    _mav_put_uint8_t(buf, 13, storage_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
#else
    mavlink_speaker_storage_information_t packet;
    packet.total_storage = total_storage;
    packet.used_storage = used_storage;
    packet.available_storage = available_storage;
    packet.storage_status = storage_status;
    packet.storage_type = storage_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
}

/**
 * @brief Encode a speaker_storage_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param speaker_storage_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_speaker_storage_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_speaker_storage_information_t* speaker_storage_information)
{
    return mavlink_msg_speaker_storage_information_pack(system_id, component_id, msg, speaker_storage_information->storage_status, speaker_storage_information->storage_type, speaker_storage_information->total_storage, speaker_storage_information->used_storage, speaker_storage_information->available_storage);
}

/**
 * @brief Encode a speaker_storage_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param speaker_storage_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_speaker_storage_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_speaker_storage_information_t* speaker_storage_information)
{
    return mavlink_msg_speaker_storage_information_pack_chan(system_id, component_id, chan, msg, speaker_storage_information->storage_status, speaker_storage_information->storage_type, speaker_storage_information->total_storage, speaker_storage_information->used_storage, speaker_storage_information->available_storage);
}

/**
 * @brief Encode a speaker_storage_information struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param speaker_storage_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_speaker_storage_information_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_speaker_storage_information_t* speaker_storage_information)
{
    return mavlink_msg_speaker_storage_information_pack_status(system_id, component_id, _status, msg,  speaker_storage_information->storage_status, speaker_storage_information->storage_type, speaker_storage_information->total_storage, speaker_storage_information->used_storage, speaker_storage_information->available_storage);
}

/**
 * @brief Send a speaker_storage_information message
 * @param chan MAVLink channel to send the message
 *
 * @param storage_status  Status of storage.
 * @param storage_type  Storage type.
 * @param total_storage [MiB] Total storage (in MiB).
 * @param used_storage [MiB] Used storage (in MiB).
 * @param available_storage [MiB] Available storage (in MiB).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_speaker_storage_information_send(mavlink_channel_t chan, uint8_t storage_status, uint8_t storage_type, float total_storage, float used_storage, float available_storage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN];
    _mav_put_float(buf, 0, total_storage);
    _mav_put_float(buf, 4, used_storage);
    _mav_put_float(buf, 8, available_storage);
    _mav_put_uint8_t(buf, 12, storage_status);
    _mav_put_uint8_t(buf, 13, storage_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION, buf, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
#else
    mavlink_speaker_storage_information_t packet;
    packet.total_storage = total_storage;
    packet.used_storage = used_storage;
    packet.available_storage = available_storage;
    packet.storage_status = storage_status;
    packet.storage_type = storage_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION, (const char *)&packet, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
#endif
}

/**
 * @brief Send a speaker_storage_information message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_speaker_storage_information_send_struct(mavlink_channel_t chan, const mavlink_speaker_storage_information_t* speaker_storage_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_speaker_storage_information_send(chan, speaker_storage_information->storage_status, speaker_storage_information->storage_type, speaker_storage_information->total_storage, speaker_storage_information->used_storage, speaker_storage_information->available_storage);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION, (const char *)speaker_storage_information, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_speaker_storage_information_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t storage_status, uint8_t storage_type, float total_storage, float used_storage, float available_storage)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, total_storage);
    _mav_put_float(buf, 4, used_storage);
    _mav_put_float(buf, 8, available_storage);
    _mav_put_uint8_t(buf, 12, storage_status);
    _mav_put_uint8_t(buf, 13, storage_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION, buf, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
#else
    mavlink_speaker_storage_information_t *packet = (mavlink_speaker_storage_information_t *)msgbuf;
    packet->total_storage = total_storage;
    packet->used_storage = used_storage;
    packet->available_storage = available_storage;
    packet->storage_status = storage_status;
    packet->storage_type = storage_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION, (const char *)packet, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_CRC);
#endif
}
#endif

#endif

// MESSAGE SPEAKER_STORAGE_INFORMATION UNPACKING


/**
 * @brief Get field storage_status from speaker_storage_information message
 *
 * @return  Status of storage.
 */
static inline uint8_t mavlink_msg_speaker_storage_information_get_storage_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field storage_type from speaker_storage_information message
 *
 * @return  Storage type.
 */
static inline uint8_t mavlink_msg_speaker_storage_information_get_storage_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field total_storage from speaker_storage_information message
 *
 * @return [MiB] Total storage (in MiB).
 */
static inline float mavlink_msg_speaker_storage_information_get_total_storage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field used_storage from speaker_storage_information message
 *
 * @return [MiB] Used storage (in MiB).
 */
static inline float mavlink_msg_speaker_storage_information_get_used_storage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field available_storage from speaker_storage_information message
 *
 * @return [MiB] Available storage (in MiB).
 */
static inline float mavlink_msg_speaker_storage_information_get_available_storage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a speaker_storage_information message into a struct
 *
 * @param msg The message to decode
 * @param speaker_storage_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_speaker_storage_information_decode(const mavlink_message_t* msg, mavlink_speaker_storage_information_t* speaker_storage_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    speaker_storage_information->total_storage = mavlink_msg_speaker_storage_information_get_total_storage(msg);
    speaker_storage_information->used_storage = mavlink_msg_speaker_storage_information_get_used_storage(msg);
    speaker_storage_information->available_storage = mavlink_msg_speaker_storage_information_get_available_storage(msg);
    speaker_storage_information->storage_status = mavlink_msg_speaker_storage_information_get_storage_status(msg);
    speaker_storage_information->storage_type = mavlink_msg_speaker_storage_information_get_storage_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN? msg->len : MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN;
        memset(speaker_storage_information, 0, MAVLINK_MSG_ID_SPEAKER_STORAGE_INFORMATION_LEN);
    memcpy(speaker_storage_information, _MAV_PAYLOAD(msg), len);
#endif
}
