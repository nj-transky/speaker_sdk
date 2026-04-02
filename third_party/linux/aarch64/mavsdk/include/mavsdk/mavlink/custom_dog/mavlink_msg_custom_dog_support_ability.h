#pragma once
// MESSAGE CUSTOM_DOG_SUPPORT_ABILITY PACKING

#define MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY 51851


typedef struct __mavlink_custom_dog_support_ability_t {
 uint32_t capability_bitmask; /*<  Supported commands (bitmask of CUSTOM_DOG_ALL_ABILITY).*/
} mavlink_custom_dog_support_ability_t;

#define MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN 4
#define MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN 4
#define MAVLINK_MSG_ID_51851_LEN 4
#define MAVLINK_MSG_ID_51851_MIN_LEN 4

#define MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC 93
#define MAVLINK_MSG_ID_51851_CRC 93



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_SUPPORT_ABILITY { \
    51851, \
    "CUSTOM_DOG_SUPPORT_ABILITY", \
    1, \
    {  { "capability_bitmask", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_custom_dog_support_ability_t, capability_bitmask) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CUSTOM_DOG_SUPPORT_ABILITY { \
    "CUSTOM_DOG_SUPPORT_ABILITY", \
    1, \
    {  { "capability_bitmask", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_custom_dog_support_ability_t, capability_bitmask) }, \
         } \
}
#endif

/**
 * @brief Pack a custom_dog_support_ability message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param capability_bitmask  Supported commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_support_ability_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t capability_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN];
    _mav_put_uint32_t(buf, 0, capability_bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
#else
    mavlink_custom_dog_support_ability_t packet;
    packet.capability_bitmask = capability_bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
}

/**
 * @brief Pack a custom_dog_support_ability message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param capability_bitmask  Supported commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_support_ability_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t capability_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN];
    _mav_put_uint32_t(buf, 0, capability_bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
#else
    mavlink_custom_dog_support_ability_t packet;
    packet.capability_bitmask = capability_bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
#endif
}

/**
 * @brief Pack a custom_dog_support_ability message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param capability_bitmask  Supported commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_custom_dog_support_ability_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t capability_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN];
    _mav_put_uint32_t(buf, 0, capability_bitmask);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
#else
    mavlink_custom_dog_support_ability_t packet;
    packet.capability_bitmask = capability_bitmask;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
}

/**
 * @brief Encode a custom_dog_support_ability struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_support_ability C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_support_ability_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_custom_dog_support_ability_t* custom_dog_support_ability)
{
    return mavlink_msg_custom_dog_support_ability_pack(system_id, component_id, msg, custom_dog_support_ability->capability_bitmask);
}

/**
 * @brief Encode a custom_dog_support_ability struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_support_ability C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_support_ability_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_custom_dog_support_ability_t* custom_dog_support_ability)
{
    return mavlink_msg_custom_dog_support_ability_pack_chan(system_id, component_id, chan, msg, custom_dog_support_ability->capability_bitmask);
}

/**
 * @brief Encode a custom_dog_support_ability struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param custom_dog_support_ability C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_custom_dog_support_ability_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_custom_dog_support_ability_t* custom_dog_support_ability)
{
    return mavlink_msg_custom_dog_support_ability_pack_status(system_id, component_id, _status, msg,  custom_dog_support_ability->capability_bitmask);
}

/**
 * @brief Send a custom_dog_support_ability message
 * @param chan MAVLink channel to send the message
 *
 * @param capability_bitmask  Supported commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_custom_dog_support_ability_send(mavlink_channel_t chan, uint32_t capability_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN];
    _mav_put_uint32_t(buf, 0, capability_bitmask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY, buf, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
#else
    mavlink_custom_dog_support_ability_t packet;
    packet.capability_bitmask = capability_bitmask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY, (const char *)&packet, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
#endif
}

/**
 * @brief Send a custom_dog_support_ability message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_custom_dog_support_ability_send_struct(mavlink_channel_t chan, const mavlink_custom_dog_support_ability_t* custom_dog_support_ability)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_custom_dog_support_ability_send(chan, custom_dog_support_ability->capability_bitmask);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY, (const char *)custom_dog_support_ability, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
#endif
}

#if MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_custom_dog_support_ability_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t capability_bitmask)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, capability_bitmask);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY, buf, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
#else
    mavlink_custom_dog_support_ability_t *packet = (mavlink_custom_dog_support_ability_t *)msgbuf;
    packet->capability_bitmask = capability_bitmask;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY, (const char *)packet, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_MIN_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_CRC);
#endif
}
#endif

#endif

// MESSAGE CUSTOM_DOG_SUPPORT_ABILITY UNPACKING


/**
 * @brief Get field capability_bitmask from custom_dog_support_ability message
 *
 * @return  Supported commands (bitmask of CUSTOM_DOG_ALL_ABILITY).
 */
static inline uint32_t mavlink_msg_custom_dog_support_ability_get_capability_bitmask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a custom_dog_support_ability message into a struct
 *
 * @param msg The message to decode
 * @param custom_dog_support_ability C-struct to decode the message contents into
 */
static inline void mavlink_msg_custom_dog_support_ability_decode(const mavlink_message_t* msg, mavlink_custom_dog_support_ability_t* custom_dog_support_ability)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    custom_dog_support_ability->capability_bitmask = mavlink_msg_custom_dog_support_ability_get_capability_bitmask(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN? msg->len : MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN;
        memset(custom_dog_support_ability, 0, MAVLINK_MSG_ID_CUSTOM_DOG_SUPPORT_ABILITY_LEN);
    memcpy(custom_dog_support_ability, _MAV_PAYLOAD(msg), len);
#endif
}
