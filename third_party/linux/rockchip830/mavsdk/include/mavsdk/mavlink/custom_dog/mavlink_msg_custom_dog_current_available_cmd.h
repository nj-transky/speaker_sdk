#pragma once
// MESSAGE CUSTOM_DOG_CURRENT_AVAILABLE_CMD PACKING

#define MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD 51852


typedef struct __mavlink_custom_dog_current_available_cmd_t {
 uint32_t available_cmd_bitmask; /*<  Currently available commands (bitmask of CUSTOM_DOG_ALL_ABILITY).*/
} mavlink_custom_dog_current_available_cmd_t;

#define MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN 4
#define MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN 4
#define MAVLINK_MSG_ID_51852_LEN 4
#define MAVLINK_MSG_ID_51852_MIN_LEN 4

#define MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC 58
#define MAVLINK_MSG_ID_51852_CRC 58



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_CURRENT_AVAILABLE_CMD { \
    51852, \
    "CUSTOM_DOG_CURRENT_AVAILABLE_CMD", \
    1, \
    {  { "available_cmd_bitmask", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_custom_dog_current_available_cmd_t, available_cmd_bitmask) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_CURRENT_AVAILABLE_CMD { \
    "CUSTOM_DOG_CURRENT_AVAILABLE_CMD", \
    1, \
    {  { "available_cmd_bitmask", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_custom_dog_current_available_cmd_t, available_cmd_bitmask) }, \
         } \
}
#endif

/**
 * @brief Pack a custom_dog_current_available_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param available_cmd_bitmask  Currently available commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_current_available_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t available_cmd_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN];
    _mav_put_uint32_t(buf, 0, available_cmd_bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
#else
    mavlink_custom_dog_current_available_cmd_t packet;
    packet.available_cmd_bitmask = available_cmd_bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
}

/**
 * @brief Pack a custom_dog_current_available_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param available_cmd_bitmask  Currently available commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_current_available_cmd_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t available_cmd_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN];
    _mav_put_uint32_t(buf, 0, available_cmd_bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
#else
    mavlink_custom_dog_current_available_cmd_t packet;
    packet.available_cmd_bitmask = available_cmd_bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
#endif
}

/**
 * @brief Pack a custom_dog_current_available_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param available_cmd_bitmask  Currently available commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_current_available_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t available_cmd_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN];
    _mav_put_uint32_t(buf, 0, available_cmd_bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
#else
    mavlink_custom_dog_current_available_cmd_t packet;
    packet.available_cmd_bitmask = available_cmd_bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
}

/**
 * @brief Encode a custom_dog_current_available_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_current_available_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_current_available_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_custom_dog_current_available_cmd_t* custom_dog_current_available_cmd)
{
    return mavlink_msg_custom_dog_current_available_cmd_pack(system_id, component_id, msg, custom_dog_current_available_cmd->available_cmd_bitmask);
}

/**
 * @brief Encode a custom_dog_current_available_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_current_available_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_current_available_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_custom_dog_current_available_cmd_t* custom_dog_current_available_cmd)
{
    return mavlink_msg_custom_dog_current_available_cmd_pack_chan(system_id, component_id, chan, msg, custom_dog_current_available_cmd->available_cmd_bitmask);
}

/**
 * @brief Encode a custom_dog_current_available_cmd struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_current_available_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_current_available_cmd_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_custom_dog_current_available_cmd_t* custom_dog_current_available_cmd)
{
    return mavlink_msg_custom_dog_current_available_cmd_pack_status(system_id, component_id, _status, msg,  custom_dog_current_available_cmd->available_cmd_bitmask);
}

/**
 * @brief Send a custom_dog_current_available_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param available_cmd_bitmask  Currently available commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_custom_dog_current_available_cmd_send(mavlink_channel_t chan, uint32_t available_cmd_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN];
    _mav_put_uint32_t(buf, 0, available_cmd_bitmask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD, buf, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
#else
    mavlink_custom_dog_current_available_cmd_t packet;
    packet.available_cmd_bitmask = available_cmd_bitmask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD, (const char *)&packet, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
#endif
}

/**
 * @brief Send a custom_dog_current_available_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_custom_dog_current_available_cmd_send_struct(mavlink_channel_t chan, const mavlink_custom_dog_current_available_cmd_t* custom_dog_current_available_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_custom_dog_current_available_cmd_send(chan, custom_dog_current_available_cmd->available_cmd_bitmask);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD, (const char *)custom_dog_current_available_cmd, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_custom_dog_current_available_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t available_cmd_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, available_cmd_bitmask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD, buf, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
#else
    mavlink_custom_dog_current_available_cmd_t *packet = (mavlink_custom_dog_current_available_cmd_t *)msgbuf;
    packet->available_cmd_bitmask = available_cmd_bitmask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD, (const char *)packet, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE CUSTOM_DOG_CURRENT_AVAILABLE_CMD UNPACKING


/**
 * @brief Get field available_cmd_bitmask from custom_dog_current_available_cmd message
 *
 * @return  Currently available commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 */
static inline uint32_t mavlink_msg_custom_dog_current_available_cmd_get_available_cmd_bitmask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a custom_dog_current_available_cmd message into a struct
 *
 * @param msg The message to decode
 * @param custom_dog_current_available_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_custom_dog_current_available_cmd_decode(const mavlink_message_t* msg, mavlink_custom_dog_current_available_cmd_t* custom_dog_current_available_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    custom_dog_current_available_cmd->available_cmd_bitmask = mavlink_msg_custom_dog_current_available_cmd_get_available_cmd_bitmask(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN? msg->len : MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN;
        memset(custom_dog_current_available_cmd, 0, MAVLINK_MSG_ID_CUSTOM_DOG_CURRENT_AVAILABLE_CMD_LEN);
    memcpy(custom_dog_current_available_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
