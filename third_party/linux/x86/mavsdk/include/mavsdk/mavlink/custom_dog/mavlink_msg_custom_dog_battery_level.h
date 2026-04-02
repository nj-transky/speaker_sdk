#pragma once
// MESSAGE CUSTOM_DOG_BATTERY_LEVEL PACKING

#define MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL 51853


typedef struct __mavlink_custom_dog_battery_level_t {
 uint32_t battery_level; /*<  Current battery level*/
} mavlink_custom_dog_battery_level_t;

#define MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN 4
#define MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN 4
#define MAVLINK_MSG_ID_51853_LEN 4
#define MAVLINK_MSG_ID_51853_MIN_LEN 4

#define MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC 129
#define MAVLINK_MSG_ID_51853_CRC 129



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_BATTERY_LEVEL { \
    51853, \
    "CUSTOM_DOG_BATTERY_LEVEL", \
    1, \
    {  { "battery_level", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_custom_dog_battery_level_t, battery_level) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_BATTERY_LEVEL { \
    "CUSTOM_DOG_BATTERY_LEVEL", \
    1, \
    {  { "battery_level", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_custom_dog_battery_level_t, battery_level) }, \
         } \
}
#endif

/**
 * @brief Pack a custom_dog_battery_level message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param battery_level  Current battery level
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_battery_level_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t battery_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN];
    _mav_put_uint32_t(buf, 0, battery_level);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
#else
    mavlink_custom_dog_battery_level_t packet;
    packet.battery_level = battery_level;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
}

/**
 * @brief Pack a custom_dog_battery_level message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param battery_level  Current battery level
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_battery_level_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t battery_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN];
    _mav_put_uint32_t(buf, 0, battery_level);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
#else
    mavlink_custom_dog_battery_level_t packet;
    packet.battery_level = battery_level;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
#endif
}

/**
 * @brief Pack a custom_dog_battery_level message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param battery_level  Current battery level
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_battery_level_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t battery_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN];
    _mav_put_uint32_t(buf, 0, battery_level);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
#else
    mavlink_custom_dog_battery_level_t packet;
    packet.battery_level = battery_level;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
}

/**
 * @brief Encode a custom_dog_battery_level struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_battery_level C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_battery_level_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_custom_dog_battery_level_t* custom_dog_battery_level)
{
    return mavlink_msg_custom_dog_battery_level_pack(system_id, component_id, msg, custom_dog_battery_level->battery_level);
}

/**
 * @brief Encode a custom_dog_battery_level struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_battery_level C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_battery_level_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_custom_dog_battery_level_t* custom_dog_battery_level)
{
    return mavlink_msg_custom_dog_battery_level_pack_chan(system_id, component_id, chan, msg, custom_dog_battery_level->battery_level);
}

/**
 * @brief Encode a custom_dog_battery_level struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_battery_level C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_battery_level_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_custom_dog_battery_level_t* custom_dog_battery_level)
{
    return mavlink_msg_custom_dog_battery_level_pack_status(system_id, component_id, _status, msg,  custom_dog_battery_level->battery_level);
}

/**
 * @brief Send a custom_dog_battery_level message
 * @param chan MAVLink channel to send the message
 *
 * @param battery_level  Current battery level
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_custom_dog_battery_level_send(mavlink_channel_t chan, uint32_t battery_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN];
    _mav_put_uint32_t(buf, 0, battery_level);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL, buf, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
#else
    mavlink_custom_dog_battery_level_t packet;
    packet.battery_level = battery_level;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL, (const char *)&packet, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
#endif
}

/**
 * @brief Send a custom_dog_battery_level message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_custom_dog_battery_level_send_struct(mavlink_channel_t chan, const mavlink_custom_dog_battery_level_t* custom_dog_battery_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_custom_dog_battery_level_send(chan, custom_dog_battery_level->battery_level);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL, (const char *)custom_dog_battery_level, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
#endif
}

#if MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_custom_dog_battery_level_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t battery_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, battery_level);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL, buf, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
#else
    mavlink_custom_dog_battery_level_t *packet = (mavlink_custom_dog_battery_level_t *)msgbuf;
    packet->battery_level = battery_level;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL, (const char *)packet, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_CRC);
#endif
}
#endif

#endif

// MESSAGE CUSTOM_DOG_BATTERY_LEVEL UNPACKING


/**
 * @brief Get field battery_level from custom_dog_battery_level message
 *
 * @return  Current battery level
 */
static inline uint32_t mavlink_msg_custom_dog_battery_level_get_battery_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a custom_dog_battery_level message into a struct
 *
 * @param msg The message to decode
 * @param custom_dog_battery_level C-struct to decode the message contents into
 */
static inline void mavlink_msg_custom_dog_battery_level_decode(const mavlink_message_t* msg, mavlink_custom_dog_battery_level_t* custom_dog_battery_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    custom_dog_battery_level->battery_level = mavlink_msg_custom_dog_battery_level_get_battery_level(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN? msg->len : MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN;
        memset(custom_dog_battery_level, 0, MAVLINK_MSG_ID_CUSTOM_DOG_BATTERY_LEVEL_LEN);
    memcpy(custom_dog_battery_level, _MAV_PAYLOAD(msg), len);
#endif
}
